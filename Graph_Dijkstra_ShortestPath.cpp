/*
Algorithm to find Shortest Path:

Dijkstra Algorithm on Graphs
*/

///	Author: Deepanker Sachdeva

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
	int dist;
	int parent;
	string color;
};
arr a[20];
int lastIndex = -1, flag = 0;

class Graph
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
		a[lastIndex].dist = imax;
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
		connectLL(index, y, wt);
		flag = 0;
		index = search(y);
		if (flag == 0 && index == -1)
		{
			cout << "Sorry, couldn't find a node with a name" << y << endl;
			goto back;
		}
		connectLL(index, x, wt);
	}

	void connectLL(int index, char y, int wt)
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
int q[20], n = 19, max = 20, pos = -1;																			//a is the queue array, f and r are index ptrs, n is total size of the queue
class Stack
{
public:
	void push(int q[],int item)																//push function to write the item to the stack
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
arr A[20];
int lastIndexA = -1;
class Dijkstra_ShortestPath :public Stack,public Graph
{
public:	
	int flagi = 0;
		void initializeStack(int q[])
		{
			for (int i = 0; i < 20; i++)
				q[i] = imax;
		}
		void initialize_SingleSource(arr a[], int s)
		{
			for (int i = 0; i <= lastIndex; i++)
			{
				a[i].dist = imax;
				a[i].parent = -1;
			}
			a[s].dist = 0;
		}
		void dijkstra(arr a[], int source)
		{
			initializeStack(q);
			initialize_SingleSource(a, source);
			for (int k = 0; k <= lastIndex; k++)
			{
				push(q, k);
			}
			int i;
			while (1)
			{
				i = extractMin();
				if (flagi==1)
					break;
				traverseLL(i);
				a[i].color = "black";
				
			}
			makeGraph(A);
		}
		void makeGraphArray(arr A[])
		{
			for (int i = 0; i <= lastIndex; i++)
			{
				lastIndexA++;
				A[lastIndexA].name = a[i].name;
				A[lastIndexA].dist = a[i].dist;
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
				if ( k!= -1)
				{
					makeParent(i,k);
				}
			}
		}
		void makeParent(int i, int k)
		{
			node *ptr = A[k].head,*pt,*temp=NULL;
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
			/*else
			{
				pt = a[search(A[k].name)].head;
				while (pt != NULL)
				{
					if (pt->name == A[k].name)
						break;
					pt = pt->next;
				}
				ptr->wt = pt->wt;
			}*/
		}
	   int extractMin()
	   {
		   int small = 0;
		   for (int i = 0; i <20; i++)
			   if (a[q[small]].dist > a[q[i]].dist&&q[i]!=-1)
				   small = i;
		   if (q[small] == imax)
			   flagi = 1;
		   q[small] =imax;
		   return small;
	   }

	   void traverseLL(int i)
	   {
		   int k;
		   node *ptr = a[i].head;
		   while (ptr != NULL)
		   {
			   k = search(ptr->name);
			   if (a[k].color == "white")
				   relax(i, k, ptr);
			   ptr = ptr->next;
		   }
	   }
	   void relax(int u, int v,node *ptr)
	   {
		   if (a[v].dist > a[u].dist + ptr->wt)
		   {
			   a[v].dist = a[u].dist + ptr->wt;
			   a[v].parent = u;
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
			   cout<< "--"<<ptr->wt << "--" << ptr->name;
			   traversePath(k);
			   ptr = ptr->next;
			   if(ptr!=NULL)
				   cout <<endl<< A[i].name ;
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
	cout << "Shortest Path algo using Dijkstra is" << endl;
	p.dijkstra(a, 0);
	p.printShortestPath();
}