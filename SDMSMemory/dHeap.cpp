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


/*!
 * \brief dHeap::dHeap
 * \param path
 */
dHeap::dHeap(){

   this->newSDSM=new  SocketServerHeap(5000,this);
list_ClientStatus=new lista<SocketClienteHeap *>();
   pthread_t hilo_NewNodo,hilo_visual;
   pthread_create(&hilo_NewNodo,0,dHeap::run,(void*)this->newSDSM);

 //   this->client =-1;
   //    this->start(8080,8081);
}

void *dHeap::run(void *obj)
{
    SocketServerHeap* puerto=(SocketServerHeap*) obj;
    try{

        puerto->run();
    }
    catch(string ex){
        cout<< ex<<puerto->get_puerto()<<endl;
    }
    pthread_exit(NULL);
}


/*!
 * \brief dHeap::d_Set
 * \param toSend
 */
void dHeap::d_set(dPointer toSend){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_set");
    writer.String("type");
    writer.String(toSend.pType);
    writer.String("Data");
    writer.String(toSend.data.c_str());
    writer.EndObject();

    cout<<s.GetString()<<endl;
    const char* mensaje=s.GetString();
    //puerto->sentMns(mensaje,8);

}
/*!
 * \brief dHeap::d_calloc
 * \param pSize
 */
void dHeap::d_calloc(int pSize){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_calloc");
    writer.String("pSize");
    writer.Int(pSize);
    writer.EndObject();

    const char* mensaje = s.GetString();
   // puerto->sentMns(mensaje,8);
}
/*!
 * \brief dHeap::dFree
 * \param toFree
 */
void dHeap::d_free(dPointer toFree){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_free");
    writer.String("dir");
    writer.Int(toFree.DirectionPointer);
    writer.String("pSize");
    writer.Int(toFree.pSize);
    writer.EndObject();
    const char* mensaje = s.GetString();
   // puerto->sentMns(mensaje,8);
}
/*!
 * \brief dHeap::d_get
 * \param toGet
 */
void dHeap::d_get(dPointer toGet){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("d_get");
    writer.String("dir");
    writer.Int(toGet.DirectionPointer);
    writer.String("pSize");
    writer.Int(toGet.pSize);
    writer.EndObject();
    const char* mensaje = s.GetString();
    //puerto->sentMns(mensaje,8);

}
/*!
 * \brief dHeap::dMalloc
 * \param size
 * \param type
 */
d_pointer_size_type* dHeap::dMalloc(int size, dChar type){

    d_pointer_size_type* puntero = new d_pointer_size_type();
    dInt siz;
    siz=size;
    puntero->setSize(siz);
    puntero->setDataType(type);

    return puntero;
    //this->vPointer = new dPointer(type);
    //this->vPointer->pType = type;
}

dHeap * dHeap::unicdHeap=NULL;

dHeap *dHeap::getInstance()
{

    if(unicdHeap==NULL){

        unicdHeap=new dHeap();



    }
 return unicdHeap;

}

void dHeap::newNode(char *message)
{
    Document doc;
    doc.ParseInsitu(message);
   if(doc.IsObject()){
           string ip;
           int puerto,status;
       if(doc.HasMember("ip")){

           if(doc["ip"].IsString()){

               ip=doc["ip"].GetString();
           }
       }
       if(doc.HasMember("puerto")){

           if(doc["puerto"].IsInt()){

               puerto=doc["puerto"].GetInt();
           }
       }
       if(doc.HasMember("status")){

           if(doc["status"].IsInt()){

               status=doc["status"].GetInt();
           }
       }
       SocketClienteHeap *nodo=new SocketClienteHeap(puerto,(char*)ip.c_str());
       if(nodo->connectar()){
           cout<<" nuevo nodo conectado "<<endl;
          list_ClientStatus->insert_head(nodo);
       }
       else{
              cout<<" nuevo nodo fallado "<<endl;
       }
   }


}





/*!
 * \brief SDSMemoryNode::d_status
 *        Envia un json conformado por lo datos retornados del manejador de memoria al pedir el estado de la memoria, al puerto
 */
void dHeap::d_status()
{
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("d_status");



    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
  //  puerto->sentMns(mensaje,8);

}




