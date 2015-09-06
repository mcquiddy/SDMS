/*
 * Servidor.cpp
 *
 *  Created on: Aug 16, 2015
 *      Author: santii
 */
#include "Servidor.h"
#include "SocketServer.h"
/**
 * @brief Servidor::unicServer
 * Se inicializa el servidor como nulo
 */
Servidor* Servidor::unicServer=NULL;

/**
 * @brief Servidor::get_instancia
 * @return
 * retorna la instancia de la clase singleton
 */
Servidor* Servidor::get_instancia(){
    if(unicServer==NULL){
        unicServer=new Servidor();
    return unicServer;
    }
}
/**
 * @brief Servidor::run
 * @param obj
 * @return
 * Corre el puerto que ingresa en un hilo
 */
void* Servidor::run(void *obj) {
    SocketServer* Puerto=(SocketServer*) obj;
    try {
        Puerto->run();

    } catch (string ex) {
        cout << ex<<Puerto->get_puerto()<<endl;
    }
    pthread_exit(NULL);
}

/**
 * @brief Servidor::Servidor
 * Constructor del Servidor
 */
Servidor::Servidor(){
    cout<<"Nuevo Servodor Creado"<<endl<<"Los Puertos son:"<<endl<<"    Puerto Administrador: 4008"<<endl<<"    Puerto Cliente: 4007"<<endl<<"    Puerto Vizualizar: 4006"<<endl;
    F_logic=new facade_logic();
    PuertoAdmin = new SocketServer(4008);
    PuertoCliente = new SocketServer(4007);
    PuertoVisualizar = new SocketServer(4006);
}

/**
 * @brief Servidor::enviarMensaje
 * @param mns
 * @param id
 * Envia un mensaje al cliente, le ingresa un id o descriptor y el mensaje como const char*
 */
void Servidor::enviarMensaje(const char* mns, int id)
{
    if(unicServer->clientes_admin.isInList(id))
        unicServer->PuertoAdmin->sentMensaje(mns,id);

    else if(unicServer->clientes_clientes.isInList(id))
        unicServer->PuertoCliente->sentMensaje(mns,id);

    else if(unicServer->clientes_visual.isInList(id))
        unicServer->PuertoVisualizar->sentMensaje(mns,id);
    else
        cout<<"No esta en la lista"<<endl;
}
/**
 * @brief Servidor::start
 * Creates a pthread for each port
 */
void Servidor::start()
{
    pthread_t hilo_PuertoAdmi,hilo_PuertoCliente,hilo_PuertoVisual;
    pthread_create(&hilo_PuertoAdmi,0,Servidor::run,(void*)PuertoAdmin);
    pthread_create(&hilo_PuertoCliente,0,Servidor::run,(void*)PuertoCliente);
    pthread_create(&hilo_PuertoVisual,0,Servidor::run,(void*)PuertoVisualizar);
}

/**
 * @brief Servidor::print_clientes_Servidor
 * Imprime los descriptores de las listas
 */
void Servidor::print_clientes_Servidor()
{
    if(PuertoAdmin!=NULL){
        //cout<<"Clientes Admin: ";
        clientes_admin.print_list();
    }
    if(PuertoCliente!=NULL){
        //cout<<"Clientes PC: ";
        clientes_clientes.print_list();
    }
    if(PuertoVisualizar!=NULL){
        //cout<<"Clientes Visual: ";
        clientes_visual.print_list();
    }
}

/**
 * @brief Servidor::newConexion
 * @param newCliente
 * @param Puerto
 * Nueva conexión recibe un cliente o descriptor y un puerto y habla con el facade de logica para avisar
 * que se ha conectado un nuevo cliente.
 * Agrega el cliente a la lista correspondiente.
 */
void Servidor::newConexion(int newCliente, int Puerto)
{
    cout<<"Nuevo Cliente: "<<newCliente<<endl;
    if(Puerto==4007){
        unicServer->clientes_clientes.insert_head(newCliente);
        unicServer->F_logic->newCliente("PC/Android",newCliente);
    }
    else if(Puerto==4008){
        unicServer->clientes_admin.insert_head(newCliente);
        unicServer->F_logic->newCliente("Admin",newCliente);
    }
    else if(Puerto==4006){
        unicServer->clientes_visual.insert_head(newCliente);
        unicServer->F_logic->newCliente("Visual",newCliente);
    }
}

/**
 * @brief Servidor::newMensaje
 * Method receives a message and sends it to facade_logic
 * @param mensaje
 * @param id
 */
void Servidor::mns_entrante(char* mensaje,int id,int puerto){
    unicServer->F_logic->mns_logica(mensaje,id,puerto);
}

/**
 * @brief Servidor::~Servidor
 * destructor de servidor
 */
Servidor::~Servidor()
{
    PuertoCliente->~SocketServer();
    PuertoAdmin->~SocketServer();
    PuertoVisualizar->~SocketServer();
}

