//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////           Authored and Copyrighted by Wilfido Castaneda    /////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "LinkedListCPP.h"
#include <stdexcept>


struct Node
{
	int data;
	Node *next;

	Node( int data )
		: data( data ), next( 0 )
	{}

};

LinkedList::LinkedList()
	: first(0), last(0), size(0), pad0(0)
{
}

LinkedList::LinkedList( const LinkedList & linkedList )
{
	//shallow copy for now
	this->first = linkedList.first;
	this->last = linkedList.last;
	this->size = linkedList.size;
	this->pad0 = 0;
}

LinkedList & LinkedList::operator=( const LinkedList & linkedList )
{
	if ( this != &linkedList )
	{
		//shallow copy for now
		this->first = linkedList.first;
		this->last = linkedList.last;
		this->size = linkedList.size;
		this->pad0 = 0;
	}

	return *this;
}

LinkedList::~LinkedList()
{
	Node* leadingPointer = this->first;
	if ( size > 0 )
	{
		for ( Node* i = this->first; i != this->last; i = leadingPointer )
		{
			leadingPointer = i->next;
			delete i;
		}

		delete this->last;

	}
}

Node * LinkedList::add( int index, int data )
{
	/*
		This function adds an element to a specified index.
		This function also supports checking for out of bound requests
	
	*/

	//Making sure that index is valid
	try
	{
		if ( index > this->size || index < 0 )
		{
			throw 10;
		}
	}
	catch(int x)
	{
		printf( "Index %d is out of bounds. Element %d was not added to LinkedList. Size is currently %d. ERROR CODE %d\n", index, data, this->size, x);
		return 0;
	}

	//if It is valid, check if adding to the front or the end
	if ( 0 == index )
	{
		return addFirst( data );
	}

	else if ( index == size )
	{
		return addLast(data);
	}


	//otherwise add it to the index originally wanted
	else
	{
		Node* newNode = new Node( data );
		int location = index - 1;
		Node* pWalker = this->first;
		for ( int i = 0; i < location; i++ )
		{
			pWalker = pWalker->next;
		}
		newNode->next = pWalker->next;
		pWalker->next = newNode;

		this->size++;
		return newNode;
	}


}

Node * LinkedList::add( int data )
{
	Node* newNode = new Node( data );

	if ( 0 == size )
	{
		this->first = newNode;
		this->last = newNode;
	}
	else
	{
		newNode->next = this->first;
		this->first = newNode;
	}

	this->size++;
	printf( "The node containing value %d has been added to the front\n", data );
	return newNode;
}

Node * LinkedList::addFirst( int data )
{
	return add(data);
}

Node * LinkedList::addLast( int data )
{
	Node* newNode = new Node( data );

	if ( 0 == size )
	{
		this->first = newNode;
		this->last = newNode;
	}
	else
	{
		this->last->next = newNode;
		this->last = newNode;
	}

	this->size++;
	printf( "The node containing value %d has been added to the end\n", data );
	return newNode;

}

int LinkedList::sizeOf()
{
	return this->size;
}

void LinkedList::printList()
{
	if ( this->first == 0 )
	{
		printf( "The current Linked List is empty!" );
		return;
	}
	else
	{
		printf( "The current linked list is as follows: %d", this->first->data );
		for ( Node* n = this->first->next; n != 0; n = n->next )
		{
			printf(" -> %d", n->data);
		}
		printf( "\n" );
		return;
	}

}
