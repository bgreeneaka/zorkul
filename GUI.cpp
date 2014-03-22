#include <QtWidgets>
#include "GUI.h"
#include <sstream>
using namespace std;

GUI::GUI(QWidget *parent) :
    QWidget(parent)
{  
    // bottom display
    bottomDisplay = new QLineEdit("");

    bottomDisplay->setAlignment(Qt::AlignLeft);
    bottomDisplay->setMaxLength(35);
    QFont font = bottomDisplay->font();
    connect(bottomDisplay, SIGNAL(returnPressed()), this, SLOT(cmdLineEnterPressed()));
    font.setPointSize(font.pointSize() + 8);
    bottomDisplay->setFont(font);
    bottomDisplay->setFocus();

    //top right display
    toprightpane = new QTextEdit("");

    //get current room details
    zorkul.getRoomDescription();
    string tempStr = zorkul.getRoomDescription();
    QString roomDescription = tempStr.c_str();
    toprightpane->setText(roomDescription);

    // room details display
    toprightpane->setReadOnly(true);
    toprightpane->setAlignment(Qt::AlignLeft);
    QFont toprightfont = toprightpane->font();
    toprightfont.setPointSize(toprightfont.pointSize() + 8);
    toprightpane->setFont(toprightfont);

    //new butttons - map, info character etc
    info_button = new QPushButton("Info", this);
    map_button = new QPushButton("Map", this);
    inv_button = new QPushButton("Inventory", this);
    look_button = new QPushButton("Look", this);


    //new butttons - map, info character etc
    info_button->setGeometry(QRect(QPoint(100, 100),
                                   QSize(200, 50)));
    map_button->setGeometry(QRect(QPoint(100, 100),
                                  QSize(200, 50)));
    inv_button->setGeometry(QRect(QPoint(100, 100),
                                  QSize(200, 50)));
    look_button->setGeometry(QRect(QPoint(100, 100),
                                   QSize(200, 50)));

    // Connect button signal to appropriate slot
    connect(info_button, SIGNAL(released()), this, SLOT(infoButtonClicked()));
    connect(map_button, SIGNAL(released()), this, SLOT(mapButtonClicked()));
    connect(inv_button, SIGNAL(released()), this, SLOT(invButtonClicked()));
    connect(look_button, SIGNAL(released()), this, SLOT(lookButtonClicked()));

    mainLayout = new QGridLayout();
    controlsLayout = new QGridLayout();
    roomLayout = new QGridLayout();

    roomLayout->setHorizontalSpacing(0);
    roomLayout->setVerticalSpacing(0);
    roomLayout->setContentsMargins(0, 0, 0, 0);

    drawFloor();
    drawWall();
    drawDoor();
    drawItem();
    setupDoors();
    itemClick();

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    controlsLayout->addWidget(toprightpane, 1, 0,4,4);
    controlsLayout->addWidget(info_button, 0,0);
    controlsLayout->addWidget(map_button, 0,1);
    controlsLayout->addWidget(inv_button, 0,2);
    controlsLayout->addWidget(look_button, 0,3);
    mainLayout->addItem(controlsLayout,0,3,2,3);
    mainLayout->addItem(roomLayout,1 ,1);
    mainLayout->addWidget(bottomDisplay, 3, 0, 1, 6);

    setLayout(mainLayout);
    setWindowTitle(tr("ZorkUL"));
}

void GUI::northButtonClicked() {
    qbutclicked("go", "north");
}

void GUI::southButtonClicked(){
    qbutclicked("go", "south");
}

void GUI::eastButtonClicked(){
    qbutclicked("go", "east");
}

void GUI::westButtonClicked(){
    qbutclicked("go", "west");
}

void GUI::infoButtonClicked(){
    qbutclicked("info", "");

}
void GUI::mapButtonClicked(){    
    qbutclicked("map", "");

}
void GUI::invButtonClicked(){
    qbutclicked("inventory", "");

}
void GUI::lookButtonClicked(){
    qbutclicked("look", "");
}

void GUI :: itemButtonClicked(){
    vector<Item> items = zorkul.getItemsInRoom();
    qbutclicked("take",items[0].getShortDescription());
}

void GUI::qbutclicked(string firstWord, string secondWord){
    Command *cmd = new Command(firstWord, secondWord);
    string tempStr = zorkul.processCommand(*cmd);
    QString zorkULQstrR = tempStr.c_str();
    toprightpane->setText(zorkULQstrR);
    updateGUI();
    delete cmd;
}

void GUI::getCurrentRoomDescription(){
    zorkul.getRoomDescription();
    string tempStr = zorkul.getRoomDescription();
    QString roomDescription = tempStr.c_str();
    toprightpane->setText(roomDescription);
}

void GUI::updateGUI(){
    drawItem();
    drawFloor();
    drawWall();
    drawDoor();

    bottomDisplay->setFocus();
}

void GUI::cmdLineEnterPressed(){
    QString QuserInput = bottomDisplay->text();
    string userinput = QuserInput.toLocal8Bit().constData();
    string first, second;
    vector<string> cmds;

    std::istringstream ss(userinput);
    string token;
    bottomDisplay->setText("");
    while(std::getline(ss, token, ' ')) {
        cmds.push_back(token);
    }
    if(cmds.size()>1){
        first = cmds.at(0);
        second = cmds.at(1);
    }
    else if(cmds.size()>0){
        first = cmds.at(0);
        second = "";
    }
    else{
        first = "";
        second = "";
    }

    Command *cmd = new Command(first, second);
    string tempStr = zorkul.processCommand(*cmd);
    QString zorkULQstrR = tempStr.c_str();
    toprightpane->setText(zorkULQstrR);
    updateGUI();
    delete cmd;
}

