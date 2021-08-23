// This program calculate fabonnaci series no.
// Fabonnaci series are got from addition of earlier two elments.
// For example 0, 1, 1, 2, 3, 5, 8, 13, 21

#include "std_lib_facilities.h"

int main()
{

	vector<unsigned long int> fab_num;   //variable to hold fabnnaci series
	unsigned int count;
 	unsigned long int temp;

	cout<<"Please enter how many element of fabonnaci seies need to be printed:";
	cin>>count;
	
	fab_num.push_back(0); // first no. of fabonnaci series
	fab_num.push_back(1); // second no. of fabonnaci series

	//fab_num.push_back(1); // 3rd no. of fabonnaci series
	for(int i=2; i<count ;++i)
	{
		temp= fab_num[i-2] + fab_num[i-1];
		fab_num.push_back(temp);
	}

	//print fabonnaci series
	for(unsigned long int x:fab_num)
		cout<<x << "\t";

	return 0;
	
}
