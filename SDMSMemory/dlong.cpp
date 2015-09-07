#include "dlong.h"

dLong::dLong()
{
    struct dLong;

}

    dLong& dLong::operator = (const long& l){
     this->x = l;
        return *this;
}
