// Program to read string input and classify each charachter into num, alph, punctuation etc


#include"../std_lib_facilities.h"

int main()
{
	cout<<"Please input string for charachter classification: ";
	string str;
	getline(cin, str);

	for(char ch :str)
	{
	
			if(isalpha(ch))
				cout<<ch <<" is alphabet\n";
		 	else
			if( isxdigit(ch))
				cout<<ch <<"is hexadecimal\n";
			else
			if(isdigit(ch))
				cout<<ch <<" is digit\n";
			else	
			if(isspace(ch))
				cout<<ch <<" is whitespace\n";
			else
			if(ispunct(ch))
				cout<<ch <<" is alphabet\n";
	// Note need to add break etc to remove dubplication.		
	
	}
	return 0;
}



