#include "weapon.h"
#include "Item.h"

#include <string>
#include <iostream>
using std::vector;

Weapon::Weapon(string inDescription, int inWeightGrams, float inValue, int damageValue, string inTile)
    : Item(inDescription, inWeightGrams, inValue, inTile)
{
    weaponDescription = inDescription;
    weaponValue = inValue;
   // setWeaponCheck(weaponCheck);
    setDamage(damageValue);
    setWeight(inWeightGrams);
}


void Weapon :: setDamage(int damageValue){

    damage = damageValue;
}

int Weapon :: getDamage(){
    return damage;
}

int Weapon :: getWeaponTile(){
    return weaponTile;
}
