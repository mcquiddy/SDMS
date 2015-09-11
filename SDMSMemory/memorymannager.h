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
int IPv4;
void* dirMemory;
};


class MemoryMannager
{
public:
    MemoryMannager();
       int memory;
       int direccion;
       void* cantidadMemoria;
   string pedirMemoria(string *pSize,string pDescriptor);
    string liberarMemoria(string* pPointer);
    string obtenerDato(string* pPointer);
    string setearDato(string* pPointer);
    string status();
    void setMemory(int pSize,void* pMemory);




};

#endif // MEMORYMANNAGER_H
