#ifndef D_POINTER_SIZE_TYPE_H
#define D_POINTER_SIZE_TYPE_H
#include<dobject.h>
#include <iostream>
#include <QObject>
#include <dint.h>
#include <dchar.h>


class d_pointer_size_type : public dObject
{
public:
    d_pointer_size_type();

    dInt getID() const;
    void setID(dInt value);
    dInt getReferences() const;
    void setReferences(dInt pReferences);

    void  print();

    void operator=(const d_pointer_size_type& obj);
    void operator=(const dObject& obj);
    bool operator==(const d_pointer_size_type& obj);

    int operator++(int);
    int operator--(int);
    dInt getPuntero() const;
    void setPuntero(dInt value);

    dInt  getSize() const;
    void setSize(dInt value);

    dChar getDataType() ;
    void setDataType(dChar value);


private:
    dInt references;
    dInt ID;
    dInt puntero;
    dInt size;
    dChar dataType;


};

#endif // D_POINTER_SIZE_TYPE_H
