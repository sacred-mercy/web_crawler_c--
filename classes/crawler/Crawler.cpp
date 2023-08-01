#include "Crawler.h"
#include <iostream>
#include <cstdlib> // for system()

// include custom data structures
#include "../../customDS/CustomQueue.h"
#include "../../customDS/string/CustomString.h"

Crawler::Crawler(int sessionId)
{
    this->sessionId = sessionId;
    dataFolder = dataFolder + sessionId + "/" + "data/";
}

void Crawler::crawlWebsite(Session &session)
{
    CustomString urlData = session.getToVisitLink();

    // split the urlData into url and fileIndex and depth
    CustomVector<CustomString> urlDataSplit = urlData.split(' ');
    CustomString url, depth, fileIndex;
    url = urlDataSplit.get(0);
    depth = urlDataSplit.get(2);
    fileIndex = urlDataSplit.get(1);

    // Create a curl command to fetch the HTML data
    CustomString curlCommand = "curl ";
    curlCommand = curlCommand + url + +" -o " + dataFolder + fileIndex + ".html";

    // Execute the command using the system function
    int result = std::system(curlCommand.c_str());

    // Check if the command was executed successfully
    if (result == 0)
        session.AddFilesToParse(fileIndex + " " + depth);
}
