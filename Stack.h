#ifndef _STACK_H
#define _STACK_H
#include "Node.h"

class Stack{
private:
	Node* top;			//creates top node
	int size;			//size counter: nodes

public:
	Stack();
	~Stack();

	void pushTop(int d);//adding to the top
	int popTop();		//removing from the top
	int getTop();

	int getSize();		//function that gets size/length
	bool isEmpty();
};

#endif