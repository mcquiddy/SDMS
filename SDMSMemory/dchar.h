#ifndef DCHAR_H
#define DCHAR_H
#include <dobject.h>

class dChar: public dObject
{
public:
    dChar();
    bool& operator==(const char& obj);
    bool& operator==(const dChar& obj);
    void operator = (const char c);
    void operator = (const dChar c);
    friend void operator<<(ostream& os, const dChar& dc);

private:

char* x = (char*)calloc(1,sizeof(char));
};

#endif // DCHAR_H

