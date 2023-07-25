#include "Crawler.h"
#include <iostream>
#include <cstdlib> // for system()

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

// include custom data structures
#include "../../customDS/CustomQueue.h"
#include "../../customDS/string/CustomString.h"

Crawler::Crawler(int sessionId)
{
    sessionID = sessionId;

    // Create a folder for the session
    // mkdir(dataFolder, 0777);
}

Crawler::~Crawler() {}

CustomString Crawler::crawlWebsite(CustomQueue<CustomString> &queue)
{
    // URL of the website you want to fetch HTML data from
    CustomString urlData = queue.front();
    queue.dequeue();

    // split the urlData into url and fileIndex and depth
    CustomVector<CustomString> urlDataSplit = urlData.split(' ');
    CustomString url, depth, fileIndex;
    url = urlDataSplit.get(0);
    depth = urlDataSplit.get(2);
    fileIndex = urlDataSplit.get(1);

    // Create a curl command to fetch the HTML data
    CustomString curlCommand = "curl ";
    curlCommand = curlCommand + url + +" -o sessionData/" + fileIndex + ".html";

    // Execute the command using the system function
    std::cout << curlCommand.c_str() << std::endl;
    std::this_thread::sleep_for(2s);
    int result = std::system(curlCommand.c_str());

    // Check if the command was executed successfully
    if (result == 0)
    {
        std::cout << "Successfully fetched website HTML data." << std::endl;
        CustomString toParse = fileIndex + " " + depth;
        return toParse;
    }
    else
    {
        std::cout << "Failed to fetch website HTML data." << std::endl;
        return "";
    }
}
