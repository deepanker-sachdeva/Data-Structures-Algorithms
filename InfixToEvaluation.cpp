/*
This program is to convert an Infix calculation equation to Postfix and then evaluate it using the postfix evaluation method as used by our calculators.
: Infix to Postfix to Evaluation of the equation
*/

///  Author : Deepanker Sachdeva
//#include "stdafx.h"
#include<iostream>
#include<math.h>
using namespace std;
int flag = 0;									//flag=0 for normal execution
class infixpostfix								//class with the functions to convert infix to postfix
{
	//variable declarations for stack
	int pos = -1;								
	const int max = 50;
	char item;

public:
	int i = 0;
	char a[50];									//input array infix
	char b[50];									//stack
	char p[50];									//output array postfix
	int pcopy;
	int operandcheck;
	void input()
	{
		cout<<"This program is to convert an Infix calculation equation to Postfix and then evaluate it!\n";
		cout<<"Note: While entering the numbers, give only 1 digit no. \n(I haven't adapted it to take 2 or 3 digit calculations!).\n\n";
		cout << "Enter the the way you want, just remember to add a ; at the end\t(Eg. 2+3*5-(9*2-2); )\n";
		for (i = 0; a[i - 1] != ';'; i++)
			cin >> a[i];
		cout << endl;
	}
	void display()
	{
		for (int i = 0; p[i] != ';'; i++)
			cout << p[i];
		cout << endl;
	}

	void entersentinel(char a[])						//a sentinel ')' is added to check the ending of the array
	{
		int k = 0;
		for (int i = 0; a[i] != ';'; i++)
			k++;
		if (a[k] == ';')
			a[k] = ')';
		//if (a[i - 1] == ';')
			//a[i - 1] = ')';
	}



	int isoperand(char operand)					//checks if character is an operand
	{
		if ((operand >= 0x0030 && operand <= 0x0039) || (operand >= 0x0041 && operand <= 0x005A) || (operand >= 0x0061 && operand <= 0x007A))	//hex values (in unicode) for 0-9,A-Z,a-z
		{
			operandcheck = 1;
			return 1;
		}
		operandcheck = 0;
		return 0;
	}


	int precedence(char operators)				//it returns 0 if operator is not there, and a value (precedence) if it is an operator
	{
		int level = 0;
		switch (operators)
		{
		case '+':
		case '-':
			level = 2;
			break;
		case '*':
		case '/':
		case '%':
			level = 3;
			break;
		case '^':
			level = 5;
			break;
		}
		return level;
	}

	void infixToPostfix()
	{
		int j = 0, k= precedence(a[i]);
		char popped;
		push('(');
		for (int i = 0; pos >= 0; i++)
		{
			if (isoperand(a[i]))								//checks whether a[i] is an operand
			{
				p[j] = a[i];
				j++;
			}
			else if (a[i] == '(')
			{
				push(a[i]);
			}
			else if (k = precedence(a[i]))						//checking whether its an operator & if it is then what is its precedence
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
				if (popped == '(')
					push('(');									//if '(' is encountered it is to be pushed back
				push(a[i]);
			}
			else if (a[i] == ')')
			{
				popped = pop();
				while (popped != '(')
				{
					p[j] = popped;								//p is the o/p array
					j++;
					popped = pop();
				}
				p[j] = ';';										//at the end put ;
			}
			if (operandcheck == 0 && k == 0 && a[i] != ')'&&a[i] != '(')
			{
				cout << "Sorry, can't recognize " << a[i] << endl;
				flag = 1;
			}
		}
	}



	void push(char item)									//push function for maintaining the stack
	{
		if (pos < max - 1)
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

class postevaluation							//class with functions to evaluate the postfix expression
{
	int b[50];									//stack
	char p[50];									//postfix output from previous class
	int i = 0;

	//variables to maintain the stack
	int pos = -1;
	const int max = 50;
	int item;
public:
	void copyans(char a[])						//copying postfix o/p from previous to this class
	{
		for (i = 0; a[i - 1] != ';'; i++)
			p[i] = a[i];
	}
	void entersentinel()						//a sentinel ')' is added to check the ending of the array
	{
		if (p[i - 1] == ';')
			p[i - 1] = ')';
	}
	int isoperand_no(char operand)					//checks if character is an operand
	{
		if (operand >= 0x0030 && operand <= 0x0039)	//hex values (in unicode) for 0-9
			return 1;
		return 0;
	}

	void scan()
	{
		int flag = 0;							//if flag=0 then function gives the ans.
		int x, y, s;
		for (int i = 0; p[i] != ')'; i++)
		{
			int a = isoperand_no(p[i]);
			if (a)
			{
				item = p[i] - '0';				//converting character (like '8') into the int (like 8) [needed to subtract the relative position] [typecasting will return its unicode no.]
				push();							//if its a no. push into the stack
			}
			else if (checkvar(p[i]))
			{
				cout << "Enter the value for " << p[i] << endl;
				cin >> item;
				push();
			}
			else
			{
				x = pop();						//pop two no. if operator is encountered
				y = pop();
				switch (p[i])					//do the required operation
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
					s = pow(y, x);
					break;
				case '%':
					s = y%x;
					break;
				default:
					cout << "Sorry, " << p[i] << " is not an operator.\n";
					flag = 1;					//flag=1 to stop
				}
				if (flag == 1)
					break;
				item = s;
				push();							//push the ans. to the stack


			}
		}
		if (flag == 0)
			cout << "Evaluated answer is " << b[pos] << endl;	//retrun top of the stack as the final ans.
	}

	int checkvar(char operand)								//check if there is a variable input
	{
		if ((operand >= 0x0041 && operand <= 0x005A) || (operand >= 0x0061 && operand <= 0x007A))	//checks bet. a-z and A-Z for variable input
		{
			return 1;
		}
		return 0;
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

	
}p;

int main()
{
	c.input();
	c.entersentinel(c.a);
	c.infixToPostfix();
	if (flag == 0)
	{
		c.display();
		p.copyans(c.p);
		p.entersentinel();
		//p.checkvar();
		p.scan();
	}
	return 0;
}


