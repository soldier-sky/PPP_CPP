/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 31 Aug 2021
* Description: 21.6.5 Understanding how set work in C++
*
*
* Note: incomplete. need to sepend more time 
***********************************************************************************/
#include<iostream>
#include<set>

using namespace std;


// comparision  function opertor 
struct my_comp
{
	bool operator()(int a, int b) { return b>50; }
};

int main()
{

	set<int> si{10,30,30,50};
	si.insert(55);
	si.insert(85);
	
	for(auto i:si)
		cout<<i<<'\t';
	cout<<'\n';
	
	// using comparision function opertor
	set<int, my_comp> sic;
	sic.insert(88);
	sic.insert(55);
	sic.insert(58);
	sic.insert(53);
	sic.insert(40);
	
	for(auto i:sic)
		cout<<i<<'\t';
	cout<<'\n';
	
	return 0;
}
