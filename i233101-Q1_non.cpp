#include <iostream>
#include "i233101-Q1_non.h"
using namespace std;

int main()
{
    DoublyLinkedList dll;
    dll.insertion(1, 10);
    dll.insertion(2, 20);
    dll.insertion(3, 30);
    dll.insertion(4, 15);
    dll.createCycle(4);
    dll.checkCycle();

    return 0;
}
