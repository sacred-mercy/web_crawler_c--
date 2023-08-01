#ifndef PARSER_H
#define PARSER_H

#include <CustomString.h>
#include <CustomQueue.h>
#include <Session.h>

#include <fstream> // for file input
#include <iostream>
#include <regex> // for regex
#include <string>

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
