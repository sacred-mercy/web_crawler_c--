#ifndef CRAWLER_H
#define CRAWLER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/CustomQueue.h"
#include "./../session/Session.h"

class Crawler
{
public:
    Crawler(int sessionId);
    ~Crawler();

    void crawlWebsite(Session &session);

private:
    CustomString dataFolder = "./sessionData/";
    int sessionId;
};

#endif // CRAWLER_H
