/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description: 7. Find the lexicographical last string in an unsorted vector<string>.
* 
* Note:
***********************************************************************************/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	vector<string> v_str{"apple", "mango", "peach", "banana"};
	string last;
	
	last=v_str[0];
	for(string s:v_str)
		if(s>last)
			last=s;
	cout<<"last string in unsorted vector<string> is :"<<last<<endl;
	
	return 0;
}

