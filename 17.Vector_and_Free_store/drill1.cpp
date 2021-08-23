/****************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 15 July 2021
* Description: Part one of drill to understand
*   how free store work etc
*
*
*******************************************/
#include "../std_lib_facilities.h"

void print_array10(ostream& os, int* a);
void print_array(ostream& os, int* a, int n);
void print_vector(ostream& os, vector<int> v);

int main()
{
	int *int_ptr=new int[10]{1,2,3,4,5,6,7,8,9,10};
	//int_ptr={1,2,3,4,5,6,7,8,9,10};
	for(int i=0; i<10;++i)
		cout<<int_ptr[i]<<endl;
	
	cout<<"Printing 10 elements of array using print_array10()\n";
	print_array10(cout,int_ptr);	
	
	int *int_ptr2=new int[10]{12,22,33,44,55,66,77,88,99,100};
	cout<<"Printing 10 elements of array using print_array()\n";
	print_array(cout,int_ptr,10);
	
	delete[] int_ptr;
	delete[] int_ptr2;
	
	
	vector<int> v1(10);
	for(auto v:v1)
		cout<<v<<endl;
	
	cout<<"Printing 10 elements of int vector using print_vector()\n";
	vector<int> v2{1,2,3,4,5,6,7,8,9,10};
	print_vector(cout,v2);
	return 0;
}

void print_array10(ostream& os, int* a)
{
	
	for(int i=0; i<10; i++)
		os<<a[i]<<"\n";
}

void print_array(ostream& os, int* a, int n)
{
	
	for(int i=0; i<n; i++)
		os<<a[i]<<"\n";
}

void print_vector(ostream& os, vector<int> vec)
{
	for(int v:vec)
		os<<v<<endl;
}

