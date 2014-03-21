#include "armor.h"

Armor::Armor(string inDescription, int inWeightGrams, float inValue, int inWeaponCheck, int inArmorStrenght)
    : Item(inDescription, inWeightGrams, inValue)
{
    armorDescription = inDescription;
    armorWeightGrams = inWeightGrams;
    weaponCheck = inWeaponCheck;
    armorStrength = inArmorStrenght;
}

void Armor :: setArmorStrength(int inArmorStrength){
    armorStrength = inArmorStrength;
}

int Armor :: getArmorStrength(){
    return armorStrength;
}

int Armor :: getArmorTile(){
    return 0;
}

