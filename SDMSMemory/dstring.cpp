#include "dstring.h"


dString::dString()
{


 }
  void operator<<(ostream& os,const dString& dt){
      Pointer puntero;
      puntero.id=dt.id;
      Pointer *data=dt.heap->d_get(puntero);


     os << data->datastring<<"\n";


 }
 dString& dString::operator = (const dString &p){

     this->x = p.x;

    return *this;

 }
 dString& dString::operator = (const string& p){

     id=heap->newDpointerSize(sizeof(char)*(p.length()-1), "S");


      cout<<" dString "<<id<<endl;
     Pointer puntero;
     puntero.datastring=p;
     puntero.id=this->id;
     heap->d_set(puntero);


    return *this;

 }

 bool& dString::operator==(const string& obj){
      bool c= true;
      if(*this->x==obj){
         cout<<"son iguales"<<"\n";
      }
      else{
          c=false;
      }
      return c;


 }
 bool& dString::operator==(const dString& obj){
      bool c= true;
      if(this->x==obj.x){
         cout<<"son iguales"<<"\n";
      }
      else{
          c=false;
      }
      return c;


 }




