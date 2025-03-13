#include <iostream>
#include "i233101-Q1.h"
using namespace std;

int main()
{
    DoublyLinkedList textEditor;
    char choice, character;

    while (true)
    {
        cout << "\n=====MENU=====\nEnter :\n1. Type a character (T/t)\n2. Backspace (B/b)\n3. Undo (U/u)\n4. Redo (R/r)\n5. Exit (E/e)\ncin here-->";
        
        cin >> choice;
        while (choice != 't' && choice != 'T' && choice != 'U' && choice != 'u' &&
            choice != 'r' && choice != 'r' && choice != 'B' && choice != 'b'&& choice != 'E' && choice != 'e')
     {
         cout << "Enter valid input\ncin here--> ";
         cin >> choice;
     }
        switch (choice)
        {
        case 'T':
        case 't':
            cout << "Enter a character to type: ";
            cin >> character;
            textEditor.typeChar(character);
            textEditor.showList();
            break;

        case 'B':
        case 'b':
            textEditor.backSpace();
            textEditor.showList();
            break;

        case 'U':
        case 'u':
            textEditor.UNDO();
            textEditor.showList();
            break;

        case 'R':
        case 'r':
            textEditor.REDO();
            textEditor.showList();
            break;

        case 'E':
        case 'e':
            cout << "Exiting text editor...\n";
            return 0;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
