#include "Session.h"
#include <iostream>
#include <fstream>
#include <cstdlib> // for system()

using namespace std;

Session::Session(int sessionID)
{
    this->sessionID = sessionID;
}

Session::~Session() {}

void Session::createSession()
{
    cout << "Session created." << endl;
}

bool Session::sessionExists()
{
    return false;
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

bool Session::checkSessionExists()
{
    return false;
}

// bool fileExists(const std::string &fileName)
// {
//     std::ifstream file(fileName);
//     return file.good();
// }

void Session::forceRestartSession()
{
    cout << "Session restarted." << endl;
}

void Session::continueSession()
{
    if (sessionExists())
    {
        std::cout << "Session continued." << std::endl;
    }
    else
    {
        std::cout << "Session does not exist." << std::endl;
    }
}