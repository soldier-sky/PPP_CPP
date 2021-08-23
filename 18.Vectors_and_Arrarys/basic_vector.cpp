/****************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 24 July 2021
* Description: implementing Vector class
*		similar to STL vector and adding 1. copy ctor and copy assignment
*		and 2. move ctor and move assingment
*
*******************************************/
#include<iostream>
#include<initializer_list>
using namespace std;

class Vector
{
public:
	Vector():size{0},elem{nullptr}                // default constructor
	{}
	
	Vector(int s):size{s},elem{new int[s]}        // single parameter constructor
	{
		for(int i=0; i<s; ++i)
			elem[i]=0;
	}
	
	Vector(const initializer_list<int> lst)
	{
		size=lst.size();
		elem= new int[size];
		std::copy(lst.begin(), lst.end(), elem);
		cout<<"inside initilizer list ctor\n";
	}
	
	Vector(const Vector& v);              	// copy constructor
	Vector& operator=(Vector& v);              	// copy constructor
	
	Vector(Vector&& v);              		// move constructor
	Vector& operator=(Vector&& v);              	// copy constructor
		
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
	
	int& operator[](int idx) {return elem[idx];}
	int operator[](int idx) const{return elem[idx];}  // to be used as read only for const copy ctor
private:
	int size;
	int* elem;

};

Vector::Vector(const Vector& v)
	:size{v.size}, elem{new int[v.size]}
{
	std::copy(v.elem, v.elem+size, elem);
	cout<<"Copy ctor called\n";
}

Vector& Vector::operator=(Vector& v)
{
	size=v.size;
	int *p=new int[size];
	
	delete[] elem;                     // deallocate older content
	std::copy(v.elem,v.elem+size, p);  // make copy of v's elem into pointer p
	elem=p;                            // assign pointer to elem
	cout<<"Inside copy assignment\n";
	return *this;
}
	
Vector::Vector(Vector&& v)
	:size{v.size}, elem{v.elem}
{
	v.size=0;
	v.elem=nullptr;
	cout<<"Inside move ctor\n";
}

Vector& Vector::operator=(Vector&& v)
{
	delete[] elem;        		// deallocate older space
	elem=v.elem;
	size=v.size;
	v.elem=nullptr;		// make r value elem null 
	v.size=0;
	cout<<"Inside move assignment\n";
	return *this;
}  

void foo(Vector&& v)
{
	cout<<v.at(0)<<'\n';
}

int main()
{
	Vector v(10);
	cout<<v.at(5)<<" "<< v.get_size()<<endl;
	
	for(int i=0; i<v.get_size();++i)
		v.set(i, i*10);   // assigning values to vector v
		
	v[5]=66666;
	cout<<v[5]<<endl;
	
	Vector v3;
	v3= v;
	Vector v4(v3);
	for(int i=0; i<v3.get_size();++i)
	{
		cout<<"Value at index "<< i<< " of V3 is " << v[i]<<endl;
	}
	
	Vector v5(10);
	foo(Vector(5));
	Vector V6{1,2,3,4,5,6,7};
	return 0;
}
