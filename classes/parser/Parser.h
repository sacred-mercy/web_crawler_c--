#ifndef PARSER_H
#define PARSER_H

#include "./../../customDS/string/CustomString.h"
#include "./../../customDS/CustomQueue.h"
#include "./../session/Session.h"
#include <string>
#include <set>

class Parser
{
public:
    // Constructor
    Parser(int sessionID);

    // Parse the HTML file
    void parseHTML(Session &session);

private:
    // CustomString content; // HTML file content

    CustomString dataFolder = "sessionData/";
    int sessionId;

    // Helper function to extract links from the HTML file
    CustomVector<std::string> extractData(std::string content);

    // helper function to extract only unique links
};

#endif // PARSER_H
