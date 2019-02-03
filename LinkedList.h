#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stddef.h> // std standard definitions
#include <vector> // Necessary library for vector class

template <typename E>
class LinkedList
{
public:
	size_t id; // Current id of this class instance
 	
 	LinkedList(); //Default non-compiler contructor 
 	LinkedList(const LinkedList<E> &); // Copy contructor
 	LinkedList(LinkedList<E> &&); // Move constructor
 	LinkedList( const E[] , size_t); // Array constructor
 	explicit LinkedList(const std::vector<E> &); // Vector constructor, explicit for avoid the compiler thinks that must do conversion of types
 	
 	
 	
 	
/*
public: 

	class iterator{
	
	Node * node_ptr;
	Node * node_ptr_tail;
	}
*/
	
private: 
	
	class Node{
		Node * prev;
		E elem;
		Node * next;
		
		Node(Node *, const E& , Node *); // Copy constructor  //DONE
		Node(Node *, E&& , Node*); // Move constructor  //DONE
		
		Node() = delete; // Not required due to have a element null, it can't exist
		Node operator=  (const Node &) = delete;
		Node operator= (Node &&) = delete;
		bool operator==  (const Node &) = delete;
		bool operator != (const Node &) = delete;
		bool operator==  (Node & n) = delete;
		bool operator != (Node & n) = delete;	
	};
	
private:
	Node * tail; //Pointer that points to the last node of the list
	Node * head; //Pointer that points to the first node of the list
	size_t size; 
	
private: 
	void copyList(const LinkedList<E> &);
	bool isEmpty(); // DONE
	
	Node& addLast(const E&);
	Node& addLast(E&&);
	

};

#endif
