#include "socketclienteHeap.h"
#include "dHeap.h"




SocketClienteHeap::SocketClienteHeap(int pPuerto,char* pIp)
{
    puerto=pPuerto;
    ip=pIp;
    heap= dHeap::getInstance();

}

void SocketClienteHeap::setComando(string mensaje)
{
    const char * mns=&mensaje[0u];
    this->setMensaje(mns);
}



bool SocketClienteHeap::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = ntohs(puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
     return false;

    pthread_t hilo;
    pthread_create(&hilo,0,SocketClienteHeap::controlador,(void *)this);
    pthread_detach(hilo);

    return true;
}

void* SocketClienteHeap::controlador(void *obj)
{
    SocketClienteHeap* client=(SocketClienteHeap*)obj;
    while (true) {
        char buffer[1000]={0};
        int bytes = recv(client->descriptor,buffer,1000,0);
        if(bytes<=0){
            break;
        }
        else{

         client->heap->reciveMns(buffer);
        }
    }
    close(client->descriptor);
    pthread_exit(NULL);

}

int SocketClienteHeap::getPuerto(){return this->puerto;}
int SocketClienteHeap::getDescriptor(){return this->descriptor;}



bool SocketClienteHeap::setMensaje(const char *msn)
{
    try{
        send(descriptor,msn,strlen(msn),0);
        return true;
    }
    catch(string ex){
        cout<<" error al enviar mensaje del cliente al dheap"<<endl;
        return false;
    }


}
