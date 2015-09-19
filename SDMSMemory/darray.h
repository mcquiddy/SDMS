#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
#include <dobject.h>
#include <dint.h>
#include <dchar.h>
using namespace std;
const int SIZE = 10;

class dArray: public dObject
{

public:
    dArray();

    int x;
    dInt y;
    dChar z;




dArray& operator[](const int& i);
dArray& operator[](const dInt& i);
dArray& operator[](const dChar& i);


};



#endif // DARRAY_H
