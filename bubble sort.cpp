/*

Implementing Bubble Sort Algorithm

*/

/// 	Author:  Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;
int a[20];											//input array
void bubble(int n)
{
	int temp;										//temp to swap
	for (int j = 0; j < n - 2; j++)
		for (int i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
			{										//if previous is greater then swap
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}

}
int main()
{
	
	int n;
	cout << "Input no. of elements and then elements\n";
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << "After sorting\n";
	bubble(n);
	for (int i = 0; i < n; i++)
		cout << a[i]<<endl;
    return 0;
}
