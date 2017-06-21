/*
Implementing Heap Sort
*/

/// Author :	Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class HeapSorting
{
public:
	int a[50],n,l,r,size;
	void input()
	{
		cout << "How many elements to enter\n";
		cin >> n;
		cout << "Start entering\n";
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		cout << "Lets do the work\n";
		size = n-1;
	}
	void display()
	{
		cout << "After Heap Sort\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << "\t";
		cout << endl;
	}
	int left(int i)
	{
		return (2 * i)+1;
	}
	int right(int i)
	{
		return (2 * i) + 2;
	}
	void swap(int arr[], int i, int l)
	{
		int temp = arr[i];
		arr[i] = arr[l];
		arr[l] = temp;
	}
	void maxHeapify(int a[], int i)
	{
		int largest;
		l = left(i);
		r = right(i);
		if (l <= size&&a[l]>a[i])
		{
			largest = l;
		}
		else
			largest = i;
		if (r <= size&&a[r] > a[largest])
			largest = r;
		if (largest != i)
		{
			swap(a, i, largest);
			maxHeapify(a, largest);
		}
	}
	void buildMaxHeap()
	{
		for (int i = size / 2; i >= 0; i--)
			maxHeapify(a,i);
	}
	void HeapSort(int a[])
	{
		buildMaxHeap();
		swap(a, 0, size);
		size = size - 1;
		while (size > 0)
		{
			maxHeapify(a, 0);
			swap(a, 0, size);
			size = size - 1;
		}
	}
}h;
int main()
{
	h.input();
	h.HeapSort(h.a);
	h.display();
    return 0;
}

 
