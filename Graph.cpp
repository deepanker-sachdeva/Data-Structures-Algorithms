/*
Implementation of Graphs :

Adjacency List Representation  (Using Linked List)
*/

/// Author: Deepanker Sachdeva

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
	node *parent;
	string color;
};
class Graph
{
public:
	int imax = numeric_limits<int>::max();
	arr a[20];
	int lastIndex = -1,flag=0;
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
		node *ptr = a[index].head,*newn;
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
		node *ptr = a[index].head,*temp=NULL;
		a[index].head = NULL;
		while (ptr != NULL)
		{
			temp = ptr;
			traverseDel(ptr,x);
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
		node *ptr = a[index].head,*temp;
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
int main()
{
	char ch;
	cout << "Let's create the first node\n";
	g.createNode(g.a);
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
			g.createNode(g.a);
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
    return 0;
}

