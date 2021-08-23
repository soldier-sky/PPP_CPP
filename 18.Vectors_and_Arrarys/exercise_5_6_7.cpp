/********************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 28 July 2021
* Description: Exercise 5 to 7
*  design string concatination function
*
***********************************************************************************/
#include<iostream>
#include<string>
using namespace std;

// concatinate two strings with provided delimiter. Default delimiter as dot i.e. '.'
string cat_dot(const string& s1, const string& s2, const string delimiter=".")
{
	string cat_str=s1+delimiter+s2;
	return cat_str;
}


// Helper function to find c style string's length excluding training 0 or '\0'
int m_strlen(const char* s)
{	
	int len=0;
	while(*s!='\0')
	{
		++len;
		s++;
	}
	
	return len;
}

// concatinate two c style string with provided delimiter. Default delimiter: dot i.e. '.'
char* c_cat_dot(const char* s1, const char * s2, const char* delimiter=".")
{
	int s1_len=m_strlen(s1);
	int s2_len= m_strlen(s2);
	int delimiter_len=m_strlen(delimiter);
	
	int cat_str_len=s1_len + s2_len + delimiter_len +1;   // additional 1 for '\0'
	
	char* cat_str=new char[cat_str_len];
	
	for(int i=0; i<s1_len;++i)			// copying s1 
		cat_str[i]=s1[i];
	

	int offset=s1_len+delimiter_len; 
	
	for(int i=0; i<offset;++i)			// copying delimiter after s1
		cat_str[i+s1_len]=delimiter[i];
	

	for(int i=0; i<cat_str_len;++i)		// copying s2 after s1+delimter 
		cat_str[i+s1_len+delimiter_len]=s2[i];
	
	cat_str[cat_str_len-1]='\0';
	
	return cat_str;
}

int main()
{
	cout<<"Concatinated string is "<<cat_dot("Sunil", "Yadav","///")<<endl;
	cout<<"Concatination using c-style string method:"<<c_cat_dot("Sunil Yadav ", "Yadav")<<endl;
	
	
	return 0;
}
