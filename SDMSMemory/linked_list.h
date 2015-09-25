/*
 * DoubleLinkedList.h
 *
 *  Created on: Jul 30, 2015
 *      Author: santii
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_
#include <iostream>
#include "Node.h"

using namespace std;

template<typename T>
class lista {
private:
	Node<T>* head;
	Node<T>* tail;
    int Length;

public:
	void insert_head(T new_data);
	void insert_tail(T new_data);
	void delete_data(T data);
	bool isInList(T data);
    Node<T>* rove(int x);
    Node<T>* get_head();
    Node<T>* get_tail();
    int length();
    T* serch(T data);
	void print_list();
    lista();
    virtual ~lista();

    void delete_Pos(int x);



};

template<typename T>
/**
 * @brief list<T>::list
 */
lista<T>::lista(){
	head=NULL;
	tail=NULL;
    Length=0;
}
template<typename T>
/**
 * @brief list<T>::insert_head
 * @param new_data
 */
void lista<T>::insert_head(T new_data){
	Node<T> *newNode=new Node<T>(new_data);
	if(this->head==NULL){
		head=newNode;
		tail=head;
	}
	else{
		Node<T>* temp=this->head;
		newNode->set_next(temp);
		temp->set_prev(newNode);
		this->head=newNode;
	}
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::insert_tail
 * @param new_data
 */
void lista<T>::insert_tail(T new_data){
	Node<T> *newNode=new Node<T>(new_data);
	if(this->tail==NULL){
		tail=newNode;
		head=tail;
	}
	else{
		Node<T>* temp=this->tail;
		temp->set_next(newNode);
		newNode->set_prev(temp);
		tail=newNode;
	}
    this->Length++;
}

template<typename T>
/**
 * @brief list<T>::delete_data
 * @param data
 */
void lista<T>::delete_data(T data){
    if(this->Length!=0){//se cumple en caso que  solo existe un nodo(head)
            Node<T>* temp=head->get_next();
            if((temp==NULL) & ((this->head->get_data())==data)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;

            }
            else{
                Node<T>* NextTemp=temp->get_next();
                if(this->head->get_data()==data){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                 if(this->tail->get_data()==data){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                while(temp->get_next()!=NULL){
                    //cout<<temp->get_data()<<" es igual a "<<data<<"?"<<endl;
                    if(temp->get_data()==data){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        temp=NextTemp;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }
                    NextTemp=temp->get_next();
                }
            }

    }
}

template<typename T>
/**
 * @brief list<T>::isInList
 * @param data
 * @return
 */
 Node<T>* lista<T>::rove(int x){
    Node<T>* temp=this->head;
    if(this->Length>=0 && x<=this->length()){

        for(int i=1;i<x;i++){

            temp=temp->get_next();

		}
	}
    else{
       temp=NULL;

    }

    return temp;
}
template<typename T>
 bool lista<T>::isInList(T data){
     bool save=false;
     if(this->Length>0){
         Node<T>* temp=this->head;
         while(temp!=NULL){
             if(temp->get_data()==data){
                 save=true;
                 break;
             }
             temp=temp->get_next();
         }
     }

     return save;
 }

template<typename T>
/**
 * @brief list<T>::serch
 * @param data
 * @return
 */
T* lista<T>::serch(T data){
	if(this->isInList(data)){
        Node<T>* temp=head;
        Node<T>* result=NULL;
		while(temp->get_next()!=NULL){
            if(temp->get_data()==data){
                result=data;
			}
		}
        return result;
	}
	else{
		return NULL;
	}
}


template<typename T>
/**
 * @brief list<T>::delete_Pos
 * @param x
 */
void lista<T>::delete_Pos(int x){
    if(this->Length!=0 && x<=this->length()){//se cumple en caso que  solo existe un nodo(head)
            Node<T>* temp=head->get_next();
            if((temp==NULL) & (x==1)){
                delete head;
                head=NULL;
                tail=NULL;
                Length=0;
            }
            else{

                if(x==1){//se cumple en caso que el nodo a eliminar sea el head
                    temp=head->get_next();
                    delete head;
                    head=temp;
                    head->set_prev(NULL);
                    this->Length--;

                    //cout<<"delete data: "<<data<<"In head"<<endl;
                }
                else if(x==this->length()){
                    temp=tail->get_prev();
                    delete tail;
                    tail=temp;
                    temp->set_next(NULL);
                    this->Length--;
                    //cout<<"delete data: "<<data<<"In tail"<<endl;
                }
                else{
                    temp=head;
                 for(int i=1; i<=x;i++){
                    if(i==x){
                        temp->get_prev()->set_next(temp->get_next());
                        temp->get_next()->set_prev(temp->get_prev());
                        delete temp;
                        this->Length--;
                        //cout<<"Data "<<data<<" deleted"<<endl;
                    }
                    else{
                        temp=temp->get_next();
                    }

                }
                }
            }
    }
}


template<typename T>
/**
 * @brief list<T>::get_head
 * @return
 */
Node<T>* lista<T>::get_head(){
    return this->head;
}

template<typename T>
/**
 * @brief list<T>::get_tail
 * @return
 */
Node<T>* lista<T>::get_tail(){
    return this->tail;
}


template<typename T>
/**
 * @brief list<T>::length
 * @return
 */
int lista<T>::length(){
    return Length;
}

template<typename T>
/**
 * @brief list<T>::print_list
 */
void lista<T>::print_list(){
	Node<T>* temp=this->head;
    cout<<"Cantidad de nodos: "<<this->Length<<endl;
	while(temp!=NULL){
        cout<<temp->get_data()<<" ";
		temp=temp->get_next();
	}
	cout<<endl;
}
template<typename T>
/**
 * @brief list<T>::~list
 */
lista<T>::~lista(){
	delete this;
}
#endif /* DOUBLELINKEDLIST_H_ */
