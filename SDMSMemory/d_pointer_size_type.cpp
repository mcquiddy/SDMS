#include "d_pointer_size_type.h"


d_pointer_size_type::d_pointer_size_type()
{


}
int d_pointer_size_type::getID() const
{
    return ID;
}

void d_pointer_size_type::setID(int value)
{
    ID = value;
}

void d_pointer_size_type::print()
{
    std::cout<< ID << "\n";
}

void d_pointer_size_type::operator=(const d_pointer_size_type& obj)
{
     this->setID(obj.getID());


}

void d_pointer_size_type::operator=(const dObject& obj){

    cout<< "is dObject"<< "\n";

}
void d_pointer_size_type::operator==(const d_pointer_size_type& obj){
    if(this->getPuntero()==obj.getPuntero()){
        cout<<"both pointers are pointing to same address"<<("/n");

    }
    else{
        cout<<"pointers are pointing to different address"<<("/n");
    }
    cout<< "is dObject"<<( "\n");

}
int d_pointer_size_type::getPuntero() const
{
    return puntero;
}


void d_pointer_size_type::setPuntero(int value)
{
    puntero = value;
}
int d_pointer_size_type::getSize() const
{
    return size;
}

void d_pointer_size_type::setSize(int value)
{
    size = value;
}
char *d_pointer_size_type::getDataType() const
{
    return dataType;
}

void d_pointer_size_type::setDataType(char *value)
{
    dataType = value;
}
int d_pointer_size_type::getReferences() const
{
    return references;
}

void d_pointer_size_type::setReferences(int value)
{
    references = value;
}




