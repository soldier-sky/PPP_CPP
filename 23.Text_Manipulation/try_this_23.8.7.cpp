/**********************************************************************************
* Chapter Chapter 22. Text Manipulation
* Author: Sunil Kumar Yadav
* Date: 22 Sep 2021
* Description:  Understanding how regex work. In this example we ask for user input for 
*	regex patter and string via terminal.
*
* Note: if regex pattern is invalid it will throw bad_expression 
***********************************************************************************/
#include<regex>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>


using namespace std;


int main()
{

	regex pattern;
	
	string pat;
	cout<<"Please enter pattern: ";
	getline(cin,pat);	// read pattern
	
	try
	{
		pattern=pat;	//this checks pat
		cout<<"Pattern: "<<pat<<endl;
	}
	//catch(bad_expression)
	catch(std::regex_error& e)
	{
		cout<<pat<<" is not a valid regular expression\n";
		cerr<<e.what();
		exit(1);
	}
	
	cout<<"Please enter lines: \n";
	int lineno=0;
	
	for(string line; getline(cin,line);)
	{
		++lineno;
		smatch matches;
		
		if(regex_search(line, matches, pattern))
		{
			cout<<"Line "<<lineno<<line<<endl;
			for(int i=0; i<matches.size();++i)
				cout<<" \tmatches["<<i<<"]"<<matches[i]<<endl;
		}
		else
			cout<<"didn't match\n";
	}
	
	return 0;
}



