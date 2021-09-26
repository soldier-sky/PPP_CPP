/**********************************************************************************
* Chapter Chapter 22. Text Manipulation
* Author: Sunil Kumar Yadav
* Date: 20 Sep 2021
* Description:  1. Program to read email from text file and store it in 
* Message container for easy retrival of subject, sender etc
*
* Note: Not using regex for pattern matching
* does not work. Need to debug
***********************************************************************************/
#include<string>
#include<vector>
#include<map>
#include<fstream>
#include<iostream>
using namespace std;

typedef vector<string>::const_iterator Line_iter;

//--------------------------------------------------------------------------------------------
// a Message point to the first and last line of message
class Message
{
private:
	Line_iter first;
	Line_iter last;
public:
	Message(Line_iter p1, Line_iter p2): first{p1}, last{p2} {}
	Line_iter begin() const{ return first;}
	Line_iter end() const { return last;}
	
};

using Mess_iter= vector<Message>::const_iterator;

//--------------------------------------------------------------------------------------------

// a Mail_file holds all the lines from a file and simplifies access to messages
struct Mail_file         
{
	string name;			//file name
	vector<string> lines;		// the lines in order
	vector<Message> m;		// Messages in order
	
	Mail_file(const string& n);	// read file n into lines.
	Mess_iter begin() const{return m.begin();}
	Mess_iter end() const{return m.end();}
};

Mail_file::Mail_file(const string& n)
// open file named n and read lines from n into lines
// find the messages in the lines and compose them in m
// for simplicity we assume everyy message is ended by a ---- line
{
	name=n;
	ifstream in{name};
	if(!in) 
	{
		cerr<<" File not found\n";   
		exit(1);			// terminat the program
	}    
	
	for( string line;getline(in,line);)	// build the vector of lines
		lines.push_back(line);
		
	auto first=lines.begin();		// build the vector of messages
	
	for(auto p=lines.begin(); p!=lines.end(); ++p)
	{
		if(*p=="----")			// ---- denotes end of evey email message
		{
			m.push_back(Message(first, p));
			first=p+1;		// ---- not part of messages
		}
	}
	
	
}


//--------------------------------------------------------------------------------------------

int is_prefix(const string& s, const string& p)   
{ // is p the first part of s?
	int n=p.size();
	if(string(s,0,n)==p)          // string(s,0,n) will create string from s[0...n]
		return n;
	return 0;
}


// find the name of the sender in a Message;
// return true if found
// if found, place the sender's name in s:
bool find_from_addr(const Message* m, string& s)
{
	for(const auto& x:*m)
	{
		if(int n=is_prefix(x,"From: "))
		{
			s=string(x,n);	 //onstructs a string consisting of the tail 
					 //of s from s[n] onward (s[n]..s[s.size()–1]),
			return true;
		}
	}
	return false;
}

// retrun the subject of the Message, if any, otherwise "":
string find_subject(const Message* m)
{
	for (const auto& x:*m)
	{
		cout<<x<<endl;
		if(int n=is_prefix(x,"Subject: "))
			return string(x,n);
	}
	return "";
}


int main()
{
	Mail_file mfile{"email_sample.txt"};		// initialize mfile from a file
	
	// first gather messsages from each sender together in a multimap
	multimap<string, const Message*> sender;
		
	
	for(const auto& m: mfile)
	{
		string s;
		if(find_from_addr(&m,s))
			sender.insert(make_pair(s,&m));
	}
	
	// now iterate throguh multimap
	// and extract the subject of John Doe's messages:
	auto pp=sender.equal_range("John Doe <jdoe@machine.example>");
	for(auto p=pp.first;p!=pp.second; ++p)
		cout<<find_subject(p->second)<<'\n';
	
	return 0;
}



