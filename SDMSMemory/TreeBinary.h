#ifndef TREEBINARY_H
#define TREEBINARY_H
#include <iostream>
#include "NodeTree.h"
#include "Node.h"
#include "constants_SDSM.h"
#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;
template<typename T>
class treeBinary {
private:
    NodeTree<T>* raiz;
    int Length;

public:
    void insert(T new_data);
    void insertAux(NodeTree<T>* newNode);
    void delete_data(T data);
    NodeTree<T>* buscarNumber(int data);
    void insertarLista(lista<NodeTree<T>*>  * pLista);
    NodeTree<T>* buscarNumberAux(int data, queue<NodeTree<T>*> *cola);
    NodeTree<T>* search_aux(T data, queue<NodeTree<T>*> *cola);
    NodeTree<T>* get_raiz();
    int length();
   NodeTree<T>* search(T data);
    void print_tree();
    treeBinary();
    void deleteNodo(lista<NodeTree<T>*>  * pList,T data);
    NodeTree<T> *buscarNodo(lista<NodeTree<T>*>  * pList, T data);
void borrarPalabra(T pDato);
NodeTree<T>*  borrarAux(NodeTree<T>* pRaiz);
  NodeTree<T>*  menorMayores( NodeTree<T>* pNodo) ;
    virtual ~treeBinary();

};

template<typename T>
/**
 * @brief list<T>::list
 */
treeBinary<T>::treeBinary(){
    raiz=NULL;
    Length=0;
}
template<typename T>
/**
 * @brief list<T>::inser
 * inserta en el arbol, si la palabra ya existe aumenta la cantidad de repeticiones
 * @param new_data
 * PALABRA
 * @param new_cant
 * Cantidad de repeticiones
 */
void treeBinary<T>::insert(T new_data){

    NodeTree<T> *newNode=new NodeTree<T>(new_data);
    if(this->raiz==NULL){
        raiz=newNode;

    }
    else{
        NodeTree<T>* temp=search(new_data);

        if(temp!=NULL){

            if(temp->isType()==ARBOL){

                if(temp->haveList()){

                     this->insertarLista(temp->get_list());
                      temp->get_list()->~lista();
                }
 NodeTree<T>* newTemp=temp;
 this->borrarPalabra(temp->get_data());
 newTemp->set_cantidad();
 this->insertAux(newTemp);


            }
            else{

                NodeTree<T>* NumberTemp=buscarNumber(temp->get_cant());
                this->deleteNodo(NumberTemp->get_list(),temp->get_data());
                temp->set_cantidad();
                temp->setType(ARBOL);
                this->insertAux(temp);

            }


        }
        else{

           this->insertAux(newNode);

        }

    }
    this->Length++;
}

template<typename T>
/*!
 * \brief treeBinary<T>::insertAux
 * metodo de insertar de un nodo
 * \param newNode
 * nuevo nodo a insertar en el arbol
 */
void treeBinary<T>::insertAux(NodeTree<T> *newNode)
{
    if(this->raiz==NULL){
        raiz=newNode;

    }
    else{
    NodeTree<T> *temp=this->raiz;
    while(temp!=NULL){

          if(newNode->get_cant()<temp->get_cant()){

              if(temp->get_izq()!=NULL){
                 temp=temp->get_izq();
              }
              else{
                  temp->set_izq(newNode);
                  temp->get_izq()->set_padre(temp);

                  break;
              }

          }
          else if(newNode->get_cant()>temp->get_cant()){
              if(temp->get_der()!=NULL){
                   temp=temp->get_der();
              }
             else{
                  temp->set_der(newNode);
                  temp->get_der()->set_padre(temp);

                  break;
              }

        }
          else{

              newNode->setType(false);
              temp->get_list()->insert_tail(newNode);
              break;
          }

    }

}
}



template<typename T>
/**
 * @brief list<T>::delete_data
 * @param data
 */
