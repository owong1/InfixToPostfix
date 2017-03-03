#ifndef _NODE_H
#define _NODE_H

class Node{
public:
	int data;
	Node* next;
	Node* prev;

	//node ctor
	Node(int d){
		data = d;
		next = prev = NULL();
	}
};
#endif