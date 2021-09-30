#include "Enemy.h"
#include <string>

Enemy:: Enemy(string name, int hp, int dam){
    name_of_enemy = name;
    HP = hp;
    damage = dam;
}

int Enemy:: getDamage(){
    return damage;
}

int Enemy:: getHP(){
    return HP;
}

string Enemy:: getName(){
    return name_of_enemy;
}

void Enemy:: setHP(int hp){
    this -> HP = hp;
}
