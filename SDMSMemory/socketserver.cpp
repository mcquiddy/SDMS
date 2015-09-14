#include "socketserver.h"
#include "sdsmemoryserver.h"

SocketServer::SocketServer(int puerto,SDSMemoryServer *server){
    Puerto=puerto;
    this->server=server;
    flag_listen=false;
    flag_busy=false;
}

void SocketServer::sentMns(const char *mns,int id)
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
bool SocketServer::crear_Socket()
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
bool SocketServer::ligar_kernel()
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
void SocketServer::run(){
    if(!crear_Socket()){
        throw string("ERROR al crear el socket en el puerto: ");
    }
    if(!ligar_kernel()){
        throw string("ERROR al ligar kernel en el puerto: ");
    }
    while(!flag_listen) {
        dataSocket data;
        socklen_t tam = sizeof(data.info);
        data.descriptor = accept(descriptor,(sockaddr*)&data.info,&tam);
        if(data.descriptor<0){
            cout<<"ERROR al aceptar el cliente"<<endl;
        }
        else{
            data.server=server;
            data.puerto=Puerto;
            if(flag_busy){
                const char* mnsError="ERROR: -Puerto Ocupado-";
                send(data.descriptor,mnsError,strlen(mnsError),0);
                close(data.descriptor);
            }
            else{
                cout<<"Creado un cliente"<<endl;
                pthread_t hilo;
                pthread_create(&hilo,0,SocketServer::controladorCliente,(void *)&data);
                pthread_detach(hilo);
                data.server->newClient(data.descriptor,Puerto);
            }
        }
    }
    close(descriptor);
}

int SocketServer::get_puerto(){return this->Puerto;}

void SocketServer::busy(bool flag){flag_busy=flag;}
void SocketServer::closeSocket(){flag_listen=false;}

/**
 * @brief SocketServer::controladorCliente
 * @param obj
 * @return
 */
void *SocketServer::controladorCliente(void *obj){    
    dataSocket*data = (dataSocket*)obj;
    while(true){
        string mensaje;
        while(true){
            char buffer[1000]={0};
            int bytes = recv(data->descriptor,buffer,40,0);
            mensaje.append(buffer,bytes);
            if(bytes<=0||mensaje=="close"){
                close(data->descriptor);
                pthread_exit(NULL);
            }
            if(bytes<40){
                break;
            }
        }
        char* mns=&mensaje[0u];
        data->server->reciveMns(mensaje);
    /*
    dataSocket*data = (dataSocket*)obj;
    while(true){
        char* mensaje,*mns;
        while(true){
            char buffer[1]={0};
            int bytes = recv(data->descriptor,buffer,1,0);
            if(mns==NULL)
                mns=buffer;
            else{
                mensaje=mns;
                mns=(char*)malloc(1+strlen(mensaje)+strlen(buffer));
                strcpy(mns,mensaje);
                strcat(mns,buffer);
                cout<<"Mensaje mns: "<<mns<<endl;
            }
            if(bytes<=0){
                close(data->descriptor);
                pthread_exit(NULL);
            }

            if(bytes<1){
                break;
            }
        }
        cout<<"recibió: "<<mns<<endl;
        data->server->reciveMns(mns);
        */
    }
    close(data->descriptor);
    pthread_exit(NULL);
}
