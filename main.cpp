#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

WSADATA wsa;
SOCKET s;
struct sockaddr_in server;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(&s);

    printf("\nInitialising Winsock...");
            if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
            {
                printf("Failed. Error Code : %d",WSAGetLastError());
                return;
            }

            printf("Initialised.\n");

            //Create a socket
            if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
            {
                printf("Could not create socket : %d" , WSAGetLastError());
            }

            printf("Socket created.\n");


            server.sin_addr.s_addr = inet_addr("52.35.85.158");
            server.sin_family = AF_INET;
            server.sin_port = htons( 1101 );

            //Connect to remote server
            if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
            {
                puts("connect error");
                system("PAUSE");
                return;
            }

            puts("Connected");

            char server_reply[2000];
            int recv_size;

            //Receive a chatroom list from the server
            if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
            {
                puts("recv failed");
            }

            puts("Reply received\n");

    w.show();

    return a.exec();
}

void sendMessage(string message)
{
    //Send some data
    char tmp[2000];
    strcpy(tmp, message.c_str());
    if( send(s , tmp , strlen(tmp) , 0) < 0)
    {
         puts("Send failed");
         return;
    }
    puts("Data Send\n");
}

void reader(MainWindow *w)
{
    char server_reply[2000];
    int recv_size;

    //Receive a chatroom list from the server
    if((recv_size = recv(s , server_reply , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }
    puts("Reply received\n");




    //
    if (==ar){

    }
    //
    if (==dr){

    }
    //
    if (==sm){

    }
}
