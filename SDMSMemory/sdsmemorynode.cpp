#include "sdsmemorynode.h"

/*!
 * \brief SDSMemoryNode::start
 *        Inicializa los puertos y el servidor
 * \param Puerto
 *        Puerto donde se comunica las ordenes
 * \param Puerto_status
 *        Puerto donde solo retorna informacion ya definida
 */
void SDSMemoryNode::start(int Puerto, int Puerto_status)
{
    this->puerto = new SocketServer(Puerto,this);
    this->puerto_status = new SocketServer(Puerto_status,this);

    SDSMemoryServer::start();
     this->informar("192.168.1.139",7090);


}

void SDSMemoryNode::actualizar()
{
    d_estado Estado=Manejador.status();
    cout<<Estado.totalMemory<<endl;


    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("nodo");
    writer.StartArray();
    writer.Int(id);
//    writer.Int(Manejador->get_memoria());
//    writer.Int(Manejador->get_freememory());
    writer.EndArray();
    writer.EndObject();

    cout<<s.GetString()<<endl;
    list_ClientStatus.print_list();
    Node<int> *temp=list_ClientStatus.get_head();
    while(temp!=NULL){
        puerto_status->sentMns(s.GetString(),temp->get_data());
        temp=temp->get_next();
    }


}



/*!
 * \brief SDSMemoryNode::d_calloc
 *        Envia un mensaje al puerto emisor el json que se construyo al llamar
 *        al manejador de memoria que reserva un espacio determinaod con pSize.
 *
 *
 * \param pSize
 *        tamaño de memoria a reservar.
 *
 */
void SDSMemoryNode::d_calloc(int pSize)
{
    d_pointer Dpointer= Manejador.pedirMemoria(pSize);
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_calloc");
    writer.String("status");
    writer.Bool(Dpointer.status);
    writer.String("direccion");
    writer.Int(Dpointer.dirMemory);


    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);

    d_status();
}

/*!
 * \brief SDSMemoryNode::d_free
 *       Envia un mensaje al puerto emisor con el json formado, al liberar un espacio de memoria
 * \param free
 *       struct conformado por un int que es el tamaño y una direccion a liberar.
 */
void SDSMemoryNode::d_free(d_pointer_size free)
{
    int status= Manejador.liberarMemoria(free);
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_free");
    writer.String("status");
    writer.Int(status);



    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);

    d_status();
}


/*!
 * \brief SDSMemoryNode::d_status
 *        Envia un json conformado por lo datos retornados del manejador de memoria al pedir el estado de la memoria, al puerto
 */
void SDSMemoryNode::d_status()
{
    d_estado estado=Manejador.status();
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_status");
    writer.String("memoria_disponible");
    writer.Int(estado.totalMemory);
    writer.String("max_chunk");
    writer.Int(estado.biggerChunk);
    writer.String("id");
    writer.Int(client);

    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);

}

/*!
 * \brief SDSMemoryNode::parseToInt
 *        Parsea un string a un int
 * \param pInt
 *        string a parsear
 * \return
 *       int del string parseado
 */
int SDSMemoryNode::parseToInt(string pInt)
{
    istringstream buffer(pInt);
    int num;
    buffer >> num;
    return num;
}

/*!
 * \brief SDSMemoryNode::parseDelimitador
 *       Obtiene el string que esta en un determinado delimitador que esta en el mensaje
 * \param pString
 *       Mensaje a obtener el dato, definido por el DELIMITADOR
 * \return
 *       Dato obtenido en el parseo
 */
string SDSMemoryNode::parseDelimitador(string* pString)
{

    string strData;
    strData=pString->substr(0,pString->find(DELIMITADOR));
    pString->erase(0,pString->find(DELIMITADOR)+1);
    return strData;

}

int SDSMemoryNode::getCliente(){return this->client;}

