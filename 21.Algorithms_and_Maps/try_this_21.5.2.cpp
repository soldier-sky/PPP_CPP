/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 28 Aug 2021
* Description:  Try this exercise from 20.5.2 to accumulate price of item where item is 
*	  a struct type
*
* Note:
***********************************************************************************/
#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

struct Record
{
	double unit_price;
	int units; 	// number of units sold
	Record(double up, int u): unit_price{up}, units{u}
	{}
	Record():unit_price{0}, units{0}   // defult used by vector of record call
	{}
};


// binary operator for Record type.
double price(double init, const Record& r)
{
	return init+ r.unit_price*r.units;    // calculate price and accumulate
}


int main()
{
	vector<Record> vec_r(4);
	Record r(100,10);
	// initialize values to vector of record
	for(int i=0; i<vec_r.size(); ++i)
		vec_r[i]=Record(10, i*2);
	
	
	double total_price=accumulate(vec_r.begin(), vec_r.end(), 0, price);
	cout<<"Total price for item "<<vec_r.size()<<" is "<<total_price<<endl;
	
	return 0;
}


