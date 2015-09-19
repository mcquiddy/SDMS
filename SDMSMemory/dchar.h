#ifndef DCHAR_H
#define DCHAR_H
#include <dobject.h>

class dChar: public dObject
{
public:
    dChar();

    char x;

bool& operator==(const char& obj);
bool& operator==(const dChar& obj);
     dChar& operator = (const char &c);
     dChar& operator = (const dChar &c);


};

#endif // DCHAR_H

