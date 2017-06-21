/*
Algorithm:		MST Prim
				Minimum Spanning Tree using Prim's Algorithm
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct node
{
	char name;
	int wt;
	node *next;
};

struct arr
{
	char name;
	node *head;
	int key;
	int parent;
	string color;
};
arr a[20];
int lastIndex = -1, flag = 0;
/*struct arra
{
	char a;
	char b;
	int wt;
};
arra z[20];*/
/*class Stack
{
public:
	void push(char x, char y, int wt)																//push function to write the item to the stack
	{
		if (pos < max - 1)
		{
			pos++;
			z[pos].a = x;
			z[pos].b = y;
			z[pos].wt = wt;
		}
		else
			cout << "Sorry, stack already full\n";
	}
}stk;*/
int q[20], n = 19, max = 20, pos = -1;																			//a is the queue array, f and r are index ptrs, n is total size of the queue
class Stack
{
public:
	void push(int q[], int item)																//push function to write the item to the stack
	{
		if (pos < max - 1)
		{
			pos++;
			q[pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}
};
class Graph:public Stack
{
public:
	int imax = numeric_limits<int>::max();
	int imin = numeric_limits<int>::min();
	
	void createNode(arr a[])
	{
		char name;
		cout << "Enter the name of the node\t";
		cin >> name;
		a[++lastIndex].name = name;
		a[lastIndex].head = NULL;
		a[lastIndex].parent = NULL;
		a[lastIndex].key = imax;
		a[lastIndex].color = "white";
	}

	node *create(char data)
	{
		node *newnode = (node *)malloc(sizeof(node));
		newnode->name = data;
		newnode->next = NULL;
		return newnode;
	}

	void addEdge()
	{
		char x, y;
		int wt;
	back:cout << "Enter the name of two nodes to make an edge between\n";
		cin >> x;
		cin >> y;
		cout << "Enter the weight of the edge!";
		cin >> wt;
		flag = 0;
		int index = search(x);
		if (flag == 0 && index == -1)
		{
			cout << "Sorry, couldn't find a node with a name" << x << endl;
			goto back;
		}
		connectLL(index, y,wt);
		flag = 0;
		index = search(y);
		if (flag == 0 && index == -1)
		{
			cout << "Sorry, couldn't find a node with a name" << y << endl;
			goto back;
		}
		connectLL(index, x,wt);
	}

	void connectLL(int index, char y,int wt)
	{
		node *ptr = a[index].head, *newn;
		if (ptr != NULL)
		{
			newn = create(y);
			newn->wt = wt;
			newn->next = ptr;
			a[index].head = newn;
		}
		else
		{
			a[index].head = create(y);
			a[index].head->wt = wt;
		}
	}

	int search(char x)
	{
		node *ptr;
		if (lastIndex < 0)
		{
			cout << "Error, No nodes\n";
			return -1;
		}
		else
		{
			for (int i = 0; i <= lastIndex; i++)
				if (a[i].name == x)
				{
					ptr = a[i].head;
					if (ptr != NULL)
					{
						flag = 0;
						return i;
					}
					else
					{
						flag = 1;
						return i;
					}
				}
			return -1;
		}
	}
	void deleteN()
	{
		char x;
		cout << "Enter the name of the node to Delete\n";
		cin >> x;
		int index = search(x);
		node *ptr = a[index].head, *temp = NULL;
		a[index].head = NULL;
		while (ptr != NULL)
		{
			temp = ptr;
			traverseDel(ptr, x);
			ptr = ptr->next;
			free(temp);
		}
		a[index].name = NULL;
	}
	void traverseDel(node *ptr, char x)
	{
		char y = ptr->name;
		int index = search(y);
		deleteLink(index, x);
	}
	void deleteLink(int index, char x)
	{
		node *ptr = a[index].head, *temp;
		temp = ptr;
		while (ptr->name != x)
		{
			temp = ptr;
			ptr = ptr->next;
		}
		if (temp == ptr)
		{
			a[index].head = ptr->next;
		}
		else
			temp->next = ptr->next;
		free(ptr);
	}
}g;
/*class circularQueue :public Graph
{
public:
	int q[20], n = 19, f, r;																			//a is the queue array, f and r are index ptrs, n is total size of the queue
	void display()
	{
		cout << "Showing the Queue & F,R\n";
		for (int i = 0; i < n; i++)
			cout << q[i] << "\t";
		cout << "F=" << f << " & R=" << r << endl;
	}
	void qinsert(int q[], int item)																		//insertion function
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
		q[r - 1] = item;
	}

	int qout()													//it pops the item out
	{
		int item;
		if (f == 0)
		{
			return imin;
		}
		else
		{
			item = q[f - 1];
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
}q;*/
int flagi = 0;
arr A[20];
int lastIndexA = -1;
class MST_Prim:public Graph
{
public:int last;
	void prim(arr a[],int r)
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			a[i].key = imax;
			a[i].parent = -1;
		}
		a[r].key = 0;
		initializeStack(q);
		for (int k = 0; k <= lastIndex; k++)
		{
			push(q, k);
		}
		int i;
		while (1)
		{
			i = extractMin();
			if (flagi == 1)
				break;
			traverseLL(i);
			a[i].color = "black";
		}
	}

