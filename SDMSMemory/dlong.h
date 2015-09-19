#ifndef DLONG_H
#define DLONG_H
#include <dobject.h>
#include <iostream>

using namespace std;

class dLong: public dObject
{
public:
    dLong();
    long x;
     dLong& operator = (const long &l);
     dLong& operator = (const dLong &l);
     bool& operator==(const long& obj);
     bool& operator==(const dLong& obj);


};

#endif // DLONG_H
