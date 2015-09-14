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
    string type;
    string data;
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
    string obtenerDato(string* pPointer);

  int setearDato(d_pointer_size pPointerSize, bystream pData);
   int setearDatoInt(d_pointer_size pPointerSize, int pData);
   int setearDatoChar(d_pointer_size pPointerSize, const char* pData);
   int setearDatoFloat(d_pointer_size pPointerSize, float pData);
   int setearDatoBool(d_pointer_size pPointerSize, bool pData);
   int setearDatoArrayInt(d_pointer_size pPointerSize, int* pData);
   int setearDatoArrayChar(d_pointer_size pPointerSize, char* pData);
   int setearDatoLong(d_pointer_size pPointerSize, long pData);
   int setearDatoDouble(d_pointer_size pPointerSize, double pData);

    string status();
    bool setMemory(int pSize);




};

#endif // MEMORYMANNAGER_H
