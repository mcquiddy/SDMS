#include "sdsmemorynode.h"
/**
 * @brief SDSMemoryNode::SDSMemoryNode
 * @param Cantidad
 * @param exponente
 * @param puerto
 * @param puerto_status
 */

SDSMemoryNode::SDSMemoryNode(int cantidad, char exponente, int puerto, int puerto_status)
{

    this->puerto = new SocketServer(puerto,this);
    this->puerto_status = new SocketServer(puerto_status,this);
    this->size=cantidad;
    if(exponente=='M')
        size=size*1024*1024;
     else if(exponente=='G')
        size=size*1024*1024*1024;
}

void SDSMemoryNode::SaveMemory()
{
    memoria_reservada=malloc(size);
    if(memoria_reservada==NULL)
        cout<<"ERROR: -No se reservó la memoria"<<endl;
    else
        cout<<"Se ha reservado "<<size<<" bytes de memoria"<<endl;
}
