#include<iostream>
#include<string>
#pragma once
using namespace std;
class node
{
private:
	char value;
	node *next;
public:
	node(){}
	char getValue()
	{
		return this->value;
	}
	void push(char val_in, node **top)
	{
		node *ptr = new(node);
		ptr->value = val_in;
		ptr->next = NULL;
		if (*top == NULL)
		{
			*top = ptr;
			//cout << "Value Inserted in Empty Stack" << endl;
		}
		else
		{
			ptr->next = *top;
			*top = ptr;
			//cout << "Value Inserted" << endl;
		}
	}
	char pop(node **top)
	{
		if (*top == NULL)
		{
			//return '.';
			//cout << "STACK UNDERFLOW!" << endl;
		}
		else
		{
			node *ptr = *top;
			//cout << "Poped data=" << ptr->value << endl;
			char out = ptr->value;
			*top = (*top)->next;
			delete ptr;
			return out;
		}
	}
	bool isEmpty(node **top)
	{
		if (*top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	char peek(node **top)
	{
		if (*top == NULL)
		{
			return NULL;
		}
		else
		{
			return (*top)->value;
		}

	}
	int precedence(char val_in)
	{
		if (val_in == '+' || val_in == '-')
		{
			return 4;
		}
		else if (val_in == '*' || val_in == '/')
		{
			return 5;
		}
		else if (val_in == '<' || val_in == '>' || val_in == '~' || val_in == '=')
		{
			return 3;
		}
		else if (val_in == '&')
		{
			return 2;
		}
		else if (val_in == '|')
		{
			return 1;
		}
		return -1;
	}
	bool isoperator(char in)
	{
		if (in == '+' || in == '-' || in == '*' || in == '/'
			|| in == '<' || in == '>' || in == '~' || in == '='
			|| in == '&' || in == '|' || in == '(' || in == ')')
		{
			return true;
		}
	}
	char* converter(char arr_in[], node **top)
	{
		int i, k;
		for (i = 0, k = -1; arr_in[i]; ++i)
		{
			if (isoperator(arr_in[i]) != true)
			{
				arr_in[++k] = arr_in[i];
			}
			else if (arr_in[i] == '(')
			{
				push(arr_in[i], &*top);
			}
			else if (arr_in[i] == ')')
			{
				while (((*top)->getValue() != '(') && (isEmpty(&*top) != true))
				{
					arr_in[++k] = pop(&*top);
				}
				if (((*top)->getValue() != '(') && (isEmpty(&*top) != true))
				{
					return NULL;
				}
				else
				{
					pop(&*top);
				}
			}
			else
			{
				int op = precedence(arr_in[i]);
				while ((isEmpty(top) == false) && (op <= precedence((*top)->value)))
				{
					arr_in[++k] = pop(&*top);
				}
				push(arr_in[i], &*top);
			}
		}
		while (isEmpty(&*top) == false)
		{

			arr_in[++k] = pop(&*top);
		}
		arr_in[++k] = '\0';
		//int size = sizeof(arr_in);
		char out[] = "";
		return arr_in;
	}
};