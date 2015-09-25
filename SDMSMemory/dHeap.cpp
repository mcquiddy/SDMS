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
#include "Node.h"


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
    list_dpointer=new lista< d_pointer_size_type *>();
    contadorID=0;
    getPointer= new Pointer();
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
    if (!doc.load_file("/home/mcquiddy/git/SDMS/config.xml")){
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
         newNodeXML("172.19.12.21",7008,7001);
         cout<<"Carga completa"<<endl;

    }
}

int dHeap::cargarPuerto(char *port)
{
    pugi::xml_document doc;
    if (!doc.load_file("/home/mcquiddy/git/SDMS/config.xml")){
        cout<<"Error al cargar xml\n";
        return -1;
    }
    pugi::xml_node root=doc.first_child();
    cout<<root.child("Puertos").attribute(port).value()<<endl;
    return atoi(root.child("Puertos").attribute(port).value());

}

void dHeap::newNodeXML(char *ip, int puerto, int status)
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
void dHeap::d_set(Pointer pointer){

    d_pointer_size_type* puntero=this->searchDpointer(pointer.id);
    if(puntero!=NULL){


    StringBuffer s;
    Writer<StringBuffer> writer(s);
    char tipo = puntero->getDataType();
    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_set");
     writer.String("pSize");
     writer.Int(puntero->getSize());
     writer.String("dir");
     writer.Int(puntero->getPuntero());
    writer.String("dato");
    //CHAR
    if(tipo=='C'){

        writer.String((char*)(pointer.datachar));
        writer.String("tipo");
        writer.String("char");
    }
    //INTEGER
    else if(tipo=='I'){
        writer.Int(pointer.dataint);
        writer.String("tipo");
        writer.String("int");
    }
    //BOLEANO
    else if(tipo=='B'){
        writer.Bool(pointer.databool);
        writer.String("tipo");
        writer.String("bool");
    }
    //FLOAT
    else if(tipo=='F'){

    }
    //ARRAY INT
    else if(tipo=='N'){

    }
    //ARRAY CHAR
    else if(tipo=='M'){

    }
    //LONG
    else if(tipo=='L'){

    }
    //DOUBLE
    else if(tipo=='D'){

    }

    writer.EndObject();

    cout<<" d_set "<<s.GetString()<<endl;
   list_nodos->get_head()->get_data()->puerto->setMensaje(s.GetString());

    }

}
/*!
 * \brief dHeap::d_calloc
 * \param pSize
 */
