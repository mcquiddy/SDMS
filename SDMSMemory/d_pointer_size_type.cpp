#include "d_pointer_size_type.h"


d_pointer_size_type::d_pointer_size_type(){
//cout<< "Constructor build" ;


}
dInt d_pointer_size_type::getID() const{
    return *this->ID;
}

void d_pointer_size_type::setID(dInt ID)
{
    *this->ID=ID;
}


dInt d_pointer_size_type::getReferences() const{
    return *this->references;
}

void d_pointer_size_type::setReferences(dInt pReferences)
{

    *this->references = pReferences;

}
void d_pointer_size_type::print(){
    std::cout<< "ID: "<< this->getID().x << "\n";
    std::cout<< "Puntero: "<< this->puntero->x << "\n";
    std::cout<< "Reference: "<< this->references->x << "\n";
}

void d_pointer_size_type::operator=(const d_pointer_size_type& obj){
     this->setID(obj.getID());
}

void d_pointer_size_type::operator=(const dObject& obj){

    cout<< "Verificar que tamano de dObject sea compatible con el reservado"<< "\n";

}
bool d_pointer_size_type::operator==(const d_pointer_size_type& obj){
    bool c=true;
    if(this->puntero->x==obj.getPuntero().x){
        //cout<<"both pointers are equals"<<("/n");

    //return true;
    }
    else{
       // cout<<"both pointers are different"<<("/n");
        c=false;

    }
    //cout<< "is dObject"<<( "\n");
    return c;
}

int d_pointer_size_type::operator++(int ){
   puntero->x+=1;

}
int d_pointer_size_type::operator--(int ){
   puntero->x-=1;

}

dInt d_pointer_size_type::getPuntero() const{
    return *puntero;
}


void d_pointer_size_type::setPuntero(dInt value)
{
    *puntero = value;
}
dInt d_pointer_size_type::getSize() const
{
    return *size;
}

void d_pointer_size_type::setSize(dInt value)
{
    *size = value;
}
dChar d_pointer_size_type::getDataType()
{
    return *dataType;
}

void d_pointer_size_type::setDataType(dChar value)
{
    *dataType = value;
}







