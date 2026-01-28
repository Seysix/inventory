#include "item.h"

std::string Item::getName() const
{
    return name;
}

void Item::setName(const std::string &newName)
{
    name = newName;
}

Rarity Item::getRarity() const
{
    return rarity;
}

void Item::setRarity(Rarity newRarity)
{
    rarity = newRarity;
}

int Item::getDurability() const
{
    return durability;
}

void Item::setDurability(int newDurability)
{
    durability = newDurability;
}

int Item::getLevel() const
{
    return level;
}

void Item::setLevel(int newLevel)
{
    level = newLevel;
}

int Item::getPrice() const
{
    return price;
}

void Item::setPrice(int newPrice)
{
    price = newPrice;
}

void Item::use()
{
    this->setDurability(this->getDurability() - 10);
}

void Item::showInfo()
{
    // dodac showInfo dla i
    std::cout << "Item - " << this->name << "\n";
    std::cout << "Price - " << this->price << "\n";
    std::cout << "Durability - " << this->durability << "/100 \n";
    std::cout << "Level - " << this->level << "\n";
    std::cout << "Rarity - " << Item::getRarityString() << "\n";
}

std::string Item::getRarityString()
{
    switch (this->rarity) {
    case common:
        return "common";
        break;
    case magic:
        return "magic";
        break;
    case rare:
        return "rare";
        break;
    case unseen:
        return "unseen";
        break;
    default:
        return "unknown";
        break;
    }
}

Item::Item() {
    name = "Stick";
    price = 1;
    durability = 100;
    level = 1;
    rarity = magic;

}

Item::Item(const std::string &name, int price)
    : name(name),
    durability(100),
    level(1),
    price(price)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 100); // zakres [0, 100]

    int randNum = dist(gen);

    if(randNum < 60) {
        rarity = common;
    }
    else if(randNum >= 60 && randNum < 90) {
        rarity = magic;
    }
    else {
        rarity = rare;
    }
}
