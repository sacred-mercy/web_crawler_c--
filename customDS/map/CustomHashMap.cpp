// #include "CustomHashMap.h"

// CustomHashMap::CustomHashMap()
// {
//     this->size = 0;
//     this->capacity = 10;
//     this->buckets = new CustomLinkedList<CustomString, CustomVector<CustomString>>[this->capacity];
// }

// CustomHashMap::~CustomHashMap()
// {
//     delete this->buckets;
// }

// int CustomHashMap::hash(CustomString key) const
// {
//     int hash = 0;
//     for (int i = 0; i < key.length(); i++)
//     {
//         hash += key.at(i)
//     }
//     return hash % this->capacity;
// }

// void CustomHashMap::insert(CustomString key, CustomVector<CustomString> value)
// {
//     int index = this->hash(key);
//     this->buckets[index].insert(key, value);
//     this->size++;

//     // Resize if load factor is greater than 0.7
//     if (this->size > 0.7 * this->capacity)
//     {
//         this->resize();
//     }
// }

// CustomVector<CustomString> CustomHashMap::find(CustomString key, CustomVector<CustomString> &value) const
// {
//     int index = this->hash(key);

//     // Find the value for the given key
//     CustomVector<CustomString> value;
//     CustomLinkedList<CustomString, CustomVector<CustomString>> *ll = &this->buckets[index];
//     while (ll != nullptr)
//     {
//         if (ll->domain == key)
//         {
//             value = ll->timestamps;
//             break;
//         }
//         ll = ll->next;
//     }
// }