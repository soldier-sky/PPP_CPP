/*************************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 25 July 2021
* Description: Understanding how debugging constructor destructor 
*
* Note: This is basic way of debuggin without debugger or testing tool
**************************************************************************************/
#include<iostream>
#include<vector>

using namespace std;
struct X
{
	int val;
	void out(const string& s, int nv)
	{
		cerr<<this <<"->"<<s <<": "<< val<<"("<< nv<<")\n";
	}
	
	X()						// default constructor
	{ 
		out("X()",0); 
		val=0; 
	}
				
	X(int v)					// parameterized constructor
	{
		val=v; out("X(int)",v);
	}
	
	X(const X& x)					 // copy constructor
	{
		val=x.val; out("X(X&)",x.val);
	} 
	
	X& operator=(const X& x)			  // copy assingment
	{
		out("X::operator=()",x.val);
		val=x.val;
		return *this;
	}
	
	~X()						// distructor
	{ 
		out("~X()",0); 
	}

};

//X glob(2); // a global variable

X copy(X a) {return a;}

X copy2(X a) 
{
	X aa=a;
	return aa;
}

X& ref_to(X& a) { return a;}

X* make(int i)
{
	X a(i); 
	return new X(a);
}


struct XX {X a; X b;};

int main()
{
	/*X loc {4};  // local variable
	X loc2 {loc}; // copy construction
	loc = X{5}; // copy assignment
	loc2 = copy(loc); // call by value and return
	loc2 = copy2(loc);
	X loc3 {6};*/
	//X& r = ref_to(loc); // call by reference and return
	delete make(7);
	delete make(8);
	//vector<X> v(4);  // default values
	
	XX loc4;		// structure XX of two X obj
	X* p = new X{9}; // an X on the free store
	delete p;
	//X* pp = new X[5]; // an array of Xs on the free store
	//delete[] pp;
		
	return 0;
}


