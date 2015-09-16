#ifndef D_POINTER_H
#define D_POINTER_H

//class d_pointer


    //d_pointer();
    template < typename T > class d_pointer
    {
        private:
        T*    pData; // Generic pointer to be stored
        public:
        d_pointer(T* pValue) : pData(pValue)
        {
        }
        ~d_pointer()
        {
            delete pData;
        }

        T& operator* ()
        {
            return *pData;
        }

        T* operator-> ()
        {
            return pData;
        }
    };

   /* void main()
    {
        d_pointer<test> p(new Person("Scott", 25));
        p->Display();
        // Dont need to delete Person pointer..
    }
*/



#endif // D_POINTER_H
