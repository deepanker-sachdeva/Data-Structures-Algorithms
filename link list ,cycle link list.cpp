/*
Program to make a cyclic Linked List
*/

/// Author: Deepanker Sachdeva

//#include"stdafx.h"
#include <iostream>

using namespace std;
class node
{
public:
	long data, i;
	node *next;
};
node *head;
node *headr;
class revll
{
	node *ptr, *temp = NULL;
	int i = 0, a[100];
public:
	node* create(long val)
	{
		i++;
		node *newnode;
		newnode = (node *)malloc(sizeof(node));
		newnode->data = val;
		newnode->next = NULL;
		newnode->i = i;
		return newnode;
	}
	void insert_end(long val)
	{

		node *newnode = create(val);
		ptr = head;
		if (head == NULL)
		{
			head = newnode;
			temp = head;
		}
		else
		{
			while (ptr != NULL)
			{
				temp = ptr;
				ptr = ptr->next;
			}
			ptr = temp->next;
			temp->next = newnode;
		}
	}
	void traverse()
	{
		ptr = head;
		int i = 1;
		while (ptr != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
			i++;
		}
	}
	void putcycle(int k)
	{
		ptr = head;
		int i = 1;
		if (i == 1 & k == 1)
			ptr->next = ptr;
		else
		{
			while (i < k)
			{
				if (ptr->next != NULL)
				{
					ptr = ptr->next;
					i++;
				}
				else
				{
					cout << "Wrong position";
					return;
				}
			}

			temp->next->next = ptr;
		}
	}
	void checkcycle(node *h)
	{
		ptr = h;
		int k = 1;
		if (ptr == NULL)
			cout << "no List\n";
		else
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
				k++;
				if (ptr->i != k)
					break;

			}
			if (ptr->next == NULL)
				cout << "Not cyclic\n";
			else
				cout << "Cyclic\n";
		}
	}
}ll;
int main() {
	long n = 1, value;
	int i = 1;
	int k, here;
	cout << "Press 1 for input at the end\n0 for exit\n";
	while (n != 0)
	{
		cin >> n;
		if (n == 1)
		{
			cin >> value;
			ll.insert_end(value);
			cout << "Want to make it cyclic\nPress 1 if yes\n";
			cin >> k;
			if (k == 1)
			{
				cout << "Where to return the last ptr, give a position\n";
				cin >> here;
				if (here > 0)
					ll.putcycle(here);
				else
					cout << "Wrong position\n";
				break;
			}
		}
		i++;
	}

	ll.checkcycle(head);
	return 0;
}



