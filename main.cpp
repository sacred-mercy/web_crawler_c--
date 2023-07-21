#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <regex>

// Custom Data Structures
#include "customDS/queue/CustomQueue.h"
#include "customDS/string/CustomString.h"

// classes
#include "classes/crawler/Crawler.h"
#include "classes/parser/Parser.h"
#include "classes/session/Session.h"

using namespace std;

int main()
{
    // seed url and session id
    string url = "https://narf.org/";
    int sessionID = 11;

    // create datastructure objects for crawler and parser
    CustomQueue toParseQueue;
    CustomQueue toVisitQueue;

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
        session.createSession(url);
    }

    // Create a crawler object
    Crawler crawler = Crawler(sessionID);

    // Create parser object
    Parser parser = Parser(sessionID);

    while (toParseQueue.size() > 0 || toVisitQueue.size() > 0)
    {
        crawler.crawlWebsite(toVisitQueue);
        parser.parseHTML(toParseQueue);
    }
}