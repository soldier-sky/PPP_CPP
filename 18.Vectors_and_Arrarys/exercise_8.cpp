/********************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 28 July 2021
* Description: Exercise 8 and 10: finding if strings is palindrom or not
*
* Note: There are two methods. 
*  1. reverse copy the string and compare with itself 
*  2. compare 0 and nth word, 1 and n-1th word etc to find if string is palindrom or not
***********************************************************************************/
#include<iostream>
#include<string>
using namespace std;
// using backword coppy method to find palindrom
bool is_palindrom(string str)
{
	string reverse_str= string{str.rbegin(), str.rend()}; // using inbuild string reverse iterator
	if(reverse_str == str)
		return true;
	else
		return false;
}


// using start and end comarision method
bool is_palindrom_2(string str)
{
	int size=str.size();
	int end_idx=size -1;
	for(int i=0; i<size/2; i++)
	{
		if(str[i] != str[end_idx-i])
			return false;
	}
	return true;
}

// using start and end comarision method
bool is_palindrom_2a(string str)
{
	
	int start_idx =0;
	int end_idx=str.size() -1;
	
	while(start_idx < end_idx)    //if not reached middle of string
	{
		if(str[start_idx] != str[end_idx])
			return false;
		start_idx++;
		end_idx--;
	}
	return true;
}


int main()
{
	string input;
	cout<<"Please input word to know if its palindrom or not: ";
	getline(cin,input);
	
	cout<<boolalpha;
	if(is_palindrom(input))
	{
		cout<<input<<" is palindrom\n";
	}
	else
		cout<<input<<" is not palindrom\n";
		
	cout<<"method 2: "<<is_palindrom_2a(input)<<endl;	
	
	return 0;
}
