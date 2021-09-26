/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 7 Sep 2021
* Description: 6. Implementing example 21.6.5 to understand set and modifying it with
*	set<Fruit*>
*
* Note: set, map are ordered i.e. sorted containers and hence no push_back or [] operator
***********************************************************************************/
#include<iostream>
#include<set>
#include<string>

using namespace std;

struct Fruit
{
	string name;
	int count;
	double unit_price;
	//Date last_sale_date;
};

// using function operator to compare fruits
struct Fruit_order
{
	bool operator()(const Fruit& a, const Fruit& b) const
	{
		return a.name<b.name;
	}
};

struct Fruit_order_ptr
{
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return a->name < b->name;
	}
};

int main()
{

	set<Fruit, Fruit_order> inventory;		// use Fruit_order(x,y) to compare fruits
	
	inventory.insert(Fruit{"quince",5, 10});
	inventory.insert(Fruit{"apple",2, 20});
	inventory.insert(Fruit{"banana",5, 12});
	
	// printing fruit names
	for(auto x:inventory)
		cout<<x.name<<'\n';
	cout<<'\n';
	
	//-----------------------------------------------------------------	
	set<Fruit*, Fruit_order_ptr> ptr_inventory;
	
	ptr_inventory.insert(new Fruit{"quince",5, 10});
	ptr_inventory.insert(new Fruit{"apple",2, 20});
	ptr_inventory.insert(new Fruit{"banana",5, 12});
	

	for(auto x:ptr_inventory)
		cout<<x->name<<'\n';
	
	return 0;
}
