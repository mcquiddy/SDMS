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
     void* puntero=malloc(sizeN);
     if(puntero==NULL){
         cout<<"ERROR: -No se pudo hacer un d_calloc"<<endl;
     return "1";
     }
     else{
memory-=sizeN;
         cout<<"Se ha reservado "<<sizeN<<" bytes de memoria"<<" en la direccion  "<<puntero<< " quedan "<<memory<<" de memoria "<<endl;

         List_Memory.insert_head(puntero);
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

   Node<void*>* search=searchMemory(dirMemory);

       if(search==NULL){
           cout<<" no se ecuentra"<<endl;
           return "1";

       }else{
           istringstream buffer(size);
            int sizeN;
            buffer >> sizeN;
            memory+=sizeN;
            free(search->get_data());
            cout<< " elimindado"<<endl;
             delete search;
            return "0";
       }





}

string MemoryMannager::obtenerEspacio(string *pPointer)
{
//    id= pComando->substr(0,pComando->find(DELIMITADOR));
//  pComando->erase(0,pComando->find(DELIMITADOR)+1);
//    posX= pComando->substr(0,pComando->find(DELIMITADOR));
//    pComando->erase(0,pComando->find(DELIMITADOR)+1);
//    posY= pComando->substr(0,pComando->find(DELIMITADOR));
//    pComando->erase(0,pComando->find(DELIMITADOR)+1);
    //        tipo= pComando->substr(0,pComando->find(DELIMITADOR));
}

string MemoryMannager::status()
{

        ostringstream totalmemory;
        totalmemory<<memory;

    cout<<" total "<<totalmemory.str()<<endl;
    return totalmemory.str();
}

void MemoryMannager::setMemory(int pSize)
{
    memory=pSize;
    cout<<" setear"<<memory<<"de  memoria"<<endl;
}

Node<void*> *MemoryMannager::searchMemory(string pDirMemory)
{
    Node<void*> *tmp=List_Memory.get_head();
    while(tmp!=NULL){
        stringstream buffer;


        buffer  << tmp->get_data();
        if(buffer.str()==pDirMemory){

             break;
        }else{
            tmp=tmp->get_next();
        }

    }
    if(tmp==NULL){
        return NULL;
    }
    else{
       return tmp;
    }
}
