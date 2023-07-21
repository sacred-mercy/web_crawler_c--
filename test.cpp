#include <iostream>

#include "./customDS/string/CustomString.h"

// using custom queue
#include "./customDS/queue/CustomQueue.h"

int main()
{
    CustomQueue<CustomString> queue;
    queue.enqueue("Hello");
    std::cout << queue.front().c_str() << std::endl;
}
