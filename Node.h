#include <iostream>
using namespace std;
template<class T>

class Node
{
 	private :
	 T info;
	 Node<T> *next;

	public:
	 Node(T info=0 , Node *next=0)
	 {
		this->info=info;
		this->next=next; 	
	 }
	void setInfo(T info);
	void setNext(Node<T> * next);
	T getInfo();
	Node<T>* getNext();
	void display();
};

// can be move to node .ccp///// decleration
template<class T>
void Node<T> :: setInfo(T info)
{
	this -> info=info;
}//setinfo

template<class T>
void Node<T> :: setNext(Node<T>* next )
{
	this -> next=next;
}//setnext

template<class T>
T Node<T> :: getInfo()
{
	return this->info;
}//get info

template<class T>
Node<T>* Node<T>:: getNext()
{
	return this->next;
}//get next adress

template<class T>
void Node<T> ::display()
{
	cout<<"|("<<this<<")|"<<this->info<<"|"<<this->next<<"|"<<endl;
}
