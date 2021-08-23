//Sample program to read name and age from user and printing name and age in month


#include"std_lib_facilities.h"

int main()
{
	
	cout<<"Please enter your name and age ";
	string name;
	double age;
	
	cin>>name;
	cin>>age;

	cout<<"Entered name is "<<name <<"and age in months is "<< age*12 <<endl;
	return 0;

}
