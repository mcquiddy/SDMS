#include "sdsmemoryserver.h"

SDSMemoryServer::SDSMemoryServer(){}

void SDSMemoryServer::reciveMns(char * message){}
void SDSMemoryServer::newClient(int id,int Puerto){}
void SDSMemoryServer::sentMns(const char* mns){}

void SDSMemoryServer::start(){
    pthread_t hilo_Puerto,hilo_PuertoStatus;
    pthread_create(&hilo_Puerto,0,SDSMemoryServer::runSockets,(void*)this->puerto);
    pthread_create(&hilo_PuertoStatus,0,SDSMemoryServer::runSockets,(void*)this->puerto_status);
    cout<<"Sockets creados \nPuerto Cliente: "<<puerto->get_puerto()<<"\nPuerto Status: "<<puerto_status->get_puerto()<<endl;
}

SDSMemoryServer::~SDSMemoryServer(){
    puerto->closeSocket();
    puerto_status->closeSocket();
}

void *SDSMemoryServer::runSockets(void* obj)
{
    SocketServer* Puerto=(SocketServer*) obj;
    try {
        Puerto->run();

    } catch (string ex) {
        cout << ex<<Puerto->get_puerto()<<endl;
    }
    pthread_exit(NULL);
}

