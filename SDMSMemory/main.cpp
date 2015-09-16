#include <QCoreApplication>
#include <iostream>
#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include <darray.h>

#include <pointer.h>
#include <d_pointer.h>
#include </home/geovanny/git/SDMS/SDMSMemory/d_pointer_size_type.h>
#include <dobject.h>


//#include "sdsmemorynode.h"
//#include "d_pointer_size_type.h"
#include "linked_list.h"

char hola[7];
 int  main()
{
 /*!
CODIGO DE SANTI  Y CRISTIAN!!!!!

SDSMemoryNode *nodeMemory=new SDSMemoryNode(2,'M',7008,7001);
       nodeMemory->~SDSMemoryNode();
   */

 /*    QCoreApplication a(argc, argv);
   dInt p;
    p = 6;
    char hola;
=======
    QCoreApplication a(argc, argv);
//    dInt p;
//    p = 6;
    SDSMemoryNode *nodeMemory=new SDSMemoryNode(2,'M',7008,7001);
    //char hola;
>>>>>>> 7849e36ecacc585635bdd5c2e041fd7e56e76686
    //hola ='hola';
   // dLong b;
    //b=1520L;
   // dChar Saludo;
    //Saludo = 'O';
<<<<<<< HEAD

       // dArray A[];
        //A[5];


      // std::cout << "Value of A[2] : " << A[2] <<endl;
 std::cout << "size of empty class: "  << p.x << "\n" ;
=======
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
>>>>>>> 7849e36ecacc585635bdd5c2e041fd7e56e76686

        //return 0;

    //std:: cout<< p ;


     //d_pointer<pointer> p(new pointer( 25));
 //    p->Display();
    d_pointer_size_type palabra;
    d_pointer_size_type  p;

    // p.setID(5);
   palabra.setPuntero(5);
   p.setPuntero(5);
   palabra==p;

    //return a.exec();
*/


             lista<d_pointer_size_type> pPointers;
             int i=0;
             while(i<=10){
                 d_pointer_size_type temp;
                 temp.setReferences(i);
                 pPointers.insert_head(temp);
                 cout<<temp.getReferences()<<"\n";
                 i++;
         }
             pPointers.print_list();

return 0;
 }


