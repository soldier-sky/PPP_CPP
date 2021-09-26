/**********************************************************************************
* Chapter Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 5 Sep 2021
* Description: Drill exercise to get familier with sort() alogrithm
*
*
* Note: Repeate below exercise for list. Since list do not of random access iterator
*       use list.sort() method to sort
***********************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include <random>  // for random no. generator

using namespace std;


//-------------------------------------------------------------------------------------------
struct Item
{	
	string name;
	int iid;
	double value;
	
	Item():name{""},iid{0}, value{0}{}
	
	Item(string str, int id, double v)
		: name{str}, iid{id}, value{v} {}
};

// helper functions for sorting
bool Item_strcmp(const Item& i1, const Item& i2){ return i1.name< i2.name; }

bool Item_idcmp(const Item& i1, const Item& i2) { return i1.iid< i2.iid;}

// comprator operation for decreasting order
bool Item_valcmp(const Item& i1, const Item& i2) { return i1.value > i2.value; }

//-------------------------------------------------------------------------------------------
int main()
{
	vector<Item> vi(10);
	string iname= "item";
	
	
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> ran_dist(1,8954); // distribution in range [1, 8954]

	// initializing vector of Item
	for(auto iter=vi.begin(); iter!= vi.end(); ++iter)
	{	
		int id=ran_dist(rng);			// using random no. generator for three fields
		int val= ran_dist(rng)/10;
		char suffix= ran_dist(rng)%128;
		
		Item temp(iname+suffix,id,val);
		*iter=temp;
	}
	
	cout<<"Printing values stored in Item\n";
	cout<<"Name\tId\tValue\n";
	for(auto v: vi)
		cout<<v.name<<'\t' <<v.iid<<'\t' <<v.value<<'\n';
		
	
	cout<<"\n----------------------------------------------------------\n";
	cout<<"Printing values after sorting by name in Item\n";
	sort(vi.begin(), vi.end(),Item_strcmp);
	for(auto v: vi)
		cout<<v.name<<'\t' <<v.iid<<'\t' <<v.value<<'\n';
	
	cout<<"\n----------------------------------------------------------\n";
	cout<<"Printing values after sorting by id in Item\n";
	sort(vi.begin(), vi.end(),Item_idcmp);
	for(auto v: vi)
		cout<<v.name<<'\t' <<v.iid<<'\t' <<v.value<<'\n';	
	
	cout<<"\n----------------------------------------------------------\n";
	cout<<"Printing values after sorting by value in Item (decrearing order)\n";
	sort(vi.begin(), vi.end(),Item_valcmp);
	for(auto v: vi)
		cout<<v.name<<'\t' <<v.iid<<'\t' <<v.value<<'\n';	
		
	cout<<"\nremoving two elements from vector of Item\n";
	vi.erase(vi.begin()+3);
	vi.erase(vi.begin());
	for(auto v: vi)
		cout<<v.name<<'\t' <<v.iid<<'\t' <<v.value<<'\n';	

	return 0;
}




