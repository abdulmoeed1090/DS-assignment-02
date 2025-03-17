#include <iostream>
#include <i233101-Q3.h>
using namespace std;

int main()
{
    Game game;
    int choice;
    string playerName;
    bool isVIP;

    do
    {
        cout << "\n====== Multiplayer Game Turn System ======\n";
        cout << "1. Add Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Next Turn\n";
        cout << "4. Skip Turn\n";
        cout << "5. Pause Game\n";
        cout << "6. Resume Game\n";
        cout << "7. Display Players\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter player name: ";
            cin >> playerName;
            cout << "Is this player a VIP? (1 for Yes, 0 for No): ";
            cin >> isVIP;
            game.addPlayer(playerName, isVIP);
            break;
        case 2:
            cout << "Enter player name to remove: ";
            cin >> playerName;
            game.removePlayer(playerName);
            break;
        case 3:
            game.nextTurn();
            break;
        case 4:
            game.skipTurn();
            break;
        case 5:
            game.pauseGame();
            break;
        case 6:
            game.resumeGame();
            break;
        case 7:
            game.displayPlayers();
            break;
        case 8:
            cout << "Exiting game\n";
            break;
        default:
            cout << "Invalid input!!\n";
        }
    } while (choice != 8);

    return 0;
}
