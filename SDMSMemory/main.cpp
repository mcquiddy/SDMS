#include <QCoreApplication>
#include <iostream>

#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include <iostream>
#include <QtNetwork/QNetworkInterface>
#include <stdio.h>
#include <stdlib.h>



#include <dobject.h>


#include "sdsmemorynode.h"
#include "d_pointer_size_type.h"
#include "linked_list.h"
#include <garbagecollector.h>
#include "dHeap.h"
#include "socketclienteHeap.h"


using namespace std;
char hola[7];
 int  main(int argc, char *argv[])
 {

     QCoreApplication a(argc, argv);


//SDSMemoryNode *nodeMemory=new SDSMemoryNode(2,'M',7008,7001);

      // nodeMemory->~SDSMemoryNode();
    dHeap* heap=dHeap::getInstance();
    heap->cargarNodos();
    //SocketClienteHeap * prueba=new SocketClienteHeap(7008,"192.168.1.122");
    //prueba->connectar();

    dInt num;







//     dInt y,z;

//    int k=4;
//     y;
//     z=y;
//     dChar a,b,c;
//    char d='h';
//     a='a';

//     c='c';
//    b=d;
     //int & f;
     //int u=5;
      //f=&u;
     //char* f;
     //f= (char*)malloc(5*sizeof(char) );
    //char* h =(char*)malloc(2);
    //free(f);
    //*f=5;
    //free(f);
   //cout<<sizeof(*y.x)<<"\n";
//     cout<<b;

     //dInt *x;
     //*x->x=5;
    // cout<<y;


     // x++;//sobrecarga para dInt





/*




             lista<d_pointer_size_type*> *pInt=new  lista<d_pointer_size_type*> ;
             d_pointer_size_type* temp1 = new d_pointer_size_type();

             temp1->setPuntero(x);
             temp1->setID(x);
             temp1->setReferences(x);
             (*temp1)--;
             d_pointer_size_type* temp2 = new d_pointer_size_type();
             temp2->setID(y);
             temp2->setPuntero(y);
             pInt->insert_head(temp1);
             pInt->insert_tail(temp2);


             // cout<<(pInt->get_head()->get_data()->getPuntero().x==pInt->get_head()->get_data()->getPuntero().x)<<"\n";


  */

    /*
              * Codigo para ejecutar dChar
             dChar x;
             x='2';
             cout<<x.x<<"\n";
              */





    /*Codigo para Ejecutar Garbage Collector
     * GarbageCollector *test = new GarbageCollector(pInt);
        test->run();
       while (true){

        }
      */

return a.exec();
 }


