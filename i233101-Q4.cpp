#include <iostream>
#include "i233101-Q4.h"
using namespace std;


int main()
{
    MusicPlaylist mp1;
    int choice = 0;
    char song;

    while (choice != 7)
    {
        cout << "\n===== Music Playlist Menu =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Current Song\n";
        cout << "3. Skip Forward\n";
        cout << "4. Go Back\n";
        cout << "5. Shuffle Songs\n";
        cout << "6. Display Playlist\n";
        cout << "7. Exit\n";
        cout << "================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        while (choice < 1 || choice > 7)
        {
            cout << "Invalid input!!\n Enter [1-7]:";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter song character: ";
            cin >> song;
            mp1.addNode(song);
            break;

        case 2:
            mp1.deletingCurrSong();
            break;

        case 3:
            mp1.skipForward();
            break;

        case 4:
            mp1.goBack();
            break;

        case 5:
            mp1.shuffleSongs();
            break;

        case 6:
            mp1.displayMusicList();
            break;

        case 7:
            cout << ".............Exiting Music Playlist.............\n";
            break;
        }
    }

    return 0;
}
