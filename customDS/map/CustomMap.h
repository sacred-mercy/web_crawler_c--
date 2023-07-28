#ifndef CUSTOM_MAP_H
#define CUSTOM_MAP_H

#include "./../string/CustomString.h"
#include "./../CustomVector.h"
#include "./../LList/CustomList.h"

template <typename T, typename U>
class CustomMap
{
private:
    CustomVector<CustomList<T, U>> *map;
    static int BucketSize;
    int hash(T domain) const;

public:
    CustomMap();
    bool find(T domain) const;
    U get(T domain) const;
    void resize(int newSize);
    void rehash() const;
    void insert(T domain, U timestamps);
    int size() const;
};

#endif
