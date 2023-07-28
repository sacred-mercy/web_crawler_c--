#include "Session.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for system()
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Session::Session(int sessionID)
{
    this->sessionID = sessionID;
    path = path + sessionID;
}

void Session::createSession()
{
    // Create a folder for the session
    string command = "mkdir -p sessionData/" + to_string(sessionID);
    system(command.c_str());

    // create htmlFiles folder
    command = "mkdir -p sessionData/" + to_string(sessionID) + "/data";
    system(command.c_str());

    // Create a file for the session
    string path = "sessionData/" + to_string(sessionID) + "/toParseQueue.txt";
    ofstream file(path.c_str());
    file.close();

    path = "sessionData/" + to_string(sessionID) + "/toVisitQueue.txt";
    file.open(path.c_str());
    file.close();

    path = "sessionData/" + to_string(sessionID) + "/visited.txt";
    file.open(path.c_str());
    file.close();
}

bool Session::checkSessionExists()
{
    // Check if the folder exists
    struct stat info;
    string path = "sessionData/" + to_string(sessionID);
    if (stat(path.c_str(), &info) != 0)
    {
        return false;
    }
    else if (info.st_mode & S_IFDIR)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Session::saveSession()
{
    FileHandler fileHandler;
    fileHandler.writeFile(path + "/toVisitQueue.txt", toVisitQueue);
    fileHandler.writeFile(path + "/toParseQueue.txt", toParseQueue);
}

void Session::loadSession()
{
    FileHandler fileHandler;
    toVisitQueue = fileHandler.readFileToQueue(path + "/toVisitQueue.txt");
    toParseQueue = fileHandler.readFileToQueue(path + "/toParseQueue.txt");
}

CustomString Session::getToParseFile()
{
    CustomString toParse = toParseQueue.front();
    toParseQueue.dequeue();
    return toParse;
}

CustomString Session::getToVisitLink()
{
    CustomString toVisit = toVisitQueue.front();
    toVisitQueue.dequeue();
    return toVisit;
}

void Session::setSeedUrl(CustomString seedUrl)
{
    toVisitQueue.enqueue(seedUrl);
}

void Session::AddLinksToVisit(CustomQueue<CustomString> links)
{
    while (!links.empty())
    {
        CustomString link = links.front();
        links.dequeue();
        // if (visitedLinks.find(link) == visitedLinks.end())
        // {
        toVisitQueue.enqueue(link);
        // }
    }
}

void Session::AddFilesToParse(CustomString file)
{
    toParseQueue.enqueue(file);
}

bool Session::isToVisitQueueEmpty()
{
    return toVisitQueue.empty();
}

bool Session::isToParseQueueEmpty()
{
    return toParseQueue.empty();
}