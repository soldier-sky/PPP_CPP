/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 14 Aug 2021
* Description:  Drill section
***********************************************************************************/
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

//--------------------------------------------------------------------------------------
// user defined template function container copy function
template <typename iter1, typename iter2>
iter2 my_copy(iter1 f1, iter1 e1, iter2 f2)
{
	if(f1==e1) return f2; // empty container
	
	for(auto iter=f1; iter!=e1; iter++)
	{
		*f2=*iter;
		f2++;
	}
	return f2;
}
//--------------------------------------------------------------------------------------

int main()
{
	int array[10]={0,1,2,3,4,5,6,7,8,9};
	vector<int> vec{0,1,2,3,4,5,6,7,8,9};
	list<int> lst={0,1,2,3,4,5,6,7,8,9};
	
	// making copy
	int array2[10];
	vector<int> vec2=vec;
	list<int> lst2=lst;
	for(int i=0; i<10;++i)
		array2[i]=array[i];
		
		
	// modifying 
	for(int i=0;i<10;++i)
	{
		array[i]+=2;
		vec[i]+=3;
		
	}
	for(list<int>::iterator it=lst.begin(); it!=lst.end(); it++)
		*it=(*it) +5;
	
	// using local copy to copy contents
	vector<int> vec3(10);
	
	my_copy(vec2.begin(), vec2.end(), vec3.begin());
	for(auto v:vec3)
		cout<<v<<"\t";
	cout<<'\n';
	
	//--------------------------------------------------------------------------------------
	// using stl algo find.
	// Note if val is not found, find() returns iter to last element
	auto iter=find(vec2.begin(), vec2.end(), 3);  // if iter is null then 3 is not in vector
	int idx =iter - vec2.begin() +1;   // +1 as index start with 0
	
	if(iter!=vec2.end())
		cout<<"value "<<*iter<< " found at index "<<idx<<"\n";
	else
		cout<<"value not found\n";
	
	auto lst_iter=find(lst2.begin(), lst2.end(), 33);  // if iter is null then 3 is not in vector
	//int idx_lst =lst_iter - lst.begin() +1;   // error: list iter doesn't support sub
	
	if(lst_iter!=lst2.end())
		cout<<"value "<<*lst_iter<< " found in list \n";
	else
		cout<<"value not found\n";
	return 0;
}

