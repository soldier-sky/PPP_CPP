/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 7 Sep 2021
* Description: 5. implementing find() algorithm
*
* Note: 
***********************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

template<typename Iter, typename T>
Iter my_find(Iter first, Iter last, const T& val)
{
	while(first!=last && *first!=val)
		first++;

	return first;
}


template<typename Iter, typename Pred>
Iter my_find_if(Iter first, Iter last, Pred pred)
{
	while(first!=last && !pred(*first))
		first++;

	return first;
}

bool is_even(int in)
{
	bool result= (in%2==0)?true:false;
	
	return result;
}


int main()
{
	vector<int> vi{1,34,5,22,6,88, 4,2,5,99,98};
	
	int pattern=501;
	
	auto iter=my_find(vi.begin(), vi.end(), pattern);
	
	if(iter!=vi.end())
		cout<<pattern<< " is present in sequence\n";
	else 
		cout<<pattern<< " is not present in sequence\n";
	
	
	auto even_iter=my_find_if(vi.begin(), vi.end(), is_even);
	if(even_iter!=vi.end())
		cout<<"First occurance of even no. in sequence "<<*even_iter;
	else 
		cout<<pattern<< "Even no. is not present in sequence";
	
	cout<<"\n";
	
	return 0;	
}
