/*
Implementing a Linked List
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
		return newnode;
	}
	void insert_beg(int val)
	{
		node *newnode=create(val);
		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			newnode->next = head;
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
	}
	void traverse()
	{
		ptr = head;
		cout << "Here they are:\n";
		int i = 1;
		while (ptr != NULL)
		{
			cout << i<<"."<<"\t";
			cout << ptr->data<<endl;
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

	void insert_loc(int pos,int val)
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
		ptr = head;
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
		if (head != NULL)
		{
			ptr = head;
			head = head->next;
			free(ptr);
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
		pos=search(item);
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

class listDivide
{
	node *ptr;
public:
	node *headtemp, *head1, *head2;
	int i=0,flag=0;//no. of elements
	void copyList()
	{
		node *temp;
		if (head == NULL)
		{
			cout << "List Empty\n";
			return;
		}
		ptr = head;
		i = 1;
		headtemp = ll.create(ptr->data);
		temp = headtemp;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			node *newnode = ll.create(ptr->data);
			temp->next = newnode;
			temp = temp->next;
			ptr = ptr->next;
			i++;
		}
	}
	void traverse(node *varhead)
	{
		ptr = varhead;
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
	void frontBackSplit()								//this one is making two sublists
	{
		node *temp;
		int left;
		if (i % 2 == 0)									//i we get through traversal
			left = i / 2;
		else
			left = i / 2 + 1;
		ptr = headtemp;
		int n = 1;
		head1 = ll.create(ptr->data);
		temp = head1;
		ptr = ptr->next;
		while (n < left)
		{
			node *newnode = ll.create(ptr->data);
			temp->next = newnode;
			temp = temp->next;
			ptr = ptr->next;
			n++;
		}
		head2 = ll.create(ptr->data);
		temp = head2;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			node *newnode = ll.create(ptr->data);
			temp->next = newnode;
			temp = temp->next;
			ptr = ptr->next;
		}
	}

	void frontBackSplitThem()
	{
		node *temp;
		int left;
		if (i % 2 == 0)
			left = i / 2;
		else
			left = i / 2 + 1;
		ptr = headtemp;
		int n = 1;
		head1 =ptr;
		temp = ptr;
		ptr = ptr->next;
		
		while (n < left)
		{
			temp = ptr;
			ptr = ptr->next;
			n++;
		}
		temp->next = NULL;//stop the 1st list
		head2 =ptr;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			ptr = ptr->next;
		}
	}
}splitter;
int main()
{
	int n,opt;
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

	splitter.copyList();
	splitter.traverse(splitter.headtemp);
	splitter.frontBackSplitThem();
	//splitter.frontBackSplit();
	splitter.traverse(splitter.head1);
	splitter.traverse(splitter.head2);
	return 0;
}

