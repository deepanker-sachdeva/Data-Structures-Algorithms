/*
Applying Stressen Multiplication on 2X2 Matrix
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
using namespace std;
int a[2][2] = {1,0,0,1}, b[2][2] = {1,0,0,1};
int strassen_mul(int *c, int *d,int n)
{
	if (n == 1)
		return *c**d;
	else
	{
		int s[10] = { b[0][1] - b[1][1],a[0][0] + a[0][1],a[1][0] + a[1][1],b[1][0] - b[0][0],a[0][0] + a[1][1],b[0][0] + b[1][1],a[0][1] - a[1][1],b[1][0] + b[1][1],a[0][0] - a[1][0],b[0][0] + b[0][1] };
		int p[7];
		p[0] = strassen_mul(&a[0][0], &s[0], n / 2);
		p[1]= strassen_mul(&s[1], &b[1][1], n / 2);
		p[2] = strassen_mul(&s[2],&b[0][0], n / 2);
		p[3] = strassen_mul(&a[1][1], &s[3], n / 2);
		p[4] = strassen_mul(&s[4], &s[5], n / 2);
		p[5] = strassen_mul(&s[6], &s[7], n / 2);
		p[6] = strassen_mul(&s[8], &s[9], n / 2);
		int c[2][2];
		c[0][0] = p[4] + p[3] - p[1] + p[5];
		c[0][1] = p[0] + p[1];
		c[1][0] = p[2] + p[3];
		c[1][1] = p[0] + p[4] - p[2] - p[6];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				cout << c[i][j] << "\t";
			cout << endl;
		}
		return -1;
	}
}
int main()
{
	cout << "Input the matrices A and B\n";
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "A[" << i << "][" << j << " : ";
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "B[" << i << "][" << j << " : ";
			cin >> b[i][j];
		}
	}
	strassen_mul(0, 0, 2);
    return 0;
}

