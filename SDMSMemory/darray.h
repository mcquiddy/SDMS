#ifndef DARRAY_H
#define DARRAY_H
#include <iostream>
using namespace std;
const int SIZE = 10;

class dArray
{

public:

    int x;


 dArray();

dArray& operator[](const int& i);
};



#endif // DARRAY_H
