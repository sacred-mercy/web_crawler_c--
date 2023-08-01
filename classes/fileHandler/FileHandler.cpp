// FileHandler.cpp
#include "FileHandler.h"

bool FileHandler::writeFile(const CustomString filename, const CustomString &data)
{
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        return false;

    file << data.c_str();
    file.close();
    return true;
}

bool FileHandler::writeFile(const CustomString filename, const CustomQueue<CustomString> &data)
{
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        return false;

    CustomQueue<CustomString> temp = data;
    while (!temp.empty())
    {
        file << temp.front().c_str() << std::endl;
        temp.dequeue();
    }
    file.close();
    return true;
}

CustomString FileHandler::readFile(const CustomString filename)
{
    CustomString result;

    FILE *ptr;
    char ch;
    ptr = fopen(filename.c_str(), "r");

    if (ptr == NULL)
    {
        std::cout << "Cannot open file\n";
        exit(0);
    }

    ch = fgetc(ptr);
    while (ch != EOF)
    {
        result.append(ch);
        ch = fgetc(ptr);
    }

    fclose(ptr);
    return result;
}

CustomQueue<CustomString> FileHandler::readFileToQueue(const CustomString filename)
{
    CustomQueue<CustomString> result;
    CustomString line;

    FILE *ptr;
    char ch;
    ptr = fopen(filename.c_str(), "r");

    if (ptr == NULL)
    {
        std::cout << "Cannot open file\n";
        exit(0);
    }

    ch = fgetc(ptr);
    while (ch != EOF)
    {
        if (ch == '\n')
        {
            result.enqueue(line);
            line = "";
        }
        else
        {
            line.append(ch);
        }
        ch = fgetc(ptr);
    }

    fclose(ptr);

    return result;
}