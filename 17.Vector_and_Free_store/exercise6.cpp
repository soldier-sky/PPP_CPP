/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 17 July 2021
* Description: 6. Testing memory allocation limit
*
**************************************************************************************/
#include<iostream>

int main()
{
	int* ip;
	int n=10000;
	int i=0;
	double size{0};
	while(1)
	{
		ip=new int[n*i];
		size=8.0*n*i; 	//sizeof(ip) is 8 in this machine
		std::cout<<i<< " Allocated "<<size <<" successfully\n";
		i++;
	}
	//  could allocate 6.71064e+09 Bytes successfully
	
	return 0;
}
