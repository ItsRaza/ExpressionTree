#include<iostream>
#include<string>
#include"Etree.h"
#include"TreeStack.h"
#include"charStack.h"
#include"driver.h"
using namespace std;
void main()
{
	node *top = NULL;
	Etree *root = NULL;
	node charstack;
	char infix[] = "(a+b(b*c)/d-(a+b))<(x+y)&c~e+b";
	cout << "Entered Infix Expression:"<<endl;
	for (int i = 0; infix[i]; i++)
	{
		cout << infix[i];
	}
	cout << endl;
	cout << endl;
	cout << "Equivalent PostFix is:"<<endl;
	char *postfix=charstack.converter(infix, &top);
	for (int i = 0; postfix[i]; i++)
	{
		cout  << postfix[i];
	}
	cout << endl;
	cout << endl;
	driver ET;
	ET.BuildTree(postfix);
	cout << "Expression Tree Traversed PREORDER" << endl;
	ET.prefix();
	cout << endl;
	cout << endl;
	system("pause");
}