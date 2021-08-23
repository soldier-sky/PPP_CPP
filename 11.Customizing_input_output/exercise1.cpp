// This program reads content of one file as input and write to another file 
// with all character to lowercase

#include"../std_lib_facilities.h"

int main()
{
	string ifile, ofile;
	cout<<"Please enter input file name: ";
	cin>>ifile;

	ifstream isf{ifile};
	if(!isf)
		error("could not open file",ifile);

	cout<<"Please enter output file name: ";
	cin>> ofile;

	ofstream osf{ofile};
	if(!osf)
		error("could not open file",ofile);

	string word;
//	while(isf>>word)  // >> stream  will ignore whitespace and new line from stream
	while(getline(isf,word))    // to read	whitespace as well	
	{
		for(char& ch:word)   // using refernece to ch as we want to upadate word's char
		{
			if(isalpha(ch))
			{
				ch=tolower(ch);   // tolower returns lower case of ch
			}
		}

		osf<<word;
		osf<<'\n';  //adding new line since infile have lines
	}  

	return 0;

}





