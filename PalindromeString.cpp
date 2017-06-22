/*
Algorithm: To check if the given String is a palindrome
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include <string>
#include <iostream>


using namespace std;
class pal
{
public:
	int top = -1, k;
	int max = 50;
	string s[50];
	string g[100];
	char n[50],p[50];
	int notdone;
	void input()
	{
		cin >> n[0];
		for (int i = 1; n[i - 1] !=';'; i++)
			cin >> n[i];
	}
	void display()
	{
		for (int i = 0; n[i] != ';'; i++)
			cout << n[i] << endl;
	}

	void length()
	{
		k = 0;
		for (int i = 0; n[i] != ';'; i++)
			k++;
	}
	void copy()
	{
		for (int i = k-1, j = 0; j<k; i--)
		{
			p[j] = n[i];
			j++;
		}
	}
	void check()
	{
		for (int i = 0; n[i] != ';'; i++)
			if (n[i] != p[i])
			{
				cout << "NOT A Palindrome";
				notdone = -1;
				break;
				
			}
			else
				continue;
		if (notdone != -1)
		{
			cout << "Its a Palindrome";
		}
		return;
	}


	
	void push(string item)
	{
		if (top<max - 1)
		{
			top++;
			s[top] = item;
			return;
		}
	}
	void pop()
	{
		string s = "gogo";
		if (top != -1)
		{

			string item;
			// g[]=s[top];
			top--;
			return;
		}
	}

}l;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	string n[50];
	cout << "Input the string to check for a palindrome, enter ; at the end to get the ans.!\n";
	l.input();
	l.length();
	l.copy();
	l.check();
//	cout << "Its is a Palindrome";

	//cout<<l.s[0];
	//cout<<endl<<l.s[1];
	return 0;
}
