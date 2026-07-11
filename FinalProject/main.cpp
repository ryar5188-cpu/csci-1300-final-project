#include <iostream>
#include <vector>
#include <string>
using namespace std;

void startingMenu(){
    cout << "                                           --- FANTASY CONGRESS ---" << endl;
    cout << "PRESS 1 TO START NEW GAME" << endl;
    cout << "PRESS 2 TO START SEEDED GAME" << endl;
    cout << "PRESS 3 TO QUIT" << endl;
}

void startMenu(){
cout << "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
cout << "| QUARTER:    1/4 | TURN: 1/3 |                                                                      FANTASY CONGRESS                                                                                |" << endl;
cout << "|-----------------|-----------|                                                                                                                                                                      |" << endl;
cout << "| CASH:        $0 |                                                                                                                                                                                  |" << endl;
cout << "|-----------------|                                                                                                                                                                                  |" << endl;
cout << "| CHARISMA PTS: 0 |                                                                                                                                                                                  |" << endl;
cout << "|---------------------------------------------|                                                                                                                                                      |" << endl;
cout << "|                  INVENTORY                  |                                                                                                                                                      |" << endl;
cout << "|----------------------|----------------------|                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|----------------------|----------------------|                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|----------------------|----------------------|                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|----------------------|----------------------|                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|----------------------|                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|                      |                      |                                                                                                                                                      |" << endl;
cout << "|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;

}

void gameQuit(){
    cout << "Game quit." << endl;
}

int main(){
    startMenu();
    int startValue;
    cin >> startValue;
    switch(startValue){
        case 1:
            break;
        case 2:
            break;
        default:
            gameQuit();
            return 0;
    }
    return 0;
}