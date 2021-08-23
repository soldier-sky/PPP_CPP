//Example program to understand type unsafe conversions
#include"std_lib_facilities.h"

int main()
{
	int a=20000;
	char c=a;
	int b=c;

	if(a!=b)
		cout<<"oops!: "<< a<<" != "<< b <<endl;
	else
		cout<<"wow! we have large characters \n";

	return 0;	
}
