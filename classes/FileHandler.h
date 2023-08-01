#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <fstream>  // for file stream operations
#include <iostream> // for input/output operations
#include <stdio.h>  // read/write operations
#include <stdlib.h> // for exit() function

#include <CustomString.h>
#include <CustomQueue.h>
#include <CustomHashSet.h>

class FileHandler
{
public:
    // Write data to a file from a string
    bool writeFile(const CustomString filename, const CustomString &data);

    // Append data to a file from a string
    bool appendFile(const CustomString filename, const CustomString &data);

    // Write data to a file from a queue
    bool writeFile(const CustomString filename, const CustomQueue<CustomString> &data);

    // Read data from a file
    CustomString readFile(const CustomString filename);

    // Read data from a file and return it as a queue
    CustomQueue<CustomString> readFileToQueue(const CustomString filename);

    // Read data from a file and return it as a hash set
    CustomHashSet<CustomString> readFileToHashSet(const CustomString filename);
};

#endif // FILE_HANDLER_H
