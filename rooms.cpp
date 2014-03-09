

#include <QtWidgets>
#include "button.h"
#include "rooms.h"



using namespace std;


rooms::rooms(QWidget *parent) :
    QWidget(parent)
{

//! temp
//!


    wesn_doors = new QPixmap("C:/rooms/wesn_door.png");

    //QPixmap mypix ("C:/empty_room.png");
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
    toprightpane = new QLineEdit("");
    toprightpane->setReadOnly(true);
    toprightpane->setAlignment(Qt::AlignRight);
    toprightpane->setMaxLength(15);
    QFont toprightfont = toprightpane->font();
    toprightfont.setPointSize(toprightfont.pointSize() + 8);
    toprightpane->setFont(toprightfont);
    //bottom right display
    botrightpane = new QLineEdit("");
    botrightpane->setReadOnly(true);
    botrightpane->setAlignment(Qt::AlignRight);
    botrightpane->setMaxLength(15);
    QFont botrightfont = botrightpane->font();
    botrightfont.setPointSize(botrightfont.pointSize() + 8);
    botrightpane->setFont(botrightfont);

    //label->setPixmap("empty_room.png");

    //Button *northButton = createButton(tr("vh"), SLOT(northButtonClicked()));
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
    //mainLayout->addItem(controlsLayout,0,0);
    mainLayout->addWidget(n_button,0,1);
    mainLayout->addWidget(s_button,2,1);
    mainLayout->addWidget(w_button,1,0);
    mainLayout->addWidget(e_button,1,2);
    mainLayout->addWidget(label,1 ,1);
    mainLayout->addWidget(display, 3, 0, 1, 6);
    mainLayout->addWidget(toprightpane, 0, 3, 3, 2);
    mainLayout->addWidget(botrightpane, 2, 3, 3, 2);
    //temp
    setLayout(mainLayout);
    setWindowTitle(tr("Four room SIM"));
}


void rooms::northButtonClicked()
{
   string direction= "north";
   QString text =  "north";
  goButtonCommand(direction,text);

}
void rooms::southButtonClicked(){
    string direction= "south";
    QString text =  "south";
    goButtonCommand(direction,text);
    }

void rooms::eastButtonClicked(){
    string direction= "east";
    QString text =  "east";
    goButtonCommand(direction,text);
}

void rooms::westButtonClicked(){
    string direction= "west";
    QString text =  "west";
    goButtonCommand(direction,text);
}

void rooms::goButtonCommand(string direction, QString text){

    zorkul.go(direction);
    display->setText(text);

  ;}

void rooms::qbutclicked(){

     //m_button->setText("Example");
}
void rooms::getCurrentRoom(){
    *currentMapRoom=zorkul.getCurrentRoom();

}

Button *rooms::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

