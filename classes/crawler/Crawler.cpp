#include "Crawler.h"
#include <iostream>
#include <sys/stat.h> // for mkdir()
#include <fstream>
#include <cstdlib> // for system()

// include custom data structures
#include "../../customDS/queue/CustomQueue.h"
#include "../../customDS/string/CustomString.h"

Crawler::Crawler(int sessionId)
{
    sessionID = sessionId;

    // Create a folder for the session
    // mkdir(dataFolder, 0777);
}

Crawler::~Crawler() {}

void Crawler::crawlWebsite(const CustomQueue<CustomString> &queue)
{
    // CustomString command = "curl -o " + dataFolder + sessionID + ".html ";
    // int result = system(command.c_str());

    // if (result == 0)
    // {
    //     cout << "Data fetched successfully." << std::endl;
    // }
    // else
    // {
    //     std::cerr << "Error fetching data." << std::endl;
    // }

    std::cout << "Crawling website." << std::endl;
}
