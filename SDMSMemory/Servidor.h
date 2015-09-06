/*
 * Servidor.h
 *
 *  Created on: Aug 16, 2015
 *      Author: santii
 */

#ifndef SERVIDOR_H
#define SERVIDOR_H
#include "SocketServer.h"
#include "linked_list.h"
#include "facade_logic.h"



class Servidor {
private:
    facade_logic *F_logic;
    static Servidor* unicServer;
    SocketServer *PuertoCliente;
    SocketServer *PuertoVisualizar;
    SocketServer *PuertoAdmin;
    static void* run(void* obj);
    list<int> clientes_clientes;
    list<int> clientes_admin;
    list<int> clientes_visual;
    Servidor();

public:
    void mns_entrante(char* mensaje,int id,int puerto);
    void newConexion(int id,int Puerto);
    void enviarMensaje(const char*,int id);
    void start();
    static Servidor* get_instancia();
    void print_clientes_Servidor();
    ~Servidor();

};

#endif /* SERVIDOR_H */
