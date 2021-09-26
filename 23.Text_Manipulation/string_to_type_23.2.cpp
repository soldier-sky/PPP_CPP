/**********************************************************************************
* Chapter Chapter 22. Text Manipulation
* Author: Sunil Kumar Yadav
* Date: 17 Sep 2021
* Description:  Understanding how to use string stream to convert type T to string and 
*		vice versa.
*
*
* Note: 
***********************************************************************************/
#include<iostream>
#include<sstream>          // stringstream
#include<string>

using namespace std;

//------------------------------------------------------------------------------------------
template<typename T>
string to_string(const T& input)
{
	ostringstream os;
	os<<input;
	return os.str();
}

//------------------------------------------------------------------------------------------
struct bad_from_string:std::bad_cast    // class to report bad string cast
{
	const char* what() const noexcept override
	{
		return "bad cast from string";
	}
};


template<typename T>
T from_string(const string& input)
{
	istringstream is{input};
	T result;
	
	if(!(is>>result)) throw bad_from_string{};
	
	return result;
}
//------------------------------------------------------------------------------------------
template<typename Target, typename Source>
Target to(Source arg)
{
	stringstream interpreter;
	Target result;
	
	if(!(interpreter<<arg) 			// write arg into stream
		|| !(interpreter>>result) 		// read result from stream
		|| !(interpreter>>std::ws).eof())	// stuff left in stream?
		throw runtime_error{"to<>()failed"};
		
	return result;
}

//------------------------------------------------------------------------------------------
int main()
{
	string str=to_string<double>(50.0*3);
	cout<<str<<endl;
	
	string s="87.44";
	try
	{
	double d=from_string<double>(s);
	cout<<d<<endl;
	
	int res=to<int>("88");
	cout<<res<<endl;
	}
	catch(bad_from_string e)
	{
		cerr<<"bad inpu string",s; 
	}
	
	return 0;
}
