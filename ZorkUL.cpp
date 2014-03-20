#include <iostream>
#include "GUI.h"
#include <QApplication>
#include <QDir>
using namespace std;
#include "ZorkUL.h"

int main(int argc, char *argv[]) {
    //ZorkUL temp;
    //temp.play();
    //return 0;
    QApplication a(argc, argv);
    QDir::setCurrent(QCoreApplication::applicationDirPath());
    GUI w;
    w.show();

    return a.exec();
}

ZorkUL::ZorkUL() {
    createRooms();
}

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i;
    player = new Character("me");

    a = new Room("a");
    a->addItem(new Item("x", 1, 11));
    a->addItem(new Item("y", 2, 22));
    b = new Room("b");
    b->addItem(new Item("xx", 3, 33));
    b->addItem(new Item("yy", 4, 44));
    c = new Room("c");
    d = new Room("d");
    e = new Room("e");
    f = new Room("f");
    g = new Room("g");
    h = new Room("h");
    i = new Room("i");

    //             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);

    currentRoom = a;
}

/**
 *  Main play routine.  Loops until end of play.
 */
/*void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}
*/
void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
string ZorkUL::processCommand(Command command) {
    /* if (command.isUnknown()) {
        // cout << "invalid input"<< endl;
        return "indvalid input";
    }
*/
    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0){
        return "reliable info here";
        printHelp();
    }
    else if (commandWord.compare("map") == 0)
    {
        string output = "Map of the world\n";
        output += "  [h] --- [f] --- [g]\n";
        output += "             |         \n" ;
        output += "             |         \n";
        output += "  [c] --- [a] --- [b]\n" ;
        output += "             |         \n" ;
        output += "             |         \n" ;
        output += "  [i] --- [d] --- [e]\n" ;
        return output;
    }

    else if (commandWord.compare("go") == 0)
        return goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
                cout << "you're trying to take " + command.getSecondWord() << endl;
                int location = currentRoom->isItemInRoom(command.getSecondWord());
                if (location  < 0 ) {
                    cout << "item is not in room" << endl;
                } else {
                    cout << "item is in room" << endl;
                    cout << "item index number " << location << endl;
                    player->addItem(currentRoom->removeItemFromRoom(location));
                    cout << endl;

                    cout << currentRoom->longDescription() << endl;
                }
            }
    }

    else if (commandWord.compare("put") == 0)
    {

        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }else if (command.hasSecondWord()) {
            //            cout << "you're adding " + command.getSecondWord() << endl;
            //            itemsInRoom.push_Back;
            int location = player->isItemInCharacter(command.getSecondWord());
            if (location < 0) {
                cout << "item is not in character" << endl;
            } else {
                currentRoom->addItem(player->getItem(location));
                player->removeItem(location);
                cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("inventory") == 0) {
        player->longDescription();
    }

    else if (commandWord.compare("look") == 0) {
       // cout << currentRoom->longDescription() << endl;

        return currentRoom->longDescription();
    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return "true"; /**signal to quit*/
    }
    return "invalid input";
}
/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

string ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        //cout << "incomplete input"<< endl;
        return "incomplete input";
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom != NULL){
        currentRoom = nextRoom;
        return currentRoom->longDescription();


    }
    else {
        cout << "underdefined input"<< endl;
        return "invalid input";
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

vector<string> ZorkUL::getRoomExits(){
    return currentRoom->getRoomExits();
}

string ZorkUL::getRoomDescription(){
    return currentRoom->longDescription();
}
