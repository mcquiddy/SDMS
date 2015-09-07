#include <QCoreApplication>
#include <iostream>
#include <dint.h>
#include <dchar.h>
#include <dlong.h>
#include <darray.h>

char hola[7];
 int  main(int argc, char *argv[])
{
     QCoreApplication a(argc, argv);
   dInt p;
    p = 6;
    //char hola;
    //hola ='hola';
   // dLong b;
    //b=1520L;
   // dChar Saludo;
    //Saludo = 'O';

        dArray A;
        A[5];

      // std::cout << "Value of A[2] : " << A[2] <<endl;
 std::cout << "size of empty class: "  << A.x << "\n" ;

        return 0;

    //std:: cout<< p ;

    return a.exec();

}


