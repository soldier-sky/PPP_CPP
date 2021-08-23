// Simple Calculator: This program takes 3 input i.e. 2 values/operand and one operator
// Based on the operator it outputs the value of math operation

#include"std_lib_facilities.h"

int main()
{
	double val1, val2;
	char op;

	cout<<"Please enter 2 input values and 1 operator: \n";
	cout<<"Example 4.0 3.0 + to calulate addition of two no. \n";

	cin>> val1>>val2>>op;

	switch(op)
	{
	case '+':
		cout<<"Addition of two inputs are: "<<(val1+val2) <<endl;
		break;
	case '-':
		cout<<"Addition of two inputs are: "<<(val1-val2) <<endl;
		break;
	case '*':
		cout<<"Addition of two inputs are: "<<(val1*val2) <<endl;
		break;
	case '/':                                                        
       		cout<<"Addition of two inputs are: "<<(val1/val2) <<endl; 	
		break;
	default:
		cout<<"Sorry! invalid operation\n";
		break;
	}
	return 0;
}
