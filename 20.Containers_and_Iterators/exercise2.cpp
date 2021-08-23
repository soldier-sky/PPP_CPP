/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 15 Aug 2021
* Description:  2. Completing 20.1.2 section's example. 
*              Using mock function to directly test data read from file
* Note: high() does not work correctly if values contained in sequence is negative(if use 20.1.2)
*       hence removed double h=-1; logic 
***********************************************************************************/
#include<iostream>
#include<vector>
#include<cstdlib> // for random no. generator
//#include<ctime>   // for seed value to random no. generator

using namespace std;


double* high(double* first, double* last);// return a pointer to the element in [first, last) that has highest value
double* get_from_jack(int count);        // jack puts doubles into an array and returns the number of element in count
vector<double>* get_from_jill();          // jill fills the vector
int random_no_generator(int max_range);
				   
//-------------------------------------------------------------------------------------
int main()
{
	int count=10;
	double* jack_data=get_from_jack(count);       // get 10 double data in double pointer from jack
	vector<double>* jill_data=get_from_jill(); 	// get 10 double data in pointer to vector from jill
	
	vector<double> &v =*jill_data;                // used reference to avoid uglu pointer derefernce
	
	double* jack_high=high(jack_data, jack_data+count);
	
	double* jill_high=high(&v[0], &v[0]+v.size());    // does not work as v.size() gives wrong size
	
	cout<<"Jack high: "<<*jack_high <<" and Jill high: "<<*jill_high<<"\n";
	
	return 0;
}


//-------------------------------------------------------------------------------------
// return a pointer to the element in [first, last) that has highest value
double* high(double* first, double* last)
{
	// need to add null ptr check
	double* high=first;
	for(double* p=first; p!=last; ++p)
		if(*high<*p)
		    high=p;
	return high;
}


double* get_from_jack(int count)
{
	double* data= new double[count];
	for(int i=0; i<count;++i)
		data[i]=random_no_generator(85647);
		
	return data;
}

vector<double>* get_from_jill()
{
	const int size=10;
	vector<double> *vptr=new vector<double>(size);
	for(int i=0; i<size;++i)
		(*vptr)[i]=random_no_generator(85647);
	//vptr=&data;
	return vptr;
}



int random_no_generator(int max_range)
{
 	time_t t;
    	srand(time(&t));                   // randon no. generator seed
	
	return rand() &max_range;
}
