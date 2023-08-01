#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include "../CustomVector.h"
#include <iostream>
#include <cstring> // for strlen and strcpy

class CustomString : public CustomVector<char>
{
public:
    // Default Constructor
    CustomString();

    // Constructor with C-style string input
    CustomString(const char *str);

    // Destructor
    ~CustomString();

    // Copy constructor
    CustomString(const CustomString &other);

    // Copy assignment operator
    CustomString &operator=(const CustomString &other);

    // Move constructor
    CustomString(CustomString &&other) noexcept;

    // Move assignment operator
    CustomString &operator=(CustomString &&other) noexcept;

    // Get the length of the string
    std::size_t length() const;

    // Append a character to the string
    void append(char c);

    // Get the character at a specific index
    char at(std::size_t index) const;

    // Convert CustomString to C-style string (char*)
    const char *c_str() const;

    // print the string
    void print() const;

    // concatenates two strings
    CustomString operator+(const CustomString &other) const;

    // to check not equal to
    bool operator!=(const CustomString &other) const;

    // split the string into a vector of strings
    CustomVector<CustomString> split(char delimiter) const;

    // conactenates custom string with a integer
    CustomString operator+(int other) const;

    // to check if two strings are equal
    bool operator==(const CustomString &other) const;

    // overload the << operator
    friend std::ostream &operator<<(std::ostream &out, const CustomString &str);
};

#endif // CUSTOMSTRING_H
