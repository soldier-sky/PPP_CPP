#include"../std_lib_facilities.h"

void print(vector<int> v, string msg)
{
	cout<<msg<<"\n";
	for(int i:v)
		cout<<i<<"\n";
}

// fibonacci generate fibonnaci sequence
// x and y are initial value of fibonacci sequence. e.g. 1 and 2 produce 1,2,3,5....
// v is empty vector<int> which will hold the value of fibonacci series
// n is no. of element in series
void fibonacci(int x, int y, vector<int>& v, int n)
{
	int temp=0;
	v.push_back(x);   // adding first value in series
	v.push_back(y);   // adding second value in series
	
	for(int i=2;i<n;++i)
	{
		temp=v[i-2]+v[i-1];
		v.push_back(temp);
	}
}

int main()
{
	vector<int> vi{1,2,3,4,5,6,7,8,9,10};
	print(vi,"printing content of vector of int");

	vector<int> f_series;
	fibonacci(1,2,f_series,10);
	print(f_series,"\nFibonnaci series:");
	return 0;
}
