#ifndef IT_2003_2004_L1_ENEMY_H
#define IT_2003_2004_L1_ENEMY_H
#include <iostream>
using namespace std;
#include <string>
#include "Item.h"

class Enemy {
public:
    Enemy(string name, int hp, int dam);
    int getDamage();
    int getHP();
    string getName();
    void setHP(int hp);

private:
    string name_of_enemy;
    int HP;
    int damage;

    void setName(int hp);
};


#endif //IT_2003_2004_L1_ENEMY_H
