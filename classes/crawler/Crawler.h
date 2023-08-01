#ifndef CRAWLER_H
#define CRAWLER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/CustomQueue.h"
#include "./../session/Session.h"

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
