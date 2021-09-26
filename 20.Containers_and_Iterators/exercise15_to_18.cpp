/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description:  15. Define a pvector to be like a vector of pointers except that it contains pointers to objects
*       and its destructor deletes each object.
*	16. Define an ovector that is like pvector except that the [ ] and * operators return a reference to the
*       object pointed to by an element rather than the pointer. 
*       17. Define an ownership_vector that hold pointers to objects like pvector but provides a mechanism for the
*       user to decide which objects are owned by the vector (i.e., which objects are deleted by the destructor).
*	 Hint: This exercise is simple if you were awake for Chapter 13.
*	18. Define a range-checked iterator for vector (a random-access iterator).
*
* Note: Incomplete
***********************************************************************************/
#include<iostream>
#include<vector>

using namespace std;

// shortcut: used std::vector to implement pvector
class pvector
{
public:
	pvector()=delete;
	pvector(int n)
	{
		for(int i=0; i<n;++i)
			p_elem.push_back(new int{0});
		sz=n;
		offset=0;
		
	}
	int* at(int i)
	{ 
	
		return p_elem[i];
	}
	
	~pvector()
	{
		//cout<<"~pvector()\n";
	}
	
private:
	vector<int*> p_elem;
	int sz;
	int offset;

};


class ovector
{
public:
	ovector()=delete;
	ovector(int n)
	{
		for(int i=0; i<n;++i)
			p_elem.push_back(new int{0});
		sz=n;
		offset=0;
		
	}
	int& at(int i)
	{ 
	
		return *p_elem[i];
	}
	
	int& operator[](int i)
	{
		return *p_elem[i];
	}
	
	~ovector()
	{
		//cout<<"~ovector()\n";
		// since used vector<> directory, no need to implecitly release pointer
	}
	
private:
	vector<int*> p_elem;
	int sz;
	int offset;

};

int main()
{
	pvector pptr(5);
			
	for(int i=0; i<4; ++i)
		*pptr.at(i)=i*i;
	
	cout<<"Printing values of pvector\n";	
	for(int i=0; i<4; ++i)
		cout<<*pptr.at(i)<<'\t';
	cout<<'\n';			
	//---------------------------------------------------------------------------
	ovector optr(5);
		
	for(int i=0; i<4; ++i)
		optr[i]=i*i*i;
		
	cout<<"Printing values of ovector\n";		
	for(int i=0; i<4; ++i)
		cout<<optr.at(i)<<'\t';
	cout<<'\n';
	return 0;
}



