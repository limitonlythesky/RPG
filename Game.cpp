#include "Game.h"
#include "Enemy.h"
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>


Game::Game() : character(Item("none", 0), Enemy("none", 0, 0)) {
    option = 0;
    playing = true;
    chance = false;
    Character character = Character(Item("none", 0), Enemy("none", 0, 0));
}

void Game::mainMenu() {
    cout << "Main menu" << endl << endl << "1) Start" << endl << "0) Quit" << endl << endl;

    cout<<"Choose option: ";
    cin >> option;
    switch (option) {
        case 0:
            break;
        case 1:
            startGame();
            playMenu();
            break;
    }
}


void Game::playMenu(){

    while (option != 0) {

        cout << "Play menu" << endl << endl;
        cout << "1. Explore" << endl;
        cout << "2. Show stats" << endl;
        cout << "0. Quit" << endl << endl;

        cout << "Choose option: ";
        cin >> option;
        switch (option) {
            case 0:
                mainMenu();
                break;
            case 1:
                exploreMenu();
                break;
            case 2: {
                showStats();
                break;
            }
            default:
                break;

        }
    }
}



void Game::exploreMenu(){


    while (option !=0) {
        cout << "==========================================================" << endl << endl;

        cout << "1. Fight" << endl;
        cout << "2. Rest (heal HP 65%)" << endl;
        cout << "3. Retreat(25%)" << endl;
        cout << "4. Show stats" << endl << endl;
        cout << "Choose option: ";
        cin >> option;
        switch (option) {
            case 3:
                playMenu();
                break;
            case 1: {
                Enemy enemy = getEnemy();
                bool fight = character.gainExp(enemy);
                if (!fight) {
                    cout << character.getName() << " lose game" << endl;
                    option = 0;
                } else {
                    cout << character.getName() << " was fighting with " << enemy.getName() << " and you are win" <<  endl;
                    character.setItem(getItem(fight));
                    Item iteem=character.getItem();
                    cout << " You got ";
                    cout << iteem.getName()<<endl;
                }
                break;
            }


            case 2:
                healHP();
                break;//TODO setHP to maxHP
            default:
                break;
            case 4:{
                showStats();
                break;
            }
        }
    }
}


void Game::startGame(){
    cout<<"What's your name? ";
    string name_of_player;
    cin>>name_of_player;
    character.initialize(name_of_player);
}

void Game::healHP(){
    random_device rd;
    mt19937 g(rd());
    shuffle(v2.begin(), v2.end(), g);
    int choice1 = v2[0];
    if(choice1 > 0 && choice1 < 8){
        character.setHP(character.getHP() + 4);
        cout << character.getName() << " your hp is " << character.getHP() << endl << endl;
    }else{
        cout << character.getName() << " can't healing " << endl << endl;
    }
}

Item Game::getItem(bool fight){
    random_device rd;
    mt19937 g(rd());
    shuffle(v.begin(), v.end(), g);
    int choice1 = v[0];
    Item item = Item("none", 0);
    switch(choice1){
        case 1:
            item = Item("Mace", 4);
            character.setItem(item);
            break;
        case 2:
            item = Item("Wrench", 3);
            character.setItem(item);
            break;
        case 3:
            item = Item("Dagger", 3);
            character.setItem(item);
            break;
        case 4:
            item = Item("Pan", 3);
            character.setItem(item);
            break;
        case 5:
            item = Item("Stone", 1);
            character.setItem(item);
            break;
        case 6:
            item = Item("Mop", 2);
            character.setItem(item);
            break;
        default:
            break;
    }
    return item;
}


Enemy Game::getEnemy(){
    Enemy enemy = Enemy("none", 0,0);
    random_device rd;
    mt19937 g(rd());
    shuffle(v1.begin(), v1.end(), g);
    int choice_Enemy = v1[0];
    cout << choice_Enemy << endl;
    switch(choice_Enemy){
        case 1:
            enemy = Enemy("Goblin", 6, 2);
            break;
        case 2:
            enemy = Enemy("Orc", 9, 2);
            break;
        case 3:
            enemy = Enemy("Gnom", 5, 1);
            break;
        case 4:
            enemy = Enemy("Dragon", 11, 3);
            break;
        case 5:
            enemy = Enemy("Slug", 2, 7);
            break;
        case 6:
            enemy = Enemy("Robber", 5, 4);
            break;
        default:
            enemy = Enemy("Dead man", 4, 2);
            break;
    }
    return enemy;
}


void Game::showStats(){
    cout<<character.showStats();

}


int Game::getOption() const{


    return option;
}

bool Game::isPlaying() const {


    return playing;
}
