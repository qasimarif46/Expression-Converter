#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
 class LinkedStack
 {
	private: 
	        Node<T>* top;

	public:
	
		     LinkedStack()
		     {
		     	this->top=0;
			 }
			 void push( T element );
			 T pop();
			 bool isEmpty();
			 T topValue();
};


template<class T>
void LinkedStack<T>::push(T element) 
{
    Node<T>* n = new Node<T>(element);
    
    if (top == 0 )
    {
        top = n;
    } 
	else {
        n->setNext(top);
        top = n;
    }
}

template<class T>
T LinkedStack<T>::pop()// Delete from HEAD
 {
 	T element;
 	
    if ( top == 0 ) {
        cerr << "Stack Underflow" << endl;
    }
    else
	{
		element = top->getInfo();
		Node<T>* ptr= top->getNext();
        delete top;
        top=ptr;
    }
    return element;
}

template <class T>
bool LinkedStack<T>:: isEmpty()
{
	return top == 0;
}


template <class T>
T LinkedStack<T>:: topValue()
{
		 return top->getInfo();
}
