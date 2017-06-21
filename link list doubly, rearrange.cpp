/*
It adds the elements to the Linked list and then rearrange them according to i th element from first and last are put at 2i-1 and 2i position, that is 1st and last element at 1st and 2nd position ans soon.
*/

/// Author : Deepanker Sachdeva

//#include "stdafx.h"

#include <iostream>
using namespace std;

struct node
{
	int data;
	node *prev;
	node *next;
	
	int i;
};
node *head = NULL;
class lil
{
	node *last = head;
	int i = 0;
public:
	node *create(int data)
	{
		i++;
		node *n = (node *)malloc(sizeof(node));
		n->data = data;
		n->prev = NULL;
		n->next = NULL;
		n->i = i;
		return n;
	}
	void insert()
	{
		int data;
		cin >> data;

		node *n = create(data);
		//last = head;
		node *ptr;
		ptr = head;
		if (head == NULL)
		{

			head = n;
			last = head;
		}
		else
		{
			last->next = n;
			n->prev = last;
			last = n;

		}
	}
	void traverse()
	{
		node *ptr;
		ptr = head;
		while (ptr != NULL)
		{
			cout << ptr->data << endl;
			ptr = ptr->next;
		}
	}
	void re()
	{
		node *ptr;
		ptr = head;
		int i = 0;
		node *temp;
		node *templast;
		while (ptr->next != NULL)
		{
			//put(ptr);
			//while(last)
			temp = ptr->next;
			if (temp == NULL)
				break;
			if (ptr->next == last)
				break;
			ptr->next = last;
			templast = last->prev;
			last->prev = ptr;
			last->next = temp;
			temp->prev = last;
			if(templast!=NULL)
				templast->next = NULL;
			last = templast;
			ptr = temp;
		}
	}

}l;


int main() {
	int k = 0;
	cout << "It adds the elements to the Linked list and then rearrange them according to i th element from first and last are put at 2i-1 and 2i position, that is 1st and last element at 1st and 2nd position ans soon.\n\n";
	cout << "Enter the elements such that \n1 4\n 1 5 \ntelling that 4 and 5 are entered in the Linked List\n when done instead of 1 enter anything else\n";
	do
	{
		cin >> k;

		if (k == 1)
			l.insert();

	} while (k == 1);
	l.re();

	l.traverse();
	return 0;
}