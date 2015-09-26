#ifndef DSTRING_H
#define DSTRING_H
#include <string>
#include <iostream>
#include <dobject.h>

class dString: public dObject
{
public:
    dString();
    dString& operator = (const string &p);

    dString& operator = ( const dString& p);
    string getDato();
    bool& operator==(const string& obj);
    bool& operator==(const dString& obj);
    friend void operator<<(ostream& os, const dString& dt);
    string* x = (string*)calloc(1,sizeof(int));
private:
int id;
};

#endif // DSTRING_H
