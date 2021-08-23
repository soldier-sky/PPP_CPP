/****************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 26 July 2021
* Description: vector drill page 452
*
*******************************************/

#include<iostream>
#include<vector>
using namespace std;

const int size=10;
vector<int> gv={1,2,4,8,16,32,64,128,512,1024};  //size 10

void f(vector<int> vec)
{
	int v_size=vec.size();
	vector<int> lv(v_size);
	
	lv=gv;
	for(auto v:lv)
		cout<<v<<" ";	
	cout<<endl;
	
	vector<int> lv2=vec;
	for(auto v:lv2)
		cout<<v<<" ";	
	cout<<endl;
}

int factorial(int n)
{
	int result=1;
	while(n>0)
	{
		result*=n;
		n--;
	}
	return result;
}

int main()
{
	f(gv);
	cout<<"-------------\n";
	
	vector<int> vv(10);

	for(int i=0; i<vv.size();++i)
		vv[i]=factorial(i);
	
	f(vv);
	
	return 0;
}
