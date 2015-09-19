#include "dint.h"

dInt::dInt()
{

struct dInt;

}


dInt& dInt::operator = (const int& p){
   this->x = p;
   return *this;

}
bool& dInt::operator==(const int& obj){
     bool c= true;
     if(this->x==obj){
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


