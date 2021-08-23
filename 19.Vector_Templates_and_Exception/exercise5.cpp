/*********************************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 7 Aug 2021
* Description: 5. Define a class Int having a single member of class int. Define constructors,
*		 assignment, and operators +, –, *, / for it. Test it, and improve its design as needed
*		 (e.g., define operators << and >> for convenient I/O).
*	       
* Note: 
***********************************************************************************************/
#include<iostream>

using namespace std;

class Int
{
public:
	Int(int i):var{i}
	{}
	Int():var{0}
	{}
	
	int get_val(){return var;}
	int operator+(int i);
	int operator-(int i);
	int operator*(int i);
	double operator/(int i);
	friend istream& operator>>(istream& is, Int& obj);  // friend non member function	
	friend ostream& operator<<(ostream& os, const Int& obj);  // friend non member function
	
private:
	int var;
};
int Int::operator+(int i)
{
	return var+i;
}

int Int::operator-(int i)
{
	return var-i;
}

int Int::operator*(int i)
{
	return var*i;
}

double Int::operator/(int i)
{
	if(i!=0)
		return var/i;
	else
		return -1;//indicating error
}	

istream& operator>>(istream& is, Int& obj)
{
	
	is>>obj.var; // not doing type check etc
	return is;
}

ostream& operator<<(ostream& os, const Int& obj)
{
	os<<obj.var;
	return os;
}
//---------------------------------------------------------------------------------------
int main()
{
	// declaring Int type
	Int val(10);
	cout<<"output of addition of val with 5 is: "<< val+5<<endl;
	cout<<"output of multiplcation of val with 5 is: "<< val*5<<endl;
	cout<<"output of division of val with 5 is: "<< val/5<<endl;
	
	cout<<"please enter int value :";
	Int v2;
	cin>>v2;					// overloaded >> operator
	cout<<"Value inside v2 "<<v2<<endl;		// overloaded << operator
	
	return 0;
}
