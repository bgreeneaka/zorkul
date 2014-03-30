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
class QStackedWidget;
class QWidget;
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
    void keepCmdLineFocus();
    void cmdLineEnterPressed();
    void drawFloor();
    void drawWall();
    void drawDoor();
    void setupDoors();
    void drawItem();
    void itemClick();
    void keyPressEvent(QKeyEvent *event);
    void showInventoryPane();
    void drawInventory();
    void inventoryButtonClick(int index);
    void setupInventory();
private:

    ZorkUL zorkul;



    Room *currentMapRoom;
    QLineEdit *bottomDisplay;
    QTextEdit  *toprightpane;
    QPushButton *info_button ;
    QPushButton *map_button ;
    QPushButton *inv_button ;
    QPushButton *look_button ;
    QPushButton *Item_botton;

    QGridLayout *mainLayout;
    QGridLayout *controlsLayout;
    QGridLayout *roomLayout;
    QGridLayout *inventoryLayout;

    QWidget *inventory;

    QStackedWidget *stackedPanes;


};

#endif // GUI_H
