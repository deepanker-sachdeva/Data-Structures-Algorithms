/*
Implementation of Binary Search Tree:


Insertion
Deletion
Searching
Max
Min
Successor
Predecessor
*/

///  Author:  Deepanker Sachdeva


//#include "stdafx.h"
#include<iostream>
using namespace std;

struct node
{
	int data;
	node *parent;
	node *left;
	node *right;
};
class BSTmaker
{
public:
	node *root = NULL;
	node *create(int data)
	{
		node *newnode;
		newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;
		return newnode;
	}
	void insert()
	{
		int value;
		node *ptr = root, *temp = NULL,*z;
		cout << "Enter the data\n";
		cin >> value;
		z = create(value);
		while (ptr != NULL)
		{
			temp = ptr;
			if (ptr->data > value)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		z->parent = temp;
		if (temp == NULL)
			root = z;
		else
		{
			if (z->data < temp->data)
				temp->left = z;
			else
				temp->right = z;
		}
	}
	node *search()
	{
		int value;
		cout << "Enter what to search for?\n";
		cin >> value;
		node *ptr = root;
		while (ptr != NULL&&ptr->data != value)
		{
			if (ptr->data > value)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}
		if (ptr != NULL)
		{
			cout << "Found it!";
			return ptr;
		}
		else
		{
			cout << "Not found";
			return NULL;
		}
	}
	node *searchRec(node *temp,int value)
	{
		if (temp == NULL)
		{
			cout << "Not found";
			return NULL;
		}
		else
		{
			if (temp->data > value)
				return searchRec(temp->left, value);
			else if (temp->data < value)
				return searchRec(temp->right, value);
			else
			{
				cout << "Found it!";
				return temp;
			}
		}
	}
	node *maximum(node *ptr)
	{
		if (ptr != NULL)
		{
			while (ptr->right != NULL)
				ptr = ptr->right;
			return ptr;
		}
		else
			return NULL;
	}
	node *minimum(node *ptr)
	{
		if (ptr != NULL)
		{
			while (ptr->left != NULL)
				ptr = ptr->left;
			return ptr;
		}
		else
			return NULL;
	}
	node *successor(node *temp,int value)
	{
		node *parent;
		node *ptr = searchRec(temp, value);
		if (ptr->right != NULL)
			return minimum(ptr->right);
		/*else
		{
			parent = ptr->parent;
			while (parent != NULL && ptr == parent->right)
			{
				ptr = parent;
				parent = parent->parent;
			}
			if (parent != NULL)
				return parent;
			else
				return NULL;
		}*/
		else
		{
			parent = ptr->parent;
			while (parent != NULL)
			{
				if (parent->left == ptr)
					return parent;
				else
				{
					ptr = parent;
					parent = ptr->parent;
					continue;
				}
			}
			return NULL;
		}
	}
	node *predecessor(node *temp, int value)
	{
		node *parent;
		node *ptr = searchRec(temp, value);
		if (ptr->left != NULL)
			return maximum(ptr->left);
		else
		{
			parent = ptr->parent;
			while (parent != NULL)
			{
				if (parent->right == ptr)
					return parent;
				else
				{
					ptr = parent;
					parent = ptr->parent;
					continue;
				}
			}
			return NULL;
		}
	}
	int inOrderCount(node *ptr,int n)
	{
		if (ptr != NULL)
		{
			n++;
			n = inOrderCount(ptr->left, n);
			n = inOrderCount(ptr->right, n);
		}
		else
			return n;
	}
	node *ret = NULL;
	int inOrder(node *ptr,int n,int i)
	{
		if (ret != NULL)
			return i;
		if (i != n&&ptr != NULL)
		{
			i = inOrder(ptr->left, n, i);
			i++;
			if (i == n)
				ret = ptr;
			i=inOrder(ptr->right, n, i);
		}
		else
		{
			if (i == n)
			{
				ret = ptr;
			}
			return i;
		}

	}
	float median(node *ptr)
	{
		int n=inOrderCount(root, 0);
		if (n % 2 == 0)
		{
			node *pt = NULL;
			inOrder(ptr, n / 2, 0);
			pt = ret;
			int data1 = pt->data;
			if (pt->right != NULL)
				pt = pt->right;
			else if (pt == pt->parent->left)
				pt = pt->parent;
			else
			{
				while (pt!=pt->parent->left)
				{
					pt = pt->parent;
				}
				pt = pt->parent;
			}
			int data2 = pt->data;
			float median1 = (data1 + data2) / 2;
			return median1;
		}
		else
		{
			node *pt = NULL;
			inOrder(ptr, (n + 1) / 2,0);
			pt = ret;
			return pt->data;
		}
	}
	void deleteNode(node *t,int item)
	{
		node *x,*y,*z = searchRec(t, item);//y is used to select node to delete
		if (z == NULL)
		{
			cout << item << " not found\n";
			return;
		}
		if (z->left == NULL || z->right == NULL)
			y = z;
		else
			y = successor(root, z->data);	//could have made successor to get args of node ptr, rather than its data to make it effective for same data values
		if (y->left != NULL)
			x = y->left;					//x is used as children of y
		else
			x = y->right;
		if (x != NULL)
			x->parent = y->parent;
		if (y->parent == NULL)
			root = x;
		else
			if (y == y->parent->left)
				y->parent->left = x;
			else
				y->parent->right = x;
		if (y != z)							//putting value of successor
			z->data = y->data;
		free(y);
		cout << "Its deleted\n";
	}
}bst;

int main()
{
	int n;
	do
	{
		bst.insert();
		cout << "Press 1 to insert more\n";
		cin >> n;
	} while (n==1);
	int value;
	node *successor,*predecessor;
	do
	{
		cout << "What to do?\n1.Search Non-Recursive\t2.Search Recursive\t3.Maximum\t4.Minimum\t5.Successor\t6.Delete a node\t7.Predecessor\n0.Exit";
		cin >> n;
		switch (n)
		{
		case 1:bst.search(); break;
		case 2:
			cout << "For rec. search, enter the value\n";
			cin >> value;
			bst.searchRec(bst.root, value);
			break;
		case 3:cout << "Maximum element is " << bst.maximum(bst.root)->data << endl; break;
		case 4:cout << "Minimum element is " << bst.minimum(bst.root)->data << endl; break;
		case 5:
			cout << "Successor of which value-";
			cin >> value;
			successor = bst.successor(bst.root, value);
			if (successor != NULL)
				cout << "Successor of " << value << " is " << successor->data;
			else
				cout << "Successor is not there\n";
			break;
		case 6:
			cout << "What to delete\n";
			cin >> value;
			bst.deleteNode(bst.root, value);
			break;
		case 7:
			cout << "Predecessor of which value-";
			cin >> value;
			predecessor = bst.predecessor(bst.root, value);
			if (predecessor != NULL)
				cout << "Predecessor of " << value << " is " << predecessor->data;
			else
				cout << "Predecessor is not there\n";
			break;
		case 8:
			cout<<bst.median(bst.root);
		}
	} while (n!=0);
	return 0;
}

