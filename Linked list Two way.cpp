/*
Implementing a 2-way Linked List
: Insertion and Deletion, Traversal
*/

/// Author : Deepanker Sachdeva


//#include "stdafx.h"
#include<iostream>
using namespace std;

struct node
{
public:
	int data;
	node *next;
	node *prev;
};
node *head = NULL;

class linkedList
{
	node *ptr;
	int notfound = 0;
public:
	int flag = 0;
	node* create(int val)
	{
		node *newnode;
		newnode = (node *)malloc(sizeof(node));
		newnode->data = val;
		newnode->next = NULL;
		newnode->prev = NULL;
		return newnode;
	}
	void insert_beg(int val)
	{
		node *newnode = create(val);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
	}
	void insert_end(int val)
	{
		node *newnode = create(val);
		ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;
	}
	void traverse()
	{
		node *temp;
		ptr = head;
		cout << "Here they are going in forward direction:\n";
		int i = 1;
		temp = ptr;
		while (ptr != NULL)
		{
			cout << i << "." << "\t";
			cout << ptr->data << endl;
			temp = ptr;
			ptr = ptr->next;
			i++;
		}
		if (i == 1)
		{
			cout << "Oh, Sorry List is Empty\n";
			flag = 1;
			return;
		}
		else
			flag = 0;
		cout << "Now in backward traversal\n";
		i = 1;
		ptr = temp;
		while (ptr != head)
		{
			cout << i << "." << "\t";
			cout << ptr->data << endl;
			ptr = ptr->prev;
			i++;
		}
		cout << i << "." << "\t";//for 1st ptr to be printed
		cout << ptr->data << endl;
	}

	void insert_loc(int pos, int val)
	{
		node *newnode = create(val);
		if (pos == 1)
		{
			insert_beg(val);
		}
		else
		{
			ptr = head;
			for (int k = 1; k < pos - 1; k++)
			{
				ptr = ptr->next;
				if (ptr == NULL)
				{
					cout << "Position invalid\n";
					return;
				}
			}
			newnode->next = ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev = newnode;
			ptr->next = newnode;
			newnode->prev = ptr;
		}
	}

	void del_beg()
	{
		if (head != NULL)
		{
			ptr = head;
			if (head->next != NULL)
			{
				head = head->next;
				head->prev = NULL;
				free(ptr);
			}
			else
			{
				free(ptr);
				head = NULL;
			}
		}
		else
			cout << "List already Empty!\n";
	}
	void del_end()
	{
		node *temp;
		ptr = head;
		temp = ptr;
		if (ptr->next == NULL)
			head = NULL;
		else
		{
			while (ptr->next != NULL)
			{
				temp = ptr;
				ptr = ptr->next;
			}
			temp->next = NULL;
		}
		free(ptr);
	}
	void del_item(int item)
	{
		int pos;
		pos = search(item);
		if (pos == -1)
			return;
		del_pos(pos);
	}

	int search(int item)
	{
		ptr = head;
		int i = 1;
		while (ptr != NULL)
		{
			if (ptr->data == item)
				return i;
			ptr = ptr->next;
			i++;
		}
		cout << "Sorry, item not present\n";
		return -1;
	}
	void del_pos(int pos)
	{
		node *temp;
		if (pos == 1)
		{
			del_beg();
		}
		else
		{
			ptr = head;
			temp = ptr;
			for (int k = 1; k < pos; k++)
			{
				temp = ptr;
				ptr = ptr->next;
				if (ptr == NULL)
				{
					cout << "Wrong position\n";
					return;
				}
			}
			temp->next = ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev = temp;
			free(ptr);
		}
	}
}li;
int main()
{
	int n, opt;
	do
	{
		cout << "Want to do:\t1.Insertion\t2.Deletion\t100. To Traverse\t0.Exit\n";
		cin >> opt;
		if (opt == 1)
		{
			cout << "1.Insert at begin\t2.Insert at end\t3.Insert at a Location\n";
			cin >> n;
			int value;
			if (n > 0 && n < 4)
			{
				cout << "Enter the value to insert.\n";
				cin >> value;
			}
			switch (n)
			{
			case 1:li.insert_beg(value); break;
			case 2:li.insert_end(value); break;
			case 3:
				cout << "Enter where to insert\n";
				int pos;
				cin >> pos;
				li.insert_loc(pos, value);
				break;
			default:li.traverse();
			}
			li.traverse();
		}
		else if (opt == 2)
		{
			if (li.flag == 1)
			{
				cout << "Sorry, List is Empty\n";
				continue;
			}
			cout << "1.Deletion at Begin\t2.Deletion at End\t3.Deletion of given itemnode\n";
			cin >> n;
			int item;
			switch (n)
			{
			case 1:li.del_beg(); break;
			case 2:li.del_end(); break;
			case 3:
				cout << "Enter the item to delete out of the given\n";
				li.traverse();
				cin >> item;
				li.del_item(item);
				break;
			default:li.traverse();
			}
			li.traverse();
		}
		else
			li.traverse();
	} while (opt != 0);
    return 0;
}

