/*
Implementing a Header Linked List
: Insertion and Deletion
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
};


class linkedList
{
	node *head = create(NULL);
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
		return newnode;
	}
	void insert_beg(int val)
	{
		node *newnode = create(val);
		newnode->next = head->next;
		head->next = newnode;
	}
	void insert_end(int val)
	{
		node *newnode = create(val);
		ptr = head->next;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
	}
	void traverse()
	{
		ptr = head->next;
		cout << "Here they are:\n";
		int i = 1;
		while (ptr != NULL)
		{
			cout << i << "." << "\t";
			cout << ptr->data << endl;
			ptr = ptr->next;
			i++;
		}
		if (i == 1)
		{
			cout << "Oh, Sorry List is Empty\n";
			flag = 1;
		}
		else
			flag = 0;
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
			ptr = head->next;
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
			ptr->next = newnode;
		}
	}
	void insert_sorted(int val)
	{
		int pos = search_sorted(val);
		insert_loc(pos, val);
	}
	int search_sorted(int val)
	{
		ptr = head->next;
		int pos = 1;
		if (ptr == NULL)
			pos = 0;
		else
		{
			while (ptr != NULL)
			{
				if (val == ptr->data)
				{
					notfound = 0;
					return pos;
				}
				else if (val > ptr->data)
				{
					ptr = ptr->next;
					pos++;
					notfound = 0;
				}
				else
				{
					notfound = 1;
					return pos;
				}
			}
		}
		notfound = 1;
		return pos;
	}
	void del_beg()
	{
		if (head->next != NULL)
		{
			ptr = head->next;
			head->next = ptr->next;
			free(ptr);
		}
		else
			cout << "List already Empty!\n";
	}
	void del_end()
	{
		node *temp;
		ptr = head->next;
		temp = ptr;
		if (ptr->next == NULL)
			head->next = NULL;
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
		ptr = head->next;
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
			ptr = head->next;
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
			free(ptr);
		}
	}
	void del_sorted(int val)
	{
		int pos = search_sorted(val);
		if (notfound == 1)
		{
			cout << "Item not present\n";
			return;
		}
		del_pos(pos);
	}
}ll;

int main()
{
	int n, opt;
	do
	{
		cout << "Want to do:\t1.Insertion\t2.Deletion\t100. To Traverse\t0.Exit\n";
		cin >> opt;
		if (opt == 1)
		{
			cout << "1.Insert at begin\t2.Insert at end\t3.Insert at a Location\t4.Insert in Sorted List\n";
			cin >> n;
			int value;
			if (n > 0 && n < 5)
			{
				cout << "Enter the value to insert.\n";
				cin >> value;
			}
			switch (n)
			{
			case 1:ll.insert_beg(value); break;
			case 2:ll.insert_end(value); break;
			case 3:
				cout << "Enter where to insert\n";
				int pos;
				cin >> pos;
				ll.insert_loc(pos, value);
				break;
			case 4:ll.insert_sorted(value); break;
			default:ll.traverse();
			}
			ll.traverse();
		}
		else if (opt == 2)
		{
			if (ll.flag == 1)
			{
				cout << "Sorry, List is Empty\n";
				continue;
			}
			cout << "1.Deletion at Begin\t2.Deletion at End\t3.Deletion of given itemnode\t4.Deletion in Sorted List\n";
			cin >> n;
			int item;
			switch (n)
			{
			case 1:ll.del_beg(); break;
			case 2:ll.del_end(); break;
			case 3:
				cout << "Enter the item to delete out of the given\n";
				ll.traverse();
				cin >> item;
				ll.del_item(item);
				break;
			case 4:
				cout << "Enter the item to delete out of the given\n";
				ll.traverse();
				cin >> item;
				ll.del_sorted(item);
				break;
			default:ll.traverse();
			}
			ll.traverse();
		}
		else
			ll.traverse();
	} while (opt != 0);
	return 0;
}

