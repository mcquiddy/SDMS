#include <QCoreApplication>
#include <iostream>
#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include </home/geovanny/git/SDMS/SDMSMemory/darray.h>
#include <iostream>
#include <QtNetwork/QNetworkInterface>



#include </home/geovanny/git/SDMS/SDMSMemory/d_pointer_size_type.h>
#include <dobject.h>


#include "sdsmemorynode.h"
#include "d_pointer_size_type.h"
#include "linked_list.h"
#include <garbagecollector.h>


using namespace std;
char hola[7];
 int  main()
{





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

     dInt x,y,z;
     x=2;
     y=2;
     z=3;
     dChar a,b,c;
     a='a';
     b='b';
     c='a';


     // x++;//sobrecarga para dInt


     dArray g;

      g [5];








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

return 0;
 }


