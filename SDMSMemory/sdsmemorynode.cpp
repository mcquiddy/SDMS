#include "sdsmemorynode.h"
/**
 * @brief SDSMemoryNode::SDSMemoryNode
 * @param Cantidad
 * @param exponente
 * @param puerto
 * @param puerto_status
 */

void SDSMemoryNode::start(int Puerto, int Puerto_status)
{
    this->puerto = new SocketServer(Puerto,this);
    this->puerto_status = new SocketServer(Puerto_status,this);
    SDSMemoryServer::start();
}

d_pointer SDSMemoryNode::Parse_dpinter(Document mns){
    assert(mns.IsObject());
    d_pointer new_dpointer;
    new_dpointer.dirMemory=mns["address"].GetInt();

    //new_dpointer.flag_espacio=mns["espacio"].GetBool();
    return new_dpointer;

}
d_pointer_size SDSMemoryNode::Parse_dpinter_size(Document mns){
    d_pointer_size new_dpointersize;
    return new_dpointersize;

}

void SDSMemoryNode::d_calloc(int pSize)
{
    d_pointer Dpointer= Manejador.pedirMemoria(pSize);
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("status");
    writer.Bool(Dpointer.status);
    writer.String("direccion");
    writer.Int(Dpointer.dirMemory);


    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);
}

void SDSMemoryNode::d_status()
{
    Manejador.status();
}

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
 * @param mns
 */
void SDSMemoryNode::reciveMns(string message){
    string comando;
    //cout<<" protocolo "<<mensaje<<" tamano "<<mensaje.length()<<endl;
    comando = message->substr(0,message->find(DELIMITADOR));
    message->erase(0,message->find(DELIMITADOR)+1);

    if(comando=="d_calloc"){
        string strPsize;
        strPsize= message->substr(0,message->find(DELIMITADOR));
        istringstream buffer(strPsize);
        int pSize;
        buffer >> pSize;
        d_calloc(pSize);
    }

    else if(comando=="d_set"){
        string strPsize;
        string strDir;
        string strData;
        strDir=message->substr(0,message->find(DELIMITADOR));
        message->erase(0,message->find(DELIMITADOR)+1);
        strPsize= message->substr(0,message->find(DELIMITADOR));
        message->erase(0,message->find(DELIMITADOR)+1);
         strData= message->substr(0,message->find(DELIMITADOR));
        istringstream buffer(strPsize);
        int pSize;
        buffer >> pSize;
        istringstream bufferDir(strDir);
        int pDir;
        bufferDir >> pDir;
        d_pointer_size pointerSize;
        pointerSize.bytes=pSize;
        pointerSize.pointer.dirMemory=pDir;
        istringstream bufferData(strData);
        int pData;
        bufferData >> pData;
        d_set(pointerSize,pData);


    }

    else if(comando=="d_status"){
        d_status();

    }
    else{
        string strPsize;
        string strDir;
        strDir=message->substr(0,message->find(DELIMITADOR));
        message->erase(0,message->find(DELIMITADOR)+1);
        strPsize= message->substr(0,message->find(DELIMITADOR));
        istringstream buffer(strPsize);
        int pSize;
        buffer >> pSize;
        istringstream bufferDir(strDir);
        int pDir;
        bufferDir >> pDir;
        d_pointer_size pointerSize;
        pointerSize.bytes=pSize;
        pointerSize.pointer.dirMemory=pDir;
        if(comando=="d_get"){
            d_get(pointerSize);
        }
        if(comando=="d_free"){

            d_free(pointerSize);
        }
    }


//    char buffer[sizeof(mns)];
//    memcpy(buffer, mns, sizeof(mns));
//   if (doc.ParseInsitu(buffer).HasParseError())
//           cout<<"ERROR"<<endl;
//   ////////////////////////////////////////////////////////////////////////////
//    // 2. Access values in document.

//   cout<<"\nAccess values in document:\n";
//   assert(doc.IsObject());    // Document is a JSON value represents the root of DOM. Root can be either an object or array.

//   assert(doc.HasMember("hello"));
//   assert(doc["hello"].IsString());
//   cout<<"hello "<< doc["hello"].GetString()<<endl;
//   cout<<" puntero  "<<endl;
}

SDSMemoryNode::~SDSMemoryNode(){
    puerto->closeSocket();
    puerto_status->closeSocket();
    delete this;
}



void SDSMemoryNode::d_set(d_pointer_size pSet, int pData)
{
    int status= Manejador.setearDato(pSet,pData);
    StringBuffer s;
    Writer<StringBuffer> writer(s);

    writer.StartObject();
    writer.String("status");
    writer.Int(status);



    writer.EndObject();
    const char* mensaje=s.GetString();
    cout<<"Enviando... "<<mensaje<<endl;
    puerto->sentMns(mensaje,client);

}
