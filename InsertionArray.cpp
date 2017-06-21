/*
A simple program to show insertion of elements in an array
*/

///  Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class arrayins
{
	int a[20];
	int n,k,l;
public:void input()
	{
		cout << "Enter the no. of elements you wanna add.";
		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " th Element\n";
			cin >> a[i];
			cout << "\n";
		}
	}
	void insert(int k,int l,int count)
	{
		for (int i = n+count; i >= k - 1; i--)
			a[i] = a[i - 1];
		a[k - 1] = l;
	}
	void check(int count)
	{
		//error in n<20
		if (n < 20)
		{
			cout << "Enter where u wanna add, enter the position\n";
			cin >> k;
			if (k - 1 < 20)
			{
				cout << "Enter the element\n";
				cin >> l;
				insert(k,l,count);
			}
			else
				cout << "Invalid location";
		}
		else
			cout << "Array is full, new element can't be added";
	}
	void display(int count)
	{
		for (int i = 0; i < n+count; i++)
			cout << a[i] << "\t";
	}

	void check2(int count)
	{
		cout << "Enter where u wanna delete\n";
		cin >> k;
		if (k - 1 < n+count)
			delet(k-1,count);
	}

	void delet(int pos,int count)
	{
		for (int i = k - 1; i < n-1+count; i++)
			a[i] = a[i + 1];
	}
}c;
int main()
{
	int i,count=0;
	char o;
	c.input();
	do
	{
		cout << "What do u wanna do?\n1.Insertion\n2.Deletion";
		cin >> i;
		if (i == 1)
		{
			count++;
			c.check(count);
			c.display(count);
		}
		else
			if (i == 2)
			{
				
				c.check2(count);
				count--;
				c.display(count);
				
			}
		cout << "Wanna do anything else?\nY/N";
		cin >> o;
		
	} while (o == 'Y');
    return 0;
}

