#include "Crawler.h"
#include <iostream>
#include <sys/stat.h> // for mkdir()
#include <fstream>
#include <cstdlib> // for system()

Crawler::Crawler(int sessionId)
{
    sessionID = sessionId;
    sprintf(dataFolder, "data/%d", sessionID);

    // Create a folder for the session
    mkdir(dataFolder, 0777);
}

Crawler::~Crawler() {}

void Crawler::crawlWebsite(const std::string &url)
{
    std::string command = "curl -o " + dataFolder + sessionID + ".html ";
    int result = system(command.c_str());

    if (result == 0)
    {
        std::cout << "Data fetched successfully." << std::endl;
    }
    else
    {
        std::cerr << "Error fetching data." << std::endl;
    }
}
