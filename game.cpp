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
    system(CLEAR);
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
                //system(CLEAR);
                // getItemOnSelectedRowsCons(rows, cols)->showInfo()
                player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol())->showInfo();
                std::cout << "Press ESC to go back...";

                while (userInput != 27){
                    userInput = int(getSingleChar());
                }
                userInput= 0;
            }
            break;
        case 117:

            if (player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol()) != nullptr){
                player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol())->use();


                if (player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol())->getDurability() <= 0){
                    player->getInv()->removeItem(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol());
                    player->getInv()->addItem(new Item("Penis Sword", 10));
                } else {
                    std::cout << "You used " << player->getInv()->getItemOnSelectedRC(player->getInv()->getCurrentRow(), player->getInv()->getCurrentCol())->getName() << "...";
                }

                userInput = int(getSingleChar());
                userInput = 0;
            }
            break;
        default:
            break;
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

void Game::setPlayerName()
{
    std::string name{};
    std::cout << "Print your name: ";
    std::cin >> name;
    player->setName(name);
}
