// FileHandler.cpp
#include "FileHandler.h"
#include <iostream>

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
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return "";

    std::string line;
    CustomString result;
    while (std::getline(file, line))
    {
        result = result + line.c_str();
        result = result + "\n";
    }
    file.close();
    return result;
}

CustomQueue<CustomString> FileHandler::readFileToQueue(const CustomString filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return CustomQueue<CustomString>();

    std::string line;
    CustomQueue<CustomString> result;
    while (std::getline(file, line))
    {
        result.enqueue(line.c_str());
    }
    file.close();
    return result;
}