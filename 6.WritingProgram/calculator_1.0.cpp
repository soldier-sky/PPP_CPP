// This program is for calculator which takes input and operation from cmd line

#include"std_lib_facilities.h"

int main()
{

	cout<<"Please enter expression (we can handle +,-,*, and / ) \n";
	cout<<"Add an x to end expression(e.g., 1+2*3x):";

	int lval=0;
	int rval;

	cin>>lval;    // Read leftmost operand

	if(!cin)
		error("No first operand");
	
	for(char op; cin>>op;) //read operator and right hand operand repeatedly
	{
		if(op!='x')
			cin>>rval;
		if(!cin)
			error("no second operand");

		switch(op)
		{
			case '+':
				lval+=rval;
				break;
			case '-':
				lval-=rval;
				break;
			case '*':
				lval*=rval;
				break;
			case '/':
				lval/=rval;
				break;

			default:	// Not another operator: print result
				cout<<"Result: "<< lval <<endl;
				return 0;
		}
	}

	error("bad expression");

}
