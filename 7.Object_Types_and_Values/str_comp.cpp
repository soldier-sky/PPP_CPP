//Read and compare names

#include "std_lib_facilities.h"

int main()
{

	cout<<"Please enter two name \n";
	string first, second;
	
	cin>>first >>second;

	if(first== second)
		cout<<"Two entered names are same";
	else if(first < second)
		cout<<first <<" is alphabetically before " <<second;
	else
		cout<< first<< " is alphabetically after "<<second;

	return 0;
}
