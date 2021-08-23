/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 17 July 2021
* Description: 11. Creating doubly linked list of 17.10.1 
*
* Note: Implementation pending
**************************************************************************************/
#include<iostream>
#include<string>
using namespace std;


//----------------------------------------------------------------------------------
class Link
{
public:
	string value;
	Link(const string& v, Link* p=nullptr, Link* s=nullptr)
		:value{v}, prev{p}, succ{s} {}
	
	Link* insert(Link* n);     			// insert n before this object
	Link* add(Link* n);	    			// insert n after this object
	Link* erase();		    			// remove this object from list
	Link* find(const string& s);			// find s in list
	const Link* find(const string& s)const;   	// find s in const list
	
	Link* advance(int n) const;			// move n positions in list
	
	Link* next() const{return succ;}
	Link* previous() const{return prev;}
		
	
private:
	Link* prev;
	Link* succ;
};

Link* Link::insert(Link* n)        // insert n before p; return n
{
	Link* p=this;        		// pointer to this object
	if(n==nullptr)  return p; 	// nothing to insert
	if(p==nullptr)	return n;	// nothing to insert into
	
	n->succ=p;			// p comes after n
	
	if(p->prev) p->prev->succ=n;
	
	n->prev=p->prev;		// p's predecessor becomes n's predecessor
	p->prev=n;			// n becomes p's predecessor
	
	return n;
}	

Link* Link::add(Link*p, Link* n)   //insert n after p; return n
{
	//much like insert
}

Link* Link::erase(Link* p)     // remove *p from list; return p's successor
{
	if(p==nullptr) return nullptr;
	if(p->succ) p->succ->prev = p->prev;
	if(p->prev) p->prev->succ= p->succ;
	return p->succ;
}

Link* Link::find(Link* p, const string& s)      // find s in list;
{						  // return nullptr for 'not found'
	while(p)
	{
		if(p->value == s) return p;
		p=p->succ;
	}
	return nullptr;
}

Link* advance(Link* p, int n)			// move n positions in list
{						// return nullptr for 'not found'
	//positive n moves forward, negative backword
	
	if(p==nullptr) return nullptr;
	if(0<n)
	{
		while(n--)
		{
			if(p->succ == nullptr) return nullptr;
			p=p->succ;
		}
	}
	else if(n<0)
	{
		while(n++)
		{
			if(p->prev ==nullptr) return nullptr;
			p= p->prev;
		}
	}

	ret
}



//----------------------------------------------------------------------------------

int main()
{
	
	Link* norse_gods=new Link{"Thor"};
	norse_gods= norse_gods->insert(new Link{"Odin"});
	norse_gods=norse_gods->insert(new Link{"Freia"}
	insert("Thor",&norse_gods);
	insert("Odin",&norse_gods);
	insert("Freia",&norse_gods);
	
	print(norse_gods);
	return 0;
}






//------------------------------------------------------------------------------------------
#if 0
struct Link
{
	string value;
	Link* prev;
	Link* succ;
	Link(const string& v, Link*p=nullptr, Link* s=nullptr)
		:value{v}, prev{p}, succ{s} {}
};
void print(Link* head);
void insert(string value,Link** ptr_to_head);

int main()
{
	/*
	Link* norse_gods= new Link{"Thor", nullptr, nullptr};
	norse_gods=new Link{"Odin", nullptr, norse_gods};
	norse_gods->succ->prev=norse_gods;
	
	norse_gods=new Link{"Freia", nullptr, norse_gods};
	norse_gods->succ->prev=norse_gods;
	*/
	Link* norse_gods=nullptr;
	insert("Thor",&norse_gods);
	insert("Odin",&norse_gods);
	insert("Freia",&norse_gods);
	
	print(norse_gods);
	return 0;
}

void print(Link* head)
{
	Link* temp=head;
	while(temp!=nullptr)
	{
		cout<< temp->value<<endl;
		temp=temp->succ;
	}
}

void insert(string value,Link** ptr_to_head)
{
	Link* temp=new Link{value, nullptr, nullptr};
	
	if(*ptr_to_head==nullptr)
	{
		*ptr_to_head= temp;
		return; 
	}
	temp->succ=*ptr_to_head;        // newly created node's succ-> head
	
	
	(*ptr_to_head)->prev=temp;     // previous of head node is new temp node       
	
	*ptr_to_head=temp;    
}
#endif








