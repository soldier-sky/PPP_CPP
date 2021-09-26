/**********************************************************************************
* Chapter Chapter 22. Text Manipulation
* Author: Sunil Kumar Yadav
* Date: 23 Sep 2021
* Description:  Understanding how regex work. In this example we will read students 
*	assignment marks from table_input.txt and then calculates sum of each students
*	assignment and match it with results of input table data
*
* Note: regex_search() finds substring with matching pattern where as regex_match() 
*	matches full string
***********************************************************************************/
#include<regex>
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

//------------------------------------------------------------------------------------------
struct bad_from_string:std::bad_cast    // class to report bad string cast
{
	const char* what() const noexcept override
	{
		return "bad cast from string";
	}
};

// helper function to convert string to int/double etc
template<typename T>
T from_string(const string& input)
{
	istringstream is{input};
	T result;
	
	if(!(is>>result)) throw bad_from_string{};
	
	return result;
}
//------------------------------------------------------------------------------------------

int main()
{
	ifstream in{"table_input.txt"};     // input file
	if(!in) cerr<<"No input file\n";
	
	string line;			// input buffer
	int lineno=0;
	
	regex header{R"(^[\w]+(	[\w]+)*$)"};  
	regex row{R"(^[\w]+(	\d+)(	\d+)(	\d+)$)"}; 
	
	if(getline(in,line))		// read header
	{
		smatch matches;
		if(!regex_match(line,matches,header))
			cerr<<"Bad line "<<lineno;
	}
	
	vector<string> names;         // holds list of stuent names
	int sub_total1=0, sub_total2=0, sub_total3=0;
	while(getline(in,line))
	{
		++lineno;
		smatch matches;
		if(!regex_match(line,matches,row))
			cerr<<"Bad line "<<lineno;
			
		names.push_back(matches[0]);
		//cout<<matches[1]<<'\t'<<matches[2]<<'\t'<<matches[3]<<endl;
		int sub1=from_string<int>(matches[1]);
		int sub2=from_string<int>(matches[2]);
		int sub3=from_string<int>(matches[3]);
		
		if(matches[1]=="Total")	// last line
		{
			if(sub1!=sub_total1) cerr<<"Total for sub1 does not add up\n";
			if(sub2!=sub_total2) cerr<<"Total for sub2 does not add up\n";
			if(sub3!=sub_total3) cerr<<"Total for sub3 does not add up\n";
		}
		sub_total1+=sub1;
		sub_total2+=sub2;
		sub_total3+=sub3;
	}

	return 0;
}

