#include "Character.h"
#include "Item.h"

Character::Character(string description) {
	this->description = description;
}

void Character::addItem(Item item) {
    cout << "adding item to char: " << item.getShortDescription() << endl;
    itemsInCharacter.push_back(item);
    cout << "char inventory size: " << itemsInCharacter.size() << endl;
}

int Character::isItemInCharacter(string description) {
    for(unsigned int i = 0; i < itemsInCharacter.size(); i++) {
        if (description.compare(itemsInCharacter[i].getShortDescription()) == 0) {
            return i;
        }
    }
    return -1;
    //iuhfdasfadfdsfdafa
}

Item* Character::getItem(int location) {
    return &itemsInCharacter[location];
}

void Character::removeItem(int location) {
    itemsInCharacter.erase(itemsInCharacter.begin()+location);
}

//void Character::addItem(Item *item) {
//    itemsInCharacter.push_back(*item);
//    delete item;
//}

string Character::longDescription() {
    string items = "inventory: \n";

    for (unsigned int i = 0; i < itemsInCharacter.size(); i++) {
        items += " "  + itemsInCharacter[i].getShortDescription() + "\n";
    }

    return items;
}

vector<Item> Character::getItems() {
    return itemsInCharacter;
}

