#include "std_lib_facilities.h"

// Pre condition: input should be greater than -273.15
// Post condition: Return kelvin equivalent of temp
double ctok(double c)
{
	double  k;
       
	if(! (c < -273.15))
	{
		k= c + 273.15;
		return k;
	}
	else
	{
		cout<<"Invalid temperature";
		return -1;
	}

}

double ctof(double c_temp)
{
	double f_temp;
	f_temp= (c_temp*9/5)+32;

	return f_temp;


}

int main()
{
	double c = 0;
	cout<<"Please enter temperature in Celcius: ";
	cin >> c;
	double k = ctok(c);
	double f_temp= ctof(c);
	cout <<"Temp in kelvin is :"<< k << "and in fahrenheit :"<< f_temp <<'\n' ;
}
