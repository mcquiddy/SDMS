#include "d_pointer_size_type.h"


d_pointer_size_type::d_pointer_size_type(){
//cout<< "Constructor build" ;


}
int d_pointer_size_type::getID() const{
    return this->ID;
}

void d_pointer_size_type::setID(int ID)
{
    this->ID=ID;
}


int d_pointer_size_type::getReferences() const{
    return *(this->references);
}

void d_pointer_size_type::setReferences(int pReferences)
{

    *(this->references) = pReferences;

}
void d_pointer_size_type::print(){
    /*std::cout<< "ID: "<< this->getID() << "\n";
    std::cout<< "Puntero: "<< this->puntero->x << "\n";
    std::cout<< "Reference: "<< this->references->x << "\n";
    */
}


void d_pointer_size_type::operator=(const dObject& obj){

    cout<< "Verificar que tamano de dObject sea compatible con el reservado"<< "\n";

}

bool d_pointer_size_type::operator==(const d_pointer_size_type& obj){
    bool c=true;
    /*if(this->puntero->x==obj.getPuntero().x){
        //cout<<"both pointers are equals"<<("/n");

    //return true;
    }
    else{
       // cout<<"both pointers are different"<<("/n");
        c=false;

    }
    //cout<< "is dObject"<<( "\n");
    */
    return c;
}

int d_pointer_size_type::operator++(int ){
   dirPuntero+=1;

}
int d_pointer_size_type::operator--(int ){
   dirPuntero-=1;

}

int d_pointer_size_type::getPuntero() const{
    return *(this->dirPuntero);
}


void d_pointer_size_type::setPuntero(int value)
{
    *(this->dirPuntero )= value;
}
int d_pointer_size_type::getSize() const
{
    return *(this->size);
}

void d_pointer_size_type::setSize(int value)
{
    *(this->size )= value;
}

char d_pointer_size_type::getDataType()

{
    return *(this->dataType);
}

void d_pointer_size_type::setDataType(char value)
{
    *(this->dataType) = value;
}







