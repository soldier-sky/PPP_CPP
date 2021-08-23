/**********************************************************************************
* Chapter 19. Vectors, templates and Exceptions
* Author: Sunil Kumar Yadav
* Date: 7 Aug 2021
* Description: 8.implementing Vector class
*		similar to STL vector and adding 
* Note: Incomplete. Need to implement allocator and expection handling as required by
*	exercise 9.
***********************************************************************************/
#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;

/*
template<typename T> 
class allocator
{
public:
	T* allocate(int n);		// allocate space for n objects of type T
	void deallocate(T* p, int n);	// deallocate n objects of type T starting at P
	
	void construct(T* p, const T& v);	// construct a T with the value v in p
	void destroy(T* p);			// destroy the T in p 
}
*/

//-------------------------------------------------------------------------------------------------------------
// almost real vector of Ts: Does not support complex types
template<typename T>
class Vector
{
private:
	int sz;		// the size
	T* elem;		// a pointer to elements
	int space;		// size + free space
public:
	Vector():sz{0},elem{nullptr}, space{0}                // default constructor
	{}
	
	explicit Vector(int s):sz{s},elem{new T[s]}, space{0}        // single parameter constructor
	{
		for(int i=0; i<sz; ++i) 
			elem[i]=0;		// elements are initialzed
	}
	
	Vector(const initializer_list<T> lst)
	{
		sz=lst.size();
		elem= new T[sz];
		space=0;
		std::copy(lst.begin(), lst.end(), elem);
		cout<<"inside initilizer list ctor\n";
	}
	
	Vector(const Vector& v);			 // copy constructor      	
	Vector& operator=(Vector& v);              	// copy assignment
	
	Vector(Vector&& v);              		// move constructor
	Vector& operator=(Vector&& v);              	// copy assignment
		
	~Vector() { delete[] elem; }			// destructor
	
	T& operator[](int idx) {return elem[idx];}
	const T operator[](int idx) const{return elem[idx];}  // to be used as read only for const copy ctor

	
	int size() const{ return sz;}
	int capacity() const {return space;}
	
	void resize(int newsize);	// growth
	void push_back(const T& d);
	void reserve(int newalloc); //{/*need to implement*/}
	
	T& at(int idx);		// range check

};


template<typename T>
void Vector<T>::reserve(int newalloc)
{/*need to implement*/
	if(newalloc <= space) return;		// never decrease allocation
	T* p =new T[newalloc];			// allocate new space
	for(int i=0; i<sz;++i) p[i]= elem[i];  // copy old elements
	delete[] elem;
	elem=p;
	space=newalloc;
}

template<typename T>
void Vector<T>::push_back(const T& val)
{
	if(space==0) 
		reserve(8);		// start with space for 8 elements
	else if(sz==space) 
		reserve(2*space);	// get more space
	//alloc.construct(&elem[sz],val)	// add val at the end
	elem[sz]=val;				// currently assigning directly
	++sz;					// increase the size
	
}

template<typename T>
T& Vector<T>::at(int idx)
{
	if(idx<0 || idx >=sz) 
	{
		cerr<<"\ninvalid index\n";  	// ideally throw exception
	}

	return elem[idx];
		
}

// copy constructor
template<typename T>
Vector<T>::Vector(const Vector& v)
		:sz{v.sz}, elem{new T[v.sz]}, space{v.space}  // copy constructor
{
	std::copy(v.elem, v.elem+sz, elem);
	cout<<"Copy ctor called\n";
}
	  
// copy assignment
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>& v)
{
	sz=v.sz;
	T *p=new T[sz];
	
	delete[] elem;                     // deallocate older content
	std::copy(v.elem,v.elem+sz, p);  // make copy of v's elem into pointer p
	elem=p;                            // assign pointer to elem
	//cout<<"Inside copy assignment\n";
	return *this;
}

// move constructor
template<typename T>	
Vector<T>::Vector(Vector<T>&& v)
	:sz{v.sz}, elem{v.elem}
{
	v.sz=0;
	v.elem=nullptr;
	//cout<<"Inside move ctor\n";
}

// move assignment
template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v)
{
	delete[] elem;        		// deallocate older space
	elem=v.elem;
	sz=v.sz;
	v.elem=nullptr;		// make r value elem null 
	v.sz=0;
	//cout<<"Inside move assignment\n";
	return *this;
}  


//-------------------------------------------------------------------------------------------------------------

int main()
{
	Vector<int> v(10);
	
	cout<<v.at(5)<<" "<< v.size()<<endl;
	
	for(int i=0; i<v.size();++i)
		v.at(i)= i*10;   // assigning values to vector v
		
	v[5]=66666;
	cout<<v[5]<<endl;
	
	Vector<int> v3;
	v3= v;
	Vector<int> v4(v3);
	
	for(int i=0; i<v3.size();++i)
	{
		cout<<"Value at index "<< i<< " of V3 is " << v[i]<<endl;
	}
	
	Vector<int> v5(10);
	//foo(Vector(5));
	Vector<int> V6{1,2,3,4,5,6,7};
	
	cout<<"------------------------------------\n";
	
	Vector<double> vec_d{1,3.4, 5, 6.9};
	
	cout<<"Vector size : "<<vec_d.size()<< " capacity: "<<vec_d.capacity() << endl;
	vec_d.push_back(888.999);
	vec_d.push_back(888.999);
	cout<<"after pushback \n";
	cout<<"Vector size : "<<vec_d.size()<< " capacity: "<<vec_d.capacity() << endl;
	
	for(int i=0; i<vec_d.size(); ++i)
		cout<<vec_d[i]<<"\t";
	cout<<endl;
	
	return 0;
}
