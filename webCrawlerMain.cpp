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
        // objects for crawler and parser queue
        CustomQueue<CustomString> toParseQueue = CustomQueue<CustomString>();
        CustomQueue<CustomString> toVisitQueue = CustomQueue<CustomString>();

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
            {
                // load the session data
                session.loadSession(toVisitQueue, toParseQueue);
            }
        }
        else
        {
            session.createSession();
            CustomString seedUrl = url + " f0 " + depth;
            toVisitQueue.enqueue(seedUrl);
        }

        // Create a crawler object
        Crawler crawler = Crawler(sessionID);

        // Create parser object
        Parser parser = Parser(sessionID);

        while (toParseQueue.size() > 0 || toVisitQueue.size() > 0)
        {
            // crawl the website
            double crawlStartTime = time(0);
            cout
                << "toCrawlQueue size: " << toVisitQueue.size() << endl;
            if (toVisitQueue.size() != 0)
            {
                CustomString result = crawler.crawlWebsite(toVisitQueue);
                if (result != "")
                    toParseQueue.enqueue(result);
            }

            // parse the html
            if (toParseQueue.size() != 0)
            {
                CustomVector<CustomString> links = parser.parseHTML(toParseQueue);
                for (std::size_t i = 0; i < links.size(); i++)
                    toVisitQueue.enqueue(links.get(i));
            }

            // save the session data
            session.saveSession(toVisitQueue, toParseQueue);

            double parseEndTime = time(0);

            double crawlTime = parseEndTime - crawlStartTime;

            // sleep if crawl time is less than 6 seconds
            if (crawlTime < 6)
            {
                std::this_thread::sleep_for(crawlTime * 1s);
            }
        }

        cout << "Crawling complete" << endl;
    }
};

WebCrawler *WebCrawler::webCrawler = NULL;
