// This program reads line input(multiple strings in user input)
// from input replacing puntuation etc

#include"../std_lib_facilities.h"

int main()
{

	string line;
	cout<<"Please enter a statement: ";
	getline(cin, line);   // read into line
	for(char& ch: line)   // replace each puntuation character from string with space
		switch(ch)
		{
			case ';': case'.': case':': case '?': case '!':
				ch=' ';
		}

	stringstream ss(line);  // make an istream ss reading from line
	vector<string> vs;

	for(string word; ss>>word;)  // read words withoug puntuation character
	{
		vs.push_back(word);
	        cout<<word <<'\n';
	}
	return 0;
}
