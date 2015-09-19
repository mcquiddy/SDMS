/*
 * client.cpp
 *
 *  Created on: 15 de set. de 2015
 *      Author: bryan
 */
#include "client.h"

client::client(){
    pClient = socket(AF_INET, SOCK_STREAM, 0);
}

int client::StartClient(){



    if (pClient < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }


    cout << "\n=> Socket client has been created..." << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(portNum);


    if (connect(pClient,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0){
        cout << "=> Connection to the server port number: " << portNum << endl;
    }



    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(pClient, buffer, bufsize, 0);

    cout << "\n\n=> Enter # to end the connection\n" << endl;


    do {
        cout << "Client: ";
        do {
            cin >> buffer;
            send(pClient, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(pClient, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != 42);

        cout << "Server: ";
        do {
            recv(pClient, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;

    } while (!isExit);



    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(pClient);
    return 0;
}











