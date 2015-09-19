#include "darray.h"

dArray::dArray()
{
   struct dArray;
}


dArray& dArray::operator[](const int& a){

    this->x = a;
    //std::cout<<a <"/n";
     return *this;

}
dArray& dArray::operator[](const dInt& a){

    this->y = a;
    //std::cout<<a <<"/n";
     return *this;

}

dArray& dArray::operator[](const dChar& a){

    this->z = a;
    //std::cout<<a <<"/n";
     return *this;

}



