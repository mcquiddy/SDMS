#ifndef SDSMEMORYSERVER_H
#define SDSMEMORYSERVER_H
#include "socketserver.h"
#include "rapidjson/rapidjson.h"

class SDSMemoryServer
{
protected:
    SocketServer *puerto;
    SocketServer *puerto_status;
    //rapidjson document;
    static void* runSockets(void* obj);
public:
    SDSMemoryServer();
    virtual void reciveMns(char *message);
    virtual void newClient(int id,int Puerto);
    virtual void sentMns(const char* mns);
    void start();
    virtual ~SDSMemoryServer();
};

#endif // SDSMEMORYSERVER_H
