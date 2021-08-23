/********************************************
* Author: Sunil Kumar Yadav
* Date: 23 June 2021
* Note: class definition Drill from chapter 15. Graphing Functions and Data
*       Not implemented sub exercise 7,8,9
*
*
*
***********************************************/
#include"../std_lib_facilities.h"

struct Person
{
private:
	string _name;
	int _age;
public:
	Person():_name{""}, _age{0} {}
	Person(string s, int a): _name{s}, _age{a} {}
	string name() const { return _name;}
	int age() const { return _age;}
	
};

istream& operator>>(istream& is, Person& p)
{	string n{};
	int a{};
	
	is>>n>>a;
	p=Person{n,a};
	
	return is;
	
}

ostream& operator<<(ostream& os, Person& p)
{
	os<<"("<<p.name()<<','<< p.age()<<")";
	return os;
	
}

int main()
{
	Person p{"Googy",63};

	cout<<"printing person details ("<<p.name() <<','<<p.age()<<")\n";
	
	cout<<"Please enter person name and age ";
	Person p2;
	cin>> p2;
	
	cout<<"Printing details of Person 2 is"<<p2<<endl;
	
	return 0;
}
