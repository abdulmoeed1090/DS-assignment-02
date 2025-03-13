#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertion(int pos, int val)
    {
        Node *node = new Node(val);

        // insert at starting position
        if (!head || pos == 1)
        {
            node->next = head;
            if (head)
            {
                head->prev = node;
            }
            head = node;
            return;
        }

        Node *temp = head;
        // insertion at pos
        for (int i = 1; temp->next != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        node->prev = temp;

        if (temp->next)
        {
            temp->next->prev = node;
        }
        temp->next = node;
    }
    void checkCycle()
    {
        if (!head)
        {
            cout << "No cycle exists in this list i.e list is empty!!\n";
            return;
        }

        Node *oneStep = head;
        Node *twoSteps = head;

        while (twoSteps && twoSteps->next)
        {
            oneStep = oneStep->next;
            twoSteps = twoSteps->next->next;
            if (oneStep == twoSteps)
            {
                cout << "Cycle detected in the list\n";
                return;
            }
        }
        cout << "No cycle exists in this list\n";
    }

    void createCycle(int pos)
    {
        if (!head)
        {
            cout << "List is empty!!\n";
            return;
        }

        Node *temp = head;
        Node *cycle = NULL;
        int count = 1;

        while (temp->next != NULL)
        {
            if (count == pos)
            {
                cycle = temp;
            }
            temp = temp->next;
            count++;
        }

        if (cycle != NULL)
        {
            temp->next = cycle;
        }
    }

};
