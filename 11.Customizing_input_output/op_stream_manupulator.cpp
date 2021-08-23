#include"../std_lib_facilities.h"

int main()
{

	// This program outputs age in decimal, hex and octel format
	
	int age=30;

	cout<<"My age is "<<age <<"(dec) "<<hex << age <<"(hex) "
	                  <<dec << age<< "(dec)"<<dec<<'\n';
	// Note: last <<dec to reset stream to dec format
	
	// Format output to show base of representation
	cout<<showbase;
	cout<<1234<<'\t'<< hex<<1234 <<'\t'<<oct<<1234<<'\n';

	//Floating point manupulators

	cout << 1234.56789 << "\t\t(defaultfloat)\n" // \t\t to line up columns
             << fixed << 1234.56789 << "\t(fixed)\n"
             << scientific << 1234.56789 << "\t(scientific)\n";


	// some floating point precision example
	cout<<1234567.89 <<'\t'
	    <<scientific<<1234567.89 <<'\t'
	    <<fixed<< 1234567.89<<'\n';


	cout << 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';

	cout << defaultfloat << setprecision(5)
		<< 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';

	
	cout << defaultfloat << setprecision(8)
		<< 1234.56789 << '\t'
		<< fixed << 1234.56789 << '\t'
		<< scientific << 1234.56789 << '\n';

	return 0;
}


