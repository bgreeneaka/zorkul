#include "Character.h"
#include "Item.h"

Character::Character(string description) {
	this->description = description;
}

void Character::addItem(Item item) {
    cout << "im in your characters, adding your items" << endl;
    itemsInCharacter.push_back(item);
    cout << "added item to inventory" << itemsInCharacter.size() << endl;
}

//void Character::addItem(Item *item) {
//    itemsInCharacter.push_back(*item);
//    delete item;
//}

//string Character::longDescription() {
//  string ret = this->description;
//  ret += "\n Item list:\n";
//  for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
//    ret += "\t"+ (*i).getLongDescription() + "\n";
//  return ret;
//}