void treeBinary<T>::delete_data(T data){
//    if(this->Length!=0){
//            NodeTree<T>* temp=head->get_next();
//            if((temp==NULL) & ((this->head->get_data())==data)){
//                delete head;
//                head=NULL;
//                tail=NULL;
//                Length=0;

//            }
//            else{
//                NodeTree<T>* NextTemp=temp->get_next();
//                if(this->head->get_data()==data){
//                    temp=head->get_next();
//                    delete head;
//                    head=temp;
//                    head->set_prev(NULL);
//                    this->Length--;
//                    //cout<<"delete data: "<<data<<"In head"<<endl;
//                }
//                 if(this->tail->get_data()==data){
//                    temp=tail->get_prev();
//                    delete tail;
//                    tail=temp;
//                    temp->set_next(NULL);
//                    this->Length--;
//                    //cout<<"delete data: "<<data<<"In tail"<<endl;
//                }
//                while(temp->get_next()!=NULL){
//                    //cout<<temp->get_data()<<" es igual a "<<data<<"?"<<endl;
//                    if(temp->get_data()==data){
//                        temp->get_prev()->set_next(temp->get_next());
//                        temp->get_next()->set_prev(temp->get_prev());
//                        delete temp;
//                        temp=NextTemp;
//                        //cout<<"Data "<<data<<" deleted"<<endl;
//                    }
//                    else{
//                        temp=temp->get_next();
//                    }
//                    NextTemp=temp->get_next();
//                }
//            }

    //    }
}


template<typename T>
/*!
 * \brief treeBinary<T>::buscarNumber
 * incializa una cola que le inserta la raiz. para luego llamar al metodo auxiliar de este
 * \param data
 * cantidad de repeticiones que se repite
 * \return
 * nodo que tenga la misma cantidad de repeticiones
 */
NodeTree<T>* treeBinary<T>::buscarNumber(int data)
{
    queue<NodeTree<T>*> *cola= new queue<NodeTree<T>*>();
     if(raiz==NULL){
         return NULL;
     }
     else{
         cola->enqueue(this->raiz);
        return  this->buscarNumberAux(data,cola);
     }
}
template<typename T>
/*!
 * \brief treeBinary<T>::insertarLista
 * inserta los datos de la lista al arbol.
 * \param pLista
 * lista con nodos de arboles
 */
void treeBinary<T>::insertarLista(lista<NodeTree<T> *> *pLista)
{
    Node<T>* headList= (Node<T>*)pLista->get_head();
    int i=1;


    while(headList!=NULL){

         i++;
         NodeTree<T>* node=(NodeTree<T>*)pLista->rove(i)->get_data();
         node->setType(ARBOL);
         this->insertAux(node);
          headList=headList->get_next();
    }

}
template<typename T>
/*!
 * \brief treeBinary<T>::buscarNumber
 * busca el nodo que consida con el mismo muero de repeticiones
 * \param data
 * cantidad de repeticiones que se repite
 * \return
 * nodo que tenga la misma cantidad de repeticiones
 */
NodeTree<T>* treeBinary<T>::buscarNumberAux(int data, queue<NodeTree<T>*> *cola)
{
    NodeTree<T> * temp=NULL;
    NodeTree<T> * result=NULL;
    while(!cola->isEmpty()){
        temp=(NodeTree<T> * )cola->dequeue()->get_data();
        if(temp->get_cant()==data){
            result=temp;
            break;
        }
        else{
            if(temp->get_izq()!=NULL){
        cola->enqueue(temp->get_izq());
        }
            if(temp->get_der()!=NULL){
                cola->enqueue(temp->get_der());
            }

    }

}
    return result;
}


template<typename T>
/**
 * @brief list<T>::serch
 * @param data
 * @return
 */
NodeTree<T>*  treeBinary<T>::search(T data){
    queue<NodeTree<T>*> *cola= new queue<NodeTree<T>*>();

    if(raiz==NULL){
        return NULL;
    }
    else{
        cola->enqueue(this->raiz);
       return  this->search_aux(data,cola);
    }


}
template<typename T>
/*!
 * \brief treeBinary<T>::search_aux
 * encuentra en el arbol y en la lista del nodo, que esta en la cola,el dato a buscar
 * \param data
 * dato a buscar
 * \param cola
 * cola donde se inserta todo nodo arbol a buscar
 * \return
 * el nodo que tiene el dato o null si no se encuentra
 */
