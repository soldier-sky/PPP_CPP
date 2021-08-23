#include "std_lib_facilities.h"
int main()
{
	try 
	{
//	<<your code here>>
//	string res ="seven"; 
//	vector<int> v(10); 
//	v[5] = 7;
 //      	cout << "Success!\n";
//bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
cout<<s.size();
	//keep_window_open();
	return 0;
	}
	catch (exception& e) 
	{
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
	}
	catch (...) 
	{
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
	}

	return 0;
}
