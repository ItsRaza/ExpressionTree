#include<iostream>
#include<string>
#include "Etree.h"
#pragma once
using namespace std;
class TreeStack
{	
public:
	Etree *node;
	TreeStack *next;
	TreeStack(Etree *node_in)
	{
		this->node = node_in;
		this->next = NULL;
	}
};