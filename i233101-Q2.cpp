#include <iostream>
using namespace std;
#include "i233101-Q2.h"

int main()
{
    DoublyLinkedList history;
    char pageName, choice;

    while (true)
    {
        cout << "\n=====MENU=====\nEnter:\n1.N for newPage\n2.B to go backward \n3.F to go forward \n4.E to exit browser\ncin here-->";
        cin >> choice;
        while (choice != 'N' && choice != 'n' && choice != 'F' && choice != 'f' &&
               choice != 'E' && choice != 'e' && choice != 'B' && choice != 'b')
        {
            cout << "Enter valid input\ncin here--> ";
            cin >> choice;
        }
        switch (choice)
        {
        case 'N':
        case 'n':
            cout << "Enter Page Name (should be a character)\ncin here-->";
            cin >> pageName;

            while (!((pageName >= 'A' && pageName <= 'Z') || (pageName >= 'a' && pageName <= 'z')))
            {
                cout << "Enter a valid alphabetic character for page name\ncin here--> ";
                cin >> pageName;
            }

            history.newPageVisit(pageName);
            history.showPages();
            break;

        case 'F':
        case 'f':
            history.moveForward();
            history.showPages();
            break;

        case 'B':
        case 'b':
            history.moveBackward();
            history.showPages();
            break;

        case 'E':
        case 'e':
            cout << "........ Exiting the browser.........\n";
            return 0;
        }
    }

    return 0;
}