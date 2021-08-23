/****************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 15 July 2021
* Description: implementing Vector class
*		similar to STL vector
*
*******************************************/
#include<iostream>
using namespace std;

class Vector
{
public:
	Vector():size{0},elem{nullptr}
	{}
	
	Vector(int s):size{s},elem{new int[s]}
	{
		for(int i=0; i<s; ++i)
			elem[i]=0;
	}

	
	~Vector() { delete[] elem; }
	
	int get_size(){ return size;}
	int at(int idx)
	{
		if(idx > size-1) 
		{
			cerr<<"\ninvalid index\n";
			return -1;
		}
		else
			return elem[idx];
		
	}
	
	void set(int idx, int val)
	{
		if(idx > size-1) 
		{
			cerr<<"invalid index";
			return;
		}
		else
			elem[idx]=val;
	}
	int operator[](int idx)
	{	
		return elem[idx];
	}

private:
	int size;
	int* elem;

};

int main()
{
	Vector v(10);
	cout<<v.at(5)<<" "<< v.get_size()<<endl;
	
	for(int i=0; i<v.get_size();++i)
		v.set(i, i*10);   // assigning values to vector v
		
	
	for(int i=0; i<v.get_size();++i)
	{
		cout<<"Value at index "<< i<< " " << v[i]<<endl;
	}
	return 0;
}
