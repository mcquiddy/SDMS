#ifndef POINTER_H
#define POINTER_H
#include <iostream>
using namespace std;
class pointer
{
        int age;
        char* pName;
        public:
            pointer(): age(0){
            }

            pointer( int age): age(age)
            {
            }
            ~pointer()
            {
            }

            void  Display() {
                cout<< " Age = %d \n"<<  age<<"\n";
                 //std::cout << "size of empty class: "  << p.x << "\n" ;
            }

            void Shout() {
                cout<<"Ooooooooooooooooo" << "\n" ;
            }

           // void  Shout();
            //void Display();

    };


#endif // POINTER_H
