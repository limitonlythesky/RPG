#include "Character.h"
#include "Enemy.h"

Character::Character(Item item, Enemy enemy) : item(item), enemy(enemy) {
    name_of_player = "Player";
    HP = 0;
    maxHP = 0;
    atk = 0;
    exp = 0;
    level = 0;
    item = Item("hand", 2);
    enemy = Enemy("none", 0, 0);
}

void Character::initialize(string name_of_player){
    this->name_of_player = name_of_player;
    HP = 10;
    maxHP = 100;
    atk = 2;
    exp = 0;
    level = 1;
    item = Item("hand", 2);
    enemy = Enemy("none", 0, 0);
};

bool Character::gainExp(Enemy enemy){
    if(checkItem()){
        exp = exp + 12;
        Item item = getItem();
    }else{
        exp = exp + 10;
    }
    int cnt = 1;
    while(HP > 0 && enemy.getHP() > 0){
        HP -= enemy.getDamage();
        enemy.setHP(enemy.getHP() - item.getDamage());
        cout << cnt << " round: " << endl;
        cout << name_of_player << " have " << HP << " hp" << endl;
        cout << enemy.getName() << " have " << enemy.getHP() << " hp " << endl << endl;
        cnt++;
    }
    if(HP <= 0){
        return false;
    }
    if(enemy.getHP() <= 0){
        levelUp();
        return true;
    }
}

void Character:: setHP(int hp){
    this -> HP = hp;
}

int Character:: getHP(){
    return HP;
}

void Character::levelUp(){
    //exp->level->add stats;
    while (exp >= level*10){
        level++;
        exp = 0;
        maxHP = maxHP + 5;
        atk = atk + 1;
    }
}

bool Character::checkItem(){
    if(getItem().getName() == "hand"){
        return false;
    }else{
        return true;
    }
}

string Character::showStats(){

    string string1= "Name: "+name_of_player+"\n"+"HP: "+ to_string(HP)+"/"+ to_string(maxHP)+
                    "\n"+ "Atk: "+ to_string(atk)+"\n"+"exp: "+to_string(exp)+"\n"+"level: "+to_string(level)+"\n"
                    +"Item: "+ item.getName()+"\n";

    return string1;

}
//In your Inventory you can store only best 3 items (they must be automatically equipped).
//more atk = better item
Item Character::getItem() const {
    return item;
}

void Character::setItem(const Item &item) {
    Character::item = item;
}

string Character::getName(){
    return name_of_player;
}






