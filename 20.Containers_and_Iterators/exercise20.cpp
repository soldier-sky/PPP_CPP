/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 17 Aug 2021
* Description: 20. Writing program to analyze perfromance difference between vector and list
*	This experiment was first suggested by John Bentley.
*
* Result on 2GB RAM Virtual machine(Ubuntu):
*
* Number of elements	Fill Time(us)		Sort Time(us)	
* 		Vector<int>	List<int>	Vector<int>	List<int>
* 10		8		8		5		16
* -------------------------------------------------------------------------
* |100		102		31		42		126	     |
* -------------------------------------------------------------------------
* 1000		74		211		503		1132
* 10000	662		2361		5354		14142
* 100000	6557		21749		80799		173762
* 1000000	65962		220016		844720		2259650
* 
***********************************************************************************/
#include<iostream>  
#include<chrono>    // C++ Chrono lib header
#include<cstdlib>   // For random no. generator
#include<ctime>     // Using system clock as seed to random no. generator
#include<algorithm> // For sort algo
#include<vector>
#include<list>


using namespace std;

template<typename T>
int  test_container(T& c,int n)
{

	time_t t;
	srand(time(&t));    // initialize seed for random no. generator
	
	chrono::time_point<chrono::system_clock> start = chrono::system_clock::now(); 
	
	for(int i=0; i<n; ++i)
		c.push_back(rand() & 0xFFFFFFFF);
		
	chrono::time_point<chrono::system_clock> end = chrono::system_clock::now(); 
	auto fill_time = chrono::duration_cast<chrono::microseconds>(end - start).count();

	return fill_time;
}

int main(int argc, char** argv)
{
	int N=1000;
	if(argc>1)
		N=atoi(argv[1]);

	vector<int> vec;
	list<int> lst;

	int v_fill_time=test_container(vec, N);
	int l_fill_time=test_container(lst, N);
	cout<<"Total fill time for vector: "<<v_fill_time<<'\n';
	cout<<"Total fill time for list: "<<l_fill_time<<'\n';
	cout<<"--------------------------------------------------------------\n";


	// sorting time for vector and list
	chrono::time_point<chrono::system_clock> vsort_start = chrono::system_clock::now(); 
	sort(vec.begin(), vec.end());
	chrono::time_point<chrono::system_clock> vsort_end = chrono::system_clock::now(); 
	
	auto vsort_time = chrono::duration_cast<chrono::microseconds>(vsort_end - vsort_start).count();
	
	
	chrono::time_point<chrono::system_clock> lsort_start = chrono::system_clock::now(); 
	lst.sort();  // using list sort as list do not have random access iterator required by std::sort
	chrono::time_point<chrono::system_clock> lsort_end = chrono::system_clock::now(); 
	
	auto lsort_time = chrono::duration_cast<chrono::microseconds>(lsort_end - lsort_start).count();
	
	
	cout<<"Total sort time for vector: "<<vsort_time<<'\n';
	cout<<"Total sort time for list: "<<lsort_time<<'\n';
	

	return 0;
}
