#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
using namespace std;
#include <vector>
using std::vector;
#include "Item.h"


class Character {

private:
    string description;
    vector <Item> itemsInCharacter;

public:
    void addItem(Item Item);
    Character(string description);
    string shortDescription();
    string longDescription();

};

#endif