NodeTree<T> *treeBinary<T>::search_aux(T data, queue<NodeTree<T>*> *cola)
{
    NodeTree<T> * temp=NULL;
    NodeTree<T> * result=NULL;

    while(!cola->isEmpty()){


        temp=(NodeTree<T> * )cola->dequeue()->get_data();

        if(temp->get_data()==data){

            result=temp;
            break;
        }
        else{
            if(temp->haveList()){

                Node<T>* head=(Node<T>*)temp->get_list()->get_head();

                NodeTree<T>* word=(NodeTree<T>*)buscarNodo(temp->get_list(),data);

                if(word!=NULL){

                    result=word;

                    break;
                }

            }
            if(temp->get_izq()!=NULL){

        cola->enqueue(temp->get_izq());
        }
            if(temp->get_der()!=NULL){

                cola->enqueue(temp->get_der());
            }

    }

}

    return result;

}



template<typename T>
/**
 * @brief list<T>::get_head
 * @return
 */
NodeTree<T>* treeBinary<T>::get_raiz(){
    return this->raiz;
}



template<typename T>
/**
 * @brief list<T>::length
 * @return
 */
int treeBinary<T>::length(){
    return Length;
}

template<typename T>
/**
 * @brief list<T>::print_list
 */
void treeBinary<T>::print_tree(){
    queue<NodeTree<T>*> *cola= new queue<NodeTree<T>*>();
    cola->enqueue(raiz);

     NodeTree<T>* temp=NULL;
while(!cola->isEmpty()){

   temp=(NodeTree<T>*)cola->dequeue()->get_data();
cout<<" dato arbol "<<temp->get_data()<<" repetoiciones "<<temp->get_cant()<<endl;

   if(temp->haveList()){
       Node<T>* head=(Node<T>*)temp->get_list()->get_head();
       int i=1;
       while(head!=NULL){

           cout<< " dato lista "<<temp->get_list()->rove(i)->get_data()->get_data()<<" repetoiciones "<<temp->get_cant()<<endl;
           i++;
           head=(Node<T>*)temp->get_list()->rove(i);
       }


   }
   if(temp->get_izq()!=NULL){
       cout<<" isquierdo "<<temp->get_izq()->get_data()<<endl;
       cola->enqueue(temp->get_izq());
   }
   if(temp->get_der()!=NULL){
         cout<<" derecho "<<temp->get_der()->get_data()<<endl;
       cola->enqueue(temp->get_der());
   }
}
}

template<typename T>
/*!
 * \brief lista<T>::buscarNodo
 * busca en la lista que consida con el dato
 * \param data
 * dato a buscar
 * \return
 * nodo
 */
NodeTree<T> *treeBinary<T>::buscarNodo(lista<NodeTree<T>*>  * pList,T data)
{
    Node<T>* temp=(Node<T>*)pList->get_head();
     NodeTree<T>* nodo=(NodeTree<T>*)pList->get_head()->get_data();


int i=1;
        while(temp!=NULL && nodo->get_data()!=data){
nodo=(NodeTree<T>*)pList->rove(i)->get_data();
            if(nodo->get_data()==data){

                break;
            }
            else{
                i++;
                temp=temp->get_next();


            }
        }
        if(temp==NULL){

            return NULL;
        }


    else{
        return nodo;
    }
}

