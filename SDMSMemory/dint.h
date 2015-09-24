#ifndef DINT_H
#define DINT_H
#include <iostream>
#include <dobject.h>
#include <cstdio>
#include <cstdlib>

/**
 * dInt
 * */

using namespace std;

class dInt: public dObject

{
public:
    dInt();
    dInt& operator = (const int &p);
    dInt& operator = ( const dInt& p);
    bool& operator==(const int& obj);
    bool& operator==(const dInt& obj);
    void operator++(int );
    void operator--(int );
    friend void operator<<(ostream& os, const dInt& dt);
    int* x = (int*)calloc(1,sizeof(int));




};
#endif // DINT_H

