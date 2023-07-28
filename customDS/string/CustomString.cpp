#include "CustomString.h"

#include "../CustomVector.h"

// Default Constructor
CustomString::CustomString() : CustomVector<char>() {}

// Constructor with C-style string input
CustomString::CustomString(const char *str) : CustomVector<char>()
{
    std::size_t len = strlen(str);
    reserve(len + 1); // Reserve space for the string characters and the null terminator

    for (std::size_t i = 0; i < len; i++)
    {
        push_back(str[i]);
    }
}

// Destructor
CustomString::~CustomString() {}

// Copy constructor
CustomString::CustomString(const CustomString &other) : CustomVector<char>(other) {}

// Copy assignment operator
CustomString &CustomString::operator=(const CustomString &other)
{
    if (this == &other)
    {
        return *this; // Self-assignment check
    }

    CustomVector<char>::operator=(other);

    return *this;
}

// Move constructor
CustomString::CustomString(CustomString &&other) noexcept : CustomVector<char>(std::move(other)) {}

// Move assignment operator
CustomString &CustomString::operator=(CustomString &&other) noexcept
{
    if (this != &other)
    {
        CustomVector<char>::operator=(std::move(other));
    }
    return *this;
}

// Get the length of the string
std::size_t CustomString::length() const
{
    return size();
}

// Append a character to the string
void CustomString::append(char c)
{
    push_back(c);
}

// Get the character at a specific index
char CustomString::at(std::size_t index) const
{
    return get(index);
}

// Convert CustomString to C-style string (char*)
const char *CustomString::c_str() const
{
    // Allocate a new char array with one extra space for the null terminator
    char *cStr = new char[size() + 1];

    // Copy the characters from the CustomString data to the C-style string
    for (std::size_t i = 0; i < size(); i++)
    {
        cStr[i] = get(i);
    }

    // Null-terminate the C-style string
    cStr[size()] = '\0';

    return cStr;
}

// print the string
void CustomString::print() const
{
    for (std::size_t i = 0; i < size(); i++)
    {
        std::cout << get(i);
    }
    std::cout << std::endl;
}

// cocatinates two strings
CustomString CustomString::operator+(const CustomString &other) const
{
    CustomString result = CustomString();

    // Copy the first string
    for (std::size_t i = 0; i < size(); i++)
    {
        result.push_back(get(i));
    }

    // Copy the second string
    for (std::size_t i = 0; i < other.size(); i++)
    {
        result.push_back(other.get(i));
    }

    return result;
}

// split the string into a vector of strings
CustomVector<CustomString> CustomString::split(char delimiter) const
{
    CustomVector<CustomString> result = CustomVector<CustomString>();

    CustomString currentString = CustomString();

    for (std::size_t i = 0; i < size(); i++)
    {
        if (get(i) == delimiter)
        {
            result.push_back(currentString);
            currentString = CustomString();
        }
        else
        {
            currentString.push_back(get(i));
        }
    }

    result.push_back(currentString); // for last string

    return result;
}

// to check not equal to
bool CustomString::operator!=(const CustomString &other) const
{
    if (size() != other.size())
        return true;

    for (std::size_t i = 0; i < size(); i++)
    {
        if (get(i) != other.get(i))
            return true;
    }

    return false;
}

// to convert number to string
CustomString CustomString::operator+(int number) const
{
    CustomString result = CustomString();

    if (number == 0)
    {
        result.push_back('0');
        return result;
    }

    while (number != 0)
    {
        int digit = number % 10;
        result.push_back(digit + '0');
        number /= 10;
    }

    // reverse the string by creating a new custom string and pushing the characters in reverse order
    CustomString reversed = CustomString();

    // Copy the first string
    for (std::size_t i = 0; i < size(); i++)
    {
        reversed.push_back(get(i));
    }

    for (std::size_t i = result.size(); i > 0; i--)
    {
        reversed.push_back(result.get(i - 1));
    }

    return reversed;
}