/*
Binary Tree Traversals:

Pre order
In order
Post order

*/
/// Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;

struct treenode
{
	int data;
	treenode *parent;
	treenode *left;
	treenode *right;
	//int level;
};
class BTmaker
{
public:
	treenode *root;
	treenode *a[30];
	int i = 0, level = 1;

	treenode *create(int data)
	{
		treenode *newnode;
		newnode = (treenode*)malloc(sizeof(treenode));
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;
		//newnode->level = level;
		return newnode;
	}
	void insert()
	{
		int data, level = 1;
		if (root == NULL)
		{
			cout << "Enter the data for root\t\t";
			cin >> data;
			root = create(data);
			a[i] = root;
		}
		else
		{
			int temp;
			treenode *ptr, *newnode;
		back:cout << "Enter the data of the node to which enter more data\t\t";
			//cout << "On which level do you want to add data\t\t";
			cin >> temp;
			ptr = search(temp);
			if (ptr == NULL)
			{
				cout << "Sorry this data currently not present\t\t";
				goto back;
			}
			else
			{
				//level++;
				i++;
				cout << "Enter the data to add\t\t";
				cin >> data;
				newnode = create(data);
				a[i] = newnode;
			b:cout << "Want to add data on its left node or the right?\t1.Left\t2.Right\t\t";
				cin >> temp;
				if (temp == 1)
				{
					if (ptr->left != NULL)
					{
						cout << "Overwriting the node\t\t";
						newnode->left = ptr->left->left;//connect to the ends if overwriting
						newnode->right = ptr->left->right;
					}
					ptr->left = newnode;
				}
				else if (temp == 2)
				{
					if (ptr->right != NULL)
					{
						cout << "Overwriting the node\n";
						newnode->left = ptr->right->left;//connect to the ends if overwriting
						newnode->right = ptr->right->right;
					}
					ptr->right = newnode;
				}
				else
					goto b;
				newnode->parent = ptr;
			}
		}
	}
	treenode *search(int temp)
	{
		for (int i = 0; a[i] != NULL; i++)
		{
			if (a[i]->data == temp)
				return a[i];
		}
		return NULL;
	}
};

class stack
{
public:
	int pos = -1;
	treenode *a[20];										//a is the stack with size of 20
	const int max = 20;

	void push(treenode *item)																//push function to write the item to the stack
	{
		if (pos < max - 1)
		{
			pos++;
			a[pos] = item;
		}
		else
			cout << "Sorry, stack already full\n";
	}

	treenode *pop()																//pop function to get element out of the stack
	{
		if (pos >= 0)
		{
			treenode *item = a[pos];
			pos--;
			return item;
		}
		else
		{
			return NULL;
		}
	}
};


class BTtraverse :public BTmaker,public stack
{
public:
	void preOrder_rec(treenode *ptr)
	{
		if (ptr != NULL)
		{
			cout << ptr->data << "\t";
			preOrder_rec(ptr->left);
			preOrder_rec(ptr->right);
		}
	}
	void inOrder_rec(treenode *ptr)
	{
		if (ptr != NULL)
		{
			inOrder_rec(ptr->left);
			cout << ptr->data << "\t";
			inOrder_rec(ptr->right);
		}
	}
	void postOrder_rec(treenode *ptr)
	{
		if (ptr != NULL)
		{
			postOrder_rec(ptr->left);
			postOrder_rec(ptr->right);
			cout << ptr->data << "\t";
		}
	}
	void preOrder_nonRec(treenode *ptr)
	{
		//ptr = root;
		push(NULL);
		while (ptr != NULL)
		{
			cout << ptr->data << "\t";
			if (ptr->right != NULL)
				push(ptr->right);
			ptr = ptr->left;
			if (ptr != NULL)					//it takes in ptr=pop() statement in while from outside as was in algo
				continue;
			else
				ptr = pop();
		}
		//ptr=pop();
	}
	void inOrder_nonRec(treenode *ptr)
	{
		push(NULL);
		while (ptr != NULL)
		{
			push(ptr);
			ptr = ptr->left;
			if (ptr == NULL)
			{
				do
				{
					ptr = pop();
					if (ptr != NULL)
					{
						cout << ptr->data << "\t";
						if (ptr->right != NULL)
						{
							ptr = ptr->right;
							break;
						}
						else
							continue;
					}
					else
						break;
				} while (ptr->right == NULL);
			}
		}
	}
	void postOrder_nonRec(treenode *ptr)
	{
		int k = 0;
		treenode *temp = NULL;
		push(NULL);
		while (ptr != NULL)
		{
			push(ptr);
			ptr = ptr->left;
			while (ptr == NULL)
			{
				ptr = pop();
				if (ptr == NULL)
					break;
				if (ptr->right != temp)
					k = 0;
				else
					k = 1;
				if (ptr->right != NULL&&k==0)
				{
					push(ptr);
					ptr = ptr->right;
					break;//to continue in outer loop
				}
				else
				{
					cout << ptr->data << "\t";
					temp = ptr;
					ptr = NULL;//for continuing it want it to ptr==NULL for condition to be true
				}
			}
		}
	}
};
int main()
{
	BTmaker bt;
	BTtraverse btr;
	stack stk;
	char want;
	do
	{
		bt.insert();
		cout << "Wanna insert more\tPress y for yes\t\t";
		cin >> want;
	} while (want == 'y');

	cout << "\nShowing the Pre order traversal\t";
	btr.preOrder_rec(bt.root);
	cout << endl;
	cout << "\tShowing the In order traversal\t";
	btr.inOrder_rec(bt.root);
	cout << endl;
	cout << "\tShowing the Post order traversal\t";
	btr.postOrder_rec(bt.root);
	cout << endl;
	cout << "\tShowing the Pre order non rec traversal\t";
	btr.preOrder_nonRec(bt.root);
	cout << endl;
	cout << "\tShowing the In order non rec traversal\t";
	btr.inOrder_nonRec(bt.root);
	cout << endl;
	cout << "\tShowing the Post order non rec traversal\t";
	btr.postOrder_nonRec(bt.root);
	cout << endl;
    return 0;
}

//5 y 5 6 1 y 5 7 2 y 6 8 1 y 6 9 2 y 9 10 2 y 7 12 1 y 7 13 2 n
//as input
/*
						5
			6					7
		8		9			12		13
					10						
												

*/
/*
pre		5 6 8 9 10 7 12 13
in		8 6 9 10 5 12 7 13
post	8 10 9 6 12 13 7 5
*/
