/*
Algorithm: Selection Sort
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class selectionsort
{
	int a[10];
public:
	void input()
	{
		cout << "Input 10 numbers\n";
		for (int i = 0; i < 10; i++)
		{
			cin >> a[i];
		}
	}
	void display()
	{
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << endl;
		}
	}
	void selection()								//selection sort function
	{
		int i,smallindex;
		for (i = 0; i < 9; i++)
		{
			smallindex = smallest(i);
			swap(i,smallindex);
		}
	}
private:
	int smallest(int i)								//to get the smallest out of given numbers
	{
		int small = a[i];
		int j = i;
		for (; i < 9; i++)
		{
			if (small > a[i + 1])
			{
				j = i + 1;
				small = a[i + 1];
			}
		}
		return j;
	}

	void swap(int i,int j)							//swapping function
	{
		int temp=a[j];
		a[j] = a[i];
		a[i] = temp;
	}
}c;
int main()
{
	c.input();
	cout << "After selection sort\n";
	c.selection();
	c.display();
    return 0;
}

