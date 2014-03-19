#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include "ZorkUL.h"
#include "Command.h"
#include <string>
#include "Room.h"
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
void goButtonCommand(string direction, QString text);
void qbutclicked();
void getCurrentRoomDescription();
void tilesInit();
void updateGUI();
void drawFloor();
void drawWall();

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
    QPushButton *n_button;
    QPushButton *s_button;
    QPushButton *e_button;
    QPushButton *w_button;

    QGridLayout *mainLayout;
    QGridLayout *controlsLayout;
    QGridLayout *roomLayout;
};

#endif // GUI_H
