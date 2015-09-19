#ifndef DINT_H
#define DINT_H
#include <iostream>
#include <dobject.h>


/**
 * se sobrecarga del operador igual(=)
 * */


class dInt: public dObject
{
public:
    dInt();

    dInt& operator = ( const int &p);
    bool& operator==(const int& obj);
    bool& operator==(const dInt& obj);
    void operator++(int );
    void operator--(int );
    int x;


     //void operator << (const dInt &p);
//private:


};

#endif // DINT_H

