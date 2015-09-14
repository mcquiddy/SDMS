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

string MemoryMannager::liberarMemoria(string *pPointer)
{
return "";


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

string MemoryMannager::setearDato(d_pointer_size pPointerSize, int pData)
{
void* puntero=(int*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
*puntero=pData;



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




