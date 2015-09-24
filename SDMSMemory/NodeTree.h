#ifndef NODETREE_H
#define NODETREE_H
#include "constants_SDSM.h"
#include "linked_list.h"
#include "Queue.h"
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
/*!
 * Nodo que se utiliza para formacion de el arbol de busqueda
 */

template <typename T>

class NodeTree {
private:
    NodeTree<T>* izq_node;
    NodeTree<T>* der_node;
    NodeTree<T>* padre;
    lista<NodeTree<T>*>  *listWords=new lista<NodeTree<T>*> ;
    T cantidad;
    T data;
    bool tipo;


public:
    NodeTree(T dato) ;
    T get_data();
    int get_cant();
    void set_der(NodeTree* node_der);
    void set_izq(NodeTree* node_izq);
    void set_padre(NodeTree* node_padre);
    void insertLista(NodeTree* newNode);
    void setType(bool newType);
    bool haveList();
    bool isType();

    void set_cantidad();
    NodeTree* get_izq();
    NodeTree* get_der();
    NodeTree* get_padre();
    void newList();
    lista<NodeTree<T> *> *get_list();
};
/**
 * Constructor of a Node
 * Setting los hijos y padre como nulos y setea el dato ( palabra) y cantidad( total de repeticiones de esa palabra)
 */
template<typename T>
NodeTree<T>::NodeTree(T dato){
    this->data=dato;
    this->cantidad="0";
    this->der_node=NULL;
    this->izq_node=NULL;
    this->padre=NULL;
    this->tipo=ARBOL;

}
/**
 * Getters and setters
 */
template<typename T>
/**
 * @brief Node<T>::get_izq
 * obtiene el hijo izquierdo
 * @return
 */
NodeTree<T>* NodeTree<T>::get_izq(){
    return this->izq_node;
}
template<typename T>
/**
 * @brief Node<T>::get_der
 * obtiene el hijo derecho
 * @return
 */
NodeTree<T>* NodeTree<T>::get_der(){
    return this->der_node;
}

template<typename T>
/*!
 * \brief NodeTree<T>::set_der
 * setea el hijo derecho
 * \param node_der
 *  nuevo hijo derecho
 */
void NodeTree<T>::set_der(NodeTree<T>* node_der){
    this->der_node=node_der;
}
template<typename T>
/*!
 * \brief NodeTree<T>::set_izq
 * setea el hijo izquierdo
 * \param node_izq
 *  nuevo hijo izquierdo
 */
void NodeTree<T>::set_izq(NodeTree<T>* node_izq){
    this->izq_node=node_izq;
}
template<typename T>
/*!
 * \brief NodeTree<T>::get_data
 * obtiene el dato
 * \return
 * palabra que guarda
 */
T NodeTree<T>::get_data(){
    return this->data;
}
template<typename T>
/*!
 * \brief NodeTree::get_cant
 * castea la cantidad T a int
 * \return
 * cantidad total de repeticiones del nodo
 */
int NodeTree<T>::get_cant()
{
    istringstream myStream(cantidad);
        unsigned int uintVar = 0;

        myStream >> uintVar;
    return uintVar;

}
template<typename T>
/*!
 * \brief NodeTree::set_padre
 * setea el padre del nodo
 * \param node_padre
 * nuevo padre
 */
void NodeTree<T>::set_padre(NodeTree *node_padre)
{
    this->padre=node_padre;
}
template<typename T>
/*!
 * \brief NodeTree::insertLista
 * inserta un nuevo nodo en la lista
 * \param newNode
 * nuevo nodo arbol
 */
void NodeTree<T>::insertLista(NodeTree *newNode)
{
    this->listWords->insert_tail(newNode);
}

template<typename T>
/*!
 * \brief NodeTree::setType
 * define el tipo que es el nodo o donde esta
 * \param newType
 * true; esta dentro de un arbol
 * false; esta dentro de una lista
 */
void NodeTree<T>::setType(bool newType)
{
    this->tipo=newType;
}
template<typename T>
/*!
 * \brief NodeTree::haveList
 *  busca en la cabeza de la lista, para verificar si este nodo tiene datos en la lista
 * \return
 * null; no tiene lista
 * si no es nulo; tiene lista
 */
bool NodeTree<T>::haveList()
{
    if(this->listWords->length()==0){
        return false;
    }
    else{
        return true;
    }

}
template<typename T>
/*!
 * \brief NodeTree::isType
 * define el tipo que es el nodo
 * \return
 * true; es arbol
 * false; es lista
 */
bool NodeTree<T>::isType()
{
return this->tipo;
}


template<class T>
/*!
 * \brief NodeTree::set_cantidad
 * actualiza la nueva cantidad
 * \param cant
 * total de repeticiones de la palabra
 */
void NodeTree<T>::set_cantidad()
{
    istringstream myStream(cantidad);
        unsigned int uintVar = 0;

        myStream >> uintVar;
    uintVar++;
    stringstream temp_str;
    temp_str<<(uintVar);
    cantidad=temp_str.str().c_str();


}
template<typename T>
/*!
 * \brief NodeTree::newList
 * elimna la lista actual
 */
void NodeTree<T>::newList()
{
   this->listWords->clear();

}


template<typename T>
/*!
 * \brief NodeTree::get_padre
 * obtiene el padre del nodo
 * \return
 * nodo padre
 */
NodeTree<T> *NodeTree<T>::get_padre()
{
    return this->padre;
}
template<typename T>
/*!
 * \brief NodeTree::get_list
 * obtiene la lista de todas las palabras que tenga la misma cantidad de repeticiones
 * \return
 * lista de palabras
 */
lista<NodeTree<T>*> *NodeTree<T>::get_list()
{
    return this->listWords;
}
#endif // NODETREE_H
