/*
Sorting Algoritms: with count of comparisons and swappings 
Insertion Sort
Bubble Sort
Selection Sort
Shell Sort

Searching:
Linear Search
Binary Search
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"

#include<iostream>
using namespace std;

class sortsearch
{
	int a[50];												//input array
	int n;													//no. of elements for the array
	
public:
	int compare = 0, swapi = 0;
	void input()
	{
		cout << "Enter the no. of elements to enter\n";
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
			cout << a[i] << "\t";
		}
		cout << endl;
	}

	//insertion sort
	void insertion()									//function to insertion sort
	{
		int temp, j, i;
		for (j = 1; j < n; j++)
		{
			temp = a[j];
			i = j - 1;
			for (; (compare = compare + 1) && (a[i] > temp&&i >= 0); i--)
			{
				swapi++;
				a[i + 1] = a[i];
			}
			a[i + 1] = temp;							//entering and displacing other elements
			swapi++;						
		}
	}


	//bubble sort
	void bubble()										
	{
		int temp;										//temp to swap
		for (int j = 0; j <= n - 2; j++)
			for (int i = 0; i < n - 1 - j; i++)
			{
				if ((compare = compare + 1) && (a[i] > a[i + 1]))
				{										//if previous is greater then swap
					temp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = temp;
					swapi++;
				}
			}
	}

	//selection sort
	void selection()								//selection sort function
	{
		int i, smallindex;
		for (i = 0; i < n-1; i++)
		{
			smallindex = smallest(i);
			swap(i, smallindex);
		}
	}
private:
	int smallest(int i)								//to get the smallest out of given numbers
	{
		int small = a[i];
		int j = i;
		for (; i < n-1; i++)
		{
			if ((compare=compare+1)&&(small > a[i + 1]))
			{
				j = i + 1;
				small = a[i + 1];
			}
		}
		return j;
	}

	void swap(int i, int j)							//swapping function
	{
		swapi++;
		int temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}

public:

	//linear search
	int search(int find)
	{
		for (int i = 0; i < n-1; i++)
			if ((compare = compare + 1) && (a[i] == find))
				return i + 1;
		return 0;
	}

	//binary search
	int binarysearch(int find)
	{
		int lb = 0, ub = n - 1;									//lowerbound and upperbounds are initialized
		int mid = (ub + lb) / 2;
		while (lb <= ub)
		{
			compare++;
			if (a[mid] == find)
			{
				compare++;
				return mid + 1;
			}
			else if (a[mid] > find)
			{
				compare = compare + 2;
				ub = mid - 1;
			}
			else
			{
				compare = compare + 2;
				lb = mid + 1;
			}
			mid = (ub + lb) / 2;
		}
		return -1;
	}
	
	//shell sort
	void shellsort()
	{
		int gap, temp,j;
		for (gap = n / 2; gap >= 1; gap = gap / 2)								//gap changes with each loop
			for (int i = gap; i<n; i++)
			{
				temp = a[i];
				for (j = i; compare++&& j >= gap && a[j - gap]>temp; j = j - gap)
				{
					swapi++;
					a[j] = a[j - gap];
				}
				a[j] = temp;
				swapi++;

			}
	}

}c;
int main()
{
	char d,y;
	int count = 0;
	do
	{
		int choice,choose;
	vaps:cout << "What do you wanna do?\n1. Sorting\n2. Searching\n";
		cin >> choice;
		if (count == 1&&(choice==1||choice==2))
		{
			cout << "Want to use previous numbers\n y for yes";
			cin >> y;
			if (y == 'y');
			else
				c.input();
		}
		else if(choice == 1 || choice == 2)
			c.input();

		if (choice == 1)
		{
		vapis:cout << "1. Insertion Sort\n2. Bubble Sort\n3. Selection Sort\n4. Shell Sort\n";
			cin >> choose;
			if (choose == 1)
				c.insertion();
			else if (choose == 2)
				c.bubble();
			else if (choose == 3)
				c.selection();
			else if (choose == 4)
				c.shellsort();
			else
			{
				cout << "Please, select the right choice\n";
				goto vapis;
			}
			cout << "After Sorting\n";
			c.display();
			cout << "Total No. of comparisons= " << c.compare << "\nTotal no. of swappings/movings= " << c.swapi << endl;
		}
		else if (choice == 2)
		{
		vapsy:cout << "1. Linear Search\n2. Binary Search\n";
			cin >> choose;
			int find, found;
			cout << "Enter the element u wanna find\n";
			cin >> find;
			if (choose == 1)
			{
				found = c.search(find);
			}
			else if (choose == 2)
			{
				cout << "As its binary search, it only search the already sorted array\nSo, after sorting it\n";
				c.bubble();
				c.display();
				found = c.binarysearch(find);
			}
			else
			{
				cout << "Please, select the right choice\n";
				goto vapsy;
			}
			
			if (found > 0)
				cout << "Its found on\t" << found << "th position\n";
			else
				cout << "Not found\n";
			cout << "Total No. of comparisons= " << c.compare << endl;
		}
		else
		{
			cout << "Please, select the right choice\n";
			goto vaps;
		}
		cout << "Want to continue?  Press y to continue.\n";
		cin >> d;
		count = 1;
	} while (d == 'Y' || d == 'y');
	return 0;
}

