#include "socketcliente.h"





SocketCliente::SocketCliente(int pPuerto,char* pIp)
{

puerto=pPuerto;
ip=pIp;

//connectgui=new ConnectGUI();
}

void SocketCliente::setComando(string mensaje)
{
//cout<<" shoot mensaje "<<mensaje<<endl;
    const char * mns=&mensaje[0u];
    this->setMensaje(mns);
}



bool SocketCliente::connectar()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = inet_addr(ip);
    info.sin_port = ntohs(puerto);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    if((::connect(descriptor,(sockaddr*)&info,(socklen_t)sizeof(info))) < 0)
     return false;


//    this->controlador();

    return true;
}











void SocketCliente::setMensaje(const char *msn)
{

const char men[]=" { \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] } ";
send(descriptor,msn,strlen(msn),0);
//    cout<< " mesnake"<< msn<<endl;
//    cout << "bytes enviados "<< send(descriptor,msn,strlen(msn),0) << endl;
}
