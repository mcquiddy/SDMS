#ifndef DLONG_H
#define DLONG_H
#include <dobject.h>
#include <iostream>

using namespace std;

class dLong: public dObject
{
public:
    dLong();
     dLong& operator = (const long &l);
     dLong& operator = (const dLong &l);
     bool& operator==(const long& obj);
     bool& operator==(const dLong& obj);
     friend void operator<<(ostream& os, const dLong& dl);
     long* x = (long*)calloc(1,sizeof(long));

};

#endif // DLONG_H
