/*
Implementation of basic
Binary Search
*/

/// Author:   Deepanker Sachdeva

//#include"stdafx.h"
#include<iostream>
using namespace std;

class arrabinaryalgo
{
	int a[20];														//array for input
public:
	int input()
	{
		int n;
		cout << "Enter the no. of elements and then enter them\n";
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		return n;
	}
	   int binarysearch(int n, int find)
	   {
		   int lb = 0, ub = n - 1;									//lowerbound and upperbounds are initialized
		   int mid = (ub + lb) / 2;
		   while (lb <= ub)
		   {
			   if (a[mid] == find)
				   return mid + 1;
			   else if (a[mid] > find)
				   ub = mid - 1;
			   else
				   lb = mid + 1;
			   mid = (ub + lb) / 2;
		   }
		   return -1;
	   }
	   void sort(int k)												//bubble sorting function
	   {
		   int temp;
		   for (int j = 0; j < k - 2; j++)
			   for (int i = 0; i < k - 1 - j; i++)
			   {
				   if (a[i] > a[i + 1])
				   {
					   temp = a[i];
					   a[i] = a[i + 1];
					   a[i + 1] = temp;
				   }
			   }
	   }
	   void display(int n)
	   {
		   for (int i = 0; i < n; i++)
			   cout << a[i] << endl;
	   }
}c;

int main()
{
	int n = c.input();
	int find;
	cout << "What to find?\n";
	cin >> find;
	c.sort(n);
	cout << "After sorting\n";
	c.display(n);
	int found = c.binarysearch(n, find);
	if (found == -1)
		cout << find << " not found!";
	else
	cout << found<<" is the position";
	return 0;
}
