#ifndef CRAWLER_H
#define CRAWLER_H

#include <../customDS/string/CustomString.h>

class Crawler
{
public:
    Crawler(int sessionId);
    ~Crawler();

    void crawlWebsite(const std::string &url);

private:
    string dataFolder = "./sessionData/";
    int sessionID;
};

#endif // CRAWLER_H
