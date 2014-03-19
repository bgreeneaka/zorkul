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

    mainLayout = new QGridLayout();
    controlsLayout = new QGridLayout();
    roomLayout = new QGridLayout();

    roomLayout->setHorizontalSpacing(0);
    roomLayout->setVerticalSpacing(0);


    drawFloor();
    drawWall();
    drawDoor();


    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    controlsLayout->addWidget(toprightpane, 0, 0,2,2);

    mainLayout->addItem(controlsLayout,0,3,2,3);
    mainLayout->addWidget(n_button,0,1);
    mainLayout->addWidget(s_button,2,1);
    mainLayout->addWidget(w_button,1,0);
    mainLayout->addWidget(e_button,1,2);
    mainLayout->addItem(roomLayout,1 ,1);
    mainLayout->addWidget(bottomDisplay, 3, 0, 1, 6);

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

void GUI::updateGUI(){
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

void GUI::drawFloor() {
    for (unsigned int i = 0; i < 10; i++) {
        for (unsigned int j = 0; j < 10; j++) {
            QLabel *floorLabel = new QLabel();
            floorLabel->setPixmap(QPixmap("://resources/images/rooms/pedestal_full.png"));
            roomLayout->addWidget(floorLabel, i, j);
        }
    }
}

void GUI::drawWall() {
    int j = 0;
    for (unsigned int i = 0; i < 10; i++) {
        QLabel *wallLabel = new QLabel();
        wallLabel->setPixmap(QPixmap("://resources/images/rooms/brick_brown0.png"));
        roomLayout->addWidget(wallLabel, i, j);
    }
    j = 9;
    for (unsigned int i = 0; i < 10; i++) {
        QLabel *wallLabel = new QLabel();
        wallLabel->setPixmap(QPixmap("://resources/images/rooms/brick_brown0.png"));
        roomLayout->addWidget(wallLabel, i, j);
    }
    j = 9;
    for (unsigned int i = 0; i < 10; i++) {
        QLabel *wallLabel = new QLabel();
        wallLabel->setPixmap(QPixmap("://resources/images/rooms/brick_brown0.png"));
        roomLayout->addWidget(wallLabel, j, i);
    }
    j = 0;
    for (unsigned int i = 0; i < 10; i++) {
        QLabel *wallLabel = new QLabel();
        wallLabel->setPixmap(QPixmap("://resources/images/rooms/brick_brown0.png"));
        roomLayout->addWidget(wallLabel, j, i);
    }
}

void GUI::drawDoor() {
    vector<string> exits = zorkul.getRoomExits();
    for (unsigned int i = 0; i < exits.size(); i++) {
        if (exits[i].compare("east") == 0) {
            QPushButton *doorButton = new QPushButton();
            doorButton->setIcon(QIcon("://resources/images/rooms/closed_door.png"));
            roomLayout->addWidget(doorButton, 4, 9);
        }
    }
}

