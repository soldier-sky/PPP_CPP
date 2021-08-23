// This program read digit input in the form of string and prints individual integer
// For example: input "123" produce "123 is 1 hundred and 2 tens and 3 ones"

#include"std_lib_facilities.h"


int main()
{
	string str_in;
	int d1,d2,d3;
	cout<<"Please enter 3 digit input";
	cin>>str_in;

	d3=str_in[0] - '0';
	d2=str_in[1] - '0';
	d1=str_in[2] - '0';
	cout<<"The input contains "<< d3<<" hundred "<< d2 <<" tens and "<<d1 << "ones";

	// below section will read integer input and give no. of ones, tens and hundreds
	cout<<"\nPlease enter 3 digit number";
	int num,h,temp,t,o;
	cin>>num;
	
	// disecting individual digits
	h=num/100;      // hundred 
	temp=num%100;
	t=temp/10;	// ten
	o=temp%10;		// one

	cout<<"Number "<<num <<"contains "
		<< h<<" hundreds "
		<< t<<" tens and "
		<< o<<" ones\n";

	return 0;
}
