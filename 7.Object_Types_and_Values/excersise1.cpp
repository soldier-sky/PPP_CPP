//Program takes two input values in integer and compares,multiply,add etc and print the result.
#include "std_lib_facilities.h"

int main()
{
	double  val1, val2;
	cout<< "Please enter two valid integers: ";
	cin>>val1;
	cin>>val2;

	cout<< "\nComparision operation \n";

	if(val1 > val2)

		cout<< val1 <<" is greater than " << val2;
	else if(val1 < val2)
		cout<< val1 <<" is smaller  than " << val2;
	else
		cout<< val1 <<" is equal to " <<val2;
	
	cout<<"\n Arithmatic operations \n";	
	cout<< val1 <<" + " << val2 << " = " <<(val1+val2)<<endl;
	cout<< val1 <<" - " << val2 << " = " <<(val1-val2)<<endl;
	cout<< val1 <<" * " << val2 << " = " <<(val1*val2)<<endl;
	cout<< val1 <<" / " << val2 << " = " <<(val1/val2)<<endl;


	return 0;
}
