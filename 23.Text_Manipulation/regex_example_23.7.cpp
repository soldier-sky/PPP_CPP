/**********************************************************************************
* Chapter Chapter 22. Text Manipulation
* Author: Sunil Kumar Yadav
* Date: 20 Sep 2021
* Description:  Understanding how regex work. In this example we are reading US postal
*	codes from file and printing line no. and pin code which we found.
*
* Note: Postal code can either be of form 1. TX77845–1234 or 2. TX77845
* matches[i].matched returns false if sub match is not found. in such case maches[i] contains
* empty string.
***********************************************************************************/
#include<iostream>
#include<regex>
#include<string>
#include<fstream> 

using namespace std;

int main()
{
	ifstream in{"postal_code.txt"};                              // input file
	
	if(!in)
		cerr<<"No file found with name postal_code.txt\n";
	
	regex pat{R"(\w{2}\s*\d{5}(-d{4})?)"};                         // postale patter
	
	int lineno=0;
	for(string line; getline(in,line);)                              // read input line into input buffer
	{
		++lineno;
		smatch matches;	                                   // matched strings go here
		if(regex_search(line,matches,pat))
			cout<<lineno<<": "<<matches[0]<<'\n';             //matches[1].. contain sub match 
									    //i.e. (-d{4})? regex
		if(1<matches.size() && matches[1].matched)
			cout<<"\t:"<<matches[1]<< '\n';                   // sub match
		
	}


	return 0;
}



