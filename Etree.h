#include<iostream>
#include<string>
#include<stack>
using namespace std;
#pragma once
class Etree
{
	
public:
	char value;
	Etree *left = NULL;
	Etree *right = NULL;
	char getValue()
	{
		return this->value;
	}
	Etree(char in)
	{
		this->value = in;
		this->left = NULL;
		this->right = NULL;
	}
		/*void BuildTree(char expression[])
	{
		//TreeStack stack;
		stack<Etree *> stack1;
		Etree *pushed;
		Etree *operand_poped1;
		Etree *operand_poped2;
		for (int i = 0; i < strlen(expression); i++)
		{
			if (!isoperator(expression[i]))
			{
				pushed = new(Etree);
				pushed->value = expression[i];
				pushed->right = NULL;
				pushed->left = NULL;
				stack1.push(pushed);
			}
			else
			{
				pushed = new(Etree);
				pushed->value = expression[i];
				pushed->right = NULL;
				pushed->left = NULL;
				operand_poped1 = stack1.top();
				stack1.pop();
				operand_poped2 = stack1.top();
				stack1.pop();
				pushed->right = operand_poped1;
				pushed->left = operand_poped2;
				stack1.push(pushed);
			}
		}
	}*/
};