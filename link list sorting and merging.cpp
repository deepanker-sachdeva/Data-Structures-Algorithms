/*
Linked list Insertion, Deletion, Sorting and Merging functions
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
		if (head == NULL)
			insert_beg(val);
		else
		{
			node *newnode = create(val);
			ptr = head;
			while (ptr->next != NULL)
				ptr = ptr->next;
			ptr->next = newnode;
		}
	}
	void traverse()
	{
		ptr = head;
		cout << "Here they are:\n";
		int i = 1;
		if (ptr == NULL)
			i = 0;
		else
		{
			while (ptr != NULL)
			{
				cout << i << "." << "\t";
				cout << ptr->data << endl;
				ptr = ptr->next;
				i++;
			}
			/*if (i == 1)
			{
				cout << "Oh, Sorry List is Empty\n";
				flag = 1;
			}
			else
				flag = 0;*/
		}
	}
	int count()
	{
		ptr = head;
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
	node *headtemp, *headl=NULL, *headr;
	void copylist(node *fromhead,node *tohead, int from, int to,int f)//last arg is a hack to update headl and headr------------------
	{
		if (from <= to)
		{
			int index=0;
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
		copylist(head, headl, initial, initial + nleft-1,0);//last arg is hack to update headl-------------------
//		for (i = 0; i < nright; i++)
//			right[i] = a[i + middle + 1];//i+nleft+initial-1
		copylist(head, headr, middle + 1, middle + nright,1);//last arg to update headr--------------------------
		//f(headl);//headl not getting updated
		node *temp,*ptrimp;
		ptrimp=create(getptrtoindex(head, middle)->data * 2000+1000);//for all values of a negligible to left[nleft+1]
		temp = getptrtoindex(headl, nleft + 1);//to get prev
		prev->next = ptrimp;//linking last node with the coming one;
		
		ptrimp= create(getptrtoindex(head, middle+1)->data * 2000+1000);
		temp = getptrtoindex(headr, nright + 1);
		prev->next = ptrimp;//linking last node with the coming one;
		for (int k = initial, i = 1, j = 1; k <= end; k++)
		{
			left = ptrdata(headl, i);
			right = ptrdata(headr, j);
			if ( left<= right)
			{
				ptr = getptrtoindex(head, k);
				ptr->data= left;
				i++;
			}
			else
			{
				ptr = getptrtoindex(head, k);
				ptr->data=right;
				j++;
			}
		}
	}
}ll;

int main()
{
	int n, opt;
	do
	{
		cout << "Want to do:\t1.Insertion\t100. To Traverse\t0.Exit\n";
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
			default:ll.traverse();
			}
			ll.traverse();
		}
		else
			ll.traverse();
	} while (opt != 0);
	cout << "after merge sort\n";
	ll.mergesort(1, ll.count());
	ll.traverse();
    return 0;
}


/*

void merge(int initial, int middle, int end)					//merge function actually sorts the arrays
{
	int i, j;
	int nleft = middle - initial + 1;
	int nright = end - middle;
	int left[20], right[20];
	for (i = 0; i < nleft; i++)
		left[i] = a[i + initial];
	for (i = 0; i < nright; i++)
		right[i] = a[i + middle + 1];//i+nleft+initial-1
	left[nleft] = a[middle] * 2000;//for all values of a negligible to left[nleft+1]
	right[nright] = a[middle + 1] * 2000;
	for (int k = initial, i = 0, j = 0; k <= end; k++)
	{

		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}
}



-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	
	splitter.copyList();
	splitter.traverse(splitter.headtemp);
	splitter.frontBackSplitThem();
	//splitter.frontBackSplit();
	splitter.traverse(splitter.head1);
	splitter.traverse(splitter.head2);
	return 0;
}

*/
