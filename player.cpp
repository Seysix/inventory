#include "player.h"

void Player::setName(const std::string &newName)
{
    name = newName;
}

void Player::setInv(Inventory *newInv)
{
    inv = newInv;
}

Inventory *Player::getInv() const
{
    return inv;
}

std::string Player::getName() const
{
    return name;
}

Player::Player() {
    this->name = "John";
    this->inv = new Inventory();
    inv->addItem(new Item("Wooden Sword", 10));
}

Player::~Player()
{
    delete inv;
}
