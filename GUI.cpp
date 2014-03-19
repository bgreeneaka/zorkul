#include <QtWidgets>
#include "GUI.h"
#include <sstream>
using namespace std;

GUI::GUI(QWidget *parent) :
    QWidget(parent)
{

    //! temp
    //!

    tilesInit();
    // wesn_doors = new QPixmap("://resources/images/rooms/wesn_door.png");

    label = new QLabel();

    label->setPixmap(*wesn_doors);

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

    //label->setPixmap("empty_room.png");

    n_button = new QPushButton("North", this);
    s_button = new QPushButton("South", this);
    e_button = new QPushButton("East", this);
    w_button = new QPushButton("West", this);

    n_button->setGeometry(QRect(QPoint(100, 100),
                                QSize(200, 50)));
    s_button->setGeometry(QRect(QPoint(100, 100),
                                QSize(200, 50)));
    e_button->setGeometry(QRect(QPoint(100, 100),
                                QSize(200, 50)));
    w_button->setGeometry(QRect(QPoint(100, 100),
                                QSize(200, 50)));

    // Connect button signal to appropriate slot
    connect(n_button, SIGNAL(released()), this, SLOT(northButtonClicked()));
    connect(s_button, SIGNAL(released()), this, SLOT(southButtonClicked()));
    connect(e_button, SIGNAL(released()), this, SLOT(eastButtonClicked()));
    connect(w_button, SIGNAL(released()), this, SLOT(westButtonClicked()));

    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *controlsLayout = new QGridLayout;





    QGridLayout *roomLayout = new QGridLayout;

    QPushButton *doorButton = new QPushButton;
    doorButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
    roomLayout->addWidget(doorButton, 0, 4);

    QPushButton *doorButton2 = new QPushButton;
    doorButton2->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
    roomLayout->addWidget(doorButton2, 4, 0);

    QPushButton *doorButton3 = new QPushButton;
    doorButton3->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
    roomLayout->addWidget(doorButton3, 4, 8);

    QPushButton *doorButton4 = new QPushButton;
    doorButton4->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
    roomLayout->addWidget(doorButton4, 8, 4);







    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    //mainLayout->addWidget(northButton, 0, 0);
    // controlsLayout->addWidget(n_button,0,1);
    // controlsLayout->addWidget(s_button,1,1);
    //controlsLayout->addWidget(w_button,1,0);
    //controlsLayout->addWidget(e_button,1,2);
    //temp
    controlsLayout->addWidget(toprightpane, 0, 0,2,2);
    mainLayout->addItem(controlsLayout,0,3,2,3);
    // diplay 2
    mainLayout->addWidget(n_button,0,1);
    mainLayout->addWidget(s_button,2,1);
    mainLayout->addWidget(w_button,1,0);
    mainLayout->addWidget(e_button,1,2);
    mainLayout->addItem(roomLayout,1 ,1);
    mainLayout->addWidget(bottomDisplay, 3, 0, 1, 6);

    // mainLayout->addWidget(botrightpane, 2, 3, 3, 2);
    //temp
    setLayout(mainLayout);
    setWindowTitle(tr("Four room SIM"));
}


void GUI::northButtonClicked()
{
    string direction= "north";
    QString text =  "north";
    goButtonCommand(direction,text);

}
void GUI::southButtonClicked(){
    string direction= "south";
    QString text =  "south";
    goButtonCommand(direction,text);
}

void GUI::eastButtonClicked(){
    string direction= "east";
    QString text =  "east";
    goButtonCommand(direction,text);
}

void GUI::westButtonClicked(){
    string direction= "west";
    QString text =  "west";
    goButtonCommand(direction,text);

}

void GUI::goButtonCommand(string direction, QString text){

    zorkul.go(direction);
    bottomDisplay->setText(text);
    getCurrentRoomDescription();
    updateGUI();
}

void GUI::qbutclicked(){

    //m_button->setText("Example");
}
void GUI::getCurrentRoomDescription(){
    zorkul.getRoomDescription();
    string tempStr = zorkul.getRoomDescription();
    QString roomDescription = tempStr.c_str();
    toprightpane->setText(roomDescription);
}

void GUI::tilesInit(){

    wesn_doors = new QPixmap("://resources/images/rooms/wesn_door.png");
    e_doors = new QPixmap("://resources/images/rooms/e_door.png");
    es_doors = new QPixmap("://resources/images/rooms/es_door.png");
    n_doors = new QPixmap("://resources/images/rooms/n_door.png");
    ne_doors = new QPixmap("://resources/images/rooms/ne_door.png");
    ns_doors = new QPixmap("://resources/images/rooms/ns_door.png");
    s_doors = new QPixmap("://resources/images/rooms/s_door.png");
    se_doors = new QPixmap("://resources/images/rooms/se_door.png");
    w_doors = new QPixmap("://resources/images/rooms/w_door.png");
    we_doors = new QPixmap("://resources/images/rooms/we_door.png");
    wes_doors = new QPixmap("://resources/images/rooms/wes_door.png");
    wn_doors = new QPixmap("://resources/images/rooms/wn_door.png");
    door = new QPixmap("://resources/images/rooms/closed_door.png");
}

void GUI::updateGUI(){
    vector<string> exits = zorkul.getRoomExits();
    label->setPixmap(*es_doors);
    bottomDisplay->setFocus();
}
void GUI::cmdLineEnterPressed(){
QString QuserInput = bottomDisplay->text();
string userinput = QuserInput.toLocal8Bit().constData();
string first, second;
vector<string> cmds;

std::istringstream ss(userinput);
string token;

while(std::getline(ss, token, ' ')) {
   cmds.push_back(token);
}
if(cmds.size()>1){
first = cmds.at(0);
second = cmds.at(1);
}
else if(cmds.size()>0){
first = "";
second = cmds.at(0);
}
else{
    first = "";
    second = "";
}

Command *cmd = new Command(first, second);
zorkul.processCommand(*cmd);


getCurrentRoomDescription();
updateGUI();

bottomDisplay->setText("");
delete cmd;
}


