    #ifndef D_POINTER_SIZE_TYPE_H
#define D_POINTER_SIZE_TYPE_H
#include <dobject.h>
#include <iostream>
#include <dint.h>
#include <dchar.h>
#include <stdio.h>
#include <stdlib.h>

class d_pointer_size_type
{
public:
    d_pointer_size_type();

    int getID() const;
    void setID(int value);
    int getReferences() const;
    void setReferences(int pReferences);

    void  print();//show the values of the variables

    void operator=(const d_pointer_size_type& obj);//overload the operator equals
    void operator=(const dObject& obj);//
    bool operator==(const d_pointer_size_type& obj);

    //both is olverload  for realize pointers arithmetic
    int operator++(int);
    int operator--(int);


    //set and get the pointer
    int *getPuntero() const;
    void setPuntero(int value);

    //set and get size of the pointer
    int  getSize() const;
    void setSize(int value);

    //set and get datatype
    char *getDataType() ;
    void setDataType(char *value);


private:
    int* ID= (int*)calloc(1,2*sizeof(int));//dInt is assigned to the size of 8 Bytes
    int* dirPuntero= (int*)calloc(1,2*sizeof(int));//puntero is assigned to the size of 8 Bytes
    int* size= (int*)calloc(1,2*sizeof(char));//size is assigned to the size of 2 Bytes
    char* dataType=(char*)calloc(1,sizeof(char));// dataType is assigned to the size of 1 Byte
    int* references=(int*)calloc(1,sizeof(char));// reference is assigned to the size of 1 Byte
    //d_pointer lack variable
};

#endif // D_POINTER_SIZE_TYPE_H
