
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	vector<int> v{1,3,5,7,9,11};

	auto r=find(v.begin(), v.end(), 11);

	if(r!=v.end()) cout<<"found\n";
	else cout<<"not found\n";

	return 0;
}
