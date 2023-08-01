#ifndef CRAWLER_H
#define CRAWLER_H

// include standard libraries
#include <iostream>
#include <cstdlib> // for system()

// include custom data structures
#include <Session.h>
#include <CustomQueue.h>
#include <CustomString.h>

class Crawler
{
public:
    Crawler(int sessionId);

    void crawlWebsite(Session &session);

private:
    int sessionId;
    CustomString dataFolder = "./sessionData/";
};

#endif // CRAWLER_H
