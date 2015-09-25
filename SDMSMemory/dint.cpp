#include "dint.h"

dInt::dInt()
{
    d_pointer_size_type *memoria=heap->dMalloc(sizeof(int),"dInt");

}
 void operator<<(ostream& os,const dInt& dt){
    os << *dt.x<<"\n";

}
dInt& dInt::operator = (const dInt &p){

    this->x = p.x;

   return *this;

}
dInt& dInt::operator = (const int& p){
   *this->x = p;

   return *this;

}

bool& dInt::operator==(const int& obj){
     bool c= true;
     if(*this->x==obj){
        cout<<"son iguales"<<"\n";
     }
     else{
         c=false;
     }
     return c;


}
bool& dInt::operator==(const dInt& obj){
     bool c= true;
     if(this->x==obj.x){
        cout<<"son iguales"<<"\n";
     }
     else{
         c=false;
     }
     return c;


}

void dInt::operator++(int ){
   this->x+=1;

}
void dInt::operator--(int ){
   this->x-=1;

}


