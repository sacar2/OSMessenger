#ifndef CHATROOM_H
#define CHATROOM_H

#include <QDialog>

namespace Ui {
class chatRoom;
}

class chatRoom : public QDialog
{
    Q_OBJECT

public:
    explicit chatRoom(QWidget *parent = 0);
    ~chatRoom();

private:
    Ui::chatRoom *ui;
};

#endif // CHATROOM_H
