/*********************************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 7 Aug 2021
* Description: 5. Define a class Int having a single member of class int. Define constructors,
*		 assignment, and operators +, –, *, / for it. Test it, and improve its design as needed
*		 (e.g., define operators << and >> for convenient I/O).
*	       6. Repeat the previous exercise, but with a class Number<T> where T can be any numeric type.
*		 Try adding % to Number and see what happens when you try to use % for Number<double> 
*		and Number<int>.
* Note: 
***********************************************************************************************/
#include<iostream>

using namespace std;

//---------------------------------------------------------------------------------------
class Int
{
public:
	Int(int i):var{i}
	{}
	Int():var{0}
	{}
	
	int get_value(){return var;}
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
// exercise 6
template<typename T>
class Number
{
public:
	Number(T val):var{val}
	{}
	Number():var{0}
	{}
	T get_value(){return var;}
	T operator+(T i) { return var+i;}
	T operator-(T i) { return var-i;}
	T operator*(T i) { return var*i;}
	T operator/(T i) { return var*i;}
	T operator%(T i) { return var%i;}   // invalid operation for float and double
	
	/*Overloading template approch 1*/
	friend istream& operator>>(istream& is, Number& obj)  // friend non member inline function
	{
		is>>obj.var; // not doing type check etc
		return is;
	}
	
	// Overloading template approch 2
	template<typename U>
	friend ostream& operator<<(ostream& os, const Number<U>& obj);
	
private:
	T var;
};

// Overloading template approch 2
template<typename T>
ostream& operator<<(ostream& os, const Number<T>& obj)
{
	os<<obj.var;
	return os;
}

//---------------------------------------------------------------------------------------

int main()
{
	/*
	// declaring Int type
	Int val(10);
	cout<<"output of addition of val with 5 is: "<< val+5<<endl;
	cout<<"output of multiplcation of val with 5 is: "<< val*5<<endl;
	cout<<"output of division of val with 5 is: "<< val/5<<endl;
	
	cout<<"please enter int value :";
	Int v2;
	cin>>v2;					// overloaded >> operator
	cout<<"Value inside v2 "<<v2<<endl;		// overloaded << operator
	
	*/
	// exercise 6
	Number<float> f;
	Number<int> i(200);
	Number<double> d{3.14};
	d=d+12;
	cout<<"Value of d is "<<d <<" and value of i "<<i%2<<endl;
	cout<<"Value inside Number object i: "<<i.get_value()/8<<endl;
	cout<<"Value inside Number object f: "<<f.get_value()<<endl;
	cout<<"Adding Number in object d: "<<d.get_value()+9<<endl;
	cout<<"Adding Number in object d: "<<d.get_value()+9<<endl;
	cout<<"Inser floating point value:";
	
	cin>>f;
	cout<<"Value of f is "<<f<<endl;
	
	return 0;
}
