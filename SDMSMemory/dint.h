#ifndef DINT_H
#define DINT_H
#include <iostream>


/*!
 * se sobrecarga del operador igual(=)
 * */

class dInt
{
public:
    dInt();
    int x;
    dInt& operator = (const int &p);

     //void operator << (const dInt &p);
private:

};

#endif // DINT_H

