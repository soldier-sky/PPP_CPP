/****************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 15 July 2021
* Description: Part two of drill to understand
*   relationship between pointer and arrays
*
*
*******************************************/
#include"../std_lib_facilities.h"

int main()
{	
	int var=7;
	int* p1=new int;
	p1=&var;
	
	cout<<"value of var: "<<var
	    <<" value of p1: "<<p1
	    <<" value of *p1: "<<*p1<<endl;

	int arr[7]{111,22,33,44,55,66,77};
	int* p2=arr;
	for(int i:arr)
		cout<<i<<endl;
	
	cout<<"printing value of array via ptr\n";	
	for(int i=0; i<7; i++)
		cout<<p2[i]<<"\n";  // optional: cout<<*p2++;
	
	int *p3=p2;
	cout<<*p3;
	
	int* ptr=new int[10];
	ptr[9]=111;
	
	delete ptr;
	
	int* iptr =new int{111};
	double* dptr= new double{10.5};
	
	cout<<"Address of iptr "<< iptr <<endl
	    <<" address of dptr "<<dptr<<endl
	    <<" next address of iptr "<<iptr+1 <<endl
	    <<" next address of dptr "<<dptr+1 <<endl;
	    
	return 0;
}
