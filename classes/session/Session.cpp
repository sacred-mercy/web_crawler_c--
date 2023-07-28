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

void Session::saveSession(const CustomQueue<CustomString> &toVisitQueue, const CustomQueue<CustomString> &toParseQueue)
{
    CustomString toVisitPath = path + "/toVisitQueue.txt";
    CustomString toParsePath = path + "/toParseQueue.txt";
    FileHandler fileHandler;
    fileHandler.writeFile(toVisitPath, toVisitQueue);
    fileHandler.writeFile(toParsePath, toParseQueue);
}

void Session::loadSession(CustomQueue<CustomString> &toVisitQueue, CustomQueue<CustomString> &toParseQueue)
{
    CustomString toVisitPath = path + "/toVisitQueue.txt";
    CustomString toParsePath = path + "/toParseQueue.txt";
    FileHandler fileHandler;
    toVisitQueue = fileHandler.readFileToQueue(toVisitPath);
    toParseQueue = fileHandler.readFileToQueue(toParsePath);
}
