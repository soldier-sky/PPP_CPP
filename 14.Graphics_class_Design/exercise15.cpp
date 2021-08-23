/*************************************************
* Exercise 15 Chapter 14.Graphics Class Design
* Author: Sunil Kumar Yadav
* Date: 19 June 2021
* Problem:  Define a class Iterator with a pure virtual function next() that returns a double* 
* (see Chapter 17). Now derive Vector_iterator and List_iterator from Iterator so that next() for
* a Vector_iterator yields a pointer to the next element of a vector<double> and List_iterator does
* the same for a list<double>. You initialize a Vector_iterator with a vector<double> and the first
*  call of next() yields a pointer to its first element, if any. If there is no next element, return 0.
*   Test this by using a function void print(Iterator&) to print the elements of a vector<double> and a list<double>.
*
**************************************************/

#include"../std_lib_facilities.h"

class Base_iterator
{     
// base class

public:
	Base_iterator(){}
	virtual double* next()=0; 
};

class Vector_iterator: public Base_iterator
{
public:
	Vector_iterator()=default;
	Vector_iterator(vector<double>vv):v{vv}
	{	
		size=v.size();
		count=0;   //pointing at start of vector
	}
	double* next()
	{
		if(size>0 && count<size)
		{
			count++;
			return &v[count-1];
			
		}
		else
			return 0;
	}
	
private:
	vector<double> v;
	int count=0;
	int size=0;
};


class List_iterator: public Base_iterator
{
public:
	List_iterator(list<double> ll):l{ll}
	{	
		size=l.size();
		it=l.begin();    // assigning iterator to start of list
	}
	
	double* next()
	{
		
		if(size>0 && it!=l.end())
		{
			return &(*it++);    // iterator it returns pointer to element 
					    // which we derefernce using * and then returning addesss 
					    //of that value to comply with next()
			
		}
		else
			return 0;
		
	}

private:
	list<double> l;
	int size=0;
	list<double>::iterator it; 
};

void print(Base_iterator &It)
{
	cout<<"Printing values of iterator\n";
	double* dptr;
	dptr=It.next();
	while(dptr!=nullptr)
	{
		cout<< *dptr <<endl;
		dptr=It.next();
	}
	
}


int main()
{
	vector<double> v;
	
	v.push_back(1.0);
	v.push_back(2.0);
	v.push_back(3.0);
	v.push_back(4.0);
	int vs=v.size();
	
	Vector_iterator vi(v);
	
	/* activating below code will set iterator to null pointer which will cause 'print(vi)' to print nothing
	for(int i=0;i<vs;++i)
		cout<<"calling Vector_iterator::next()"<<*vi.next()<<endl;
	*/
	
	list<double> l;
	l.push_back(1.0);
	l.push_back(2.0);
	l.push_back(3.0);
	l.push_back(4.0);
	
	int ls=l.size();
	List_iterator li(l);
	
	print(vi);
	print(li);
	return 0;
}
