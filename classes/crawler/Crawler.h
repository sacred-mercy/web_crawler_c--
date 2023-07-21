#ifndef CRAWLER_H
#define CRAWLER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/queue/CustomQueue.h"

class Crawler
{
public:
    Crawler(int sessionId);
    ~Crawler();

    void crawlWebsite(CustomQueue<CustomString> &queue);

private:
    CustomString dataFolder = "./sessionData/";
    int sessionID;
};

#endif // CRAWLER_H
