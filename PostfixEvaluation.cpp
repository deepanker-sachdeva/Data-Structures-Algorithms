/*
Using Postfix Evaluation procedure
*/

/// Author : Deepanker Sachdeva

//only for 1-digit integer enries

//#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;

//for stack
int pos = -1;
const int max = 50;
int item;

class post
{
	int i = 0;
	char a[50];									//char array
	int b[50];									//stack

public:
	void input()
	{
		cout << "Enter the the way you want, just remember to add a ; at the end\n";
		for ( i = 0; a[i - 1] != ';'; i++)
			cin >> a[i];
		cout << endl;
	}
	void display()
	{
		for (int i = 0; a[i-1] != ')'; i++)
			cout<< a[i];
	}
	void entersentinel()						//a sentinel ')' is added to check the ending of the array
	{
		if (a[i-1] == ';')
		a[i-1] = ')';
	}
	int isoperand(char operand)					//checks if character is an operand
	{
		if (operand >= 0x0030 && operand <= 0x0039)	//hex values (in unicode) for 0-9
			return 1;
	}
	void scan()
	{
		int flag = 0;							//if flag=0 then function gives the ans.
		int x,y,s;
		for (int i = 0; a[i] != ')'; i++)
		{
			
			if (isoperand(a[i]) == 1)
			{
				item = a[i]-'0';				//converting character (like '8') into the int (like 8) [needed to subtract the relative position] [typecasting will return its unicode no.]
				push();							//if its a no. push into the stack
			}
			else
			{
				x = pop();						//pop two no. if operator is encountered
				y = pop();
				switch (a[i])					//do the required operation
				{
				case '+':
					s = y + x;
					break;
				case '-':
					s = y - x;
					break;
				case '*':
					s = y*x;
					break;
				case '/':
					s = y / x;
					break;
				case '^':
					s = pow(y,x);
					break;
				case '%':
					s = y%x;
					break;
				default:
					cout << "Sorry, " << a[i] << " is not an operator.\n";
					flag = 1;
				}
				item = s;
				push();							//push the ans. to the stack

			}
		}
		if(flag==0)
		cout << "Evaluated answer is " << b[pos]<<endl;	//retrun top of the stack as the final ans.
	}

	void checkvar()								//check if there is a variable input
	{
		for (int i = 0; a[i] != ')'; i++)
		{
			if ((a[i] >= 0x0041 && a[i] <= 0x005A) || (a[i] >= 0x0061 && a[i] <= 0x007A))	//checks bet. a-z and A-Z for variable input
			{
				cout << "Enter the value for " << a[i] << endl;
				cin >> a[i];
			}
		}
	}
	

	void push()									//push function for maintaining the stack
	{
		if (pos < max - 1)
		{
			pos++;
			b[pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}

	int pop()									//pop function for maintaining the stack
	{
		if (pos >= 0)
		{
			int item = b[pos];
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
	c.checkvar();
	c.scan();
	//c.display();
    return 0;
}

