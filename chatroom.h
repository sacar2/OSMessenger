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

private slots:
    void on_sendButton_clicked();

private:
    Ui::chatRoom *ui;
    //this is the id on the server
    QString *chatroomName;
};

#endif // CHATROOM_H
