// Program to detect repeated words in sentence

#include"std_lib_facilities.h"

int main()
{	
	cout<<"\nPlease note in order to exit from program press Ctrl + C";
	cout<<"\nPlease input words: ";
	
	
	string previous=" ";
	string current;
	int word_number=0;
	int count=0; // count to store repeated words in sentence	
	while(cin>>current)
	{
		++word_number;
		if(current == previous)
		{
			cout<<" word number "<< word_number<<" and repeat word is  "<<current<<endl;
			count++;
		}
	previous = current;

	}
	
	return 0;
}
