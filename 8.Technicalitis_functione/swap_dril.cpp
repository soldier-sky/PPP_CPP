// This program use swapping of two input to show difference between
// call by value, call by const refernce and pass by refernce

#include"../std_lib_facilities.h"

void swap_v(int a, int b)
{
	int temp;
	temp =a;
	a=b;
	b=temp;
}
void swap_r(int& a, int& b)
{                         

	int temp; 
	temp =a;
	a=b;     
	b=temp;
}

/*   Commenting swap by cost ref as const ref can not be modified
void swap_cr(const int& a, const int& b)
{                         

	int temp; 
	temp =a;
	a=b;     
	b=temp;
}
*/
int main()
{
	int x=7;
	int y=9;

	swap_v(x,y);
	cout<<"x,y "<<x <<","<<y<<"\n";
	swap_r(x,y);
//	swap_cr(x,y);

	cout<<"x,y "<<x <<","<<y<<"\n";
	return 0;
}
