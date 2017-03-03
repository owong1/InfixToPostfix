#include<iostream>
#include<cstring>
#include<cctype>
#include "Stack.h"
#include "Postfix.h"

using namespace std;

// higher precedence is performed first
// and can be stacked on top
// for non operators, return 0 
int Arith::getPrece(char ch){
	switch (ch) {
	case '*':				//multiplication and division: highest
	case '/': return 2;
	case '+':
	case '-': return 1;		//addition and subtraction: second
	default: return 0;
	}
}

// convert infix expression to postfix using a stack
void Arith::infixToPostfix(char infix[], char postfix[], int size){
	Stack s;	//postfix stack
	int weight;
	int i = 0;		//infix iterator
	int j = 0;		//postfix iterator
	char ch;		//store read infix char
	// iterate over the infix expression   
	while (i < size){
		ch = infix[i];
		if (ch == '('){
			// push the opening parenthesis
			// on any occasion
			s.pushTop(ch);
			i++;
			continue;
		}
		if (ch == ')'){
			// if we see a closing parenthesis,
			// pop all the elements and append it to
			// the postfix expression until an opening
			// parenthesis is found
			while (!s.isEmpty() && s.getTop() != '('){
				postfix[j++] = s.getTop();
				s.popTop();
			}
			// pop off the opening parenthesis
			if (!s.isEmpty()){
				s.popTop();
			}
			i++;
			continue;
		}
		weight = getPrece(ch);
		if (weight == 0){
			// there is an operand
			// append it to postfix expression
			postfix[j++] = ch;

		}
		else {
			// there is an operator
			if (s.isEmpty()){
				// push the operator onto stack if
				// stack is empty
				s.pushTop(ch);
			}
			else{
				// pop all the operators from the stack and
				// append it to the postfix expression until we
				// see an operator with a lower precedence than
				// the current operator
				while (!s.isEmpty() && s.getTop() != '(' &&
					weight <= getPrece(s.getTop())){
					postfix[j++] = s.getTop();
					s.popTop();

				}
				// push the current operator onto stack
				s.pushTop(ch);
			}
		}
		i++;
	}
	// pop off the remaining operators present in the stack
	// and append it to postfix expression 
	while (!s.isEmpty()){
		postfix[j++] = s.getTop();
		s.popTop();
	}
	postfix[j] = 0; // null terminate the postfix expression 
}

// returns the value when a specific operator
// operates on two operands
int Arith::eval(int op1, int op2, char op) {
	switch (op) {
	case '*': return op2 * op1;
	case '/': return op2 / op1;
	case '+': return op2 + op1;
	case '-': return op2 - op1;
	default: return 0;
	}
}

// evaluate postfix operations using stack
int Arith::evalPostfix(char postfix[], int size){
	Stack operand;
	char p;
	int value;
	for(int i = 0; i < size; i++){
		p = postfix[i];
		if (isdigit(p)){
			// push the operand digit onto stack
			operand.pushTop(p - '0');
		}
		else{
			// there is an operator
			// pop off the top two operands from the
			// stack and evalute them using the current
			// operator
			int op1 = operand.getTop();
			operand.popTop();
			int op2 = operand.getTop();
			operand.popTop();
			value = eval(op1, op2, p);
			// push the value obtained after evaluating
			// onto the stack
			operand.pushTop(value);
		}
	}
	return value;
}

void Arith::test(char infix[]){
	Arith exp;
	int size;
	size = strlen(infix);						//size of infix
	char postfix[MAX];

	exp.infixToPostfix(infix, postfix, size);
	cout << "Infix Expression: " << infix << endl;
	cout << "Postfix Expression: " << postfix << endl;

	size = strlen(postfix);							//size of postfix
	int val = exp.evalPostfix(postfix, size);
	cout << "Expression evaluates to: " << val << endl;
}