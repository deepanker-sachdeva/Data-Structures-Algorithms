/*
This program is to convert an Infix calculation equation to Postfix.
: Infix to Postfix conversion
*/

///  Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

int pos = -1;
const int maxi = 50;
char item;

class infixpostfix
{
	int i = 0;
	char a[50];									//input array
	char b[50];									//stack
	char p[50];									//output array

public:
	void input()
	{
		cout<<"Here you can enter an Infix equation, to get it converted to Postfix as a result\n(Eg. a+b*c or a+2*d-(4/r); )\n";
		cout << "Enter the the way you want, just remember to add a ; at the end\n";
		for (i = 0; a[i - 1] != ';'; i++)
			cin >> a[i];
		cout << endl;
	}
	void display()
	{
		for (int i = 0; p[i] != ';'; i++)
			cout << p[i];
	}

	void entersentinel()						//a sentinel ')' is added to check the ending of the array
	{
		if (a[i - 1] == ';')
			a[i - 1] = ')';
	}

	

	int isoperand(char operand)					//checks if character is an operand
	{
		if ((operand >= 0x0030 && operand <= 0x0039)|| (operand >= 0x0041 && operand <= 0x005A) || (operand >= 0x0061 && operand <= 0x007A))	//hex values (in unicode) for 0-9,a-z,A-Z
			return 1;
		return 0;
	}

	

	int precedence(char operators)
	{
		int level=0;
		switch (operators)
		{
		case '+':
		case '-':
			level = 1;
			break;
		case '*':
		case '/':
			level = 2;
			break;
		case '%':
			level = 3;
			break;
		case '^':
			level = 4;
			break;
		}
		return level;
	}

	void infixToPostfix()
	{
		int j = 0, k;
		char popped;
		push('(');
		for (int i = 0; pos >= 0; i++)
		{
			if (isoperand(a[i]))
			{
				p[j] = a[i];
				j++;
			}
			else if (a[i] == '(')
			{
				push(a[i]);
			}
			else if (k = precedence(a[i]))						//checking whether its an operator & if it is then what is it
			{
				popped = pop();
				while (popped != '(')
				{
					if (precedence(popped) >= k)
					{
						p[j] = popped;
						j++;
					}
					else
					{
						push(popped);
						break;
					}
						popped = pop();
				}
				if(popped=='(')
				push('(');
				push(a[i]);
			}
			else if (a[i] == ')')
			{
				popped = pop();
				while (popped != '(')
				{
					p[j] = popped;
					j++;
					popped = pop();
				}
				//pop();
				p[j] = ';';
			}
		}
	}

	void push(char item)									//push function for maintaining the stack
	{
		if (pos < maxi - 1)
		{
			pos++;
			b[pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}

	char pop()									//pop function for maintaining the stack
	{
		if (pos >= 0)
		{
			char item = b[pos];
			pos--;
			return item;
		}
		else
		{
			return -1;
		}
	}
}c;

int main()
{
	c.input();
	c.entersentinel();
	c.infixToPostfix();
	c.display();
    return 0;
}

