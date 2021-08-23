/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 10 Aug 2021
* Description: Write a function void copy(int* f1, int* e1, int* f2) that copies the elements of an array of ints defined
* by [f1:e1) into another [f2:f2+(e1–f1)). Use only the iterator operations mentioned above (not subscripting)
*
* Note:
***********************************************************************************/
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void copy(int* f1, int* e1, int*f2)
{
	if(f1==nullptr) 
	{
		cout<<"Null pointer!\n";
		return; // invalid pointer to begin
	}	
	for(int* first=f1;first!=e1; ++first,f2++)
		*f2=*first;
	
}


// 20.3.1: templated high() function 
// returns Iterator to element in [first:last) that has highest value
template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{	
	/* add null check and throw exception*/
	Iterator high=first;
	for(Iterator p=first; p!=last;++p)
		if(*high<*p) high=p;
	return high;

}

int main()
{
	const int size=2;
	//int in_array[5]={12,29,34,4,15};
	int out_array[size];
	//int *in_array=nullptr;
	int in_array[size]={18,22};
	
	copy(in_array,in_array+size, out_array);
	for(int i=0; i<size; i++)
		cout<<out_array[i]<<"\t";
	cout<<endl;
	
	int* largest=high(in_array, in_array+size);
	cout<<"largest in collection is :"<<*largest<<endl;
	return 0;
}

