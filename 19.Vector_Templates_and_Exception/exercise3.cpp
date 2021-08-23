/*********************************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 7 Aug 2021
* Description: 3. Write a template class Pair that can hold a pair of values of any type. 
*		Use this to implement a simple symbol table like the one we used in the calculator($7.8)
* Note: 
***********************************************************************************************/
#include<iostream>

using namespace std;

// Class template Pair to hold pair of any value types
template<typename T, typename P>
class Pair
{
public:
	Pair()=delete;
	Pair(T t, P v):type{t}, value{v}
	{}
	T get_type() const {return type;}
	P get_value() const {return value;}
private:
	T type;
	P value;
};

int main()
{
	Pair<int, char> p1(5,'a');
	Pair<string, char> p3("str type", 'x');
	
	cout<<"value and pairs for p1 "<<p1.get_type()<<" : "<<p1.get_value()<<endl;
	cout<<"value and pairs for p3 "<<p3.get_type()<<" : "<<p3.get_value()<<endl;

	return 0;
}
