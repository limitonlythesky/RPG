#include "Game.h"

int main() {

    Game game = Game();

    while (game.isPlaying()) {
        game.mainMenu();
    }
    return 0;
}

