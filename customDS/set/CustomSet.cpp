#include "CustomSet.h"
#include <iostream>

CustomSet::CustomSet() {}

CustomSet::~CustomSet() {}

void CustomSet::insert(int value)
{
    if (!contains(value))
    {
        data.push_back(value);
    }
}

void CustomSet::remove(int value)
{
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (data[i] == value)
        {
            data.erase(data.begin() + i);
            break;
        }
    }
}

bool CustomSet::contains(int value)
{
    for (int num : data)
    {
        if (num == value)
        {
            return true;
        }
    }
    return false;
}

void CustomSet::display()
{
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
