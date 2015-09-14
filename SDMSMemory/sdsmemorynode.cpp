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

d_pointer SDSMemoryNode::Parse_dpinter(string mns){
//    assert(mns.IsObject());
    d_pointer new_dpointer;
//    new_dpointer.dirMemory=mns["address"].GetInt();

    //new_dpointer.flag_espacio=mns["espacio"].GetBool();
    return new_dpointer;

}
d_pointer_size SDSMemoryNode::Parse_dpinter_size(char* mns){




    d_pointer_size pointerSize;


    return pointerSize;

}

bystream SDSMemoryNode::Parse_bystream(Document doc)
{


//    string strData;
//    string strType;
//    strData=parseDelimitador(mns);
//    strType= parseDelimitador(mns);
    bystream Dato;
//    Dato.data=strData;
//    Dato.type=strType;
    return Dato;

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

void SDSMemoryNode::d_free(d_pointer_size free)
{
    int status= Manejador.liberarMemoria(free);
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

void SDSMemoryNode::d_get(d_pointer_size get)
{

}

void SDSMemoryNode::d_status()
{
    Manejador.status();
}

int SDSMemoryNode::parseToInt(string pInt)
{
    istringstream buffer(pInt);
    int num;
    buffer >> num;
    return num;
}

string SDSMemoryNode::parseDelimitador(string* pString)
{

    string strData;
    strData=pString->substr(0,pString->find(DELIMITADOR));
    pString->erase(0,pString->find(DELIMITADOR)+1);
    return strData;

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
void SDSMemoryNode::reciveMns(char * message){

    cout<<message<<endl;
    Document doc;
    doc.ParseInsitu(message);
    assert(doc.IsObject());
    assert(doc.HasMember("protocolo"));
    assert(doc["protocolo"].IsString());


    string comando;
    comando=doc["protocolo"].GetString();
    if(comando=="d_calloc"){
      assert(doc.HasMember("pSize"));
      assert(doc["pSize"].IsInt());
      int pSize= doc["pSize"].GetInt();
      d_calloc(pSize);
    }


    else if(comando=="d_status"){
        d_status();

    }
    else{

        assert(doc.HasMember("dir"));
        assert(doc["dir"].IsInt());
        int pDir= doc["dir"].GetInt();

        assert(doc.HasMember("pSize"));
        assert(doc["pSize"].IsInt());
        int pSize= doc["pSize"].GetInt();


        d_pointer_size pointerSize;
        pointerSize.bytes=pSize;
        pointerSize.pointer.dirMemory=pDir;

       if(comando=="d_set"){
          int status;
           assert(doc.HasMember("tipo"));
           assert(doc["tipo"].IsString());
           string tipo= doc["tipo"].GetString();
            assert(doc.HasMember("dato"));

           if(tipo=="char"){
               assert(doc["dato"].IsString());
              //Parsear a char
                const char* pData =doc["dato"].GetString();
                status= Manejador.setearDatoChar(pointerSize,pData);
           }
           else if(tipo=="int"){
               assert(doc["dato"].IsInt());
                //Parsear a int
                int pData =doc["dato"].GetInt();
                status= Manejador.setearDatoInt(pointerSize,pData);
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
            d_set(pointerSize,status);

        }
       if(comando=="d_get"){

        d_get(pointerSize);
        }
       if(comando=="d_free"){

            d_free(pointerSize);
        }
    }


}

SDSMemoryNode::~SDSMemoryNode(){
    puerto->closeSocket();
    puerto_status->closeSocket();
    delete this;
}



void SDSMemoryNode::d_set(d_pointer_size pSet, int pStatus)
{
    int status=pStatus;
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
