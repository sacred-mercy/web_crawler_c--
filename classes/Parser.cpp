#include <Parser.h>

using namespace std;

// Constructor
Parser::Parser(int sessionId)
{
    this->sessionId = sessionId;
    dataFolder = dataFolder + sessionId + "/" + "data/";
}

// Helper function to extract links from the HTML file
// TODO: use customString instead of string
CustomVector<string> Parser::extractData(string html)
{
    // use regex to extract links
    regex linkRegex(R"(\b((?:https?:\/\/|www\.)[a-zA-Z0-9+&@#\/%?=~_|!:,.;-]*\.[a-zA-Z]{2,}[a-zA-Z0-9+&@#\/%=~_|]*))");

    smatch match;
    CustomVector<string> links = CustomVector<string>();

    // iterate over all matches
    while (regex_search(html, match, linkRegex))
    {
        // get the link
        string link = match[1].str();

        // add the link to the vector
        links.push_back(link);

        // remove the match from the string
        html = match.suffix().str();
    }

    return links;
}

// // Parse the HTML file
void Parser::parseHTML(Session &session)
{
    CustomString contentToParse = session.getToParseFile();

    CustomString fileIndex, depth;
    CustomVector<CustomString> contentToParseSplit = contentToParse.split(' ');
    fileIndex = contentToParseSplit.get(0);
    depth = contentToParseSplit.get(1);

    // Open the HTML file
    std::ifstream htmlFile;
    CustomString filePath = dataFolder;
    filePath = filePath + fileIndex + ".html";
    htmlFile.open(filePath.c_str());

    // Check if the file was opened successfully
    if (htmlFile.is_open())
    {

        // Read the file content into a string
        std::string line;
        std::string content = "";
        while (getline(htmlFile, line))
        {
            content += line;
        }

        // Close the file
        htmlFile.close();

        // Extract links from the HTML file
        CustomVector<string> links = extractData(content);

        // Add fileindex and depth-1 after the link
        CustomQueue<CustomString> linksWithDepth = CustomQueue<CustomString>();
        for (int i = 0; i < links.size(); i++)
        {
            string link = links.get(i);

            int depthNum = stoi(depth.c_str());
            if (depthNum == 0)
                break;

            depthNum--;

            char depthNumChar = depthNum + '0';

            string linkWithDepth = link + " " +
                                   fileIndex.c_str() + "_" + std::to_string(i) + " " +
                                   depthNumChar;

            // convert string to char*
            char *tab2 = new char[linkWithDepth.length() + 1];
            strcpy(tab2, linkWithDepth.c_str());

            // add to queue
            CustomString finalData = CustomString(tab2);
            linksWithDepth.push_back(finalData);
        }
        session.AddLinksToVisit(linksWithDepth);
    }
}
