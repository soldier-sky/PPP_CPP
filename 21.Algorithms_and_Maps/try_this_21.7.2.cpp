/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 7 Sep 2021
* Description: 21.7.2 Understanding how stream iterots work
*
*
* Note: input file name is input.txt
***********************************************************************************/
#include<iostream>
#include<fstream>          // for ifstream and ofstream
#include<string>
#include<algorithm>	    // for sort() and copy()
#include<iterator>	    // for istream_iterator and ostream_iterator
#include<vector>

using namespace std;

int main()
{
	
	string from, to;
	
	cout<<"insert input and output file names: ";
	cin >> from >> to;                        // get source and target file names. input file contain words
	
	ifstream ifs{from};                       //open input stream
	ofstream ofs{to};	                   // open output stream
	
	istream_iterator<string> ii{ifs};         // make input iterator for stream
	istream_iterator<string> eos;	           // input sentinel 
	ostream_iterator<string> oo{ofs,"\n"};    // make output iterator for stream
	
	vector<string> b{ii, eos};		   // b is a ector initialized from input
	
	sort(b.begin(), b.end());		   // sort the buffer
	copy(b.begin(), b.end(), oo);		   // copy buffer to output
	
	/*
	ostream_iterator<string> oo{cout};
	*oo="Hello, ";
	++oo;
	*oo= "world!\n";
	*/
	return 0;
}
