#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <random>

enum Rarity {
    common,
    magic,
    rare,
    unseen
};

class Item
{
protected:
    std::string name;
    Rarity rarity;
    int durability;
    int level;
    int price;
public:
    Item();
    Item(const std::string &name, int price);

    //methods
    void use();
    void showInfo();

    std::string getRarityString();

    //setters and getters
    std::string getName() const;
    void setName(const std::string &newName);
    Rarity getRarity() const;
    void setRarity(Rarity newRarity);
    int getDurability() const;
    void setDurability(int newDurability);
    int getLevel() const;
    void setLevel(int newLevel);
    int getPrice() const;
    void setPrice(int newPrice);
};

#endif // ITEM_H
