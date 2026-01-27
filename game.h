#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game
{
private:
    Player* player;
public:
    Game();
    ~Game();
    void play();
    void setPlayerName();
    void setPlayer(Player *newPlayer);
    Player *getPlayer() const;
};

#endif // GAME_H
