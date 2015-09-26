#include "memorymannager.h"

MemoryMannager::MemoryMannager(){}
/*!
 * \brief MemoryMannager::pedirMemoria
 *        Reserva un determinado espacio de memoria.
 *
 * \param pSize:
 *        tamaño de memoria a reservar.
 * \return
 *      un struct con:
 *       La direccion de memoria.
 *       false, si esta ingresando en una direccion de memoria indebida.
 *       true,si se reservo la memoria correctamente.
 *
 */
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

/*!
 * \brief MemoryMannager::liberarMemoria
 *        Libera o setea a cero la direccion de memoria especificado
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa
 * \return
 *        0, si esta ingresando en una direccion indebida.
 *        1, si se libero correctamente
 */
int MemoryMannager::liberarMemoria(d_pointer_size pPointerSize)
{
    int status;
    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);

    if(puntero==NULL){
        status=0;
    }
    else{
        int i = 0;
            for (i = 0; i < pPointerSize.bytes; i++ )
            {
                if( char(*puntero)!=0 ){

                *puntero=0;

                }
                puntero=(char*)(cantidadMemoria + (pPointerSize.pointer.dirMemory+i));
            }
        status=1;
    }
    return status;


}


/*!
 * \brief MemoryMannager::obtenerDatoInt
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        int del dato.
 */
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
/*!
 * \brief MemoryMannager::obtenerDatoChar
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        char del dato.
 */
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

/*!
 * \brief MemoryMannager::obtenerDatoFloat
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        float del dato.
 */
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

/*!
 * \brief MemoryMannager::obtenerDatoBool
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        bool del dato.
 */
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

/*!
 * \brief MemoryMannager::obtenerDatoArrayInt
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        ArrayInt del dato.
 */
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
/*!
 * \brief MemoryMannager::obtenerDatoArrayChar
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        ArrayChar del dato.
 */
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

/*!
 * \brief MemoryMannager::obtenerDatoLong
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        long del dato.
 */
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

/*!
 * \brief MemoryMannager::obtenerDatoDouble
 *        obtiene el dato que esta reservando la direccion de memoria especificada.
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \return
 *        struct conformado por:
 *        int que es 0,si esta ingresando en una direccion indebida y 1,si se obtenio el dato correctamente.
 *        double del dato.
 */
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

bystream MemoryMannager::obtenerDatoString(d_pointer_size pPointerSize)
{
    bystream dato;

    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);

    if(puntero==NULL){
        dato.status=0;
    }
    else{
        dato.status=1;




           dato.dataString=dato.dataString.append(&(*puntero));



    }
    return dato;
}


/*!
 * \brief MemoryMannager::setearDatoInt
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo int a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
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
/*!
 * \brief MemoryMannager::setearDatoChar
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo char a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
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
/*!
 * \brief MemoryMannager::setearDatoFloat
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo float a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoFloat(d_pointer_size pPointerSize, float pData)
{

    int status;
    return status;
}

/*!
 * \brief MemoryMannager::setearDatoBool
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo bool a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoBool(d_pointer_size pPointerSize, bool pData)
{

    int status;
    return status;
}

/*!
 * \brief MemoryMannager::setearDatoArrayInt
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo ArrayInt a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoArrayInt(d_pointer_size pPointerSize, int* pData)
{

    int status;
    return status;
}

/*!
 * \brief MemoryMannager::setearDatoArrayChar
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo ArrayChar a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoArrayChar(d_pointer_size pPointerSize, char* pData)
{

    int status;
    return status;
}

/*!
 * \brief MemoryMannager::setearDatoLong
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo long a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoLong(d_pointer_size pPointerSize, long pData)
{

    int status;
    return status;
}

/*!
 * \brief MemoryMannager::setearDatoDouble
 *        Setea el dato en la posicion de memoria especificada
 * \param pPointerSize
 *        struct conformado por un int de la direccion de memoria y un int con el tamaño que ocupa.
 * \param pData
 *        dato de tipo double a setear en la memoria.
 *
 * \return
 *      0,si esta ingresando en una direccion de memoria indebida.
 *      1, si se guarda el dato correctamente.
 */
int MemoryMannager::setearDatoDouble(d_pointer_size pPointerSize, double pData)
{

    int status;
    return status;
}

int MemoryMannager::setearDatoString(d_pointer_size pPointerSize, string pData)
{
    int status;

    char* puntero =(char*)(cantidadMemoria + pPointerSize.pointer.dirMemory);

    if(puntero==NULL){
        status=0;
    }
    else{
        char* dato=(char*)pData.c_str();
        for(int i=0;i<=pPointerSize.bytes;i++){
            *(puntero +sizeof(char)*i)=dato[i];
}
        status=1;
    }
    return status;
}

/*!
 * \brief MemoryMannager::status
 *        recorre todas las posiciones de memoria verificando cual esta vacio y cual esta lleno
 * \return
 *       un struct con la total de memoria libre y el chunk de memoria libre mas grande
 */
d_estado MemoryMannager::status()
{
    cout<<" entro al estado "<<endl;
    d_estado estadoMemoria;
    char* puntero=(char*)(cantidadMemoria);
    int memoriaTotal=0;
    int chunkMemoria=0;
    int chunkMemoriaTemp=0;
    int count=0;
    while(count<memory){
        if(char(*puntero)==0){
            chunkMemoriaTemp++;
             memoriaTotal++;
            chunkMemoria=chunkMemoriaTemp;
        }
        else{
            chunkMemoriaTemp=0;
        }

        count++;
        puntero=(char*)(cantidadMemoria+count);
    }
    estadoMemoria.biggerChunk=chunkMemoria;
    estadoMemoria.totalMemory=memoriaTotal;
    return estadoMemoria;

}

/*!
 * \brief MemoryMannager::setMemory
 *        inicializa el malloc que reserva una cantidad de memoria especificada,
 *        inicializa dos int que guardaran el total de memoria reservado.
 * \param pSize
 *        tamaño de memoria a reservar
 * \return
 *       false, si la cantidad de memoria a reservar no se puede procesar
 *       true, si la cantidad de memoria se reservo correctamente
 */
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




