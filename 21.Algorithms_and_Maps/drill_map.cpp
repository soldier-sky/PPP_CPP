/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 5 Sep 2021
* Description: Drill exercise to get familier with map
*
*
* Note: 
***********************************************************************************/
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<numeric>

using namespace std;

// overloaded cin operator
istream& operator>>(istream& is, map<string, int>& m)
{
	string str;
	int i;
	while(is>>str)
	{
		is>> i;
		m[str]=i;
	}
	return is;
}


int main()
{

	map<string, int> msi;
	
	msi["apple"]=240;
	msi["banana"]=50;
	msi["mango"]=100;
	msi["kiwi"]=100;
	msi["pineapple"]=50;
	msi["chickoo"]=80;
	msi["custurd"]=100;
	msi["papaya"]=30;
	
	msi.erase("kiwi");
	
	cout<<"Printing value of msi\n";
	
	for(auto val: msi)
		cout<<val.first<<" : " <<val.second<<'\n';
	
	cout<<" Inseart string int pair (ctrl+d to exit) : ";
	cin>> msi;
	
	cout<<"\n--------------------------------------------------\n";
	cout<<"Printing additional pairs of msi\n";
	for(auto val: msi)
		cout<<val.first<<" : " <<val.second<<'\n';
		
	int result=0;
	for(auto val: msi)
		result+=val.second;
	cout<<"\nSummation of msi: "<<result<<endl;
	
	
	cout<<"\n--------------------------------------------------\n";
	cout<<"Printing value of mis\n";
	map<int, string> mis;
	
	for(auto val: msi)     // adding value from msi to mis
		mis[val.second]=val.first;
		
	for(auto val: mis)
		cout<<val.first<<" : " <<val.second<<'\n';
	
	return 0;
}