template<typename T>
void treeBinary<T>::deleteNodo(lista<NodeTree<T>*>  * pList,T data)
{
    Node<T>* temp=(Node<T>*)pList->get_head();
     NodeTree<T>* nodo=(NodeTree<T>*)pList->get_head()->get_data();
     int i=1;
    while(temp!=NULL){

            if(nodo->get_data()==data){
                pList->delete_data(nodo);
break;
            }
            else{
                temp=temp->get_next();
                nodo=(NodeTree<T>*)pList->rove(i)->get_data();
            }
}

}
template<typename T>
/**
     * Borra el nodo que contenga igual numero de rankink llamando el metodo de
     * borraraux, si el dato no esta en la raiz se busca el nodo que desea
     * borrar y llama el metodo de borraraux
     *
     *
     * @param pDato
     *            page rank o ranking
     */
     void treeBinary<T>::borrarPalabra(T pDato) {
        if (raiz != NULL) {
            if (raiz->get_data()==pDato) {

                if (raiz->isType()) {
                    lista<NodeTree<T>*>  *listWords= raiz->get_list();
                    raiz = this->borrarAux(raiz);
                    if (raiz != NULL) {
                        raiz->set_padre(NULL);
                    }
                    this->insertarLista(listWords);

                }
                else {
                   lista<NodeTree<T>*>  *listWords = this->buscarNumber(raiz->get_cant())->get_list();
                   this->deleteNodo(listWords,raiz->get_data());

                }

            }
            else {
                NodeTree<T>* aux = this->search(pDato);
                if (aux != NULL) {
                    if (aux->isType()) {

                        if (aux->get_padre()->get_izq() != NULL && aux->get_padre()->get_izq()==aux) {
                            aux->get_padre()->set_izq(this->borrarAux(aux));
                            if (aux->get_padre()->get_izq() != NULL) {
                                aux->get_padre()->get_izq()->set_padre(aux->get_padre());
                            }

                        }
                        else {
                            aux->get_padre()->set_der(this->borrarAux(aux));
                            if (aux->get_padre()->get_der() != NULL) {
                                aux->get_padre()->get_der()->set_padre(aux->get_padre());
                            }
                        }
if(aux->haveList()){
                       lista<NodeTree<T>*>  *listWords = aux->get_list();
                       this->insertarLista(listWords);

                        aux->get_list()->~lista();
}

                    }
                    else {
                        lista<NodeTree<T>*>  *listWords =this->buscarNumber(aux->get_cant())->get_list();
                        this->deleteNodo(listWords,aux->get_data());

                    }

                }
            }
        }
    }
     template<typename T>
     /**
          * Borra el nodo, posicionandolo en el menor de los mayores y el menor de
          * los mayores en la posicion del nodo a eliminar, cuando el nodo a eliminar
          * hizo la rotacion entonces el padre deja de apuntarlo.
          *
          * @param pRaiz
          *            Nodo a eliminar del arbol
          * @return retorna el nodo que intercambio con pRaiz, para que el padre de
          *         pRaiz lo setea como padre.
          */

       NodeTree<T>*  treeBinary<T>::borrarAux(NodeTree<T>* pRaiz) {

             if (pRaiz->get_izq() == NULL) {
                 return pRaiz->get_der();
             }
             else if (pRaiz->get_der() == NULL) {
                 return pRaiz->get_izq();
             }
             else {
                 NodeTree<T>* menor_Padre = menorMayores(pRaiz->get_der());
                 if (menor_Padre == pRaiz->get_der()) {
                     if (menor_Padre->get_izq() == NULL) {
                         menor_Padre->set_izq(pRaiz->get_izq());

                         return menor_Padre;
                     }
                 }

                 NodeTree<T>* menor = menor_Padre->get_izq();
                 menor->set_izq(pRaiz->get_izq());
                 if (menor->get_izq() != NULL) {
                     menor->get_izq()->set_padre(menor);
                 }
                 NodeTree<T>*  menor_Hder = menor->get_der();
                 menor->set_der(pRaiz->get_der());
                 if (menor->get_der() != NULL) {
                     menor->get_der()->set_padre(menor);
                 }
                 pRaiz->set_der(menor_Hder);

                 if (menor_Padre->get_izq() == menor) {
                     menor_Padre->set_izq(menor_Hder);
                     return menor;
                 }
                 else {
                     menor_Padre->set_der(menor_Hder);
                     return menor;
                 }

             }

         }
 template<typename T>
       /**
            * Busca el nodo de menor valor en los lados de los mayores de la raiz (lado
            * derecho)
            *
            * @param pNodo
            *            Nodo de donde se quiere iniciar la busqueda del menor.
            * @return retorna el padre del menor de los mayores
            */

           NodeTree<T>*  treeBinary<T>::menorMayores( NodeTree<T>* pNodo) {
               if (pNodo->get_izq() == NULL) {
                   return pNodo;
               }
               else if (pNodo->get_izq()->get_izq() != NULL) {
                   return menorMayores(pNodo->get_izq());
               }
               else {
                   return pNodo;
               }
           }
template<typename T>
/**
 * @brief list<T>::~list
 */
treeBinary<T>::~treeBinary(){
    delete this;
}
#endif // TREEBINARY_H
