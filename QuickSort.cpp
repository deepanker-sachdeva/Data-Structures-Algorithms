/*
Algorithm: Quick Sort
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;



class quicksorting
{
	//variables for stack
	int pos = -1;// , a[20];										//a is the stack with size of 20
	const int max = 20;
	int stack[50];
public:	int n; int a[20];											//a is the array of 20 elements max. to sort

		void input()
		{
			cout << "Enter the no. of elements to quick sort\n";
			cin >> n;
			cout << "Enter the elements:\n";
			for (int i = 0; i < n; i++)
				cin >> a[i];
		}
		void display()
		{
			cout << "Displaying all the elements\n";
			for (int i = 0; i < n; i++)
				cout << a[i] << "\t";
		}

		int partition(int initial,int end)
		{
			int x = a[end];								//last no. taken as pivot
			int i = initial - 1;
			for (int j = initial; j <= end - 1;j++)
				if (a[j] <= x)
				{
					i++;								//index for smaller window
					swap(a[i], a[j]);
				}
			swap(a[i + 1], a[end]);
			return i + 1;								//return the position of the pivot
		}

		void quicksort_rec(int initial, int end)			//recursive call of the quick sort function
		{
			int pivot;
			if (initial < end)
			{
				pivot = partition(initial, end);		//returns the pivot position

				quicksort_rec(initial, pivot - 1);			//divides array into left and right
				quicksort_rec(pivot + 1, end);
			}
		}

		void quicksort_non_rec(int initial, int end)
		{
		//	int stack[end - initial + 1];
			push(initial);
			push(end);
			while (pos != -1)
			{
				end = pop();
				initial = pop();
				if (initial < end)
				{
					int pivot = partition(initial, end);
					if (pivot - 1>initial&&pivot+1<end)
					{
						push(pivot + 1);
						push(end);
						push(initial);
						push(pivot - 1);
					}
					else if(pivot-1>initial&&pivot+1>=end)
					{
						push(initial);
						push(pivot - 1);
					}
					else
					{
						push(pivot + 1);
						push(end);
					}
				}
			}
		}

		void push(int item)																//push function to write the item to the stack
		{
			if (pos < max - 1)
			{
				pos++;
				stack[pos] = item;
			}
			else
				cout << "Sorry, stack already full\n";
		}

		int pop()																//pop function to get element out of the stack
		{
			if (pos >= 0)
			{
				int item = stack[pos];
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
	int opt;
	c.input();
	b:cout << "Want to use Recursive Way or Non-Recursive Way\n1.Recursive\t2.Non-Recursive\n";
	cin >> opt;
	if (opt == 1)
		c.quicksort_rec(0, c.n - 1);
	else if (opt == 2)
		c.quicksort_non_rec(0, c.n - 1);
	else
		goto b;
	c.display();
    return 0;
}
