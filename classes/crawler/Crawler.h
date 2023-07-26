#ifndef CRAWLER_H
#define CRAWLER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/CustomQueue.h"

class Crawler
{
public:
    Crawler(int sessionId);
    ~Crawler();

    CustomString crawlWebsite(CustomQueue<CustomString> &queue);

private:
    CustomString dataFolder = "./sessionData/";
    int sessionId;
};

#endif // CRAWLER_H
