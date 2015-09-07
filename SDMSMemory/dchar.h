#ifndef DCHAR_H
#define DCHAR_H

class dChar
{
public:
    dChar();

    char x;
    int y;

     dChar& operator = (const char &c);
};

#endif // DCHAR_H
