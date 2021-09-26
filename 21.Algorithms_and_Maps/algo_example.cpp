/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 27 Aug 2021
* Description:  example program to test standard algos like find, find_if, sort etc
*
* Note: STL approch of predicate is recommended if predicate is not expected to be used 
*	else where.
***********************************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct value_greater_than
{
	int val;
	value_greater_than(int vv):val{vv} 
	{}
	bool operator()(int x)      //function object
	{
		return x>val;
	}	
};

int main()
{
	vector<int> vi{1,4,49,2,55,3, 66,9, 893};
	
	int value=34;
	
	auto res=find(vi.begin(), vi.end(), value);
	if(res!=vi.end())
		cout<<value<<" is present in list\n";
	else
		cout<<value<<" is not present in list\n";
		
		
	// using find_if to search value greater than 49 using predicate.
		
	auto val_greater_49= find_if(vi.begin(), vi.end(), value_greater_than(49));

	if(val_greater_49!=vi.end())
		cout<<"Value greater than 49 is "<<*val_greater_49<< " present in list\n";
	else
		cout<<"Value greater than 49 is not present in list\n";
	
	
	// using find_if with template predicate
	auto val_greater_86= find_if(vi.begin(), vi.end(), [](int x) {return x>86;});
	
	if(val_greater_86!=vi.end())
		cout<<"Value greater than 49 is "<<*val_greater_86<< " present in list\n";
	else
		cout<<"Value greater than 49 is not present in list\n";
		
	// sorting vector<int>
	sort(vi.begin(), vi.end());
	for(auto v: vi)
		cout<<v <<'\t';
	cout<<'\n';
	
	return 0;
}
