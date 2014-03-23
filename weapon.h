#ifndef WEAPON_H
#define WEAPON_H

#include <map>
#include <string>
#include <iostream>

#include <vector>
#include "Item.h"
using namespace std;
using std::vector;


class Weapon : public Item
{
private:
    string weaponDescription;
    int weaponWeightGrams;
    float weaponValue;
    bool weaponCheck;
    int damage;
    int weaponTile;
    vector <Item> weaponsList;

public:
    Weapon(string description, int inWeight, float inValue,int damageValue, string inTile);
    void setDamage(int damageValue);
    int getDamage();
    int getWeaponTile();
    vector<Item> vectorOfWeapons();
    string displayWeapons();
};
#endif // WEAPON_H
