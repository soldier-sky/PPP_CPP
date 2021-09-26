/**********************************************************************************
* Chapter Chapter 21. Algorithms and Mapsv
* Author: Sunil Kumar Yadav
* Date: 9 Sep 2021
* Description:  8. Take the word-frequency example from §21.6.1 and modify it to output its 
*    lines in order of frequency (rather than in lexicographical order). An example line would be 
*    3: C++ rather than C++: 3.
*
*
* Note: Using multimap for storing <int, string> pair as key(int) is unique in standar map
***********************************************************************************/
#include<map>
#include<iostream>
#include<string>

using namespace std;
int main()
{
	map<string, int> words;		// words is scripted by string(key) and int is value
	
	cout<<"Please enter string with repeated words. Use ctrl +D to terminate:";
	
	for(string s; cin>>s;)
		++words[s];
		
	cout<<"Result of word count (sorted lexicographically)\n";
	for(const auto& w:words)
		cout<<w.first<<" : "<<w.second<<endl;
	
	cout<<endl;
	
	//------------------------------------------------------------------------------------------------
	multimap<int, string> count_word;			// holds word fequency
	for(const auto& w:words)
		count_word.insert({w.second,w.first}); //mis[w.second]=w.first;
	
	cout<<"Result of word count (sorted frequency wise)\n";
	for(const auto& w:count_word)
		cout<<w.first<<" : "<<w.second<<endl;
		
	return 0;
}
