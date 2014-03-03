#ifndef ROOMS_H
#define ROOMS_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPixmap;
class QPushButton;
QT_END_NAMESPACE
class Button;


class rooms : public QWidget
{
    Q_OBJECT

public:
    rooms(QWidget *parent = 0);
private slots:
void northButtonClicked();
void southButtonClicked();
void eastButtonClicked();
void westButtonClicked();
void qbutclicked();

private:
    Button *createButton(const QString &text, const char *member);
    QLabel *label;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QPixmap *emptyroom;
    QPixmap *room_with_hero;

    QPushButton *n_button;
    QPushButton *s_button;
    QPushButton *e_button;
    QPushButton *w_button;




};

#endif // ROOMS_H
