#include "memorymannager.h"

MemoryMannager::MemoryMannager(){}

d_pointer MemoryMannager::pedirMemoria(int pSize)
{
d_pointer NewDpointer;
NewDpointer.dirMemory=memory-offset;
offset=offset-pSize;

     if(offset<=0){
         cout<<"ERROR: -No se pudo hacer un d_calloc"<<endl;
         NewDpointer.status=false;
     return NewDpointer;
     }
     else{   
           NewDpointer.status=true;
           cout<<" resevacion con exito "<<endl;
            return NewDpointer;

   }




}

int MemoryMannager::liberarMemoria(d_pointer_size pPointerSize)
{
    int status;
    int* puntero =(int*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        status=0;
    }
    else{
        cout<<" dato liberado "<<*puntero<<endl;
        *puntero=0;
         cout<<" dato actual "<<*puntero<<endl;
        status=1;
    }
    return status;


}

string MemoryMannager::obtenerDato(string *pPointer)
{
    string descriptor= pPointer->substr(0,pPointer->find(DELIMITADOR));
 pPointer->erase(0,pPointer->find(DELIMITADOR)+1);
 string dirMemory= pPointer->substr(0,pPointer->find(DELIMITADOR));
pPointer->erase(0,pPointer->find(DELIMITADOR)+1);
string size=pPointer->substr(0,pPointer->find(DELIMITADOR));

istringstream buffer(dirMemory);
 int dirMemoryN;
 buffer >> dirMemoryN;
int * puntero=(int*)cantidadMemoria+dirMemoryN;
    if(puntero==NULL){
        cout<<" no se ecuentra"<<endl;
        return "2";

    }else{

        istringstream buffer(size);
         int sizeN;
         buffer >> sizeN;
 string retorno="0;";
  ostringstream id;



 cout<<"number  "<<*(puntero)<<" posicion "<<puntero<<endl;
     id<<*(puntero);

    retorno.append(id.str());



 cout<<" retorno  "<<retorno<<endl;
    return retorno;

    }



}

int MemoryMannager::setearDato(d_pointer_size pPointerSize, bystream pData)
{


int status;
if(pData.type=="char"){

     status= setearDatoChar(pPointerSize,pData);
}
else if(pData.type=="int"){

     status= setearDatoInt(pPointerSize,pData);
}
else if(pData.type=="bool"){

      status= setearDatoBool(pPointerSize,pData);
}
else if(pData.type=="float"){

      status= setearDatoFloat(pPointerSize,pData);

}
else if(pData.type=="arrayint"){

      status= setearDatoArrayInt(pPointerSize,pData);
}
else if(pData.type=="arraychar"){

      status= setearDatoArrayChar(pPointerSize,pData);
}
else if(pData.type=="long"){

      status= setearDatoLong(pPointerSize,pData);
}
else if(pData.type=="double"){

      status= setearDatoDouble(pPointerSize,pData);
}

return status;



}

int MemoryMannager::setearDatoInt(d_pointer_size pPointerSize, bystream pData)
{
    int status;
    //Parsear a int
    istringstream bufferN(pData.data);
     int dato;
     bufferN >> dato;
     int* puntero =(int*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
     if(puntero==NULL){
         status=0;
     }
     else{
         *puntero=dato;
         status=1;
     }
     return status;
}

int MemoryMannager::setearDatoChar(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a char
    const char* dato=pData.data.c_str();
    int status;
    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        status=0;
    }
    else{
        *puntero=dato;
        status=1;
    }
    return status;
}

int MemoryMannager::setearDatoFloat(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Float
    int status;
    return status;
}

int MemoryMannager::setearDatoBool(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Bool
    int status;
    return status;
}

int MemoryMannager::setearDatoArrayInt(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Arrray de enteros
    int status;
    return status;
}

int MemoryMannager::setearDatoArrayChar(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Array de chars
    int status;
    return status;
}

int MemoryMannager::setearDatoLong(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Long
    int status;
    return status;
}

int MemoryMannager::setearDatoDouble(d_pointer_size pPointerSize, bystream pData)
{
    //Parsear a Double
    int status;
    return status;
}

string MemoryMannager::status()
{

        ostringstream totalmemory;
        totalmemory<<memory;

    cout<<" total "<<totalmemory.str()<<endl;
    return totalmemory.str();
}

bool MemoryMannager::setMemory(int pSize)
{
    cantidadMemoria=malloc(pSize);
    offset=pSize;
    memory=pSize;
    if(cantidadMemoria==NULL)
        return false;
    else
        return true;
}




