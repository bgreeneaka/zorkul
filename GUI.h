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
class QLabel;
class QPixmap;
class QPushButton;
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
void getCurrentRoom();


private:

    ZorkUL zorkul;
    QLabel *label;
    QPixmap *wesn_doors;
    Room *currentMapRoom;
    QLineEdit *display;
    QLineEdit *toprightpane;
    QLineEdit *botrightpane;
    QPushButton *n_button;
    QPushButton *s_button;
    QPushButton *e_button;
    QPushButton *w_button;



};

#endif // GUI_H
