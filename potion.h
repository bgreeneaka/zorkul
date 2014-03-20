#ifndef POTION_H
#define POTION_H

#include <map>
#include <string>
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;


class Potion : public Item
{
private:
    string potionDescription;
    int potionWeightGrams;
    float potionValue;
    bool weaponCheck;
    int potionStrength;
    string potionEffect;
    int potionTile;

public:
    Potion(string inDescription, int inWeightGrams, float inValue, int inWeaponCheck, int inPotionStrenght, string inPotionEffect);
    void setPotionStrength(int inPotionStrength);
    int getPotionStrength();
    int getPotionTile();
    string getPotionEffect();
};

#endif // POTION_H
