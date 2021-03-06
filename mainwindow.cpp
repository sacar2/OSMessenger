#include <stdio.h>
#include <stdlib.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, SOCKET s) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sock= s;

    model = new QStringListModel(this);

    //THIS IS WHERE YOU ADD THE EXISTING CHAT ROOMS
    chatlist = new QStringList;



    //THIS GOES INTO READER
    *chatlist << "Ma Baes" << "ES3313 groupies" << "DOGS" << "Fam";
    model->setStringList(*chatlist);
    //set the chatlist list values as the values provided by the model
    ui->chatListView->setModel(model);





// these are edit triggers, so you can change the chatorom name when you select the row and type, or if you select the row and double click
// ui->chatListView->setEditTriggers(QAbstractItemView::AnyKeyPressed || QAbstractItemView::DoubleClicked);

}







QVector<chatRoom*> MainWindow::getChatRoom()
{
    return this->chatrooms;

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::openChatDialogue(QString chatRoomName){
    qDebug()<<chatRoomName;
    // create new chat window
    // create new chatwindow and add it to our list of chatrooms
    chatRoom *chatwindow = new chatRoom(this);
    chatrooms<<chatwindow;
    chatwindow->show();
    chatwindow->setWindowTitle(chatRoomName);

}


void MainWindow::on_addChatButton_clicked()
{
    // input dialoge box for new chat name
        //take user input for the  name of the new chatroom
        QString name = QInputDialog::getText(this, "New Chat Room", "enter a name for this new chatroom");

    // add new chat into the main list, and model

        //send new chatroom id to server
        String message = "MR" + name;
        sendMessage(message);

        *chatlist<<name;
        //find #rows in the model,

    //Insert to top of list
        //int row = ui->chatListView->currentIndex().row();
        //OR add to bottom
        int row = model->rowCount();

    //    insert 1 row into a new row in the model (list item)
        model->insertRows(row,1);

    //find position in model and create a reference to it called index
        QModelIndex index = model->index(row);


    // add new chat into chatListView on UI
        //let the chatListView display the data stored in 'model'
        ui->chatListView->setCurrentIndex(index);
        model->setStringList(*chatlist);
        ui->chatListView->setModel(model);

    openChatDialogue(name);
}




void MainWindow::on_chatListView_doubleClicked(const QModelIndex &index)
{

    // when you double click on the chat room name,
    // a new thread will be spawned corresponding to that specific chat room

    //get the name of the chatroom - this is also the id on the server
    QString roomName = index.data(Qt::DisplayRole ).toString();

    String message = "ER" + roomName;
    sendMessage(message);

    openChatDialogue(roomName);

    return;
}

void MainWindow::sendMessage(string message)
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
