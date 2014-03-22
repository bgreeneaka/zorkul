#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "weapon.h"
#include "potion.h"
#include "armor.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {

private:
	Parser parser;
	Room *currentRoom;
    Character *player;
    vector <Item> vectorOfItems;
	void createRooms();
	void printWelcome();
    //bool processCommand(Command command);
	void printHelp();
    string goRoom(Command command);
    void createItems();


public:
	ZorkUL();
	void play();
	string go(string direction);
    string processCommand(Command command);
    vector<string> getRoomExits();
    string getRoomDescription();
    vector<Item> getItemsInRoom();
    string displayItem();
};

#endif
