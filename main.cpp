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

int main()
{
    // seed url and session id
    CustomString url = "https://www.example.com";
    int sessionID = 11;

    // objects for crawler and parser queue
    CustomQueue<CustomString> toParseQueue = CustomQueue<CustomString>();
    CustomQueue<CustomString> toVisitQueue = CustomQueue<CustomString>();

    // Create a session object
    Session session = Session(sessionID);

    if (session.checkSessionExists())
    {
        // ask user if they want to continue or restart
        cout << "Session already exists. ";
        cout << "Do you want to continue or restart ? (c / r) " << endl;
        char choice;
        cin >> choice;

        session.continueOrRestartSession(choice == 'c');
    }
    else
    {
        session.createSession();
        CustomString seedUrl = url + " f0 5";
        toVisitQueue.enqueue(seedUrl);
    }

    // Create a crawler object
    Crawler crawler = Crawler(sessionID);

    // Create parser object
    Parser parser = Parser(sessionID);

    while (toParseQueue.size() > 0 || toVisitQueue.size() > 0)
    {
        double crawlStartTime = time(0);
        cout
            << "toCrawlQueue size: " << toVisitQueue.size() << endl;
        if (toVisitQueue.size() != 0)
        {
            CustomString result = crawler.crawlWebsite(toVisitQueue);
            if (result != "")
                toParseQueue.enqueue(result);
        }

        cout << "toParseQueue size: " << toParseQueue.size() << endl;
        if (toParseQueue.size() != 0)
        {
            CustomVector<CustomString> links = parser.parseHTML(toParseQueue);
            if (links.size() != 0)
                for (std::size_t i = 0; i < links.size(); i++)
                    toVisitQueue.enqueue(links.get(i));
        }

        double parseEndTime = time(0);

        double crawlTime = parseEndTime - crawlStartTime;

        // sleep if crawl time is less than 6 seconds
        if (crawlTime < 6)
        {
            std::this_thread::sleep_for(crawlTime * 1s);
        }
    }
}
