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
    String message = "LR" + chatroomName;
    sendMessage(message);

    delete ui;
}

void chatRoom::on_sendButton_clicked()
{
    String message = "SM" + chatroomName + "," + textEdit.toPlainText();
    sendMessage(message);
    //call the writer

}

void chatRoom::sendMessage(string message)
{
    //Send some data
    char tmp[2000];
    strcpy(tmp, message.c_str());
    if( send(sock , tmp , strlen(tmp) , 0) < 0)
    {
         puts("Send failed");
         return;
    }
    puts("Data Send\n");
}
