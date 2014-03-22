#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "ZorkUL.h"
#include "Command.h"
#include <string>
#include "Room.h"
#include "item.h"
using namespace std;

QT_BEGIN_NAMESPACE
class QLineEdit;
class QTextEdit;
class QLabel;
class QPixmap;
class QPushButton;
class QGridLayout;
QT_END_NAMESPACE



class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = 0);

private slots:
    void northButtonClicked();
    void southButtonClicked();
    void eastButtonClicked();
    void westButtonClicked();
    void infoButtonClicked();
    void mapButtonClicked();
    void invButtonClicked();
    void lookButtonClicked();
    void itemButtonClicked();
    void qbutclicked(string firstWord, string secondWord);
    void getCurrentRoomDescription();
    void updateGUI();
  void  keepCmdLineFocuse();
    void cmdLineEnterPressed();
    void drawFloor();
    void drawWall();
    void drawDoor();
    void setupDoors();
    void drawItem();
    void itemClick();
    void keyPressEvent(QKeyEvent *event);

private:

    ZorkUL zorkul;
    QLabel *label;

    // tiles
    QPixmap *wesn_doors;
    QPixmap *e_doors;
    QPixmap *es_doors;
    QPixmap *n_doors;
    QPixmap *ne_doors;
    QPixmap *ns_doors;
    QPixmap *s_doors;
    QPixmap *se_doors;
    QPixmap *w_doors;
    QPixmap *we_doors;
    QPixmap *wes_doors;
    QPixmap *wn_doors;
    QPixmap *door;
    // tiles

    Room *currentMapRoom;
    QLineEdit *bottomDisplay;
    QTextEdit  *toprightpane;
    QLineEdit *botrightpane;
    QPushButton *info_button ;
    QPushButton *map_button ;
    QPushButton *inv_button ;
    QPushButton *look_button ;
    QPushButton *n_button;
    QPushButton *s_button;
    QPushButton *e_button;
    QPushButton *w_button;
    QPushButton *Item_botton;

    QGridLayout *mainLayout;
    QGridLayout *controlsLayout;
    QGridLayout *roomLayout;

signals:

    void moveLeft();
    void moveRight();
};

#endif // GUI_H
