#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include <iostream>
#include <string>
using namespace std;

class ZorkUL {

private:
	Parser parser;
	Room *currentRoom;
    Character *player;
	void createRooms();
	void printWelcome();
	bool processCommand(Command command);
	void printHelp();
	void goRoom(Command command);
    void createItems();
    void displayItems();

public:
	ZorkUL();
	void play();
	string go(string direction);
    vector<string> getRoomExits();
    string getRoomDescription();
};

#endif
