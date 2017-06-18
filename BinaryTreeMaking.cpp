/*
Implementation of a simple Binary tree
*/


///	Author: Deepanker Sachdeva


//#include "stdafx.h"
#include<iostream>

using namespace std;

struct node
{
	int data;
	node *parent;
	node *left;
	node *right;
	//int level;
};
class BTmaker
{
	node *root=NULL;
	node *a[30];
	int i = 0,level=1;

	node *create(int data)
	{
		node *newnode;
		newnode = (node*)malloc(sizeof(node));
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = NULL;
		//newnode->level = level;
		return newnode;
	}
public:
	void insert()
	{
		int data,level=1;
		if (root == NULL)
		{
			cout << "Enter the data for root\n";
			cin >> data;
			root = create(data);
			a[i] = root;
		}
		else
		{
			int temp;
			node *ptr,*newnode;
		back:cout << "Enter the data of the node to which enter more data\n";
			//cout << "On which level do you want to add data\n";
			cin>>temp;
			ptr = search(temp);
			if (ptr == NULL)
			{
				cout << "Sorry this data currently not present\n";
				goto back;
			}
			else
			{
				//level++;
				i++;
				cout << "Enter the data to add\n";
				cin >> data;
				newnode = create(data);
				a[i] = newnode;
				b:cout << "Want to add data on its left node or the right?\t1.Left\t2.Right";
				cin >> temp;
				if (temp == 1)
					ptr->left = newnode;
				else if (temp == 2)
					ptr->right = newnode;
				else
					goto b;
				newnode->parent = ptr;
			}
		}
	}
	node *search(int temp)
	{
		for (int i = 0; a[i] != NULL; i++)
		{
			if (a[i]->data == temp)
				return a[i];
		}
		return NULL;
	}
};

int main()
{
	BTmaker bt;
	char want;
	do
	{
		bt.insert();
		cout << "Wanna insert more\tPress y for yes\n";
		cin >> want;
	} while (want == 'y');
    return 0;
}

