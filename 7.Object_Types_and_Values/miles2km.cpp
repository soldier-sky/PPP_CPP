#include <iostream>
using namespace std;

int main()
{
	double km,mile;
	cout<<"Please enter miles travelled: ";
	cin>>mile; //miles is string
	km=mile*1.6;
	
	cout<< "\nYou've travelled "<< km << " km"<<endl;

	return 0;
}
