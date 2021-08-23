// Sample program to learn how we can end up accessing out of range index
// This time we will use try catch block to handle out of range/index error

#include "std_lib_facilities.h"

int main()
{
	try
	{
		vector<int> v;  // vector of ints

		cout<<"Please enter list of numbers: ";  // User ctrl+d to terminate loop
		for(int i; cin>> i;)
			v.push_back(i);    //get values

		for(int i=0; i<=v.size();++i)
			cout<<"v["<<i<<"]=="<<v[i]<<"\n";
	}
	catch(out_of_range)
	{
		cerr<<"Oops ! Range error \n";	
		return 1;
	}
	catch(...)		// catch all other exception
	{
		cerr<<"Exception: Something went wrong\n";
		return 2;
	}

	return 0;
}
