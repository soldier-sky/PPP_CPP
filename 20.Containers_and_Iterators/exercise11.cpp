/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description:  11. Given a list<int> as a (by-reference) parameter, make a vector<double> and copy the elements
*   of the list into it. Verify that the copy was complete and correct. Then print the elements sorted 
*   in order of increasing value.
* 
* Note: 
***********************************************************************************/
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>  	// to use std::sort

using namespace std;

// copies content from list to vector
vector<double> copy_list2vector(list<int>& lst)
{
	vector<double> vec;
	for(auto l:lst)
		vec.push_back(l);
		
	return vec;
		
}

int main()
{
	list<int> my_list{111,2,43,4,5,76,7,83};
	vector<double> my_vec;
	
	my_vec=copy_list2vector(my_list);
	
	cout<<"Copied list into vector\n";
	for(auto v:my_vec)
		cout<<v<<'\t';
		
	cout<<"\nsorted sequence in vector\n";
	sort(my_vec.begin(), my_vec.end());

	for(auto v:my_vec)
		cout<<v<<'\t';
	cout<<'\n';

	return 0;
}
