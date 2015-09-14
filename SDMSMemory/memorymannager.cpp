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


return status;



}

int MemoryMannager::setearDatoInt(d_pointer_size pPointerSize, int pData)
{
    int status;

     int* puntero =(int*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
     if(puntero==NULL){
         status=0;
     }
     else{
         *puntero=pData;
         status=1;
     }
     return status;
}

int MemoryMannager::setearDatoChar(d_pointer_size pPointerSize, const char* pData)
{

    int status;
    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        status=0;
    }
    else{
        *puntero=*(const_cast<char *>(pData));
        status=1;
    }
    return status;
}

int MemoryMannager::setearDatoFloat(d_pointer_size pPointerSize, float pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoBool(d_pointer_size pPointerSize, bool pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoArrayInt(d_pointer_size pPointerSize, int* pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoArrayChar(d_pointer_size pPointerSize, char* pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoLong(d_pointer_size pPointerSize, long pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoDouble(d_pointer_size pPointerSize, double pData)
{

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




