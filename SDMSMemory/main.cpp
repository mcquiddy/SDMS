#include <QCoreApplication>
#include <iostream>
#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include <darray.h>
#include "sdsmemorynode.h"

char hola[7];
 int  main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    dInt p;
//    p = 6;
    SDSMemoryNode *nodeMemory=new SDSMemoryNode(2,'M',7008,7001);
    //char hola;
    //hola ='hola';
   // dLong b;
    //b=1520L;
   // dChar Saludo;
    //Saludo = 'O';
//{ \"protocolo\" : \"d_calloc\", \"pSize\" : 2 }
//        dArray A;
//        A[5];
        string i;
        while(i!="close"){
            cin>>i;
        }
        nodeMemory->~SDSMemoryNode();

      // std::cout << "Value of A[2] : " << A[2] <<endl;
 //std::cout << "size of empty class: "  << A.x << "\n" ;

        //return 0;

    //std:: cout<< p ;

    return a.exec();

}


