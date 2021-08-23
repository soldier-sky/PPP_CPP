/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 17 July 2021
* Description: 9. excersise to determin direction of stack and heap growth
*
*
**************************************************************************************/
#include<iostream>
using std::cout;
int main()
{
	int arr1[10];
	cout<<"Pushing array 1 to stack "<<&arr1<<'\n';

	int arr2[10];
	cout<<"Pushing array 2 to stack "<<&arr2<<'\n';
	
	int *iptr1=new int[10];
	cout<<"Pushing array 1 to heap "<<iptr1<<'\n';
	
	int *iptr2=new int[10];
	cout<<"Pushing array 2 to heap "<<iptr2<<'\n';
	
	if(&arr1 > &arr2)
		cout<<"Stack grows up\n";
	else
		cout<<"Stack grows down\n";
		
	if(iptr2 > iptr1)
		cout<<"Heap grows up\n";
	else
		cout<<"Heap grows down\n";
	
	delete[] iptr1;
	delete[] iptr2;
	return 0;
}

/* sample output: stack grows down and heap grows up
Pushing array 1 to stack 0x7ffd56fdfcd0
Pushing array 2 to stack 0x7ffd56fdfd00
Pushing array 1 to heap 0x55c01c3e92c0
Pushing array 2 to heap 0x55c01c3e92f0
*/
