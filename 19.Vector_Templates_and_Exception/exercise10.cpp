/**********************************************************************************
* Chapter 19. Vectors, templates and Exceptions
* Author: Sunil Kumar Yadav
* Date: 8 Aug 2021
* Description: 10. Implement a simple unique_ptr supporting only a constructor, destructor, –>, *, and release(). 
* 		In particular, don’t try to implement an assignment or a copy constructor
*
* Note: Incomplete
***********************************************************************************/
#include<iostream>

using namespace std;
// test unique_ptr for int

template<typename T>
class Unique_ptr
{
public:
	Unique_ptr(){}
	
	Unique_ptr(T* p):ptr{p}
	{}
	
	T* operator->();
	T& operator[](int idx){ return ptr[idx];}
	T& operator*(){return *ptr;}
	~Unique_ptr(){delete ptr;}
	
private:
	T* ptr=nullptr;
};

template<typename T>
T* Unique_ptr<T>::operator->()
{
	return ptr;
}

int main()
{
	Unique_ptr<int> ptr(new int[3]);
	int x;
	*ptr=100;
	ptr[2]=88;
	cout<<ptr[2]<<endl;
	cout<<*ptr;
	
	return 0;
}