void GUI::drawFloor() {
    for (unsigned int i = 0; i < 10; i++) {
        for (unsigned int j = 0; j < 10; j++) {
            QPushButton *floorLabel = new QPushButton();
            floorLabel->setIcon(QIcon("://resources/images/rooms/pedestal_full.png"));
            floorLabel->setFlat(true);
            floorLabel->setIconSize(QSize(32, 32));
            floorLabel->setStyleSheet("border: none; padding: 0 0 0 0;");
            roomLayout->addWidget(floorLabel, i, j);
        }
    }
}

void GUI::setupDoors() {
    QPushButton *eastButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(4, 9)->widget());
    connect(eastButton, SIGNAL(released()), this, SLOT(eastButtonClicked()));

    QPushButton *westButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(4, 0)->widget());
    connect(westButton, SIGNAL(released()), this, SLOT(westButtonClicked()));

    QPushButton *northButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(0, 5)->widget());
    connect(northButton, SIGNAL(released()), this, SLOT(northButtonClicked()));

    QPushButton *southButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(9, 5)->widget());
    connect(southButton, SIGNAL(released()), this, SLOT(southButtonClicked()));
}

void GUI::drawWall() {
    int j = 0;
    for (unsigned int i = 0; i < 10; i++) {
        QPushButton *wallLabel = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(i, j)->widget());
        wallLabel->setFlat(true);
        wallLabel->setIconSize(QSize(32, 32));
        wallLabel->setIcon(QIcon("://resources/images/rooms/brick_brown0.png"));
    }
    j = 9;
    for (unsigned int i = 0; i < 10; i++) {
        QPushButton *wallLabel = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(i, j)->widget());
        wallLabel->setFlat(true);
        wallLabel->setIconSize(QSize(32, 32));
        wallLabel->setIcon(QIcon("://resources/images/rooms/brick_brown0.png"));
    }
    j = 9;
    for (unsigned int i = 0; i < 10; i++) {
        QPushButton *wallLabel = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(j, i)->widget());
        wallLabel->setFlat(true);
        wallLabel->setIconSize(QSize(32, 32));
        wallLabel->setIcon(QIcon("://resources/images/rooms/brick_brown0.png"));
    }
    j = 0;
    for (unsigned int i = 0; i < 10; i++) {
        QPushButton *wallLabel = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(j, i)->widget());
        wallLabel->setFlat(true);
        wallLabel->setIconSize(QSize(32, 32));
        wallLabel->setIcon(QIcon("://resources/images/rooms/brick_brown0.png"));
    }
}

void GUI::drawDoor() {
    vector<string> exits = zorkul.getRoomExits();
    for (unsigned int i = 0; i < exits.size(); i++) {
        if (exits[i].compare("east") == 0) {
            QPushButton *eastButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(4, 9)->widget());
            eastButton->setFlat(true);
            eastButton->setIconSize(QSize(32, 32));
            eastButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
        }
        if (exits[i].compare("west") == 0) {
            QPushButton *westButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(4, 0)->widget());
            westButton->setFlat(true);
            westButton->setIconSize(QSize(32, 32));
            westButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
        }
        if (exits[i].compare("north") == 0) {
            QPushButton *northButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(0, 5)->widget());
            northButton->setFlat(true);
            northButton->setIconSize(QSize(32, 32));
            northButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
        }
        if (exits[i].compare("south") == 0) {
            QPushButton *southButton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(9, 5)->widget());
            southButton->setFlat(true);
            southButton->setIconSize(QSize(32, 32));
            southButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
        }
    }
}

void GUI:: itemClick(){
    QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
    connect(Item_botton, SIGNAL(released()), this, SLOT(itemButtonClicked()));
}

void GUI::drawItem(){
    vector<Item> items = zorkul.getItemsInRoom();

        if(zorkul.displayItem().compare("no items in room")==0){
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/rooms/pedestal_full.png"));
        }

    for (unsigned int i = 0; i < items.size(); i++) {
        if (items[i].getShortDescription().compare("Sword") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/weapons/bastard_sword.png"));
            //items.erase(items.begin());
        }
        else if (items[i].getShortDescription().compare("Axe") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/weapons/battle_axe2.png"));
        }
        else if (items[i].getShortDescription().compare("Hammer") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/weapons/morningstar1.png"));
        }
        else if (items[i].getShortDescription().compare("Gold Dragona Armour") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/armour/gold_dragon_armour.png"));
        }
        else if (items[i].getShortDescription().compare("Chain Mail Armour") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/armour/chain_mail2.png"));
        }
        else if (items[i].getShortDescription().compare("Blue Dragon Scale Armor") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/armour/blue_dragon_scale_mail.png"));
        }
        else if (items[i].getShortDescription().compare("Death-Cap Draught") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/potions/orange.png"));
        }
        else if (items[i].getShortDescription().compare("Elixir of Life") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/potions/emerald.png"));
        }
        else if (items[i].getShortDescription().compare("Invisibility Potion") == 0) {
            QPushButton *Item_botton = dynamic_cast<QPushButton*>(roomLayout->itemAtPosition(5, 5)->widget());
            Item_botton->setFlat(true);
            Item_botton->setIconSize(QSize(32, 32));
            Item_botton->setIcon(QIcon("://resources/images/items/potions/emerald.png"));
        }
    }
}
