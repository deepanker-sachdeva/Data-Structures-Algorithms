/*
Tower of Hanoi (Non-recursive way)
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>

using namespace std;
int posbeg = -1, posaux = -1, posend = -1;
class towerHanoi_non_rec
{
public:	int stkn[20], a[20], b[20], c[20], stkadd[20];					//a,b,c are the 3 stacks for 3 towers
	int top = -1, max = 20;
	int *stkbeg[40], *stkaux[40], *stkend[40];							//these stacks are for holding respective stacks out of 3 stacks a,b,c and their respective positions
	int add;
	

	int n;
	void input()
	{
		cout << "Enter the no. of discs to move, it can solve upto 10 discs (as according to the size of stacks used)\n";
		cin >> n;
		cout << "At start, the discs are in Begin or 1st Rod\n";
		for (int i = n; i >0; i--)
		{
			push(a, &posbeg, i);											//put initial discs to beg
		}
	}

	void display(int a[])
	{
		for (int i = n - 1; i >= 0; i--)
		{
			cout << a[i] << endl;
		}
	}

	int tower_non_rec(int beg[], int aux[], int end[], int *posbeg, int *posaux, int *posend)
	{
		return(step1(beg,aux, end,posbeg,posaux,posend));
		
	}
	int step1(int beg[], int aux[], int end[], int *posbeg, int *posaux, int *posend)
	{
		if (n == 1)
		{
			push(end,posend, pop(beg,posbeg));
			return(step5(beg,aux,end,posbeg,posaux,posend));
		}
		return(step2(beg, aux, end, posbeg, posaux, posend));
	}
	int step2(int beg[], int aux[], int end[], int *posbeg,int *posaux, int *posend)
	{
		int *tmp;
		top = top + 1;
		stkn[top] = n;
		stkbeg[top] = beg;
		stkbeg[top + 20] = posbeg;
		stkaux[top] = aux;
		stkaux[top + 20] = posaux;
		stkend[top] = end;
		stkend[top + 20] = posend;
		stkadd[top] = 3;
		n = n - 1;
		tmp = aux;
		aux = end;
		end = tmp;
		tmp = posaux;
		posaux = posend;
		posend = tmp;
		return(step1(beg, aux, end, posbeg,posaux, posend));
	}
	int step3(int beg[], int aux[], int end[], int *posbeg, int *posaux, int *posend)
	{
		push(end, posend, pop(beg, posbeg));
		return(step4(beg, aux, end, posbeg, posaux, posend));
	}
	int step4(int beg[], int aux[], int end[], int *posbeg,int *posaux, int *posend)
	{
		top = top + 1;
		stkn[top] = n;
		stkbeg[top] = beg;
		stkbeg[top + 20] = posbeg;
		stkaux[top] = aux;
		stkaux[top+20] = posaux;
		stkend[top] = end;
		stkend[top+20] = posend;
		stkadd[top] = 5;
		n = n - 1;
		int *tmp;
		tmp = beg;
		beg = aux;
		aux = tmp;
		tmp = posbeg;
		posbeg = posaux;
		posaux = tmp;
		return(step1(beg,aux, end, posbeg,posaux, posend));
	}
	int step5(int beg[], int aux[], int end[], int *posbeg, int *posaux, int *posend)
	{
		if (top != -1)
		{
			n = stkn[top];
			beg = stkbeg[top];
			posbeg = stkbeg[top + 20];
			aux = stkaux[top];
			posaux = stkaux[top + 20];
			end = stkend[top];
			posend = stkend[top + 20];
			add = stkadd[top];
			top = top - 1;
			if (add == 3)
				return(step3(beg, aux, end, posbeg, posaux, posend));
			else
				return(step5(beg, aux, end, posbeg, posaux, posend));
		}
		else
			return 1;
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
}z;


int main()
{
	z.input();
	z.display(z.a);
	int y=z.tower_non_rec(z.a, z.b, z.c, &posbeg, &posaux, &posend);

	if (y == 1)
	{
		cout << "After solving , showing 3rd rod\n";
		z.display(z.c);
	}
	return 0;
}

