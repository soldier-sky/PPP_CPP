/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description:  6. Write a find-and-replace operation for Documents based on §20.6.2
* 
* Note: Incomplete and partially implemented search and replace
***********************************************************************************/
#include<iostream>
#include<vector>
#include<list>

using namespace std;

//----------------------------------------------------------------------------------------------------------
using Line = vector<char>;      // a line is a vector of characters

class Text_iterator      // keep track of line and character position within a line
{
	list<Line>::iterator ln;
	Line::iterator pos;
public:
	// start the iterator at line ll's character position pp
	Text_iterator(list<Line>::iterator ll, Line::iterator pp)
		:ln{ll}, pos{pp} {}
		
	char& operator*() {return *pos;}
	Text_iterator& operator++();
	
	bool operator==(const Text_iterator& other) const
		{ return ln==other.ln && pos== other.pos; }	
	bool operator!=(const Text_iterator& other) const
		{ return !(*this == other); }
};

Text_iterator& Text_iterator::operator++()
{
	++pos;					// proceed to next character
	
	if(pos==(*ln).end()) 
	{	
		ln++;				// proceed to next line
		pos=(*ln).begin();		// bad if ln==line.end(); make sure it isn't
	}
	return *this;
}

//----------------------------------------------------------------------------------------------------------

struct Document
{
	list<Line> line;
	
	Document()	                   // Default constructor to create non empty line 
	{				    // since >> operator on Document with empty list is undefined behaviour
		line.push_back(Line(1));   // Added Line to avoid runtime issue
	}
	
	Text_iterator begin()		// first character of first line
		{ return Text_iterator(line.begin(), (*line.begin()).begin()); }
	Text_iterator end()
	{
		auto last=line.end();
		--last;		// we know that the document is not empty
		return Text_iterator(last, (*last).end());
	}	
};

//----------------------------------------------------------------------------------------------------------

istream& operator>>(istream& is, Document& d)
{
	for(char ch; is.get(ch);)
	{
		//cout<<"char: "<<ch<<endl;
		d.line.back().push_back(ch);		// add the charachter: Added default constructor with non empty line
		if(ch=='\n')
			d.line.push_back(Line{}); 	// add another line
	}
	
	if(d.line.back().size())
		d.line.push_back(Line{});		// add final empty line
	return is;
}

// need to debug error
void print(Document& d)
{
	for(auto p:d) cout<<p;            // originally *p supposed to return *Text_iterator::pos
}

template<typename Iter>  	// requires Forward_terator<Iter>
void advance(Iter& p, int n)
{
	while(0<n) { ++p; --n; }
}

void erase_line(Document& d, int n)
{
	if(n<0 || d.line.size() -1 <= n)
		return;
	
	auto p=d.line.begin();
		advance(p,n);
	d.line.erase(p);
}

// finds and replaces first occurance of character c
// need to expand for string
void find_and_replace(Document& d, char pattern, char replacement)
{
	if(d.line.empty()) return;   
	
	for(auto& p:d)
	{
		if(p==pattern)
		{ 	
			p=replacement;
			return;
		}
			
	}	
}

//----------------------------------------------------------------------------------------------------------
int main()
{
	Document my_doc;
	cout<<"Enter text into document (Ctrl+D to terminate input):";
	cin>>my_doc;
	cout<<"Entered text is: \n";
	print(my_doc);
	
	find_and_replace(my_doc, 'S', 'X');
	cout<<"\nAfter running find and replace on text: \n";
	print(my_doc);
	
	return 0;
}
