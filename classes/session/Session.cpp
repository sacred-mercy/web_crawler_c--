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
}

Session::~Session() {}

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
    // TODO: Check if the session exists
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

void Session::continueOrRestartSession(bool answer)
{
    if (answer)
    {
        continueSession();
    }
    else
    {
        forceRestartSession();
    }
}

void Session::forceRestartSession()
{
    // Delete the folder
    string command = "rm -rf sessionData/" + to_string(sessionID);
    system(command.c_str());
    // Create a folder for the session
    createSession();
}

void Session::continueSession()
{
    // TODO: Continue the session
}