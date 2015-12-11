#include "chatroom.h"
#include "ui_chatroom.h"

chatRoom::chatRoom(QWidget *parent, SOCKET s) :
    QDialog(parent),
    ui(new Ui::chatRoom)
{
    ui->setupUi(this);

    sock = s;
}

chatRoom::~chatRoom()
{
    QString message = "LR" + *chatroomName;
    sendMessage(message);

    delete ui;
}

void chatRoom::on_sendButton_clicked()
{
    QString message = "SM" + *chatroomName + "," + ui->textEdit->toPlainText();
    sendMessage(message);
    //call the writer

}

void chatRoom::sendMessage(QString message)
{
    //Send some data
    QByteArray charstring = message.toLocal8Bit();
    char* tmp = charstring.data();
    if( send(sock , tmp , strlen(tmp) , 0) < 0)
    {
         puts("Send failed");
         return;
    }
    puts("Data Send\n");
}
