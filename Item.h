#ifndef IT_2003_2004_L1_ITEM_H
#define IT_2003_2004_L1_ITEM_H
#include <iostream>
using namespace std;
#include <string>


class Item {
public:
    Item(string name, int damage);

    const string &getName() const;

    void setName(const string &name);

    int getDamage() const;

    void setDamage(int damage);

private:
    string name;
    int damage;


};


#endif //IT_2003_2004_L1_ITEM_H
