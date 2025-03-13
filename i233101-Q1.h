#include <iostream>
using namespace std;

class Node
{
public:
    char character;
    Node *prev;
    Node *next;
    Node(char d)
    {
        character = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *current;
    Node *undo;
    Node *redo;

public:
    DoublyLinkedList()
    {
        head = NULL;
        current = NULL;
        undo = redo = NULL;
    }

    void typeChar(char val)
    {
        Node *temp = new Node(val);
        if (!head)
        {
            head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            temp->prev = current;
            current = temp;
        }

        // If a new character is typed, redo history is cleared
        redo = NULL;
    }

    void showList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->character;
            if (temp == current)
            {
                cout << "|"; // Cursor indicator
            }
            temp = temp->next;
        }
        cout << "\n";
    }

    void backSpace()
    {
        if (!current)
        {
            cout << "List is empty!!\n";
            return;
        }

        undo = current;
        if (current->prev)
        {
            current = current->prev;
            current->next = NULL;
        }
        else
        {
            head = NULL;
            current = NULL;
        }

        redo = NULL;
    }

    void UNDO()
    {
        if (!undo)
        {
            cout << "Nothing to undo!\n";
            return;
        }

        redo = undo;

        if (!head)
        {
            head = undo;
            current = undo;
        }
        else
        {
            current->next = undo;
            undo->prev = current;
            current = undo;
        }

        undo = NULL;
    }

    void REDO()
    {
        if (!redo)
        {
            cout << "Nothing to redo!\n";
            return;
        }

        if (!head)
        {
            head = redo;
            current = redo;
        }
        else
        {
            // current->prev = redo;
            // redo->next = current;
            // current = redo;
            backSpace();
        }

        redo = NULL;
    }
};
