#ifndef SESSION_H
#define SESSION_H

#include "./../../customDS/CustomQueue.h"
#include "./../../customDS/string/CustomString.h"
#include "./../fileHandler/FileHandler.h"

class Session
{
public:
    Session(int sessionID);
    void createSession();
    void continueOrRestartSession(bool answer);
    bool checkSessionExists();
    void forceRestartSession();
    void continueSession();
    void saveSession(const CustomQueue<CustomString> &toVisitQueue, const CustomQueue<CustomString> &toParseQueue);
    void loadSession(CustomQueue<CustomString> &toVisitQueue, CustomQueue<CustomString> &toParseQueue);

private:
    int sessionID;
    CustomString path = "sessionData/";
};

#endif // SESSION_H
