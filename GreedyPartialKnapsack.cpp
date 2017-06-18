/*
Greedy Approach:
Partial Knapsack problem
*/

/// 	Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class knapsack
{
	float amt[30], amtunit[30],totalqtyKnap,knapAmt[30], n[30], Knapn[30],totalAmtKnap=0;
	int no;
	string name[30];
public:
	void input()
	{
		cout << "How many items to do the partial knapsack problem for?\n";
		cin >> no;
		cout << "Enter the name,quantity and price (of that quantity) of the product\n";
		for (int i = 0; i < no; i++)
		{
			cout << i + 1 << ".\t";
			cin >> name[i];
			cin >> n[i] >> amt[i];
		}
		cout << "What is the Total Size of the Sack\t";
		cin >> totalqtyKnap;
	}
	void display()
	{
		for (int i = 0; i < no; i++)
		{
			cout << i + 1 << ".\t";
			cout << name[i] << "\t" << n[i] << "\t" << amt[i] << "\t"<<"Qty taken\t"<<Knapn[i]<<"\tAmt in price\t"<<knapAmt[i]<<endl;
		}
	}
	float partialKnapsack()
	{
		for (int i = 0; i < no; i++)
			amtunit[i] = amt[i] / n[i];
		sort(amtunit,n,amt,name);
		int N = no-1;
		while (1)//totalqtyKnap != 0)
		{
			if (n[N] > totalqtyKnap)
			{
				Knapn[N] = totalqtyKnap;
				knapAmt[N] = totalqtyKnap*amtunit[N];
				totalqtyKnap = 0;
				break;
			}
			else
			{
				totalqtyKnap = totalqtyKnap - n[N];
				Knapn[N] = n[N];
				knapAmt[N] = amt[N];
				N = N - 1;
			}
		}
		for (int i = 0; i < no; i++)
			totalAmtKnap = totalAmtKnap + knapAmt[i];
		return totalAmtKnap;
	}
	void sort(float a[],float b[],float c[],string name[])//insertion sort
	{
		int j, i;
		float temp,tempb,tempc;
		string tempn;
		for (j = 1; j < no; j++)
		{
			temp = a[j];
			tempb = b[j];
			tempc = c[j];
			tempn = name[j];
			i = j - 1;
			for (; a[i] > temp&&i >= 0; i--)
			{
				a[i + 1] = a[i];
				b[i + 1] = b[i];
				c[i + 1] = c[i];
				name[i + 1] = name[i];
			}
			a[i + 1] = temp;
			b[i + 1] = tempb;
			c[i + 1] = tempc;
			name[i + 1] = tempn;
		}
	}
}pk;
int main()
{
	pk.input();
	float total=pk.partialKnapsack();
	cout << "Total amt in price of the Sack after filling is " << total << endl;
	pk.display();
    return 0;
}

