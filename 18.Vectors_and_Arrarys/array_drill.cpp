/****************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 26 July 2021
* Description: array drill page 452
*
*******************************************/

#include<iostream>
using namespace std;

const int size=10;
int ga[size]={1,2,4,8,16,32,64,128,512,1024};

void f(int array[], int array_size)
{
	int la[10]={};
	for(int i=0; i<10;i++)
	{
		la[i]=ga[i];
		cout<<la[i]<< " ";
	}
	cout<<endl;
	
	int* p=new int[array_size];
	for(int i=0; i<array_size; ++i)
	{
		p[i]=array[i];
		cout<<p[i]<< " ";
	}
	cout<<endl;
	
	delete[] p;
}

int factorial(int n)
{
	int result=1;
	while(n>0)
	{
		result*=n;
		n--;
	}
	return result;
}

int main()
{
	f(ga,10);
	
	const int la_size=10;
	int aa[la_size]={};
	for(int i=0; i<la_size;++i)
		aa[i]=factorial(i);
	
	f(aa, la_size);
	
	return 0;
}
