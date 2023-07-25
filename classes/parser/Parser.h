#ifndef PARSER_H
#define PARSER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/CustomQueue.h"
#include <string>

class Parser
{
public:
    // Constructor
    Parser(int sessionID);

    // Destructor
    ~Parser();

    // Parse the HTML file
    CustomVector<CustomString> parseHTML(CustomQueue<CustomString> &toParseQueue);

private:
    // CustomString content; // HTML file content

    // Helper function to extract links from the HTML file
    CustomVector<std::string> extractData(std::string content);
};

#endif // PARSER_H