void dHeap::d_calloc(int pSize){
    cout<<" de calooc "<<endl;
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
void dHeap::d_free(d_pointer_size_type *toFree){
    toFree=list_dpointer->get_head()->get_data();
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_free");
    writer.String("dir");
    writer.Int(toFree->getPuntero());
    writer.String("pSize");
    writer.Int(toFree->getSize());
    writer.EndObject();
    cout<<" d_free"<<s.GetString()<<endl;
   list_nodos->get_head()->get_data()->puerto->setMensaje(s.GetString());
}
/*!
 * \brief dHeap::d_get
 * \param toGet
 */
Pointer* dHeap::d_get(Pointer pointer){
    d_pointer_size_type* puntero=this->searchDpointer(pointer.id);
    if(puntero!=NULL){


    StringBuffer s;
    Writer<StringBuffer> writer(s);
    char tipo = puntero->getDataType();
    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_get");
     writer.String("pSize");
     writer.Int(puntero->getSize());
     writer.String("dir");
     writer.Int(puntero->getPuntero());
    writer.String("tipo");
    //CHAR
    if(tipo=='C'){

        writer.String("char");
    }
    //INTEGER
    else if(tipo=='I'){

        writer.String("int");
    }
    //BOLEANO
    else if(tipo=='B'){

        writer.String("bool");
    }
    //FLOAT
    else if(tipo=='F'){

    }
    //ARRAY INT
    else if(tipo=='N'){

    }
    //ARRAY CHAR
    else if(tipo=='M'){

    }
    //LONG
    else if(tipo=='L'){

    }
    //DOUBLE
    else if(tipo=='D'){

    }

    writer.EndObject();

    cout<<" d_get "<<s.GetString()<<endl;
   list_nodos->get_head()->get_data()->puerto->setMensaje(s.GetString());
   cout<<" entro while dato "<<endl;
   flag_dget=true;
   while(flag_dget){
       cout<<" obteniendo dato"<<endl;

   }
   cout<<" salio while dato "<<endl;
   return getPointer;

    }

}
/*!
 * \brief dHeap::dMalloc
 * \param size
 * \param type
 */

d_pointer_size_type* dHeap::dMalloc(int size, char *type){

    d_pointer_size_type * pointer=new d_pointer_size_type();
     cout<<" d malloc "<<endl;
    pointer->setDataType(*(type));
cout<<" d type "<<endl;
    pointer->setSize(size);

    pointer->setID(contadorID);

    contadorID++;
    d_calloc(size);
    cout<<" entro while "<<endl;
    while(flag_dirpointer){
        cout<<" reservando memoria "<<endl;

    }
    cout<<" salio while "<<endl;
    cout<<" id malloc "<<contadorID<<endl;
    cout<<" tipo mallos "<<*(type)<<endl;
    cout<<" id malloc pointer "<<pointer->getID()<<endl;
    cout<<" tipo malloc pointer "<<pointer->getDataType()<<endl;
    pointer->setPuntero(dirPointer);

    return pointer;

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
/*!
 * \brief dHeap::searchDpointer
 * busca en la lista de d_pointer_sizy_tipe, el que consida con el id
 * \param pID
 * \return
 */
d_pointer_size_type *dHeap::searchDpointer(int pID)
{
    cout<<" search "<<endl;
    Node<d_pointer_size_type *>* temp=this->list_dpointer->get_head();

    while(temp!=NULL){
         cout<<" id search "<<temp->get_data()->getID()<<endl;
         cout<< " id parametro " <<pID<<endl;
        if(temp->get_data()->getID()==pID){
            break;
        }
        else{
            temp=temp->get_next();
        }
    }
    cout<<" salio del search "<<endl;

    if(temp==NULL){
        return NULL;
    }
    else{
         return temp->get_data();
    }


}

int dHeap::newDpointerSize(int size, char* type)
{
    d_pointer_size_type* direccion=this->dMalloc(size,type);
    list_dpointer->insert_head(direccion);
    cout<<" id dpointer "<<direccion->getID()<<endl;
       cout<<" id dpointer lista  "<<list_dpointer->get_head()->get_data()->getID()<<endl;
    return direccion->getID();
}

void dHeap::checkcalloc(bool status, int direccion)
{
    if(status==true){
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

void dHeap::checkfree(int status)
{
    if(status==1){
        cout<<" memoria liberada "<<endl;
    }
    else{
        cout<<" no se pudo liberar "<<endl;
    }

}

void dHeap::checkset(int status)
{
    if(status=1){
        cout<<" dato seteado correctamente"<<endl;
    }
    else{
        cout<<" no se pudo setear"<<endl;
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

    cout<<" recibe heap "<<message<<endl;
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
        bool status;
         int direccion;
        if(doc.HasMember("status")){
            if(doc["status"].IsBool()){
                status= doc["status"].GetBool();
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
        string tipo;
        if(doc.HasMember("status")){
            if(doc["status"].IsInt()){
                status= doc["status"].GetInt();
            }

            if(doc.HasMember("tipo")){
                if(doc["tipo"].IsString()){
                    tipo= doc["tipo"].GetString();
                }
            //verifica el tipo que se obtuvo
            if(tipo=="char"){
                if(doc.HasMember("dato")){
                    if(doc["dato"].IsString()){
                        //Parsear a char
                        char pData =*(const_cast<char *>(doc["dato"].GetString()));
                        getPointer->datachar=pData;

                    }
                }
            }
            else if(tipo=="int"){
                if(doc["dato"].IsInt()){
                    //Parsear a char
                    int pData =doc["dato"].GetInt();
                    getPointer->dataint=pData;

                }
                }
                else if(tipo=="bool"){
                    //Parsear a bool
                    //status= Manejador.setearDatoBool(pointerSize,pData);
                }
                else if(tipo=="float"){
                    //parsear a float
                    // status= Manejador.setearDatoFloat(pointerSize,pData);
                }
                else if(tipo=="arrayint"){
                    //parsear a arreglo de int
                    // status= Manejador.setearDatoArrayInt(pointerSize,pData);
                }
                else if(tipo=="arraychar"){
                    //Parsear a arreglos de char
                    //status= Manejador.setearDatoArrayChar(pointerSize,pData);
                }
                else if(tipo=="long"){
                    //Parsear a long
                    // status= Manejador.setearDatoLong(pointerSize,pData);
                }
                else if(tipo=="double"){
                    //Parsear a double
                    // status= Manejador.setearDatoDouble(pointerSize,pData);
                }
            }
        }

        flag_dget=false;
    }
    else{
        int status;
        if(doc.HasMember("status")){
            if(doc["status"].IsInt()){
                status= doc["status"].GetInt();
            }
            if(comando == "d_free"){
                checkfree(status);
            }
            else if(comando == "d_set"){
                checkset(status);
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





