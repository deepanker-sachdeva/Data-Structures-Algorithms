/*
Algorithm:		Merge Sort
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;
class mergesorting
{
	
public:	int n; int a[20];											//n is the no. of elements
	void input()													//a is the input array
	{
		cout << "Enter the elements:\n";
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void display()													//display function
	{
		cout << "Displaying all the elements\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << endl;
	}
	void mergesort(int initial, int end)							//merge sort function
	{
		int middle;
		if (initial < end)
		{
			middle = (initial + end) / 2;
			mergesort(initial, middle);								//recursive call to divide into left
			mergesort(middle + 1, end);								//and right array
			merge(initial, middle, end);							//merge function to sort them in steps
		}
	}
	void merge( int initial, int middle, int end)					//merge function actually sorts the arrays
	{
		int i, j;
		int nleft = middle - initial + 1;
		int nright = end - middle;
		int left[20],right[20];
		for (i = 0; i < nleft; i++)
			left[i] = a[i + initial];
		for (i = 0; i < nright; i++)
			right[i] = a[i + middle+1];//i+nleft+initial-1
		left[nleft] = a[middle] * 2000;//for all values of a negligible to left[nleft+1]
		right[nright] = a[middle + 1] * 2000;
		for (int k = initial, i = 0, j = 0; k <= end; k++)
		{
			
			if (left[i] <= right[j])
			{
				a[k] = left[i];
				i++;
			}
			else 
			{
				a[k] = right[j];
				j++;
			}
		}
	}
}c;
int main()
{
	cout << "Enter the no. of elements\n";
	cin >> c.n;
	c.input();
	c.mergesort(0, c.n - 1);
	cout << "After Sorting:";
	c.display();
    return 0;
}

