#include "Item.h"


Item::Item(string name, int damage) {
    this -> name = name;
    this -> damage = damage;
}

const string &Item::getName() const {
    return name;
}

void Item::setName(const string &name) {
    Item::name = name;
}

int Item::getDamage() const {
    return damage;
}

void Item::setDamage(int damage) {
    Item::damage = damage;
}