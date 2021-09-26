/**********************************************************************************
* Chapter Chapter 21. Algorithms and Mapsv
* Author: Sunil Kumar Yadav
* Date: 30 Aug 2021
* Description:  Understading how map work in cpp. In this example we read string from 
*	console and store inside map and list how many times a word appear in input
*
* Note:
***********************************************************************************/
#include<map>
#include<iostream>
#include<string>


using namespace std;
int main()
{
	map<string, int> words;     // words is scripted by string(key) and int is value
	
	cout<<"Please enter string with repeated words. Use ctrl +D to terminate:";
	
	for(string s; cin>>s;)
		++words[s];
		
	// print final word count
	for(const auto& w:words)
		cout<<w.first<<" : "<<w.second<<endl;
	
	return 0;
}
