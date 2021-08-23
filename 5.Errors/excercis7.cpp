// This program will calculate the quadratic equations solution
// for a  given quadratic equation of form:
//         a*x^2 + b*x +c = 0
//
//         x = -b +/- sqrt(b^2 -4ac)
//             ----------------------
//                     2a
//
#include "std_lib_facilities.h"


// This function only calculate real part 
int quad_eq_solver(int a, int b, int c)
{
	int discriminant, result=0;

	discriminant = (b*b) - (4*a*c);

	if(discriminant <0)
	{
		cout<<"Failed! Discriminant of quadratic equeation is less than zero\n";
		return -1;
	}
	else
	{
		result = ((-b) +  discriminant )/(2*a);
	}

	return result;
}


int main()
{
	int a=1, b=2, c=1;
	int result= quad_eq_solver(a,b,c);

	cout<<"Result is :"<<result;

	return 0;
}
