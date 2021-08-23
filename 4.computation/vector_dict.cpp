// Simple dictionary: list of sorted words
#include"std_lib_facilities.h"

int main()
{
	vector<string> words;

	cout<<"Please enter list of word(use Ctrl + D once done with list): ";
	for(string temp; cin>>temp;)      // read whitespace seperator
		words.push_back(temp);    // put into vector

	cout<<"Number of words:"<<words.size()<<"\n";

	sort(words);                     // sort the words

	// Removing duplicate words
	for(int i=0;i<words.size();++i)
		if(i==0 || words[i-1] != words[i])   //if thei is a new word?
			cout<<words[i]<<endl;

	return 0;
}
