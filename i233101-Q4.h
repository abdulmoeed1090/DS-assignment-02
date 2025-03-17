#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class node
{
public:
    node *next;
    node *prev;
    char song;
    node(char s)
    {
        next = NULL;
        prev = NULL;
        song = s;
    }
};

class MusicPlaylist
{
private:
    node *head;
    node *tail;
    node *current;

public:
    MusicPlaylist()
    {
        head = NULL;
        tail = NULL;
        current = NULL;
    };

    int calculateLen()
    {
        if (!head)
        {
            return 0;
        }

        node *temp = head->next;
        int len = 1;
        while (temp != head)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    void shuffleSongs()
    {
        srand(time(0));

        int len = calculateLen();
        if (len < 2)
        {
            cout << "Not enough songs to shuffle!" << endl;
            return;
        }

        node *current = head;
        for (int i = 0; i < len - 1; i++)
        {
            int randomIndex = i + rand() % (len - i);

            node *target = head;
            for (int j = 0; j < randomIndex; j++)
            {
                target = target->next;
            }

            swap(current->song, target->song);

            current = current->next;
        }

        cout << "Songs shuffled successfully!" << endl;
    }

    void deletingCurrSong()
    {
        if (!head || !current)
        {
            cout << "list is empty!!\n";
            return;
        }
        node *deletion = current;
        if (head == tail)
        {
            delete current;
            head = NULL;
            tail = NULL;
            current = NULL;
            cout << "list is empty!!\n";
            return;
        }

        if (current == head)
        {
            head = current->next;
        }
        if (current == tail)
        {
            tail = current->prev;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        current = current->next;

        delete deletion;
        cout << "Current song deleted\n";
        cout << "Now playing song[" << current->song << "]\n";
    }

    void skipForward()
    {
        if (!current || !head)
        {
            cout << "Can't skip, List is empty!!\n";
            return;
        }
        cout << "Skipped forward\n";
        current = current->next;
    }
    void goBack()
    {
        if (!head || !current)
        {
            cout << "Can't go back, List is empty!!\n";
            return;
        }
        cout << "Moved back\n";
        current = current->prev;
    }

    void addNode(char s)
    {
        node *temp = new node(s);

        if (!head)
        {
            head = temp;
            tail = temp;
            temp->next = temp;
            temp->prev = temp;
            current = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            temp->next = head;
            head->prev = temp;
            tail = temp;
        }
        current = temp;
        cout << "Added song: " << s << endl;
    }

    void displayMusicList()
    {
        if (!head)
        {
            cout << "List is empty !!\n";
            return;
        }
        node *temp = head;

        cout << "Playlist: ";
        do
        {
            if (temp == current)
            {
                cout << "[" << temp->song << "] <-> ";
            }
            else
            {
                cout << temp->song << " <-> ";
            }
            temp = temp->next;
        } while (temp != head);

        cout << "(Looping back)\n";
    }
};