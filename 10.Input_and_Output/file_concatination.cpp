// Exercise 8
// this program takes two file name as input and concatinate the content
// into another output file.

#include"../std_lib_facilities.h"

int main()
{
	string infile1, infile2, outfile;
	string data1,data2;
	cout<<"Please enter 2 file names whom you wish to concatinate: ";
	cin>>infile1>>infile2;

	cout<<"Please enter output file name: ";
	cin>>outfile;

	ifstream ifs1{infile1}, ifs2{infile2};

	if(!ifs1 || !ifs2)
		error("Could not open input file");

	ofstream ofs{outfile};
	if(!ofs)
		error("Could not open output file");

	//ofs<<ifs1;//>>ofs;
	//ifs2>>ofs;
	//ifs1>>data1;   // This will only read one string at at time
	//cout<<data1;

	string line;
	while(std::getline(ifs1,line))
	{
		ofs<<line<<'\n';
	}

	while(std::getline(ifs2,line))
	{
		ofs<<line<<'\n';
	}

	return 0;
}




