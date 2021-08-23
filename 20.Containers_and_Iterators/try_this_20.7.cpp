/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 12 Aug 2021
* Description: What does that list of differences mean in real code? For each array of char,
*   vector<char>, list<char>, and string, define one with the value "Hello", pass it to a function as
*   an argument, write out the number of characters in the string passed, try to compare it to "Hello"
*   in that function (to see if you really did pass "Hello"), and compare the argument to "Howdy" to
*   see which would come first in a dictionary. Copy the argument into another variable of the same type.
*
*
* Note: Not clear on requirments. Performance and size would differ but other factors are
*	will decide use of data structur. 
***********************************************************************************/
#include<iostream>
#include<list>
#include<vector>

using namespace std;

template<typename T>
void foo(T param)
{
	cout<<"size of param: "<< param.size()<<endl;
	
	for(auto itr=param.begin(); itr!=param.end();++itr)
		cout<<*itr<<"\t";
	cout<<endl;
}

int main()
{
	char ca[6] {'H','e','l','l','o','\n'};
	vector<char> cv{'H','e','l','l','o'};
	list<char> cl{'H','e','l','l','o'};
	string s{"Hello"}; 


	foo(cv);
	foo(cl);
	foo(s);
	return 0;
}
