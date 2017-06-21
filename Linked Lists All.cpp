/*
1. Linked List				:Insertion/Deletion/Splitting
2. Sorting of two lists and Merging
3. Two Way Linked List		:Insertion/Deletion
4. Header Linked List
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
		node *newnode = create(val);
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
	node *lefthead, *righthead;
	void insertBegin(node *temp, int val, int option)
	{
		node *newnode = create(val);
		if (temp == NULL)
		{
			temp = newnode;
		}
		else
		{
			newnode->next = temp;
			temp = newnode;
		}
		if (option == 0)
			lefthead = temp;
		else
			righthead = temp;
	}

	int count(node *h)
	{
		ptr = h;
		int i = 1;
		if (ptr == NULL)
			i = 0;
		else
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
				i++;
			}
		}
		return i;
	}

	void mergesort(int initial, int end)							//merge sort function
	{
		int middle;
		if (initial < end)
		{
			middle = (initial + end) / 2;
			mergesort(initial, middle);								//recursive call to divide into left
			mergesort(middle + 1, end);								//and right array
			merge(initial, middle, end);							//merge function to sort them in steps
		}
	}
	node *ptrtemp;
	node *headtemp, *headl = NULL, *headr;
	void copylist(node *fromhead, node *tohead, int from, int to, int f)//last arg is a hack to update headl and headr------------------
	{
		if (from <= to)
		{
			int index = 0;
			node *temp;
			ptrtemp = fromhead;
			//fromhead = create(2);
			index++;
			while (index < from)
			{
				ptrtemp = ptrtemp->next;
				index++;
			}
			ptr = ptrtemp;
			tohead = create(ptr->data);
			temp = tohead;
			ptr = ptr->next;
			prev = temp;
			temp = temp->next;
			while (index < to)
			{
				temp = create(ptr->data);
				prev->next = temp;
				ptr = ptr->next;
				prev = temp;
				temp = temp->next;
				index++;
			}
			if (f == 0)															//this is a hack to update ptr------------------------
				headl = tohead;
			else
				headr = tohead;
			//temp->next = NULL;
		}
	}
	int ptrdata(node *headtemp, int index)
	{
		if (index > 0)
		{
			int i = 1;
			ptr = headtemp;
			while (i < index)
			{
				ptr = ptr->next;
				i++;
			}
			return ptr->data;
		}
		else
		{
			//invalid or null
		}
	}
	node *prev;
	node* getptrtoindex(node *headtemp, int index)
	{
		int i = 1;
		ptr = headtemp;
		while (i < index)
		{
			prev = ptr;
			ptr = ptr->next;
			i++;
		}

		return ptr;
	}

	void merge(int initial, int middle, int end)					//merge function actually sorts the arrays
	{
		int i, j;
		int left, right;
		int nleft = middle - initial + 1;
		int nright = end - middle;
		//		for (i = 0; i < nleft; i++)
		//			left[i] = a[i + initial];
		copylist(head, headl, initial, initial + nleft - 1, 0);//last arg is hack to update headl-------------------
															   //		for (i = 0; i < nright; i++)
															   //			right[i] = a[i + middle + 1];//i+nleft+initial-1
		copylist(head, headr, middle + 1, middle + nright, 1);//last arg to update headr--------------------------
															  //f(headl);//headl not getting updated
		node *temp, *ptrimp;
		ptrimp = create(getptrtoindex(head, middle)->data * 2000 + 1000);//for all values of a negligible to left[nleft+1]
		temp = getptrtoindex(headl, nleft + 1);
		prev->next = ptrimp;//linking last node with the coming one;

		ptrimp = create(getptrtoindex(head, middle + 1)->data * 2000 + 1000);
		temp = getptrtoindex(headr, nright + 1);
		prev->next = ptrimp;//linking last node with the coming one;
		for (int k = initial, i = 1, j = 1; k <= end; k++)
		{
			left = ptrdata(headl, i);
			right = ptrdata(headr, j);
			if (left <= right)
			{
				ptr = getptrtoindex(head, k);
				ptr->data = left;
				i++;
			}
			else
			{
				ptr = getptrtoindex(head, k);
				ptr->data = right;
				j++;
			}
		}
	}

	void mergeLists(node *head1, node *head2, node *headbig)
	{
		node *temp, *ptrimp;
		ptrimp = create(10000);//for all values of a negligible to left[nleft+1]
		temp = getptrtoindex(head1, count(head1) + 1);
		prev->next = ptrimp;//linking last node with the coming one;

		ptrimp = create(10000);
		temp = getptrtoindex(head2, count(head2) + 1);
		prev->next = ptrimp;//linking last node with the coming one;
		int m = count(head1);
		m = m + count(head2);
		m = m - 2;
		int left, right;
		int begin = 0;
		for (int k = 1, i = 1, j = 1; k <= m; k++)
		{

			left = ptrdata(head1, i);
			right = ptrdata(head2, j);
			if (left <= right)
			{
				if (i == 1 && begin == 0)
				{
					headbig = create(left);
					i++;
					begin = 1;
				}
				else
				{
					ptr = getptrtoindex(headbig, k);
					ptr = create(left);
					prev->next = ptr;
					i++;
				}
			}
			else
			{
				if (j == 1 && begin == 0)
				{
					headbig = create(right);
					j++;
					begin = 1;
				}
				else
				{
					ptr = getptrtoindex(headbig, k);
					ptr = create(right);
					prev->next = ptr;
					j++;
				}
			}
		}
		head = headbig;
	}
}ll;

class listDivide
{
	node *ptr;
public:
	node *headtemp, *head1, *head2;
	int i = 0, flag = 0;//no. of elements
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
		if (i % 2 == 0)
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
		head1 = ptr;
		temp = ptr;
		ptr = ptr->next;
		
		while (n < left)
		{
			temp = ptr;
			ptr = ptr->next;
			n++;
		}
		temp->next = NULL;//stop the 1st list
		head2 = ptr;
		ptr = ptr->next;
		while (ptr != NULL)
		{
			ptr = ptr->next;
		}
	}
}splitter;


class HeaderLL
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
}hll;


struct nodep
{
public:
	int data;
	nodep *next;
	nodep *prev;
};

class TwoWaylinkedList
{
	nodep *head;
	nodep *ptr;
	int notfound = 0;
public:
	int flag = 0;
	nodep* create(int val)
	{
		nodep *newnode;
		newnode = (nodep *)malloc(sizeof(nodep));
		newnode->data = val;
		newnode->next = NULL;
		newnode->prev = NULL;
		return newnode;
	}
	void insert_beg(int val)
	{
		nodep *newnode = create(val);
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
		nodep *newnode = create(val);
		ptr = head;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
		newnode->prev = ptr;
	}
	void traverse()
	{
		nodep *temp;
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
		nodep *newnode = create(val);
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
			if (ptr->next != NULL)
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
		nodep *temp;
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
		nodep *temp;
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
			if (ptr->next != NULL)
				ptr->next->prev = temp;
			free(ptr);
		}
	}
}li;
int main()
{
	int n, opt;
	back:
	cout << "1.Insertion/Deletion/Splitting\n2.Sorting of two lists and Merging\n3.Two Way Linked List-Insertion/Deletion\n4.Header Linked List\n";
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		do
		{
			cout << "Want to do:\t1.Insertion\t2.Deletion\t100. To Traverse\t0.Exit from Insertion Deletion Functions\nNOTE: Splitting will be done after you insert some elements\n";
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
		cout << "1.Split the list\t0. Exit\n";
		cin >> opt;
		if (opt == 1)
		{
			splitter.copyList();
			cout << "The given list is:\n";
			splitter.traverse(splitter.headtemp);//this traverse is also copying the elements
			if (splitter.i <= 1)
			{
				cout << "You can't split this list\n";
				return 0;
			}
			splitter.frontBackSplitThem();
			//splitter.frontBackSplit();
			cout << "After Splitting:\nFirst List:\n";
			splitter.traverse(splitter.head1);
			cout << "Second list:\n";
			splitter.traverse(splitter.head2);
		}
		else
			return 0;
		break;
	}
	case 2:
		int value;
		cout << "For simplicity ,Insertion at begin is only made available\n";
		cout << "Insert elements of first list\n";

		cout << "Enter values to Insert & Keep on Inserting and at the end just press 1010\n";
		do
		{
			cin >> value;
			if (value != 1010)
				ll.insertBegin(ll.lefthead, value, 0);
		} while (value != 1010);

		cout << "Insert elements of second list\n";
		cout << "Enter values to Insert & Keep on Inserting and at the end just press 1010\n";
		do
		{
			cin >> value;
			if (value != 1010)
				ll.insertBegin(ll.righthead, value, 1);
		} while (value != 1010);

		cout << "After merge sorting\nFirst List:\n";
		head = ll.lefthead;
		ll.mergesort(1, ll.count(head));
		ll.traverse();

		cout << "Second List:\n";
		head = ll.righthead;
		ll.mergesort(1, ll.count(head));
		ll.traverse();

		cout << "After Merging them\n";
		ll.mergeLists(ll.lefthead, ll.righthead, head);
		ll.traverse();
		break;

	case 3:
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
		break;
	case 4:
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
				case 1:hll.insert_beg(value); break;
				case 2:hll.insert_end(value); break;
				case 3:
					cout << "Enter where to insert\n";
					int pos;
					cin >> pos;
					hll.insert_loc(pos, value);
					break;
				case 4:hll.insert_sorted(value); break;
				default:hll.traverse();
				}
				hll.traverse();
			}
			else if (opt == 2)
			{
				if (hll.flag == 1)
				{
					cout << "Sorry, List is Empty\n";
					continue;
				}
				cout << "1.Deletion at Begin\t2.Deletion at End\t3.Deletion of given itemnode\t4.Deletion in Sorted List\n";
				cin >> n;
				int item;
				switch (n)
				{
				case 1:hll.del_beg(); break;
				case 2:hll.del_end(); break;
				case 3:
					cout << "Enter the item to delete out of the given\n";
					hll.traverse();
					cin >> item;
					hll.del_item(item);
					break;
				case 4:
					cout << "Enter the item to delete out of the given\n";
					hll.traverse();
					cin >> item;
					hll.del_sorted(item);
					break;
				default:hll.traverse();
				}
				hll.traverse();
			}
			else
				hll.traverse();
		} while (opt != 0);
		break;
	default:
		cout << "Wrong choice\n";
		goto back;
	}
	return 0;
}

