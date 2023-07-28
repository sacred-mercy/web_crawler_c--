#ifndef SESSION_H
#define SESSION_H

#include "./../../customDS/CustomQueue.h"
#include "./../../customDS/string/CustomString.h"
#include "./../fileHandler/FileHandler.h"
#include <set>

class Session
{
public:
    Session(int sessionID);
    void createSession();
    bool checkSessionExists();
    void saveSession();
    void loadSession();

    CustomString getToParseFile();
    CustomString getToVisitLink();

    void setSeedUrl(CustomString seedUrl);
    void AddLinksToVisit(CustomQueue<CustomString> links);
    void AddFilesToParse(CustomString file);

    bool isToVisitQueueEmpty();
    bool isToParseQueueEmpty();

private:
    int sessionID;
    CustomString path = "sessionData/";
    CustomQueue<CustomString> toVisitQueue;
    CustomQueue<CustomString> toParseQueue;
    std::set<CustomString> visitedLinks;
};

#endif // SESSION_H
