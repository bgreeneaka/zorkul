

#include <QtWidgets>
#include "GUI.h"



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

    // bottom displa
    display = new QLineEdit("");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMaxLength(15);
    QFont font = display->font();
    font.setPointSize(font.pointSize() + 8);
    display->setFont(font);
    //top righ display
    toprightpane = new QTextEdit("");
    //get current room details
    zorkul.getRoomDiscription();
    string tempStr = zorkul.getRoomDiscription();
    QString roomDiscription = tempStr.c_str();
    toprightpane->setText(roomDiscription);
    // room detailsdisplayed
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
    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *controlsLayout = new QGridLayout;
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
    mainLayout->addWidget(label,1 ,1);
    mainLayout->addWidget(display, 3, 0, 1, 6);

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
    display->setText(text);
getCurrentRoom();
updateGUI();
  }

void GUI::qbutclicked(){

     //m_button->setText("Example");
}
void GUI::getCurrentRoom(){

   zorkul.getRoomDiscription();
   string tempStr = zorkul.getRoomDiscription();
   QString roomDiscription = tempStr.c_str();
   toprightpane->setText(roomDiscription);
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
}

void GUI::updateGUI(){

string exits = zorkul.getCurrentRoom();


     label->setPixmap(*wes_doors);;
}


