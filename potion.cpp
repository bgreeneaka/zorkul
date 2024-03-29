#include "potion.h"

Potion::Potion(string inDescription, int inWeightGrams, float inValue, int inWeaponCheck, int inPotionStrenght, string inPotionEffect, string inTile)
    : Item(inDescription, inWeightGrams, inValue, inTile)
{
    potionDescription = inDescription;
    potionWeightGrams = inWeightGrams;
    potionValue = inValue;
    weaponCheck = inWeaponCheck;
    potionStrength = inPotionStrenght;
    potionEffect = inPotionEffect;
}

void Potion :: setPotionStrength(int inPotionStrength){
    potionStrength = inPotionStrength;
}

int Potion :: getPotionStrength(){
    return potionStrength;
}

int Potion :: getPotionTile(){
    return potionTile;
}

string Potion ::getPotionEffect(){
    return potionEffect;
}
