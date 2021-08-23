// This example open file for IO operation and use seekg(get) and seekp(put)
// to modify the content.

#include"../std_lib_facilities.h"

int main()
{

	string fname;
	cout<<"Please enter file name: ";
	cin>> fname;
	fstream fs{fname};  // opening file for IO operation
	if(!fs)
		error("Could not open file");

	fs.seekg(22);     //move reading position (g for get) to 22 i.e. 23rd position
	char ch;
	fs>>ch;           // read 22 postion content

	cout<<"Charachter[22] is "<< ch << " (int) " <<ch <<'\n';

	fs.seekp(3);     // move writing position to 3 or 4th position
	fs<<'Y';


	return 0;
}
