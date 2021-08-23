// This program is to learn about namespaces in c++

#include"../std_lib_facilities.h"

namespace X
{
	int var;
	void print(void); //print the value of var
};
void X::print(void)
{
	std::cout<<"x::var "<<var<<"\n";
}

namespace Y
{
	int var;
	void print(void)
	{
		std::cout<<"Y::var "<<var<<"\n";
	}
};


namespace Z
{
	int var;
	void print(void)
	{
		std::cout<<"Z::var "<<var<<"\n";
	}
};

int main()
{

	X::var=7;
	X::print();

	using namespace Y;
	var=9;
	print();            // print Y's var
	{
		using Z::var;
		using Z::print;

		var =11;
		print();    // print Z's var
	}
	print();	    // print Y's var
	X::print();         // print X's var

	return 0;
}
