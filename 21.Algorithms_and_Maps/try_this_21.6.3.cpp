/**********************************************************************************
* Chapter 21. Algorithms and Maps
* Author: Sunil Kumar Yadav
* Date: 31 Aug 2021
* Description: Calculating Dow index for sample companies and share price
*
*
*
* Note:
***********************************************************************************/
#include<map>
#include<iostream>
#include<string>
#include<numeric>
#include<functional>

using namespace std;


// helper function required for extracting map values in inner_product() 
// params are pari<> since map<> uses them internally
double weighted_value(const pair<string, double>& a, const pair<string, double>& b)
{
	return a.second * b.second;
}

int main()
{
	// map containing stock symbol and stock price
	map<string, double> dow_price= {
		{"MMM", 81.86},
		{"AA", 34.69},
		{"MO", 54.45}
		};
	// map containing % weight in dow index
	map<string, double> dow_weight= {
		{"MMM", 5.8549},
		{"AA", 2.4808},
		{"MO", 3.8940}
		};
		
	double dji_index= inner_product(dow_price.begin(), dow_price.end(),     // compinies 3 in this case
				dow_weight.begin(),				   // compnies weight
				0.0,						   // initial value
				plus<double>(),				   // add binary operator(<functional>)
				weighted_value);				   // extract values and weights
										   // and multiply

	cout<< "value of dow index with 3 stocks is "<<dji_index<<endl;
	
	return 0;
}
