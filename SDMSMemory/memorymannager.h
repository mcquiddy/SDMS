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


class MemoryMannager
{
public:
    MemoryMannager();
int memory;
       int offset;
       void* cantidadMemoria;
    d_pointer pedirMemoria(int pSize);
    string liberarMemoria(string* pPointer);
    string obtenerDato(string* pPointer);

    string setearDato(d_pointer_size pPointerSize, int pData);
    string status();
    bool setMemory(int pSize);




};

#endif // MEMORYMANNAGER_H
