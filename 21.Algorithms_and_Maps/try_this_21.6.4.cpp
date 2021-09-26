/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 31 Aug 2021
* Description: 21.6.4 Understanding how unordered_map aka hash_map work
*
*
* Note:
***********************************************************************************/
#include<map>
#include<unordered_map>
#include<iostream>
#include<string>
//#include<numeric>
//#include<functional>

using namespace std;



int main()
{
	// map containing stock symbol and stock price
	unordered_map<string, double> dow_price= {
		{"MMM", 81.86},
		{"AA", 34.69},
		{"MO", 54.45}
		};
		
	for(const auto& p:dow_price)
	{
		const string& symbol=p.first;
		cout<< symbol << '\t'<< p.second << '\n';	
	}
		
	return 0;
}
