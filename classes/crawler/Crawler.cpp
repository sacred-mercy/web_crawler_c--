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

void Crawler::crawlWebsite(CustomQueue<CustomString> &queue)
{
    // URL of the website you want to fetch HTML data from
    std::string url = "https://example.com";

    std::string curlCommand = "curl " + url + " -o output.html ";

    // Concatenate the URL and curl command
    std::string fullCommand = curlCommand + url;

    // Execute the command using the system function
    int result = std::system(fullCommand.c_str());

    // Check if the command was executed successfully
    if (result == 0)
    {
        std::cout << "Website HTML data fetched successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to fetch website HTML data." << std::endl;
    }
}
