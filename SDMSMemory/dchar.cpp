#include "dchar.h"
#include <darray.h>
dChar::dChar()
{




}

void operator<<(ostream& os,const dChar& dc){
   os << *dc.x<<"\n";

}
void dChar::operator =(const dChar c){
   *this->x = *c.x;

}
void dChar::operator = ( const char c){
   *this->x = c;

}


bool& dChar::operator==(const char& obj){
     bool c= true;
     if(*this->x==obj){
        //cout<<"son iguales"<<"\n";
     }
     else{
         c=false;
     }
     return c;


}
bool& dChar::operator==(const dChar& obj){
     bool c= true;
     if(this->x==obj.x){
        //cout<<"son iguales"<<"\n";
     }
     else{
         c=false;
     }
     return c;


}





