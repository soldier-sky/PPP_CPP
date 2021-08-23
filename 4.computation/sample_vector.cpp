#include<vector>
#include<iostream>

using namespace std;
int main()
{
	vector<int> v1={2,4,6,8,10};  //initializing vector of size 5
	vector<int> v2(6);           //declaring empty vector of size 6

	//For range loop example
	for(int x: v1)
	{
		cout<<x<<endl;
	}

	for(int i=0;i<v2.size();++i)
	{
		v2[i]=i*i;
	}

	//Print value of v2
	for(int x: v2)
		cout<<x<<endl;


	return 0;
}