	void initializeStack(int q[])
	{
		for (int i = 0; i < 20; i++)
			q[i] = imax;
	}
	/*int extractMin(arra q[])
	{
		int small=0;
		for (int i = 0; i <= lastIndex; i++)
			if (q[small].wt > q[i].wt)
				small = i;
		if (q[small].wt == imax)
			flagi = 1;
		q[small].wt = imax;
		return small;
	}*/
	int extractMin()
	{
		int small = 0;
		for (int i = 0; i <20; i++)
			if (a[q[small]].key > a[q[i]].key&&q[i] != -1)
				small = i;
		if (q[small] == imax)
			flagi = 1;
		q[small] = imax;
		return small;
	}
	void traverseLL(int i)
	{
		int k;
		node *ptr = a[i].head;
		while (ptr != NULL)
		{
			k = search(ptr->name);
			if (a[k].color == "white"&&ptr->wt<a[search(ptr->name)].key)
			{
				a[k].parent = i;
				a[k].key = ptr->wt;
				last = k;
			}
			ptr = ptr->next;
		}
	}

	void printallParents()
	{
		for (int i = 0; i <= lastIndex; i++)
			cout << a[i].name << ":\t" << a[a[i].parent].name << endl;
	}

	void makeGraphArray(arr A[])
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			lastIndexA++;
			A[lastIndexA].name = a[i].name;
			A[lastIndexA].key = a[i].key;
			A[lastIndexA].parent = a[i].parent;
			A[lastIndexA].head = NULL;
		}
	}
	void makeGraph(arr A[])
	{
		makeGraphArray(A);
		int k;
		for (int i = 0; i <= lastIndexA; i++)
		{
			k = A[i].parent;
			if (k != -1)
			{
				makeParent(i, k);
			}
		}
	}
	void makeParent(int i, int k)
	{
		node *ptr = A[k].head, *pt, *temp = NULL;
		if (ptr != NULL)
		{
			while (ptr != NULL)
			{
				temp = ptr;
				ptr = ptr->next;
			}
			ptr = create(A[i].name);
			temp->next = ptr;
		}
		else
		{
			ptr = create(A[i].name);
			A[k].head = ptr;
		}
		pt = a[search(A[i].name)].head;
		if (pt != NULL)
		{
			while (pt != NULL)
			{
				if (pt->name == A[k].name)
					break;
				pt = pt->next;
			}
			ptr->wt = pt->wt;
		}
	}

	void printShortestPath()
	{
		int i;
		for (i = 0; i <= lastIndexA; i++)
		{
			if (A[i].parent == -1)
				break;
		}
		cout << A[i].name << "--";
		traversePath(i);
	}

	void traversePath(int i)
	{
		int k;

		node *ptr = A[i].head;
		while (ptr != NULL)
		{
			k = searchA(ptr->name);
			cout << "--" << ptr->wt << "--" << ptr->name;
			traversePath(k);
			ptr = ptr->next;
			if (ptr != NULL)
				cout << endl << A[i].name;
		}
	}
	int searchA(char x)
	{
		node *ptr;
		if (lastIndex < 0)
		{
			cout << "Error, No nodes\n";
			return -1;
		}
		else
		{
			for (int i = 0; i <= lastIndex; i++)
				if (A[i].name == x)
				{
					ptr = A[i].head;
					if (ptr != NULL)
					{
						flag = 0;
						return i;
					}
					else
					{
						flag = 1;
						return i;
					}
				}
			return -1;
		}
	}
	/*void printPaths()
	{
		int nodes[10],k=-1;
		for (int i = 0; i <= lastIndex; i++)
		{
			if (A[i].head == NULL&&A[i].parent != -1)
			{
				k++;
				nodes[k] = i;
			}
		}
		for (int i = 0; i <= k; i++)
		{
			printPathfromStart(nodes[k]);
			cout << endl;
		}
	}

	void printPathfromStart(int k)
	{
		if (A[k].parent != -1)
			printPathfromStart(A[k].parent);
		cout << A[k].name<<"--";
	}*/
}p;
int main()
{
	char ch;
	cout << "Let's create the first node\n";
	g.createNode(a);
	cout << "Now to do diff. tasks, Press-\n";
	cout << "N - Making newnode\nE - Connecting the nodes(Making Edges)\nD - Deleting a node\nX - To Exit\n";
	do
	{
		cout << "Enter the command\n";
		cin >> ch;
		switch (ch)
		{
		case 'N':
		case 'n':
			g.createNode(a);
			break;
		case 'E':
		case 'e':
			g.addEdge();
			break;
		case 'D':
		case 'd':
			g.deleteN();
		}
	} while (ch != 'X' && ch != 'x');
	p.prim(a, 0);
	p.printallParents();
	cout << "\n";
	p.makeGraph(A);
	p.printShortestPath();
	return 0;
}

