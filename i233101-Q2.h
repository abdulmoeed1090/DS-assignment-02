#include <iostream>
using namespace std;

class Node
{
public:
    char page;
    Node *prev;
    Node *next;
    Node(char d)
    {
        page = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *current;

public:
    DoublyLinkedList()
    {
        head = NULL;
        current = NULL;
    }
    void showPages()
    {
        Node *traverse = head;
        if (!head)
        {
            cout << "List is empty!!\n";
            return;
        }
        while (traverse)
        {
            if (traverse == current)
            {
                cout << "[";
                cout << traverse->page;
                cout << "]->";
            }
            else
            {
                cout << traverse->page << "->";
            }
            traverse = traverse->next;
        }
        cout << "NULL\n";
    }

    void newPageVisit(char val)
    {
        Node *temp = new Node(val);
        if (!head)
        {
            head = temp;
            current = temp;
            return;
        }
        Node *traverse = current->next;
        while (traverse)
        {
            Node *nextNode = traverse->next;
            delete traverse;
            traverse = nextNode;
        }
        current->next = temp;
        temp->prev = current;
        current = temp;
    }
    void moveForward()
    {
        if (!head)
        {
            cout << "List is empty!!\n";
            return;
        }
        if (current->next != NULL)
        {
            current = current->next;
        }
        else
        {
            cout << "No forward page exists!!\n";
        }
    }
    void moveBackward()
    {
        if (!head)
        {
            cout << "List is empty!!\n";
            return;
        }
        if (current->prev != NULL)
        {
            current = current->prev;
        }
        else
        {
            cout << "No backward page exists!!\n";
        }
    }
};