/**
 * @brief SDSMemoryNode::reciveMns
 *       Resive el mensaje que es un formato json, lo parsea y verifica cual orden es,despues
 *       de verificar la orden parsea los datos entrantes y llama al metodo especificado por
 *       la orden  o el protocolo.
 * @param mns
 *       Mensaje en formato json
 */
void dHeap::reciveMns(char * message){

    cout<<message<<endl;
    Document doc;
    doc.ParseInsitu(message);
   if(doc.IsObject()){
       // Verifica cual orden o accion se tiene que hacer
       if(doc.HasMember("protocolo")){
           string comando;
           if(doc["protocolo"].IsString()){

               comando=doc["protocolo"].GetString();
           }
           //Si la orden o protocolo es d_calloc, se obtiene el dato pSize, y se llama a que se reserve un espacio
           //de memoria
               if(comando=="d_calloc"){
                 int status,direccion;
                 if(doc.HasMember("status")){
                 if(doc["status"].IsInt()){
                    status= doc["status"].GetInt();

                 }
                 }if(doc.HasMember("direccion")){
                     if(doc["direccion"].IsInt()){
                         direccion = doc["direccion"].GetInt();
                     }
                 }
                 //checkcalloc(status,direccion);
               }

 //Si la orden o protocolo es d_status se llama a que retorne es estado de memoria
               else if(comando=="d_status"){
                   int mem_disponible,max_chunk;
                   if(doc.HasMember("memoria_disponible")){
                   if(doc["memoria_disponible"].IsInt()){
                      mem_disponible= doc["memoria_disponible"].GetInt();

                   }
                   }if(doc.HasMember("max_chunk")){
                       if(doc["max_chunk"].IsInt()){
                           max_chunk = doc["max_chunk"].GetInt();
                       }
                   }
                   //checkstatus(mem_disponible,max_chunk);


               }
               else if(comando =="d_get"){






                   int status;
                   if(doc.HasMember("status")){
                   if(doc["status"].IsInt()){
                      status= doc["status"].GetInt();

                   }

                   //verifica el tipo que se obtuvo


                                              if(this->vPointer->pType=="char"){


                                                         if(doc.HasMember("dato")){
                                                             if(doc["dato"].IsString()){
                                                            //Parsear a char

                                                              char pData =*(const_cast<char *>(doc["dato"].GetString()));
                                                              cout << pData <<"char entrante"<< endl;
                                                             }
                                                         }





                                              }
                                              else if(this->vPointer->pType=="int"){
                                                  if(doc["dato"].IsInt()){
                                                 //Parsear a char

                                                   int pData =doc["dato"].GetInt();
                                                   cout << pData <<"int entrante"<< endl;





                                              }
                                              else if(this->vPointer->pType=="bool"){
                                          //Parsear a bool
                                                    //status= Manejador.setearDatoBool(pointerSize,pData);
                                              }
                                              else if(this->vPointer->pType=="float"){
                                          //parsear a float
                                                   // status= Manejador.setearDatoFloat(pointerSize,pData);

                                              }
                                              else if(this->vPointer->pType=="arrayint"){
                                          //parsear a arreglo de int
                                                   // status= Manejador.setearDatoArrayInt(pointerSize,pData);
                                              }
                                              else if(this->vPointer->pType=="arraychar"){
                                          //Parsear a arreglos de char
                                                    //status= Manejador.setearDatoArrayChar(pointerSize,pData);
                                              }
                                              else if(this->vPointer->pType=="long"){
                                          //Parsear a long
                                                   // status= Manejador.setearDatoLong(pointerSize,pData);
                                              }
                                              else if(this->vPointer->pType=="double"){
                                          //Parsear a double
                                                   // status= Manejador.setearDatoDouble(pointerSize,pData);
                                              }

                                         }}







               }
                   else{
                   int status;
                   if(doc.HasMember("status")){
                   if(doc["status"].IsInt()){
                      status= doc["status"].GetInt();

                   }
                   if(comando == "d_free"){
                       //checkfree(status);
                   }
                   else if(comando == "d_set"){
                       //checkset(status);
                   }
                   }

           }


       }

   }
}




/*!
 * \brief SDSMemoryNode::~SDSMemoryNode
 * cierra los puertos y los libera de la memoria
 */
dHeap::~dHeap(){

    delete this;
}





