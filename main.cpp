#include <iostream>
#include "Postfix.h"

using namespace std;

int main(){
	Arith exp;
	//first example
	char f[MAX] = "5*(2+1)/3";
	exp.test(f);

	cout << endl;

	//second example
	char g[MAX] = "(9-1)+5*6/(7-4)-(2*3+8)";
	exp.test(g);

	//keep .exe window open
	getchar();
	return 0;
}