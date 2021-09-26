/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 7 Sep 2021
* Description: 3. implementing count()
*		4. implementing count_if()
*
* Note: 
***********************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

template<typename Iter, typename T>
int my_count(Iter start, Iter end, T val)
{
	int count=0;
	while(start!=end)
	{
		if(*start == val) count++;
		start++;
	}
	return count;
}


template<typename Iter, typename Pred>
// Pred return boolean
int my_count_if(Iter first, Iter last, Pred pred)
{
	int count=0;
	while(first!=last) 
	{
		if(pred(*first))
			count++;
		first++;
	}
	return count;
}

bool is_even(int in)
{
	bool result= (in%2==0)?true:false;
	
	return result;
}

int main()
{
	vector<int> vi{1,3,5,22,6,88, 4,2,5,99,98};
	
	int pattern=5;
	int cnt=my_count(vi.begin(), vi.end(), pattern);
	cout<<pattern <<" occurs total "<<cnt<<" times in sequence\n";
	
	cout<<" No. of odds in sequence are "<<my_count_if(vi.begin(), vi.end(),is_even)<<'\n';
	
	return 0;
}
