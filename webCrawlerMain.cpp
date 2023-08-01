#include <iostream>
#include <ctime>
#include <thread>

// Custom Data Structures
#include "customDS/CustomQueue.h"
#include "customDS/string/CustomString.h"

// classes
#include "classes/crawler/Crawler.h"
#include "classes/parser/Parser.h"
#include "classes/session/Session.h"

using namespace std;

class WebCrawler
{
private:
    // static pointer to the WebCrawler object
    static WebCrawler *webCrawler;

    // private constructor
    WebCrawler() {}

public:
    // delete copy constructor and assignment operator
    WebCrawler(WebCrawler const &) = delete;
    void operator=(WebCrawler const &) = delete;

    // static method to get the WebCrawler object
    static WebCrawler *getWebCrawler()
    {
        if (webCrawler == NULL)
            webCrawler = new WebCrawler();
        return webCrawler;
    }

    // Start the web crawler
    void start(CustomString url, int sessionID, int depth)
    {
        CustomString seedUrl = url + " f0 " + depth;

        // Create a session object
        Session session = Session(sessionID);

        if (session.checkSessionExists())
        {
            // ask user if they want to continue or restart
            cout << "Session already exists. ";
            cout << "Do you want to continue session? (1/0) " << endl;
            int choice;
            cin >> choice;

            if (choice == 1)
                session.loadSession(); // load the session data
            else
                session.createSession(seedUrl);
        }
        else
        {
            session.createSession(seedUrl);
        }

        // Create a crawler object
        Crawler crawler = Crawler(sessionID);

        // Create parser object
        Parser parser = Parser(sessionID);

        while (session.isToParseQueueEmpty() == false || session.isToVisitQueueEmpty() == false)
        {
            double crawlStartTime = time(0); // start time of crawling

            // crawl the website
            if (!session.isToVisitQueueEmpty())
                crawler.crawlWebsite(session);

            // parse the html
            if (!session.isToParseQueueEmpty())
                parser.parseHTML(session);

            session.saveSession(); // save the session data

            double parseEndTime = time(0); // end time of parsing

            double totalCrawlTime = parseEndTime - crawlStartTime;

            // sleep if crawl time is less than 6 seconds
            if (totalCrawlTime < 6)
                std::this_thread::sleep_for(totalCrawlTime * 1s);
        }
    }
};

WebCrawler *WebCrawler::webCrawler = NULL;
