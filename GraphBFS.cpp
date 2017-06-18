/*
Breadth First Search on Graph
:BFS Algo
*/

/// 	Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct node
{
	char name;
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
int lastIndex = -1;
arr a[20];
class Graph
{
public:
	int imax = numeric_limits<int>::max();
	int imin = numeric_limits<int>::min();
	int flag = 0;
	void createNode(arr a[])
	{
		char name;
		cout << "Enter the name of the node\t";
		cin >> name;
		a[++lastIndex].name = name;
		a[lastIndex].head = NULL;
		a[lastIndex].parent = -1;
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
	back:cout << "Enter the name of two nodes to make an edge between\n";
		cin >> x;
		cin >> y;
		flag = 0;
		int index = search(x);
		if (flag == 0 && index == -1)
		{
			cout << "Sorry, couldn't find a node with a name" << x << endl;
			goto back;
		}
		connectLL(index, y);
		flag = 0;
		index = search(y);
		if (flag == 0 && index == -1)
		{
			cout << "Sorry, couldn't find a node with a name" << y << endl;
			goto back;
		}
		connectLL(index, x);
	}

	void connectLL(int index, char y)
	{
		node *ptr = a[index].head, *newn;
		if (ptr != NULL)
		{
			newn = create(y);
			newn->next = ptr;
			a[index].head = newn;
		}
		else
			a[index].head = create(y);
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

class circularQueue:public Graph
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
	void qinsert(int q[],int item)																		//insertion function
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
}q;

class GraphBFS:public circularQueue
{
public:
	void GrBFS(arr a[], char source)
	{
		int index = search(source),u,v;
		for (int i = 0; i <= lastIndex; i++)
		{
			a[i].color = "white";
			a[i].dist = imax;
			a[i].parent = NULL;
		}
		a[index].color = "grey";
		a[index].dist = 0;
		a[index].parent = NULL;
		qinsert(q, index);//queue has the index of the source node
		while (f != 0)//to check if queue is empty
		{
			u = qout();
			cout << a[u].name<<"\t";
			node *ptr = a[u].head;
			while (ptr != NULL)
			{
				v=search(ptr->name);
				if (a[v].color == "white")
				{
					a[v].color = "grey";
					a[v].dist = a[u].dist + 1;
					a[v].parent = u;
					qinsert(q, v);
				}
				ptr = ptr->next;
			}
			a[u].color = "black";
		}
	}
}bfs;
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
	cout << "Now, from which node to start the BFS?\n";
	char name;
	cin >> name;
	bfs.GrBFS(a, name);
	return 0;
}








//may get a small if a is null-
//problem when after creating the nodes and linking them, it goes in grbfs and search in the same arr a[20] but all the a[] is null
