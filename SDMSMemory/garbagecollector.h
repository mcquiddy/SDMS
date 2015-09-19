#ifndef GARBAGECOLLECTOR_H
#define GARBAGECOLLECTOR_H
#include <d_pointer_size_type.h>
#include <linked_list.h>
#include <pthread.h>
#include <dobject.h>

class GarbageCollector : public dObject
{
public:
    GarbageCollector(lista<d_pointer_size_type*> *node);
    lista<d_pointer_size_type*> *nodes ;
    void run();
   static void* garbageManager(void *obj);
};

#endif // GARBAGECOLLECTOR_H
