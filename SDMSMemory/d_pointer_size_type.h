    #ifndef D_POINTER_SIZE_TYPE_H
#define D_POINTER_SIZE_TYPE_H
#include<dobject.h>
#include <iostream>
#include <QObject>
#include <dint.h>
#include <dchar.h>
#include <stdio.h>
#include <stdlib.h>

class d_pointer_size_type : public dObject
{
public:
    d_pointer_size_type();

    dInt getID() const;
    void setID(dInt value);
    dInt getReferences() const;
    void setReferences(dInt pReferences);

    void  print();//show the values of the variables

    void operator=(const d_pointer_size_type& obj);//overload the operator equals
    void operator=(const dObject& obj);//
    bool operator==(const d_pointer_size_type& obj);

    //both is olverload  for realize pointers arithmetic
    int operator++(int);
    int operator--(int);


    //set and get the pointer
    dInt getPuntero() const;
    void setPuntero(dInt value);

    //set and get size of the pointer
    dInt  getSize() const;
    void setSize(dInt value);

    //set and get datatype
    dChar getDataType() ;
    void setDataType(dChar value);


private:
    dInt* ID= (dInt*)calloc(1,2*sizeof(int));//dInt is assigned to the size of 8 Bytes
    dInt* puntero= (dInt*)calloc(1,2*sizeof(int));//puntero is assigned to the size of 8 Bytes
    dInt* size= (dInt*)calloc(1,2*sizeof(char));//size is assigned to the size of 2 Bytes
    dChar* dataType=(dChar*)calloc(1,sizeof(char));// dataType is assigned to the size of 1 Byte
    dInt* references=(dInt*)calloc(1,sizeof(char));// reference is assigned to the size of 1 Byte
    //d_pointer lack variable
};

#endif // D_POINTER_SIZE_TYPE_H
