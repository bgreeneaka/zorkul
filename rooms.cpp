

#include <QtWidgets>

#include "button.h"
#include "rooms.h"

rooms::rooms(QWidget *parent) :
    QWidget(parent)
{

//! temp
    emptyroom = new QPixmap("C:/empty_room.png");
    room_with_hero = new QPixmap("C:/char_in_room.png");
    //QPixmap mypix ("C:/empty_room.png");
    label = new QLabel();
    label2 = new QLabel();
    label3= new QLabel();
    label4 = new QLabel();
    label->setPixmap(*emptyroom);
    label2->setPixmap(*emptyroom);
    label3->setPixmap(*emptyroom);
    label4->setPixmap(*room_with_hero);
   //! temp

//! [1] //! [2]




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
    connect(w_button, SIGNAL(released()), this, SLOT(eastButtonClicked()));
    connect(e_button, SIGNAL(released()), this, SLOT(westButtonClicked()));

    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


    //mainLayout->addWidget(northButton, 0, 0);
    controlsLayout->addWidget(n_button,0,1);
    controlsLayout->addWidget(s_button,1,1);
    controlsLayout->addWidget(w_button,1,0);
    controlsLayout->addWidget(e_button,1,2);
    //temp
    mainLayout->addItem(controlsLayout,0,0);
    mainLayout->addWidget(label,1,0);
    mainLayout->addWidget(label2,1,1);
    mainLayout->addWidget(label3,2,0);
    mainLayout->addWidget(label4,2,1);
    //temp
    setLayout(mainLayout);
    setWindowTitle(tr("Four room SIM"));
}


void rooms::northButtonClicked()
{
    ;
}
void rooms::southButtonClicked(){
    ;
}

void rooms::eastButtonClicked(){
    ;
}

void rooms::westButtonClicked(){
    ;
}

void rooms::qbutclicked(){

     //m_button->setText("Example");
}

Button *rooms::createButton(const QString &text, const char *member)
{
    Button *button = new Button(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

