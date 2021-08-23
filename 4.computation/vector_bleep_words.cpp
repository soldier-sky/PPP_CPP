// This program replaces word with BLEEP if it matches restricted word.
#include"std_lib_facilities.h"

int main()
{
	vector<string> words;   //list of input string
	string disliked="Kalyan";

	cout<<"Please enter list of strings (user ctrl+D to terminate input) :";
	
	for(string temp; cin>>temp; )
		words.push_back(temp);
	
	// find disliked words and replace them with BLEEP
	for(string x:words)
	{
		if(x==disliked)
			cout<<"BLEEP "<<endl;
		else
			cout<<x <<endl;	
	}
	return 0;
}
