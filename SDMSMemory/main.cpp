#include <QCoreApplication>
#include <iostream>
#include "dstring.h"
#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include <iostream>
#include <QtNetwork/QNetworkInterface>
#include <stdio.h>
#include <stdlib.h>
#include <dHeap.h>
#include <dobject.h>
#include "sdsmemorynode.h"
#include <ctime>
 #include <cstdio>

using namespace std;

 int  main(int argc, char *argv[])
 {

     QCoreApplication a(argc, argv);







//dString s;

//s="hola";

//cout<<s;

//     dHeap* heap=dHeap::getInstance();

//      heap->cargarNodos();
//dInt b;
//b=5;
//cout<<b;
//b++;
//cout<<b;
//b--;
//cout<<b;

//d_pointer_size_type* hola=NULL;
//heap->d_free(hola);
SDSMemoryNode *nodeMemory=new SDSMemoryNode(2,'M',7005,7001);
/*!
CODIGO DE SANTI  Y CRISTIAN!!!!!
>>>>>>> Stashed changes


=======
//
>>>>>>> 0bfc03cecd3bb36e7f3481b76e5c99b8a8422cfb

      // nodeMemory->~SDSMemoryNode();
    dHeap* heap=dHeap::getInstance();
    heap->cargarNodos();
    //SocketClienteHeap * prueba=new SocketClienteHeap(7008,"192.168.1.122");
    //prueba->connectar();

    dInt num;







//     dInt y,z;

<<<<<<< Updated upstream
//    int k=4;
//     y;
//     z=y;
//     dChar a,b,c;
//    char d='h';
//     a='a';

//     c='c';
//    b=d;
     //int & f;
=======

    dLong l;
    l=3.5;
     y=3;
     z=y;
     dChar a,b,c;
    //d_pointer_size_type x;

    char d='h';
     a='a';


     c='c';
    b=d;



      //int & f;
>>>>>>> Stashed changes
     //int u=5;
      //f=&u;
     //char* f;
     //f= (char*)malloc(5*sizeof(char) );
    //char* h =(char*)malloc(2);
    //free(f);
    //*f=5;
    //free(f);
   //cout<<sizeof(*y.x)<<"\n";
<<<<<<< Updated upstream
//     cout<<b;

     //dInt *x;
     //*x->x=5;
    // cout<<y;
=======
     //cout<<b;

     //dInt *x;
     //*x->x=5;
    //     cout<<y;
>>>>>>> Stashed changes


     // x++;//sobrecarga para dInt









             lista<d_pointer_size_type*> *pInt=new  lista<d_pointer_size_type*> ;
             d_pointer_size_type* temp1 = new d_pointer_size_type();
               dInt x;
               x=3;
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




    /*
              * Codigo para ejecutar dChar
             dChar x;
             x='2';
             cout<<x.x<<"\n";
              */





    //Codigo para Ejecutar Garbage Collector

 //     GarbageCollector *test = new GarbageCollector(pInt);
   //     test->run();
     //   while (true){
       // }


return a.exec();
 }


