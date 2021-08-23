/*****************************************
* Author: Sunil Kumar Yadav
* Date: 24 June 2021
* Problem: Sample program to create singly linked list
*	    which allows adding new value at start of list
*
*
*
********************************************/
//#include"../std_lib_facilities.h"
#include<iostream>
using std::cout;
using std::endl;

struct node
{
	int data;
	struct node* next;
};

struct node* head=nullptr;

void insert(int value,  int idx)
// adding value at the start of node
{
	struct node* ptr=head;
	struct node* new_node= new struct node;
	
	new_node->data=value;
	new_node->next=nullptr;
	
	if(idx==0)
	{
		new_node->next=head;
		head= new_node;
	}
	
	int count=0;
	/*
	while(ptr!=nullptr)
	{
		if(count==idx)
		{
			ptr->data=value;
			ptr->next=
		}
		ptr=ptr->next;
	}
	*/
	
}

void display()
{
	struct node* ptr=head;
	while(ptr!=nullptr)
	{
		cout<<ptr->data<<endl;
		ptr=ptr->next;
	}
}

int main()
{

	insert(1,0);
	insert(2,0);
	insert(4,0);
	
	cout<<"Printing value of node:\n";
	display();
	return 0;
}

