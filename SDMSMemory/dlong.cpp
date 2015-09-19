#include "dlong.h"



dLong::dLong()
{
    struct dLong;

}

    dLong& dLong::operator = (const long &l){
     this->x = l;
        return *this;
}
    dLong& dLong::operator = (const dLong &l){
     this->x = l.x;
        return *this;
}

    bool& dLong::operator==(const long& obj){
         bool c= true;
         if(this->x==obj){
            cout<<"son iguales"<<"\n";
         }
         else{
             c=false;
         }
         return c;


    }
    bool& dLong::operator==(const dLong& obj){
         bool c= true;
         if(this->x==obj.x){
            cout<<"son iguales"<<"\n";
         }
         else{
             c=false;
         }
         return c;
    }
