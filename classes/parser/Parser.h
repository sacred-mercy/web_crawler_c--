#ifndef PARSER_H
#define PARSER_H

#include "./../../customDS/array/CustomVector.h"
#include "./../../customDS/string/CustomString.h"

class Parser
{
public:
    // Constructor
    Parser(int sessionID);

    // Destructor
    ~Parser();

    // Parse the HTML file
    void parseHTML(CustomVector<CustomString> &toParseQueue);

private:
    CustomString content; // HTML file content

    // Helper function to extract links from the HTML file
    void extractData(CustomString content);
};

#endif // PARSER_H
