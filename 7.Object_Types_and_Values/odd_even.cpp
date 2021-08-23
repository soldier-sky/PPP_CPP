//Program to print whether input integer is odd or even
//
#include"std_lib_facilities.h"

int main()
{
	int num;

	cout<<"Plase enter integer number: ";
	cin>>num;

	if(num%2==0)
		cout<<"Entered number" <<num <<" is even number"<<endl;
	else
		cout<<"Entered number" <<num <<" is odd number"<<endl;

	return 0;
}
