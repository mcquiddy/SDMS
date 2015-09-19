#include "garbagecollector.h"



GarbageCollector::GarbageCollector(lista<d_pointer_size_type *> *node){

    this->nodes=node;
}






void GarbageCollector::run(){


    pthread_t hilo;
    pthread_create(&hilo,0,GarbageCollector::garbageManager,(void*)nodes);
    pthread_detach(hilo);
}

void* GarbageCollector::garbageManager(void *obj){
    lista<d_pointer_size_type*> *pInt = (lista<d_pointer_size_type*>*) obj;

    while (true){
        for(int i=1; i<=pInt->length();i++){
           if ( pInt->rove(i)->get_data()->getReferences()==0){
               pInt->delete_Pos(i);

           }
           cout<<pInt->length()<<"\n";
        }

    }
    pthread_exit(NULL);
}
