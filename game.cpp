#include "game.h"
#include "charCheck.h"


void Game::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

Player *Game::getPlayer() const
{
    return player;
}

Game::Game() {
    this->player = new Player();
}

Game::~Game()
{
    delete this->player;
}

void Game::play()
{
    int userInput = 0;
    while (userInput != 27){
        player->getInv()->display();
        userInput = int(getSingleChar());

        switch(userInput){
        case 97:
            player->getInv()->setCurrentCol(player->getInv()->getCurrentCol() - 1);
            break;
        case 100:
            player->getInv()->setCurrentCol(player->getInv()->getCurrentCol() + 1);
            break;
        case 119:
            player->getInv()->setCurrentRow(player->getInv()->getCurrentRow() - 1);
            break;
        case 115:            
            player->getInv()->setCurrentRow(player->getInv()->getCurrentRow() + 1);
            break;
        case 105:
            // show info
            if (player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol()) != nullptr){
                system(CLEAR);
                // getItemOnSelectedRowsCons(rows, cols)->showInfo()
                player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol())->showInfo();
                std::cout << "Press ESC to go back...";

                while (userInput != 27){
                    userInput = int(getSingleChar());
                }
                userInput= 0;
            }
            break;
        default:
            return;
        }

        system(CLEAR);
    }


    // enter : 10
    // backspace : 127
    // w : 119
    // a : 97
    // s : 115
    // d : 100
    // i : 105
}
