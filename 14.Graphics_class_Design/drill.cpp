// Drill to understand CPP language OOP concept

#include "../std_lib_facilities.h"

class B1
{
public:
	virtual void vf()
	{
	       	cout<<"B1::vf\n";
	}

	void f()
	{
		cout<<"B1::f\n";
	}

	virtual void pvf()=0;
};

class D1: public B1
{	
public:
	void vf()
	{
		cout<<"D1::vf\n";
	}

	void f()
	{
		cout<<"D1::f\n";
	}

	void pvf()
	{
		cout<<"D::pvf\n";
	}
};

int main()
{
//	B1 b1;
//	b1.vf();
//	b1.f();

	D1 d1;
	d1.vf();
	d1.f();
	d1.pvf();

	B1& b_ref=d1;
	//b_ref=d1;

	b_ref.vf();
	b_ref.f();
	b_ref.pvf();
	return 0;
}
