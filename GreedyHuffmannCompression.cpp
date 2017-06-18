/*
Greedy Approach:
Implementation of Huffmann Compression
*/

/// 	Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

struct node
{
public:
	char data;
	int freq;
	node *next;
	node *left;
	node *right;
};
node *head = NULL;
int n;
class linkedList
{
	node *ptr;
	char val;
public:int freq;
	void input()
	{
		cout << "How many characters?\n";
		cin >> n;
		cout << "Start entering\tChar,Frequency\n";
		for (int i = 0; i < n; i++)
		{
			cin >> val>>freq;
			insert(val, freq);
		}
	}
	node* create(char val,int freq)
	{
		node *newnode;
		newnode = (node *)malloc(sizeof(node));
		newnode->data = val;
		newnode->freq = freq;
		newnode->next = NULL;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	void insert(node *in)
	{
		if (head == NULL)
		{
			head = in;
		}
		else
		{
			in->next = head;
			head = in;
		}
	}
	void insert(char val,int freq)
	{
		node *newnode = create(val, freq);
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
}ll;

class stacks
{
	public:
	int code[20];
	node *list[20];
	int top = -1,max=19,topl=-1;
	void push(int item)
	{
		if (top < max)
		{
			top++;
			code[top] = item;
		}
		else
			cout << "Stack full\n";
	}
	void push(node *item)
	{
		if (topl < max)
		{
			topl++;
			list[topl] = item;
		}
		else
			cout << "Stack full\n";
	}
	node *pop()
	{
		if (topl != -1)
		{
			node *item = list[topl];
			topl--;
			return item;
		}
		else
			return NULL;
	}
}stk;
class huffmannCompress:private linkedList,private stacks
{
	node *ptr,*lastptr=NULL;
public:
	node *ExtractMin()
	{
		ptr = head;
		node *min = ptr, *temp = ptr,*lasttemp=NULL;
		if (ptr == NULL)
			return NULL;
		else

		{
			while (ptr != NULL)
			{
				if (ptr->freq < min->freq)
				{
					temp = lasttemp;
					min = ptr;
				}
				lasttemp = ptr;
				ptr = ptr->next;
			}
			if (head == min)
			{
				head = min->next;
			}
			else
			{
				if (min->next != NULL)
					temp->next = min->next;
				else
					temp->next = NULL;
			}
			min->next = NULL;
			return min;
		}
	}
	node *huffmannCompression(node *ptr)
	{
		node *z,*min1,*min2;
		for (int i = 1; i <= n - 1; i++)
		{
			min1 = ExtractMin();
			min2 = ExtractMin();
			if (min2 == NULL)
				head = min1;
			else
			{
				z = create(NULL, min1->freq + min2->freq);
				z->left = min1;
				z->right = min2;
				insert(z);
			}
		}
		return head;
	}
	/*void encryptr(node *ptr)                                                            //works for 5-6 nodes only
	{
		lastptr = findlastnode();
		node *k=NULL,*uff;
		if (ptr->left != NULL)
		{
			push(ptr);
			ptr = ptr->left;
			push(0);
			if (ptr->data == NULL)
				encryptr(ptr);
			else
			{
				while (ptr->data != NULL)
				{
					int u = 1;
					cout << ptr->data << "\t";
					for (int i = 0; i <= top; i++)
						cout << code[i];
					cout << "\n";
					if (ptr == lastptr)
						return;
					back:ptr = pop();
					top--;
					uff = ptr;
					for (int i = 0; i < u; i++)
					{
						uff = uff->right;
					}
					if (k == uff)
					{
						goto there;
					}
					if (ptr != NULL)
					{
						if (k != ptr->right&&ptr->right!=NULL)
						{
							push(ptr);
							ptr = ptr->right;
							k = ptr;
							push(1);
						}
						else
						{
						there:	u++;
							goto back;
						}
					}
					else
						return;
				}
				encryptr(ptr);
			}

		}
	}*/
	int ch[10],o=-1;
	void encrypt(node *ptr)
	{
		if (ptr->data == NULL)
		{
			o++;
			ch[o] = 0;
			encrypt(ptr->left);
			o++;
			ch[o] = 1;
			encrypt(ptr->right);
			o--;
		}
		else
		{
			cout << ptr->data << "\t";
			for (int i = 0; i <= o; i++)
				cout << ch[i];
			cout << endl;
			o--;
		}
	}
	node *findlastnode()
	{
		node *ptr = head;
		while (ptr != NULL)
		{
			lastptr = ptr;
			ptr = ptr->right;
		}
		if (lastptr->left != NULL)
			lastptr = lastptr->left;
		return lastptr;
	}
}hc;
int main()
{
	ll.input();
	node *ptr = hc.huffmannCompression(head);
	hc.encrypt(ptr);
    return 0;
}