/*!
 * \brief SDSMemoryNode::SDSMemoryNode
 *         Define el total de bytes a reservar
 * \param cantidad
 *        Cantidad de memeoria a reservar
 * \param exponente
 *        exponente de memoria a reservar ya sea en G(gigas) o M(megas)
 * \param Puerto
 *        Puerto donde se comunica las ordenes
 * \param Puerto_status
 *        Puerto donde solo retorna informacion ya definida
 */
SDSMemoryNode::SDSMemoryNode(int cantidad, char exponente, int puerto, int puerto_status)
{

    this->client=-1;
    int size=cantidad;
    if(exponente=='M')
        size=size*1024*1024;
    else if(exponente=='G')
        size=size*1024*1024*1024;
    this->start(puerto,puerto_status);
    if(Manejador.setMemory(size))
        cout<<"Se reservaron: "<<size<<" bytes correctamente\n";
    else
        cout<<"ERROR: -No se reservó la memoria"<<endl;
}

/*!
 * \brief SDSMemoryNode::newClient
 *       Administra las conexiones de nuevos clientes al servidor
 * \param id
 *        id del nuevo cliente
 * \param Puerto
 *        Puerto donde se conecto
 */
void SDSMemoryNode::newClient(int id, int Puerto)
{
    if(Puerto==this->puerto->get_puerto()){
        if(this->client==-1){
            cout<<"Se ha conectado un cliente nuevo con el id: "<<id<<endl;
            this->client=id;
            this->puerto->busy(true);
        }
        else
            cout<<"ERROR: -Already have a client-"<<endl;
    }
    else if(Puerto==this->puerto_status->get_puerto()){
        cout<<"Se ha conectado un cliente status nuevo con el id: "<<id<<endl;
    }
    else
        cout<<"ERROR: -No se reconoce el puerto-"<<endl;
}


/**
 * @brief SDSMemoryNode::reciveMns
 *       Resive el mensaje que es un formato json, lo parsea y verifica cual orden es,despues
 *       de verificar la orden parsea los datos entrantes y llama al metodo especificado por
 *       la orden  o el protocolo.
 * @param mns
 *       Mensaje en formato json
 */
void SDSMemoryNode::reciveMns(char * message){

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
                 if(doc.HasMember("pSize")){
                 if(doc["pSize"].IsInt()){
                 int pSize= doc["pSize"].GetInt();
                 d_calloc(pSize);
                 }
                 }
               }

 //Si la orden o protocolo es d_status se llama a que retorne es estado de memoria
               else if(comando=="d_status"){
                   d_status();

               }
               else{
// Si no puede ser la orden de liberar memoria(d_free), obtener dato(d_get) o setear dato(d_set).
// todos estos ordenes ocupa el struc pointerSize
                  d_pointer_size pointerSize;
// obtiene la direcion de memoria del json y lo guarda en el pointerSize
                  if(doc.HasMember("dir")){
                  if(doc["dir"].IsInt()){
                   int pDir= doc["dir"].GetInt();
                   pointerSize.pointer.dirMemory=pDir;

}
                   }
// obtiene la tamaño de memoria del json y lo guarda en el pointerSize
                   if(doc.HasMember("pSize")){
                   if(doc["pSize"].IsInt()){
                   int pSize= doc["pSize"].GetInt();
                   pointerSize.bytes=pSize;
}
                   }


                   if(comando=="d_free"){

                        d_free(pointerSize);
                    }
                   else{

//Documento para en caso de que se quiera obtener el dato
                       StringBuffer s;
                       Writer<StringBuffer> writer(s);
                       writer.StartObject();
                       writer.String("dato");


                     int status;
                     bystream statusBystream;
//verifica el tipo que se va a setear o obtener
                      if(doc.HasMember("tipo")){
                      if(doc["tipo"].IsString()){
                      string tipo= doc["tipo"].GetString();

                           if(tipo=="char"){

                                 if(comando=="d_set"){
                                      if(doc.HasMember("dato")){
                                          if(doc["dato"].IsString()){
                                         //Parsear a char

                                           char pData =*(const_cast<char *>(doc["dato"].GetString()));
                                           status= Manejador.setearDatoChar(pointerSize,pData);
                                          }
                                      }

                                 }
                                if(comando=="d_get"){
                                    statusBystream=Manejador.obtenerDatoChar(pointerSize);
                                    writer.String(&(statusBystream.datachar));
                                    writer.String("tipo");
                                    writer.String("char");


                                 }


                           }
                           else if(tipo=="int"){

                                if(comando=="d_set"){
                                    if(doc.HasMember("dato")){
                                    if(doc["dato"].IsInt()){
                                     //Parsear a int
                                     int pData =doc["dato"].GetInt();
                                     status= Manejador.setearDatoInt(pointerSize,pData);
                                    }
                                    }
                                }
                               if(comando=="d_get"){

                                   statusBystream=Manejador.obtenerDatoInt(pointerSize);
                                   writer.Int(statusBystream.dataint);
                                   writer.String("tipo");
                                   writer.String("int");

                                }


                           }
                           else if(tipo=="string"){

                                if(comando=="d_set"){
                                    if(doc.HasMember("dato")){
                                    if(doc["dato"].IsString()){
                                     //Parsear a string
                                     string pData =doc["dato"].GetString();
                                     status= Manejador.setearDatoString(pointerSize,pData);
                                    }
                                    }
                                }
                               if(comando=="d_get"){

                                   statusBystream=Manejador.obtenerDatoString(pointerSize);
                                   writer.String(statusBystream.dataString.c_str());
                                   writer.String("tipo");
                                   writer.String("string");

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
                           if(comando=="d_set"){
                              d_set(status);

                           }
                          if(comando=="d_get"){
                              writer.String("status");
                              writer.Int(statusBystream.status);
                              writer.String("protocolo");
                              writer.String("d_get");
                              writer.EndObject();
                              const char* mensaje=s.GetString();
                              cout<<"Enviando... "<<mensaje<<endl;
                              puerto->sentMns(mensaje,client);

                           }


                      }}



                   }



               }
           }


       }

   }




