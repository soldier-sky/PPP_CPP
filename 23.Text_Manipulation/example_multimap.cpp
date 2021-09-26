// sample code for usage of multimap
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	multimap<int , string> mis;

	mis.insert({1,"apple"});
	mis.insert({2, "orange"});
	mis.insert({1,"kiwi"});

	for(auto fruit: mis)
		cout<<fruit.first<<" : "<<fruit.second<<endl;
	cout<<endl;

	return 0;
}

