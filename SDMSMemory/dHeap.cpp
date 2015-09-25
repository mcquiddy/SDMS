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
#include "d_pointer_size_type.h"



dHeap * dHeap::unicdHeap=NULL;
/*!
 * \brief dHeap::dHeap
 * \param path
 */
dHeap::dHeap(){
    int SDSMport=cargarPuerto("SDSMport");
    int SDSMstatus=cargarPuerto("visual");
    cout<<"Creando puertos "<<SDSMport<<" "<<SDSMstatus<<endl;
    list_nodos=new lista<NodoSDSM*>();
    if(SDSMport!=-1 && SDSMstatus!=-1){
        this->newSDSM = new  SocketServerHeap(SDSMport,this);
        this->newStatus=new  SocketServerHeap(SDSMstatus,this);
        pthread_t hilo_NewNodo,hilo_visual;
        pthread_create(&hilo_NewNodo,0,dHeap::run,(void*)this->newSDSM);
        pthread_create(&hilo_visual,0,dHeap::run,(void*)this->newStatus);

    }
    else
        cout<<"ERROR: -algun puerto no pudo ser cargado-\n";
}

dHeap *dHeap::getInstance()
{
    if(unicdHeap==NULL)
        unicdHeap=new dHeap();
    return unicdHeap;
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

void dHeap::cargarNodos()
{
    cout<<"Cargando nodos...";
    pugi::xml_document doc;
    if (!doc.load_file("/home/santii/Dropbox/pugixmlPruebas/config.xml")){
        cout<<"Error al cargar xml\n";
    }
    else{
        pugi::xml_node root=doc.first_child();
         cout<<"creando nodos de: "<<root.name()<<endl;
        pugi::xml_node temp=root.child("memoryNodes").first_child();

        while(temp!=NULL){
            cout<<temp.name()<<", ip: "<<temp.attribute("ip").value()<<", puerto: "<<temp.attribute("puerto").value()<<", status: "<<temp.attribute("status").value()<<endl;
            //newNode((char*)temp.attribute("ip").value(),atoi(temp.attribute("puerto").value()),atoi(temp.attribute("status").value()));
            temp=temp.next_sibling();


        }
         Node("192.168.1.122",7008,7001);
         cout<<"Carga completa"<<endl;

    }
}

int dHeap::cargarPuerto(char *port)
{
    pugi::xml_document doc;
    if (!doc.load_file("/home/santii/Proyecto1/SDMS/config.xml")){
        cout<<"Error al cargar xml\n";
        return -1;
    }
    pugi::xml_node root=doc.first_child();
    cout<<root.child("Puertos").attribute(port).value()<<endl;
    return atoi(root.child("Puertos").attribute(port).value());

}

void dHeap::Node(char *ip, int puerto, int status)
{

    SocketClienteHeap *newPuerto=new SocketClienteHeap(puerto,ip);
//    SocketClienteHeap *newStatus=new SocketClienteHeap(status,ip);
    //&&(newStatus->connectar())
    if((newPuerto->connectar())){
        cout<<" nuevo nodo conectado "<<endl;

        NodoSDSM *newNodo=new NodoSDSM();

        newNodo->id=contadorID;

        newNodo->puerto=newPuerto;

//        newNodo->status=newStatus;
        contadorID++;

        list_nodos->insert_head(newNodo);


    }
    else{
           cout<<" nuevo nodo fallado "<<endl;
    }

}


/*!
 * \brief dHeap::d_Set
 * \param toSend
 */
void dHeap::d_set(dPointer toSend){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("protocolo");
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
    writer.String("protocolo");
    writer.String("d_calloc");
    writer.String("pSize");
    writer.Int(pSize);
    writer.EndObject();
    cout<<s.GetString()<<endl;
    //const char* mensaje = s.GetString();
    cout<<list_nodos->get_head()->get_data()->puerto->getDescriptor();
    list_nodos->get_head()->get_data()->puerto->setMensaje(s.GetString());
    cout<<"puerto->sentMns(mensaje,8);"<<endl;
    flag_dirpointer=true;

}
/*!
 * \brief dHeap::dFree
 * \param toFree
 */
void dHeap::d_free(dPointer toFree){
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("protocolo");
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

    //puerto->sentMns(mensaje,8);

}
/*!
 * \brief dHeap::dMalloc
 * \param size
 * \param type
 */

d_pointer_size_type* dHeap::dMalloc(int size, char* type){
    d_pointer_size_type pointer;
    pointer.setDataType(type);
    pointer.setSize(size);
    pointer.setID(contadorID);
    contadorID++;
    d_calloc(size);
    cout<<" entro while "<<endl;
    while(flag_dirpointer){

    }
    cout<<" salio while "<<endl;
    pointer.setPuntero(dirPointer);
    return &pointer;

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
       SocketClienteHeap *newPuerto=new SocketClienteHeap(puerto,(char*)ip.c_str());
       SocketClienteHeap *newStatus=new SocketClienteHeap(status,(char*)ip.c_str());
       if(newPuerto->connectar()&&newStatus->connectar()){
           cout<<" nuevo nodo conectado "<<endl;
           NodoSDSM *newNodo;
           newNodo->id=contadorID;
           newNodo->puerto=newPuerto;
           newNodo->status=newStatus;
           contadorID++;
           list_nodos->insert_head(newNodo);
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

void dHeap::checkcalloc(int status, int direccion)
{
    if(status==1){
        cout<<" reservacion correcta "<<endl;
        dirPointer=direccion;
        flag_dirpointer=false;
    }
    else{
        cout<<" reservacion incorrecta "<<endl;
        dirPointer=-1;
        flag_dirpointer=false;
    }

}




/**
 * @brief SDSMemoryNode::reciveMns
 *       Resive el mensaje que es un formato json, lo parsea y verifica cual orden es,despues
 *       de verificar la orden parsea los datos entrantes y llama al metodo especificado por
 *       la orden  o el protocolo.
 * @param mns
 *       Mensaje en formato json
 */
void dHeap::reciveMns(char * message)
{

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
        }
        if(doc.HasMember("direccion")){
            if(doc["direccion"].IsInt()){
                direccion = doc["direccion"].GetInt();
            }
        }
        checkcalloc(status,direccion);
    }
     //Si la orden o protocolo es d_status se llama a que retorne es estado de memoria
    else if(comando=="d_status"){
        int mem_disponible,max_chunk;
        if(doc.HasMember("memoria_disponible")){
            if(doc["memoria_disponible"].IsInt()){
                mem_disponible= doc["memoria_disponible"].GetInt();
            }
        }
        if(doc.HasMember("max_chunk")){
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
            }
        }
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





