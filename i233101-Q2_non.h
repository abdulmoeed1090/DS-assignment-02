#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class linkedList
{
private:
    Node *head;

public:
    linkedList()
    {
        head = NULL;
    }

    void insertion(int pos, int val)
    {
        Node *node = new Node(val);

        if (!head || pos == 1)
        {
            node->next = head;
            head = node;
            return;
        }

        Node *temp = head;
        for (int i = 1; temp->next != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = node;
    }
    int calculateLen()
    {
        Node *temp = head;
        int len = 0;
        while (temp)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void reverseList(int k)
    {
        if (!head || k <= 1 || k > calculateLen())
        {
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        Node *next = NULL;

        int count = 0;

        count = 0;
        while (temp && count < k)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
            count++;
        }

        head->next = next;
        head = prev;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
