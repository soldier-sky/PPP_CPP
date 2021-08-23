/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 16 Aug 2021
* Description:  5. Define an input and an output operator (>> and <<) for vector.
***********************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& vec)
// overloading insertion operator for vector type
{
	for(auto &v:vec)
	   os<<v <<"\t";
	
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& vec)
// overloading insertion operator for vector type
{
	T temp;
	while(is>>temp)    // ctrl + D to terminate i.e. EOF
		vec.push_back(temp);
	return is;
}

int main()
{
	cout<<"Printing vector contents\n";
	vector<int> vi{1,5,7,9,11,13,15};
	cout<<vi<<'\n';
	
	vector<string> vs{"sunil", "kumar", "invalid", "details"};
	cout<<vs<<'\n';
	
	vector<int> vi2;
	cout<<"Enter sequence of int (ctrl + D to exit):";
	cin>>vi2;
	
	cout<<vi2<<'\n';
	
	
	return 0;
}
