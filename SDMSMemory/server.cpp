/*
 * server.cpp
 *
 *  Created on: 15 de set. de 2015
 *      Author: bryan
 */
#include "server.h"

server::server(){
    client = socket(AF_INET, SOCK_STREAM, 0);

}
int server::StartServer(){
    if (client < 0)
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }



    cout << "\n=> Socket server has been created..." << endl;


    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);


    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0)
    {
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        return -1;
    }


    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;


    listen(client, 1);


    int clientCount = 1;
    pServer = accept(client,(struct sockaddr *)&server_addr,&size);



    if (pServer < 0)
        cout << "=> Error on accepting..." << endl;

    while (pServer > 0)
    {
        strcpy(buffer, "=> Server connected...\n");
        send(pServer, buffer, 1024, 0);
        cout << "=> Connected with the client #" << clientCount << ", you are good to go..." << endl;
        cout << "\n=> Enter # to end the connection\n" << endl;

        cout << "Client: ";
        do {
            recv(pServer, buffer, 1024, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');

        do {
            cout << "\nServer: ";
            do {
                cin >> buffer;
                send(pServer, buffer, 1024, 0);
                if (*buffer == '#') {
                    send(pServer, buffer, 1024, 0);
                    *buffer = '*';
                    isExit = true;
                }
            } while (*buffer != '*');

            cout << "Client: ";
            do {
                recv(pServer, buffer, 1024, 0);
                cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    isExit = true;
                }
            } while (*buffer != '*');
        } while (!isExit);


        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(pServer);
        cout << "\nGoodbye..." << endl;
        isExit = false;
        exit(1);
    }

    close(client);
    return 0;
}







