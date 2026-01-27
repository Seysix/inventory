#include "game.h"


int main() {
    // std::cout << "Detected OS: " << OS_NAME << std::endl;

    Game game;
    game.setPlayerName();
    game.play();

    return 0;
}
