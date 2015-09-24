#include "socketserverHeap.h"
#include "dHeap.h"

SocketServerHeap::SocketServerHeap(int puerto, dHeap *server){
    Puerto=puerto;

    this->server=server;


}

void SocketServerHeap::sentMns(const char *mns,int id)
{
    cout<<"en el socket "<<mns<<endl;
    send(id,mns,strlen(mns),0);
}
/**
 * @brief SocketServer::crear_Socket
 * @return
 * Funcion que crea un SocketServer. descriptor es el ID que le asigna el sistema operativo al
 * socket y es el mismo que se utiliza para crear el juego.
 * Se asignan otros valores como el puerto necesarios para la comunicacion.
 */
bool SocketServerHeap::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor<0){
        return false;
    }
    info.sin_family=AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(Puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));
    return true;
}
/**
 * @brief SocketServer::ligar_kernel
 * @return
 * Funcion que se encarga de hablar con el sistema operativo para cargar el nuevo Socket
 */
bool SocketServerHeap::ligar_kernel()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0){
        return false;
    }
    listen(descriptor,5);
    return true;
}

/**
 * @brief SocketServer::run
 * Funcion estatica de la clase que es llamada por el hilo,
 * Llama al metodo de crear_Socket y valida que no haya problemas
 * llama al metodo de ligar kernel que valida si el puerto está abierto o no
 */
void SocketServerHeap::run(){

    if(!crear_Socket()){
        throw string("ERROR al crear el socket en el puerto: ");
    }
    if(!ligar_kernel()){
        throw string("ERROR al ligar kernel en el puerto: ");
    }
    while(true) {
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor<0){
            cout<<"ERROR al aceptar el cliente"<<endl;
            break;
        }
        else{
            data.server=server;
            data.puerto=Puerto;

                cout<<"Creado un cliente"<<endl;
                data.server=dHeap::getInstance();
                pthread_t hilo;
                pthread_create(&hilo,0,SocketServerHeap::controladorCliente,(void *)&data);
                pthread_detach(hilo);



        }
    }
    close(descriptor);
}

int SocketServerHeap::get_puerto(){return this->Puerto;}



/**
 * @brief SocketServer::controladorCliente
 * @param obj
 * @return
 */
void *SocketServerHeap::controladorCliente(void *obj){
    dataSocket*data = (dataSocket*)obj;
    while(true){


            char buffer[1000]={0};
            int bytes = recv(data->descriptor,buffer,1000,0);
            if(bytes<=0){

            break;
            }
            else{
                cout<<buffer<<endl;
                data->server->newNode(buffer);

        }






    }
    close(data->descriptor);
    pthread_exit(NULL);
}
