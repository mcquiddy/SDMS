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
class MemoryMannager
{
public:
    MemoryMannager();
       int memory;
    string pedirMemoria(string *pSize,string pDescriptor);
    string liberarMemoria(string* pPointer);
    string obtenerEspacio(string* pPointer);
    string setearEspacio(string* pPointer);
    string status();
    void setMemory(int pSize);
    Node<void*> *searchMemory(string pDirMemory);


 private:
     list <void*>   List_Memory;
};

#endif // MEMORYMANNAGER_H
