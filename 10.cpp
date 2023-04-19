#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

struct Player {
    char name[15];
    int level;
    int points;
};

struct ComputerGame {
    char nameOfGame[20];
    Player players[30];
    int numOfPlayers;
};

void bestPlayer(ComputerGame *list, int n) {
    int maxi = 0;
    int maxj = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (max < list[i].numOfPlayers) {
            max = list[i].numOfPlayers;
            maxi = i;
        }
    }
    //cout<<list[maxi].nameOfGame<<endl;
    int maxPoeni = list[maxi].players[0].level;
    for (int i = 0; i < list[maxi].numOfPlayers; ++i) {
        if (max < list[maxi].players[i].points && maxPoeni >= list[maxi].players[i].level) {
            max = list[maxi].players[i].points;
            maxj = i;
        }
    }
    cout << "Najdobar igrac e igracot so korisnicko ime " << list[maxi].players[maxj].name << " koj ja igra igrata "
         << list[maxi].nameOfGame << endl;
}

int main() {
    int n;
    cin >> n;
    ComputerGame game[100];
    for (int i = 0; i < n; ++i) {
        cin >> game[i].nameOfGame;
        cin >> game[i].numOfPlayers;
        for (int j = 0; j < game[i].numOfPlayers; ++j) {
            cin >> game[i].players[j].name >> game[i].players[j].level >> game[i].players[j].points;
        }
    }

    bestPlayer(game, n);
}
