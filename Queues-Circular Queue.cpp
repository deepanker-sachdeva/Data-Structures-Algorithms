/*
Implementation of Circular Queue
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

class circularQueue
{
public:
	int a[20],n,f,r;																			//a is the queue array, f and r are index ptrs, n is total size of the queue
	void display()
	{
		cout << "Showing the Queue & F,R\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << "\t";
		cout << "F=" << f << " & R=" << r<<endl;
	}
	void qinsert(int item)																		//insertion function
	{
		if ((r == n&&f == 1) || (f == r + 1))
		{
			cout << "Overflow\nQueue is already full\n";
			return;
		}
		if (f == 0 || r == 0)
		{
			f = 1;
			r = 1;
		}
		else if (r == n)																			
		{
			r = 1;
		}
		else
			r = r + 1;
		//rather than else if else , these at the last 
		//r=(r+1)%n;
		a[r-1] = item;
	}

	int qout()													//it pops the item out
	{
		int item;
		if (f == 0)
		{
			cout << "Queue is already empty\n";
			return 100000;
		}
		else
		{
			item = a[f-1];
			if (f == r)
			{
				f = 0;
				r = 0;
			}
			else
			{
				f = f + 1;
				if (f > n)
					f = 1;
			}
			//f=(f+1)%n;    in place of above else
		}
		return item;
	}
}q;
int main()
{
	cout << "Enter the size of the queue\n";
	cin >> q.n;
	cout << "Lets start the tasks\n";
	cout << "For Insertion, Press I and then after a space the element\ne.g. I 8\nFor Deletion, just press D\t\tPress ; to exit\n";
	char what='}';
	int item,flag=0;
	do
	{
		cin >> what;
		if (what == 'I'||what=='i')
		{
			cin >> item;
			q.qinsert(item);
		}
		else if (what == 'D'||what=='d')
		{
			if(flag==0)
				cout << "NOTE:\tWhen queue elements are popped out, they actually remain there until some other element overwrites them\n";
			item = q.qout();
			if(item!=100000)
				cout << "Element popped out is " << item << endl;
			flag = 1;
		}
		q.display();
	} while (what != ';');
	cout << "Bye\n";
    return 0;
}

