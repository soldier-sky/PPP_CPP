/***********************************************
* Chapter: 15. Graphing Functions and Data
* Author: Sunil Kumar Yadav
* Date: 23 June 2021
* Problem: Calculating factorial by recursive and iterative method
*          and testing for various values
*
************************************************/
#include"../std_lib_facilities.h"
#include<iomanip>

unsigned long int fact_r(int n)      // factorial via recursive method
{
	return (n>1? n*fact_r(n-1):1);
}

unsigned long int fact_i(int n)     // factorial via iterative method
{
	long int r=1;
	while(n>1){
	   r*=n;
	   n--;
	}
	return r;
}
int main()
{
	cout<<"printing factorial results";
	
	for(int i=0; i<50;++i)
	{
		cout<<"Factorial of "<<i<< " is via recursion " <<setw(20)<<fact_r(i) << 
		" and via iteration "<<setw(20)<< fact_i(i)<<endl;
	}
	
	return 0;
}

