#include <iostream>
#include <cassert>

#include "Stack.h"

using namespace std;

Stack::Stack(){	//ctor
	size = 0;
	top = NULL;
}
Stack::~Stack(){	//dtor
	while (!isEmpty()){
		popTop();
	}
}

void Stack::pushTop(int d){	//insert
	Node* n = new Node(d);	//n address of new node data = memory space
	if (isEmpty()){			//if empty, make space for inserting at top
		top = n;
	}
	else{
		n->prev = top;		//new at prev becomes head
		top->next = n;		//head at next becomes new
		top = n;
	}
	size++;					//increment size of stack
}

int Stack::popTop(){		//delete
	assert(!isEmpty());
	int d = top->data;		//copy of data
	if (getSize() == 1){	//delete node if only 1 node
		delete top;			//empty list
		top = NULL;
	}
	else{					//if more than one node
		top = top->prev;	//copy data to prev
		delete top->next;	//remove data
		top->next = NULL;	//removed address is null
	}
	size--;					//decrement size of stack
	return d;
}

//get top value of stack
int Stack::getTop(){
	int d;		
	d = popTop();	//store value
	pushTop(d);		//put it back
	return d;

	
}

bool Stack::isEmpty(){
	return size == 0 ? true : false;
}
int Stack::getSize(){
	return size;
}