#include <iostream>
using namespace std;
#include "i233101-Q2_non.h"

int main()
{
    linkedList l1;
    int k=3;
    l1.insertion(1, 10);
    l1.insertion(2, 20);
    l1.insertion(3, 30);
    l1.insertion(4, 15);
    l1.reverseList(k);
    l1.display();
    return 0;
}