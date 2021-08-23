// This program calculates sum for first 'N'  num and then then terminates the input
// operation post '|' symbole input.
//
// does not work as intended
#include "std_lib_facilities.h"

int main()
{
	int num=0, sum=0,size=0;
	char c;


	cout<<"Please enter no. of integer input required: ";
	cin>> size;   //hold how many of N int is expected.
	
	cout<< "Please enter valid "<< size <<" intergers and use | post input";
	for(int i=0; i<size;++i)
	{
		cin>>num;
		sum+=num;
	}
	cin>>c;
	if(c=='|')
	cout<<"Done! sum is "<<sum;

	return 0;
}
