/*
 * nodo.h
 *
 *  Created on: Jul 29, 2015
 *      Author: santii
 */

#ifndef NODO_H_
#define NODO_H_
template <typename T>
class Node {
private:
	Node<T>* next_node;
	Node<T>* prev_node;
	T data;

public:
	Node(T dato) ;
	T get_data();
	void set_next(Node* next_node);
	void set_prev(Node* prev_node);
	Node* get_next();
	Node* get_prev();
};
/**
 * Constructor of a Node
 * Setting nex_node and prev_node as 0 or NULL
 */
template<typename T>
Node<T>::Node(T dato){
	this->data=dato;
	this->next_node=0;
	this->prev_node=0;
}
/**
 * Getters and setters
 */
template<typename T>
/**
 * @brief Node<T>::get_next
 * @return
 */
Node<T>* Node<T>::get_next(){
	return this->next_node;
}
template<typename T>
/**
 * @brief Node<T>::get_prev
 * @return
 */
Node<T>* Node<T>::get_prev(){
	return this->prev_node;
}
template<typename T>
void Node<T>::set_next(Node<T>* new_next_node){
	this->next_node=new_next_node;
}
template<typename T>
void Node<T>::set_prev(Node<T>* new_prev_node){
	this->prev_node=new_prev_node;
}
template<typename T>
T Node<T>::get_data(){
	return this->data;
}
#endif /* NODO_H_ */

