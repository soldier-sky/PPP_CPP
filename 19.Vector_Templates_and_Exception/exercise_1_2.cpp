/*********************************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 4 Aug 2021
* Description: 1. Template function to add two vector<T> such that v1[i]+=v2[i]
*	       2. Template funciton to multiply two vector<T> and reurns v1[i]*v2[i]
* Note: 
***********************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

// Template function foo_add sums element wise of one vector into another
template<typename T>
void foo_add(vector<T>& v1, vector<T>& v2)
{
	int v1_size=v1.size();
	int v2_size=v2.size();
	if(v1_size != v2_size)
		cout<<"Size of two vectors are not same";
	// in case of un equal size, we'll use v2.size() as looping parameter
	for(int i=0; i<v2_size;i++)
		v1[i]+=v2[i];
}

// Template function foo_mul retuns element wise multiplication of two input vector
template<typename T>
vector<T>  foo_mul(vector<T>& v1, vector<T>& v2)
{
	int v1_size=v1.size();
	int v2_size=v2.size();
	vector<int> result(v2_size);
	
	if(v1_size != v2_size)
		cout<<"Size of two vectors are not same";

	// in case of un equal size, we'll use v2.size() as looping parameter
	for(int i=0; i<v2_size;i++)
		result[i]=v1[i]*v2[i];
	
	return result;
}

int main()
{
	vector<int> v1{1,2,3,4,5,6,7,8,9,10};
	vector<int> v2{1,2,3,4,5,6,7,8,9,10};
	
	vector<int> mul_result=foo_mul<int>(v1,v2);
	for(auto v:mul_result)
		cout<<v <<" ";
	cout<<endl;

	foo_add<int>(v1,v2);
	for(auto v:v1)
		cout<<v <<" ";
	cout<<endl;
	

	
	return 0;
}
