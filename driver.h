#include<iostream>
#include<string>
#include"Etree.h"
#include"TreeStack.h"
using namespace std;
class driver
{
private:
	TreeStack *top;
public:
	driver()
	{
		top = NULL;
	}
	bool isoperator(char in)
	{
		if (in == '+' || in == '-' || in == '*' || in == '/'
			|| in == '<' || in == '>' || in == '~' || in == '='
			|| in == '&' || in == '|' || in == '(' || in == ')')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(Etree *ptr_in)
	{
		if (top == NULL)
		{
			top = new TreeStack(ptr_in);
			//cout << "Value Inserted in Empty Stack" << endl;
		}
		else
		{
			TreeStack *ptr = new TreeStack(ptr_in);
			ptr->next = top;
			top = ptr;
			//cout << "Value Inserted" << endl;
		}
	}
	Etree* pop()
	{
		if (top == NULL)
		{
			//cout << "STACK UNDERFLOW!" << endl;
			//return;
		}
		else
		{
			Etree *ptr = top->node;
			top = top->next;
			return ptr;
		}
	}
	void BuildTree(char exp[])
	{
		for (int i = 0; exp[i]; i++)
		{
			if (isoperator(exp[i])==false)
			{
				Etree *newnode = new Etree(exp[i]);
				newnode->value = exp[i];
				newnode->left = NULL;
				newnode->right = NULL;
				push(newnode);
			}
			else
			{
				Etree *newnode = new Etree(exp[i]);
				newnode->value = exp[i];
				newnode->right =pop();
				newnode->left = pop();
				push(newnode);
			}
		}
	}
	void Postorder(Etree *root)
	{
		if (root == NULL)
		{
			return;
		}
		Postorder(root->left);
		Postorder(root->right);
		cout << root->value << endl;
	}
	void prefix()
	{
		Preorder(top->node);
	}
	void Preorder(Etree *root)
	{
		if (root == NULL)
		{
			return;
		}
		cout << root->value;
		Preorder(root->left);
		Preorder(root->right);
	}


};