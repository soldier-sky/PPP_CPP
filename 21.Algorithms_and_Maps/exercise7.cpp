/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 7 Sep 2021
* Description: 7. Implementing binary search for vector<int> and list<string>
*	
*
* Note: Binary search expects sequence to be already sorted
* Correction to binary search (list) on 16 Sep 2021
***********************************************************************************/
#include<iostream>
#include<list>
#include<vector>
#include<string>
#include<iterator>     // used for implementing binary sort for list
#include<algorithm>    // to validate own function with STL

using namespace std;

//-------------------------------------------------------------------------------------------------------------
// binary search for vector. Here we are not following STL style of [b:e)
// Note: we can use std::distance() and std::advance() to make generic algo similar to STL
bool binary_search_vector(vector<int>& vi, int val)
{
	int first=0;
	int last=vi.size()-1;
	int middle= (first+last)/2;
	
	while(first<=last)
	{
		if(vi[middle]==val)
		{
			return true;
		}
		else if(vi[middle]>val)           //search in left half
			last=middle-1;  
		else 				    //search in right half
			first= middle+1;
		
		middle= (first+last)/2;	
	}
	return false;    
}

//-------------------------------------------------------------------------------------------------------------

// binary search for list<string>
// Using std::distance() to calculate distance between to iterator of same sequence and 
// std::advance() to move iterator to specified offset
bool binary_search_list(list<string>::iterator first, list<string>::iterator last, string val)
{
	list<string>::iterator middle;
	std::iterator_traits<list<string>::iterator>::difference_type count, step;
	count= std::distance(first, last);
	
	while(count>0)
	{
		middle= first;
		step=count/2;
		std::advance(middle, step);
		if(*middle==val)
			return true;
		else if(*middle<val)
		{
			std::advance(middle, 1);
			first=middle;
		}
		else
		{
			std::advance(middle, -1);
			last=middle;
		}
		count= std::distance(first, last);
		
	}
	return false;
}
//-------------------------------------------------------------------------------------------------------------


int main()
{
	vector<int> vi{1,3,5,7,8,22,24, 55, 60, 99};
	int val=88;
	
	auto found =binary_search_vector(vi,val);
	if(found)
		cout<<val<<" is present\n\n";
	else
		cout<<val<<" is not present\n\n";
		
	//------------------------------------------------------------------------------------------------------
	list<string> fruits{"apple","banana","kiwi","pineapple","guava","orange","dragon fruit","mango","chickoo","watermelon"};
	
	fruits.sort();   // sorting list
	
	cout<<"Printing sorted list of fruits\n";
	for(auto fruit: fruits)
		cout<<fruit<<endl;
	cout<<endl;
	
	string str_pattern="watermelon";
	
	auto result=binary_search_list(fruits.begin(), fruits.end(),str_pattern);
	if(result)
		cout<<str_pattern<<" is present\n";
	else
		cout<<str_pattern<<" is not present\n";
		
	return 0;
}


