/*
 * LinkedStack.h
 *
 *  Created on: Nov 9, 2017
 *      Author: ferdinand tembo
 */


#ifndef LINKEDSTACK_H_
#define LINKEDSTACK_H_
#include <iostream>
using namespace std;

// LinkedList-based implementation of Stack
template <class T>

struct node{
	T data;
	node* next;
};

template <class T>
class LinkedStack{
protected:
	node<T> * top;

public:
	LinkedStack();
	bool isFull();
	bool isEmpty();
	void push(T&);
	T pop();
	T stop();
	void destroy();
	template <class U>
	friend ostream& operator <<(ostream& os, LinkedStack<U>& stack);
	~LinkedStack();
	void display(){
		node<T>* temp = top;
		while(temp != NULL ){
			cout<<" From display "<<temp->data<<endl;
			temp = temp->next;
		}
	}

};

template <class T>
LinkedStack<T>::LinkedStack(){

}

template <class T>
LinkedStack<T>::~LinkedStack(){

}

template <class T>
bool LinkedStack<T>::isFull(){
	return top;
}

template <class T>
bool LinkedStack<T>::isEmpty(){
	return top==0;
}


template <class T>
void LinkedStack<T>::push(T& item){

	node<T> *p = new node<T>;
	p->data = item;
	p->next= NULL;

	if (top != NULL){
		p->next=top;
		top= p;
	}
	else{
		top = p;
	}


}

template <class T>
T LinkedStack<T>::pop(){
	if(!isEmpty()){
     node<T> *temp = top;
	 top=top->next;
	 return (temp->data);
		}

	}

template <class T>
T LinkedStack<T>::stop(){
	if(!isEmpty()){
		return &(top->data);
	}
	return NULL;

}



template <class T>
ostream& operator <<(ostream& os, LinkedStack<T>& stack){
		node<T> * cp = stack.top;
					while(cp != NULL){
						os<<cp->data;
						cp = cp->next;
					}
					return os;
}

#endif /* STACK_H_ */
