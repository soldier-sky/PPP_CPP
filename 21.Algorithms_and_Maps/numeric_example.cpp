/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 28 Aug 2021
* Description:  example program to test standard algos from numeric header
*
* Note: <functional> contain binary opertor function such as multiplies<T> (multiplies T types)
*    plus (it adds), minus (it subtracts), divides,and modulus (it takes the remainder)
***********************************************************************************/
#include<iostream>
#include<vector>
#include<numeric>
#include<functional>

using namespace std;

// user defined binary operator. Note initial value is first arg to operator
template<typename T>
T my_multiplies(T init, T val)
{
	return init*val;
}

int main()
{

	vector<int> vi{1,3,5,7,9,11,13,15,17,19};
	vector<int> v1{1,2,3,4,5,6,7,8};
	vector<int> v2{1,2,3,4,5,6,7,8};
	
	int sum=accumulate(vi.begin(), vi.end(),0);
	
	cout<<"accumulated result is "<<sum<<endl;
	
	// using 4 arg accumulate:
	//int sum2=accumulate(v1.begin(), v1.end(),1, multiplies<int>());
	int sum2=accumulate(v1.begin(), v1.end(),1, my_multiplies<int>);
	cout<<"accumulated result using multiply opertor is "<<sum2<<endl;
	
	//--------------------------------------------------------------------------------
	// calculating inner product between two vectors
	int ip_result=inner_product(v1.begin(), v1.end(), v2.begin(), 0);
	cout<<"Result to inner prodcut for two vector<int> is "<<ip_result<<endl;
	
	return 0;
}
