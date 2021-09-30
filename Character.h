#ifndef IT_2003_2004_L1_CHARACTER_H
#define IT_2003_2004_L1_CHARACTER_H
#include <iostream>
using namespace std;
#include <string>
#include "Item.h"
#include "Enemy.h"

class Character {
public:
    Character(Item item, Enemy enemy);
    void initialize(string name_of_player);
    void levelUp();
    string showStats();

    Item getItem() const;
    string getName();
    void setItem(const Item &item);
    bool gainExp(Enemy enemy);
    void setHP(int hp);
    int getHP();
bool checkItem();

private:
    string name_of_player;
    int HP;
    int maxHP;
    int atk;
    int exp;
    int level;
    Item item;
    Enemy enemy;


    void writeitem(const Item &item);
};


#endif //IT_2003_2004_L1_CHARACTER_H
