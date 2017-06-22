/*
Tower of Hanoi (Recursive way)
*/

/// Author : Deepanker Sachdeva

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

//variables for stack
int posbeg = -1,posend=-1,posaux=-1,pos=-1;									//position variables for 3 stacks as beg,end,aux
const int max = 20;
/*
void push(int a[] , int * , int);											//prototype of the push and pop functions
int pop(int a[] , int *);
int item;

void tower(int n, int beg[], int aux[], int end[])
{
	if (n == 1)
		push(end, &posend, pop(beg, &posbeg));
	else if (n > 1)
	{
		tower(n - 1, beg, end, aux);
		push(end, &posend, pop(beg, &posbeg));
		tower(n - 1, aux, beg, end);
	}
}
*/

class towerhanoi
{
public:
	int n, beg[20], end[20], aux[20];										//declaration of 3 stacks and n is the no. of discs initially in beg
	string stack_non_rec[20];
	void input()
	{
		cout << "Enter the no. of discs to move\n";
		cin >> n;
		cout << "At start, the discs are in Begin Rod\n";
		for (int i = n; i >0; i--)
		{
			push(beg, &posbeg, i);											//put initial discs to beg
		}
	}
	void display(int a[])
	{
		for (int i = n - 1; i >= 0; i--)
		{
			cout << a[i] << endl;
		}
	}


	void tower(int n, int beg[], int aux[], int end[],int *posbeg,int *posaux,int *posend)			//it has args as n-the no. of discs
	{																								//beg,aux,end as reference to 3 stacks
		if (n == 1)																					//last 3 are pointers to top positions of the stacks
			push(end, posend, pop(beg, posbeg));
		else if (n > 1)
		{
			tower(n - 1, beg, end, aux,posbeg,posend,posaux);
			push(end, posend, pop(beg, posbeg));
			tower(n - 1, aux, beg, end,posaux,posbeg,posend);
		}
	}

/*	void tower_non_rec()
	{
		string k = (string) n;
		pushstring(n);
		while(pos!=-1)
		if(n==1)

	}
	*/
	void pushstring(string item)																//push function to write the item to the stack
	{
		if (pos < max - 1)
		{
			pos++;
			stack_non_rec[pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}

	string popstring()																//pop function to get element out of the stack
	{
		if (pos >= 0)
		{
			string item = stack_non_rec[pos];
			pos--;
			return item;
		}
		else
		{
			return "sorry";
		}
	}

	void push(int a[], int *pos, int item)																//push function to write the item to the stack
	{
		if (*pos < max - 1)
		{
			*pos = *pos + 1;
			a[*pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}

	int pop(int a[], int *pos)																//modified pop function to get element out of the stack
	{																						//and then delete element from there as would in real rods(towers)
		if (*pos >= 0)
		{
			int item = a[*pos];
			a[*pos] = 0;
			*pos = *pos - 1;
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
	/*
	int n, beg[20], end[20], aux[20];
	
	cout << "Enter the no. of discs to move\n";
	cin >> n;
	cout << "At start, the discs are in Begin Rod\n";
	for (int i = n; i >0; i--)
	{
		push(beg, &posbeg, i);
	}
	cout << "Displaying Begin Rod\n";
	for (int i = n-1; i >=0; i--)
	{
		cout << beg[i]<<endl;
	}
	tower(n, beg, aux, end);
	for (int i = n - 1; i >= 0; i--)
	{
		cout << end[i] << endl;
	}
	*/
	c.input();
	cout << "Displaying \n";
	cout<< "Begin Rod\n";
	c.display(c.beg);
	cout << "Auxiliary Rod\n";
	c.display(c.aux);
	cout << "End Rod\n";
	c.display(c.end);
	cout << "Applying The Algo\n";
	c.tower(c.n, c.beg, c.aux, c.end,&posbeg,&posaux,&posend);
	cout << "Displaying \n";
	cout << "Begin Rod\n";
	c.display(c.beg);
	cout << "Auxiliary Rod\n";
	c.display(c.aux);
	cout << "End Rod\n";
	c.display(c.end);
    return 0;
}

/*
void push(int a[],int *pos,int item)																//push function to write the item to the stack
{
	if (*pos < max - 1)
	{
		*pos=*pos+1;
		a[*pos] = item;
	}
	else
		cout << "Sorry, stack already full\n";
}

int pop(int a[],int *pos)																//pop function to get element out of the stack
{
	if (*pos >= 0)
	{
		int item = a[*pos];
		*pos=*pos-1;
		return item;
	}
	else
	{
		return -1;
	}
}*/
