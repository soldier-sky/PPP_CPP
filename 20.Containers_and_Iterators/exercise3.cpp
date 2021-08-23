/**********************************************************************************
* Chapter 20. Containers and Iterators
* Author: Sunil Kumar Yadav
* Date: 16 Aug 2021
* Description: 3. Look at the palindrome examples (§18.7); redo the Jack-and-Jill example from §20.1.2 using that 
*               variety of techniques.
* 
***********************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

/*  example palindrome implementation
bool is_palindrome(const string& s)
{
	int first = 0;               // index of first letter
	
	int last = s.length()–1;     // index of last letter
	
	while (first < last) 
	{
		
		if (s[first]!=s[last])       // we haven’t reached the middle
			return false;
		++first; // move forward
		--last; // move backward
			
	}
	return true;
}
*/

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first:last) that has the highest value
{
	Iterator high=first;
	Iterator p=first;
	while(p!=last)
	{
		if(*high<*p) 
		{
			high=p;
		}
		p++;
	}

	return high;
}

int main()
{
	vector<int> vi{1883,3,6,2,45,50,245};
	
	auto largest=high(vi.begin(), vi.end());
	
	cout<<"Largest value "<<*largest<<'\n';
	
	return 0;
	
}
