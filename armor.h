#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

class Armor : public Item
{
private:
    string armorDescription;
    int armorWeightGrams;
    float armorValue;
    bool weaponCheck;
    int armorStrength;
    int armorTile;

public:
    Armor(string inDescription, int inWeightGrams, float inValue, int inWeaponCheck, int inArmorStrenght);
    void setArmorStrength(int inArmorStrength);
    int getArmorStrength();
    int getArmorTile();
};

#endif // ARMOR_H
