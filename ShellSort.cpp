/*
Algorithm: Shell Sort
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class shell
{
public:int a[50] = { 62,83,18,53,7,17,95,86,47,69,25,28 };
	   int n = 12, j;
	void display()
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << "\n";
		cout << endl;
	}
	void shellsort()
	{
		int gap,temp;
		for (gap = n/2; gap >= 1;gap=gap/2)								//gap changes with each loop
		for (int i = gap;i<n; i++)
		{
			temp = a[i];
			for ( j = i; j >= gap && a[j - gap]>temp; j = j - gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
};
int main()
{
	char q;
	shell c;
	cout << "Want to do it with already given elements\nY for given\tN for new inputs\n";
	cin >> q;
	if (q == 'Y' || q == 'y')
	{
		c.display();
		c.shellsort();
		c.display();
	}
	else
	{
		cout << "Input the no. of elements\n";
		cin >> c.n;
		cout << "Input elements\n";
		for (int i = 0; i < c.n; i++)
			cin >> c.a[i];
		cout << "After applying shell sort\n";
		c.shellsort();
		c.display();
	}
    return 0;
}

