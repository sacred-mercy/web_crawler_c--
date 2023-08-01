#ifndef SESSION_H
#define SESSION_H

#include <iostream>    // for cout
#include <fstream>     // for file handling
#include <cstdlib>     // for system()
#include <sys/types.h> // for stat()
#include <sys/stat.h>  // for stat()
#include <unistd.h>    // for stat()

#include <CustomString.h>
#include <CustomQueue.h>
#include <FileHandler.h>
#include <CustomHashSet.h>

class Session
{
public:
    Session(int sessionID);
    void createSession(CustomString seedUrl);
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
    CustomHashSet<CustomString> visitedLinks;
};

#endif // SESSION_H
