#ifndef MEMORYMANNAGER_H
#define MEMORYMANNAGER_H
#include <linked_list.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <Node.h>
#include <constants_SDSM.h>

using namespace std;
struct d_pointer{
    int dirMemory;
    bool status;
};
struct d_pointer_size{
    d_pointer pointer;
    int bytes;
};
struct bystream{
    int status;
    //tipos de datos
    float datafloat;
    int dataint;
    char datachar;
    bool databool;
    int* dataArrayint[];
    char* dataArraychar[];
    long datalong;
    double datadouble;


};
struct d_estado{
    int totalMemory;
    int biggerChunk;
};

class MemoryMannager
{
public:
    MemoryMannager();
int memory;
       int offset;
       void* cantidadMemoria;
    d_pointer pedirMemoria(int pSize);
    int liberarMemoria(d_pointer_size pPointerSize);

//Obtener diferentes tipod de datos
     bystream obtenerDatoInt(d_pointer_size pPointerSize);
     bystream obtenerDatoChar(d_pointer_size pPointerSize);
     bystream obtenerDatoFloat(d_pointer_size pPointerSize);
     bystream obtenerDatoBool(d_pointer_size pPointerSize);
     bystream obtenerDatoArrayInt(d_pointer_size pPointerSize);
     bystream obtenerDatoArrayChar(d_pointer_size pPointerSize);
     bystream obtenerDatoLong(d_pointer_size pPointerSize);
     bystream obtenerDatoDouble(d_pointer_size pPointerSize);

//Setear diferentes tipos de datos
   int setearDatoInt(d_pointer_size pPointerSize, int pData);
   int setearDatoChar(d_pointer_size pPointerSize, char pData);
   int setearDatoFloat(d_pointer_size pPointerSize, float pData);
   int setearDatoBool(d_pointer_size pPointerSize, bool pData);
   int setearDatoArrayInt(d_pointer_size pPointerSize, int* pData);
   int setearDatoArrayChar(d_pointer_size pPointerSize, char* pData);
   int setearDatoLong(d_pointer_size pPointerSize, long pData);
   int setearDatoDouble(d_pointer_size pPointerSize, double pData);

    d_estado status();
    bool setMemory(int pSize);




};

#endif // MEMORYMANNAGER_H
