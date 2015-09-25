#include "dint.h"

dInt::dInt()
{
   id=heap->newDpointerSize(sizeof(int),"I");


    cout<<" dInt "<<id<<endl;

}
 void operator<<(ostream& os,const dInt& dt){
     Pointer puntero;
     puntero.id=dt.id;
     Pointer *data=dt.heap->d_get(puntero);
     //dt.x=&(data->dataint);

    os << data->dataint<<"\n";

}
dInt& dInt::operator = (const dInt &p){

    this->x = p.x;

   return *this;

}
dInt& dInt::operator = (const int& p){
   cout<<" hola "<<endl;
  Pointer puntero;
  puntero.dataint=p;
  puntero.id=this->id;
  heap->d_set(puntero);
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


