#include"std_lib_facilities.h"

int  main()
{
	constexpr double cm_per_inch=2.54;

	double length=1;
	char unit='a';

	cout<<"Please enter a lenght followed by c(cm) or i(inches): ";
	cin>>length>>unit;

	if(unit=='i')
		cout<<length <<"inch = " << cm_per_inch*length <<"cm \n";
	else if(unit == 'c')
		cout<<length <<"cm = " << length/cm_per_inch <<"inches \n";
	else
		cout<<"Sorry. Input unit is invalid\n";
	return 0;
}