/*!
 * \brief SDSMemoryNode::~SDSMemoryNode
 * cierra los puertos y los libera de la memoria
 */
SDSMemoryNode::~SDSMemoryNode(){
    puerto->closeSocket();
    puerto_status->closeSocket();
    delete this;
}


/*!
 * \brief SDSMemoryNode::d_set
 * Envia el json conformado por el estatus que se obtuvo al seteaer el dato, por mensaje al puerto emisor.
 * \param pStatus
 * 0, si el dato no se pudo setear ya que se estaba ingresando en una direccion de memoria indebida.
 * 1, si el dato se pudo guardar correctamente.
 */
void SDSMemoryNode::d_set(int pStatus)
{
    int status=pStatus;
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("protocolo");
    writer.String("d_set");
    writer.String("status");




    writer.Int(status);
    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);

}

void SDSMemoryNode::informar(char *IP, int puerto)
{
    cout<<"informando.."<<endl;
    string ip=getAddresss();
    SocketCliente *miCliente=new SocketCliente(puerto,IP);
    StringBuffer s;
    Writer<StringBuffer> writer(s);
    writer.StartObject();
    writer.String("id");
    writer.Int(this->id);
    writer.String("ip");
    writer.String(ip.c_str());
    writer.String("puerto");
    writer.Int(this->puerto->get_puerto());
    writer.String("status");
    writer.Int(puerto_status->get_puerto());
    writer.String("size");
    writer.Int(Manejador.memory);
    writer.EndObject();
    cout<<s.GetString()<<endl;
    if(miCliente->connectar()){
        try{
            miCliente->setMensaje(s.GetString());
        }
        catch (string ex){
            cout<<"ERROR: -no se envió mensaje-\n";
        }
    }
    else{
        cout<<"ERROR: -no se pudo conectar-\n";
    }
}



char *SDSMemoryNode::getAddresss()
{
    string ip="Error";
    struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("%s IP Address %s\n", ifa->ifa_name, addressBuffer);
            ip=addressBuffer;
            cout<<ip;

        }
        else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
        }
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
    return (char*)ip.c_str();
}
