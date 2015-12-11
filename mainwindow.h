#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QVector>
#include <QStringList>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QInputDialog>
#include "chatroom.h"

#pragma comment(lib,"ws2_32.lib") //Winsock Library

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    SOCKET sock;

    explicit MainWindow(QWidget *parent = 0);
    QVector<chatRoom *> getChatRoom();
    Ui::MainWindow *ui;
    QStringList *chatlist;


    ~MainWindow();

private slots:
    void openChatDialogue(QString chatRoomName);

    void on_addChatButton_clicked();

    void on_chatListView_doubleClicked(const QModelIndex &index);

private:

    //somehow set the model into the server info!!!!!
    QStringListModel *model;
    QVector<chatRoom*> chatrooms;
};

#endif // MAINWINDOW_H
