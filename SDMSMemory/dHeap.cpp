/*
 * dHeap.cpp
 *
 *  Created on: 12 de set. de 2015
 *      Author: bryan
 */
/*
si esto no funciona, pasar los metodos al servidor, enviar solo los argumentos a cada tipo de metodo y enviarlos desde ahi
*/
#include "dHeap.h"
#include "dPointer.h"

/*!
 * \brief dHeap::dHeap
 * \param path
 */
dHeap::dHeap(char path){
    pFolder = path;


}
/*!
 * \brief dHeap::d_Set
 * \param toSend
 */
void dHeap::d_Set(dPointer toSend){
    stringbuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_set");
    writer.String("type");
    writer.Int(toSend.pType);
    writer.String("Data");
    writer.Int(toSend.data);
    writer.EndObject();

    cout<<s.GetString()<<endl;
    const char* mensaje=s.GetString();
    server->sentMns(mensaje);

}
/*!
 * \brief dHeap::d_calloc
 * \param pSize
 */
void dHeap::d_calloc(int pSize){
    stringbuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("dcalloc");
    writer.String("Size");
    writer.Int(pSize);
    writer.EndObject();

    const char* mensaje = s.GetString();
    server->sentMns(mensaje);
}
/*!
 * \brief dHeap::dFree
 * \param toFree
 */
void dHeap::dFree(dPointer toFree){
    stringbuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_free");
    writer.Int(dPointer.DirectionPointer);
    writer.Int(dPointer.pSize);
    writer.EndObject();
    const char* mensaje = s.GetString();
    server->sentMns(mensaje);
}
/*!
 * \brief dHeap::d_get
 * \param toGet
 */
void dHeap::d_get(dPointer toGet){
    stringbuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_get");
    writer.Int(dPointer.DirectionPointer);
    writer.Int(dPointer.pSize);
    writer.EndObject();
    const char* mensaje = s.GetString();
    server->sentMns(mensaje);

}
/*!
 * \brief dHeap::dMalloc
 * \param size
 * \param type
 */
void dHeap::dMalloc(int size, char* type){

    this->vPointer = new dPointer(type);
    this->vPointer->pType = type;


}




