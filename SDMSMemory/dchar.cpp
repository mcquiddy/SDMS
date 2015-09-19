#include "dchar.h"
#include <darray.h>
dChar::dChar()
{


struct dChar;
struct dArray;

}

dChar& dChar::operator = (const dChar &c){
   this->x = c.x;
    return *this;
}
dChar& dChar::operator = ( const char& c){
   this->x = c;
    return *this;
}


bool& dChar::operator==(const char& obj){
     bool c= true;
     if(this->x==obj){
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





