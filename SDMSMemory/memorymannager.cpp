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



bystream MemoryMannager::obtenerDatoInt(d_pointer_size pPointerSize)
{
    bystream dato;
    int* puntero=(int*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        dato.status=0;
    }
    else{
        dato.status=1;
        dato.dataint=*puntero;

    }
    return dato;


}

bystream MemoryMannager::obtenerDatoChar(d_pointer_size pPointerSize)
{
    bystream dato;
    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        dato.status=0;
    }
    else{
        dato.status=1;
        dato.datachar=*puntero;

    }
    return dato;
}

bystream MemoryMannager::obtenerDatoFloat(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
}

bystream MemoryMannager::obtenerDatoBool(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
}

bystream MemoryMannager::obtenerDatoArrayInt(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
}

bystream MemoryMannager::obtenerDatoArrayChar(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
}

bystream MemoryMannager::obtenerDatoLong(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
}

bystream MemoryMannager::obtenerDatoDouble(d_pointer_size pPointerSize)
{
    bystream dato;
//    char* puntero=(char*)(cantidadMemoria+pPointerSize.pointer.dirMemory);
//    if(puntero==NULL){
//        dato.status=0;
//    }
//    else{
//        dato.status=1;
//        dato.datachar=*puntero;

//    }
    return dato;
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

int MemoryMannager::setearDatoChar(d_pointer_size pPointerSize, char pData)
{

    int status;
    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);
    if(puntero==NULL){
        status=0;
    }
    else{
        *puntero=pData;
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

d_estado MemoryMannager::status()
{
    cout<<" entro al estado "<<endl;
    d_estado estadoMemoria;
    int* puntero=(int*)(cantidadMemoria);
    int memoriaTotal=0;
    int chunkMemoria=0;
    int chunkMemoriaTemp=0;
    int count=0;
    while(count<memory){
        if(*puntero==0){
            chunkMemoriaTemp++;
             memoriaTotal++;
            chunkMemoria=chunkMemoriaTemp;
        }
        else{
            chunkMemoriaTemp=0;
        }

        count++;
        puntero=(int*)(cantidadMemoria+count);
    }
    estadoMemoria.biggerChunk=chunkMemoria;
    estadoMemoria.totalMemory=memoriaTotal;
    return estadoMemoria;

}

bool MemoryMannager::setMemory(int pSize)
{
    cantidadMemoria=calloc(pSize,sizeof(char));
    offset=pSize;
    memory=pSize;
    if(cantidadMemoria==NULL)
        return false;
    else
        return true;
}




