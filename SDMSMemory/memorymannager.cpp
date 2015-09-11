#include "memorymannager.h"

MemoryMannager::MemoryMannager()
{
}

string MemoryMannager::pedirMemoria(string *pSize,string pDescriptor)
{
string size=pSize->substr(0,pSize->length());
    istringstream buffer(size);
     int sizeN;
     buffer >> sizeN;
     int* puntero=(int*)cantidadMemoria+direccion;
     int **p=&puntero;

     cout<<" puntero "<<puntero<<" second "<<*p<<endl;
     if(puntero==NULL){
         cout<<"ERROR: -No se pudo hacer un d_calloc"<<endl;
     return "1";
     }
     else{
memory-=sizeN;
stringstream bufferstr;


bufferstr  << puntero;
istringstream bufferDIr(bufferstr.str());
 int dirMemoryN;
 bufferDIr >> dirMemoryN;
direccion+=dirMemoryN;
         cout<<"Se ha reservado "<<sizeN<<" bytes de memoria"<<" en la direccion  "<<puntero<< " quedan "<<memory<<" de memoria "<<endl;


          string retorno="0;";
          retorno.append(pDescriptor);
          retorno.append(";");
         stringstream buffer;


         buffer  << puntero;

        retorno.append(buffer.str());
         retorno.append(";");
         cout<<" retorno "<<retorno<<endl;
return retorno;

   }




}

string MemoryMannager::liberarMemoria(string *pPointer)
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
            cout<<" direcion "<<puntero<<"ndo dir "<<*puntero<<endl;
           *puntero=NULL;


        istringstream  buffersize(size);
            int sizeN;
            buffersize >> sizeN;
            memory+=sizeN;


            cout<< " elimindado"<<endl;



            return "0";
       }





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

string MemoryMannager::setearDato(string *pPointer)
{
    string descriptor= pPointer->substr(0,pPointer->find(DELIMITADOR));
 pPointer->erase(0,pPointer->find(DELIMITADOR)+1);
 string dirMemory= pPointer->substr(0,pPointer->find(DELIMITADOR));
pPointer->erase(0,pPointer->find(DELIMITADOR)+1);
string size=pPointer->substr(0,pPointer->find(DELIMITADOR));
pPointer->erase(0,pPointer->find(DELIMITADOR)+1);

string dato=pPointer->substr(0,pPointer->find(DELIMITADOR));
istringstream buffer(dirMemory);
 int dirMemoryN;
 buffer >> dirMemoryN;
 cout<<" direccion "<<direccion<<" and "<<dirMemoryN<<" o "<<dirMemory<<endl;
int * puntero=(int*)cantidadMemoria;
    if(puntero==NULL){
        cout<<" no se ecuentra"<<endl;
        return "2";

    }else{
         cout<<" direcion "<<puntero<<"ndo dir "<<*puntero<<endl;
         istringstream buffer(size);
          int sizeN;
          buffer >> sizeN;


 cout<<" xxxxxxxxxxxxxxxxxx "<<  *(puntero)<<endl;

      istringstream bufferData(dato);
       int dataN;
       bufferData >> dataN;


     *puntero=dataN;
        cout<<" dato "<<  *(puntero)<<" pos "<<puntero<<endl;






         return "0";
    }


}

string MemoryMannager::status()
{

        ostringstream totalmemory;
        totalmemory<<memory;

    cout<<" total "<<totalmemory.str()<<endl;
    return totalmemory.str();
}

void MemoryMannager::setMemory(int pSize,void* pMemory)
{
    direccion=0;
    memory=pSize;
    cantidadMemoria=pMemory;
    cout<<" setear"<<memory<<"de  memoria"<<endl;
}




