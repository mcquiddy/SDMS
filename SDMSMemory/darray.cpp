#include "darray.h"

dArray::dArray()
{
   struct dArray;
}


dArray& dArray::operator[](const int& a){

    this->x = a;
    //std::cout<<a <<"/n";
     return *this;

}



