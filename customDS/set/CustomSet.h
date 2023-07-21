#ifndef CUSTOMSET_H
#define CUSTOMSET_H

#include <vector>

class CustomSet
{
public:
    CustomSet();
    ~CustomSet();

    void insert(int value);
    void remove(int value);
    bool contains(int value);
    void display();

private:
    std::vector<int> data;
};

#endif // CUSTOMSET_H
