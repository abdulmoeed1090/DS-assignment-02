#include <iostream>
using namespace std;

class Player
{
public:
    string name;
    Player *next;
    bool skipNextTurn;
    bool isVIP;

    Player(string n, bool vip = false)
    {
        name = n;
        next = NULL;
        skipNextTurn = false;
        isVIP = vip;
    }
};

class Game
{
private:
    Player *current;
    bool isPaused;

public:
    Game()
    {
        current = NULL;
        isPaused = false;
    }

    void addPlayer(string name, bool isVIP = false)
    {
        Player *newPlayer = new Player(name, isVIP);
        if (!current)
        {
            current = newPlayer;
            current->next = current;
        }
        else
        {
            Player *temp = current;
            while (temp->next != current)
            {
                temp = temp->next;
            }
            temp->next = newPlayer;
            newPlayer->next = current;
        }
        cout << name << " joined the game. " << (isVIP ? "(VIP Player)" : "") << endl;
    }

    void removePlayer(string name)
    {
        if (isPaused)
        {
            cout << "Game is paused! You cannot remove players now\n";
            return;
        }

        if (!current)
        {
            cout << "No players in the game!\n";
            return;
        }

        Player *temp = current, *prev = NULL;
        do
        {
            if (temp->name == name)
            {
                if (temp == current && temp->next == current)
                {
                    delete temp;
                    current = NULL;
                    cout << "Game has no players left\n";
                    return;
                }

                if (temp == current)
                {
                    current = current->next;
                }
                if (prev)
                {
                    prev->next = temp->next;
                }
                else
                {
                    Player *last = current;
                    while (last->next != temp)
                    {
                        last = last->next;
                    }
                    last->next = temp->next;
                    current = temp->next;
                }
                delete temp;
                cout << name << " left the game\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != current);

        cout << "Player not found\n";
    }

    void skipTurn()
    {
        if (isPaused)
        {
            cout << "Game is paused! You cannot skip turns now\n";
            return;
        }

        if (!current)
        {
            cout << "No players in the game!\n";
            return;
        }
        current->skipNextTurn = true;
        cout << current->name << " chose to skip their next turn\n";
    }

    void pauseGame()
    {
        isPaused = true;
        cout << "Game paused |>\n";
    }

    void resumeGame()
    {
        isPaused = false;
        cout << "Game resumed ||\n";
    }

    void nextTurn()
    {
        if (isPaused)
        {
            cout << "Game is paused! Cannot proceed to next turn\n";
            return;
        }

        if (!current)
        {
            cout << "No players in the game!\n";
            return;
        }

        do
        {
            if (!current->skipNextTurn)
            {
                cout << "It's " << current->name << "'s turn\n";
                if (current->isVIP)
                {
                    cout << current->name << " is a VIP! Taking another turn\n";
                }
                current = current->next;
                if (current->isVIP)
                {
                    cout << "It's " << current->name << "'s VIP turn again!\n";
                }
                return;
            }
            else
            {
                current->skipNextTurn = false;
                current = current->next;
            }
        } while (true);
    }

    void displayPlayers()
    {
        if (isPaused)
        {
            cout << "Game is paused! Cannot display players now\n";
            return;
        }

        if (!current)
        {
            cout << "No players in the game\n";
            return;
        }
        Player *temp = current;
        cout << "Players in game: ";
        do
        {
            cout << temp->name << (temp->isVIP ? "(VIP) " : " ") << "-> ";
            temp = temp->next;
        } while (temp != current);
        cout << "(Back to " << current->name << ")\n";
    }
};
