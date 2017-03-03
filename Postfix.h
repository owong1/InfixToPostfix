#ifndef POSTFIX_H
#define POSTFIX_H
#define MAX 50			//max array size for expressions

class Arith{
public:
	//get operator precedence
	int getPrece(char ch);
	//conversion
	void infixToPostfix(char infix[], char postfix[], int size);
	//evaluate operations
	int eval(int op1, int op2, char op);
	//evaluate from postfix expression
	int evalPostfix(char postfix[], int size);

	//function to test program
	void test(char infix[]);
};

#endif