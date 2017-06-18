/*
Basic implementation of
Linear Search
*/

///	Author:  Deepanker Sachdeva

//#include"stdafx.h"
#include<iostream>
using namespace std;

class arraysearch
{
	int a[9] = {1,2,3,4,5,6,7,10,20};
public:int search(int find)
	{
		for (int i = 0; i < 9; i++)
			if (a[i] == find)
				return i + 1;
		return 0;
	}
}c;

int main()
{
	int find,found;
	cout << "Enter the element u wanna find\n";
	cin >> find;
	found=c.search(find);
	if (found != 0)
		cout << "Its found on\t" << found << "th position";
	else
		cout << "Not found";
    return 0;
}

