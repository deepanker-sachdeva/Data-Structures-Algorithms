/*
Implementation of Stack:
Push and Pop operations
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//variables for stack
int pos=-1,a[20];										//a is the stack with size of 20
const int max = 20;

void push();											//prototype of the push and pop functions
int pop();
int item;
int main()
{
	string c;
	string p;
	int popi;											//popped element
	cout << "What to do? Right now stack is empty!\n";
	do {
	back:cout << "Wanna push or pop\nJust say the word eg.\npush 43\tor\tpop\n";
		cin >> p;
		if (p == "push" || p == "PUSH")
		{
			lo:
			cin >> item;
			push();
			cout << "Stack: ";
			for (int i = 0; i <= pos; i++)
			{
				cout << a[i] << "\t";
			}
		}
		else if (p == "pop" || p == "POP")
		{
		li:
			popi = pop();
			if (popi != -1)
				cout << "Item popped is " << popi;
			else
				cout << "Sorry, stack already empty\n";
		}
		else
		{
			goto back;
		}
		cout << "\nTo do more, just enter y \t(or you can directly give the commands)\n";
		cin >> c;
		if (c == "push")
		{
			goto lo;
		}
		else if (c == "pop")
			goto li;
	} while (c == "Y" || c == "y");
    return 0;
}

void push()																//push function to write the item to the stack
{
	if (pos < max-1)
	{
		pos++;
		a[pos] = item;
	}
	else
		cout << "Sorry, stack already full\n";
}

int pop()																//pop function to get element out of the stack
{
	if (pos >= 0)
	{
		int item = a[pos];
		pos--;
		return item;
	}
	else
	{
		return -1;
	}
}
