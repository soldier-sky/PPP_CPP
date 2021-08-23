// Example functions reverse the order of a given vector
// 1. in place and 2. return copy of revers order

#include"../std_lib_facilities.h"

void reverse_in_place(vector<int>& v)
{
	int size=v.size();

	for(int i=0;i < size/2; ++i)
		std::swap(v[i],v[size-1-i]);
}

vector<int> reverse(vector<int> vi)
{
	int size=vi.size();
	vector<int> vo(size,0); //declaring empty vector of size

	for(int i=0; i<size ;++i)
		vo[size-1-i]=vi[i];

	return vo;
}

void print_int_vector(const vector<int>& v)
{
	for(int i: v)
		cout<< i<<"\n";
}

int main()
{
	vector<int> vi={1,2,3,4,5,6,7,8,9,10};
	
	reverse_in_place(vi);
	print_int_vector(vi);
	
	vector<int> v2=reverse(vi);
	print_int_vector(v2);
	return 0;

}
