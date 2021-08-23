/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 17 July 2021
* Description: 11. Creating doubly linked list of 17.10.1 
*
**************************************************************************************/
#include<iostream>
#include<string>
using namespace std;

struct sNode;           // forward declared node structure

void insert_to_start(string data, sNode** ptr_to_head);
//void insert_to_start2(string data);
void print_list(sNode* node);

// single linked list node
struct sNode
{
	string data;
	sNode* next;
	sNode():data{""},next{nullptr}
	{}
	
	sNode(string str):data{str},next{nullptr}
	{}
	
};

sNode *head=nullptr;     // global head pointer to singly linked list

int main()
{
	/*  manually constructing singly linked list
	sNode *node1=new sNode("Sunil");
	sNode *node2=new sNode("Ayaan");
	sNode *node3=new sNode("Pooja");
	
	head=node1;
	node1->next=node2;
	node2->next=node3;
	
	*/
		
	insert_to_start("Sunil Yadav",&head);
	insert_to_start("Ayaan Yadav",&head);
	insert_to_start("Pooja Yadav",&head);
	
	print_list(head);
	
	return 0;
}


void insert_to_start(string data, sNode** ptr_to_head)
{
	sNode* node= new sNode(data);
	
	node->next=*ptr_to_head;
	*ptr_to_head=node;
}

/*
void insert_to_start(string data)
{
	sNode* node= new sNode(data);
	node->next=head;
	head=node;
}
*/


void print_list(sNode* node)
{
	while(node!=nullptr)
	{
		cout<< node->data <<endl;
		node=node->next;
	}
}







