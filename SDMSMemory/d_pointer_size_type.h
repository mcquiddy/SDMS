#ifndef D_POINTER_SIZE_TYPE_H
#define D_POINTER_SIZE_TYPE_H
#include<dobject.h>
#include <iostream>


class d_pointer_size_type  : public dObject
{
public:
    d_pointer_size_type();

    int getID() const;
    void setID(int value);


    void  print();

    void operator=(const d_pointer_size_type& obj);
    void operator=(const dObject& obj);
    void operator==(const d_pointer_size_type& obj);
    //void operator=(const example& obj);
    int getPuntero() const;
    void setPuntero(int value);

    int getSize() const;
    void setSize(int value);

    char *getDataType() const;
    void setDataType(char *value);

    int getReferences() const;
    void setReferences(int value);

private:
    int ID=0;
    int puntero=0;
    int size =0;
    char *dataType="int";
    int references;
    //dpointer pointer;




};

#endif // D_POINTER_SIZE_TYPE_H
