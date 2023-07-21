#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include "../array/CustomVector.h"

class CustomString
{
public:
    // Constructors
    CustomString();
    CustomString(const char *str);

    // Destructor
    ~CustomString();

    // Copy constructor
    CustomString(const CustomString &other);

    // Assignment operator
    CustomString &operator=(const CustomString &other);

    // Get the length of the string
    std::size_t length() const;

    // Append a character to the string
    void append(char c);

    // Get the character at a specific index
    char at(std::size_t index) const;

    // Convert CustomString to C-style string (char*)
    const char *c_str() const;

private:
    CustomVector<char> data;
};

#endif // CUSTOMSTRING_H
