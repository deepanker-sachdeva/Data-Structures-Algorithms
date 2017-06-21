/*
Basic Implementation of Insertion Sort
*/

///  Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class insertionsort
{
	int a[50];												//input array
	int n;													//no. of elements for the array
public:
	void input()
{
	cout << "Enter the no. of elements to enter";
	cin >> n;
	cout << "Enter the elements as numbers, one by one\n";
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ":\t";
		cin >> a[i];
	}
}
	void display()
	{
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << endl;
		}
	}

	void insertion()									//function to insertion sort
	{
		int temp,j,i;
		for (j = 1; j < n; j++)
		{
			temp = a[j];
			i = j - 1;
			for (; a[i] > temp&&i>=0; i--)
				a[i + 1] = a[i];						//entering and displacing other elements
			a[i + 1] = temp;
		}
	}
}c;
int main()
{
	c.input();
	cout << "After sorting\n";
	c.insertion();
	c.display();
    return 0;
}

