/*
Implementing Hash functions:

Using Linear and Quadratic Probing
*/

/// 	Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;
#define DEL -1
class Hashing
{
public:
	int max = 22;
	int t[23];
	int hash(int x)
	{
		return x % 23;
	}
	int hash(int x, int i,int opt)
	{
		if (opt == 1)
			return (hash(x) + i) % 23;
		else
			return (hash(x) + i*i) % 23;
	}
	int hash_insert(int t[], int k,int opt)
	{
		int i = 0;
		do
		{
			int j = hash(k, i,opt);
			if (t[j] <=0)
			{
				t[j] = k;
				return j;
			}
			else
				i++;
		} while (i != max);
	}
	int hash_search(int t[], int k,int opt)
	{
		int i = 0,j;
		do
		{
			j = hash(k, i,opt);
			if (t[j] == k)
				return j;
			else
				i++;
		} while (t[j] != NULL && i != max);
		return -1;
		//cout << "Sorry, " << k << " is not found in the table\n";
	}
	int hash_delete(int t[], int k,int opt)
	{
		int i = 0, j;
		k=hash_search(t, k,opt);
		if (k == NULL)
		{
			cout << "Sorry, " << k << " is not found in the table\n";
			return -1;
		}
		t[k] = DEL;
		return k;
	}

}h;

int main()
{
	for (int i = 0; i <= h.max; i++)
		h.t[i] = 0;
	int key,y,opt=0;
	char ch='}';
	cout << "What to do?\t You can do Insertion as I 45, Deletion as D 50,Searching as S 45\n";
	cout << "But first select, which type of probing function to use?\n1.Linear Probing\t2.Quadaratic Probing\n";
	cin >> opt;
	do
	{
		cout << "Insert-I\tDelete-D\tSearch-S\tExit-E\n";
		cin >> ch;
		if (ch == 'E' || ch == 'e');
		else
			cin >> key;
		switch (ch)
		{
		case 'I':
		case 'i':
			cout << key << " is Inserted at " << h.hash_insert(h.t, key,opt)<<" index\n";
			break;
		case 'D':
		case 'd':
			y = h.hash_delete(h.t, key,opt);
			if(y!=-1)
			cout << key << " is Deleted from " <<y<<" index\n" ;
			break;
		case 'S':
		case 's':
			y=h.hash_search(h.t, key,opt);
			if (y != -1)
				cout << key << " is found at " << y << " index\n";
			else
				cout << key << " not found\n";
			break;
		}
	} while (ch != 'E' && ch != 'e');
	return 0;
}
