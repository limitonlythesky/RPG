#include <iostream>
using namespace std;
#include <string>
#include "Character.h"
#include "Enemy.h"
#include <random>

#ifndef IT_2003_2004_L1_GAME_H
#define IT_2003_2004_L1_GAME_H


class Game {
public:
    Game();
    void mainMenu();
    int getOption() const;
    bool isPlaying() const;
    void playMenu();
	Item getItem(bool fight);
	Enemy getEnemy();
private:
    int option; //choice of player
    bool playing; //if player is playing game?
    Character character;
    bool chance;
    vector <int> v = {1, 2, 3, 4, 5, 6};
    vector <int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector <int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};


    void showStats();

    void startGame();

    void exploreMenu();

    void getItem();

    void healHP();
};


#endif //IT_2003_2004_L1_GAME_H
