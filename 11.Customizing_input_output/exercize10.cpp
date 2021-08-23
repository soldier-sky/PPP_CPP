// Program to split string containing whitespace into vector of word

#include"../std_lib_facilities.h"

vector<string> split(const string& s)
{
	vector<string> words;
	string word="";

	int sp=0,ep=0;   //to hold starting and end position of word in string

	for(int i=0; i<s.length() ;++i)
	{
		if(!isspace(s[i]))
		{
			word+=s[i];
		}
		else
		{
			if(word.length()>0)            // if word contain somthing
				words.push_back(word); // push word into vector of words
			word="";
		}
	}

	return words;
}

int main()
{
	cout<<" This program spilts the strings into words";

	string str="this is sample string for current example";

	cout<<"Input string s: "<<str <<'\n';

	vector<string> words;  

	words=split(str);

	// print list of words
	for(string s:words)
		cout<<s<<'\n';



	return 0;
}
