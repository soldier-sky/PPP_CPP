// Sample program to learn how we can end up accessing out of range index

#include "std_lib_facilities.h"

int main()
{
	vector<int> v;

	cout<<"Please enter list of numbers: ";  // User ctrl+d to terminate loop
	for(int i; cin>> i;)
		v.push_back(i);    //get values

	for(int i=0; i<=v.size();++i)
		cout<<"v["<<i<<"]=="<<v[i]<<"\n";


	return 0;
}
