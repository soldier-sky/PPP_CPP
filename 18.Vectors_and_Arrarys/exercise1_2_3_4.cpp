/********************************************************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 27 July 2021
* Description: Exercise 1 to 4.
* 1. Write a function, char* strdup(const char*), that copies a C-style string into memory it allocates on
* the free store. Do not use any standard library functions. Do not use subscripting; 
* use the dereference operator * instead.
*
* 2. Write a function, char* findx(const char* s, const char* x), that finds the first occurrence of the 
* C-style string x in s. Do not use any standard library functions. Do not use subscripting; 
* use the dereference operator * instead.
*
* 3. Write a function, int strcmp(const char* s1, const char* s2), that compares C-style strings. 
* Let it return a negative number if s1 is lexicographically before s2, zero if s1 equals s2, and 
* a positive number if s1 is lexicographically after s2. Do not use any standard library functions.
* Do not use subscripting; use the dereference operator * instead.
*
***********************************************************************************/
#include<iostream>
using namespace std;

// returns the lenght of c style string including training 0 or '\0'
int m_strlen(const char* s)
{	
	int len=0;
	while(*s!='\0')
	{
		++len;
		s++;
	}
	
	return len+1;
}

// Duplicate input string and return memory location of copied string from heap
char* strdup(const char* s)
{
	int str_len=m_strlen(s);
	char* str=new char[str_len];
	
	for(int i=0; i<str_len;++i)    // other alternative would be while(s*!=0) type loop
	{
		*(str+i)=*(s+i);
	}
	return str;	
}

// Find substring x in string s: using naive method to search substring
// return " " if not found. Note: findx() return pointer to char in s with first occurance
char* findx(const char* s, const char* x)
{
	int s_len=m_strlen(s)-1;    // excluding last '\0'
	int x_len=m_strlen(x)-1;
	
	int match_count{0};
	
	if(s_len<x_len)  return " ";
	
	for(int i=0; i<s_len-x_len; i++)
	{
		match_count=0;
		for(int j=0; j<x_len; ++j)
		{
			if(*(s+i+j) == *(x+j)) // alternativly break inner loop once mismatch
				match_count++;		
		}
		if(match_count==x_len)         // alternativly cont. use j==x_len validate match
			return (char*)(s+i);
	}
	
	return " ";
	
	
}

//compares two C style string lexicographically. 
// return -1 if s1<s2, 0 if s1==s2 and 1 s1>s2
int strcmp(const char* s1, const char* s2)
{
	while(*s1!='\0' || *s2!=0)
	{
		if(*s1>*s2) 
			return 1;
		else if(*s1<*s2)  
			return -1;
		else 
		{
			s1++;
			s2++;
		}
		
	}
	return 0;   // if reach here then s1 and s2 are same
}

int main()
{
	const char* i_str="Sunil Yadav";
	cout<<i_str<<" has "<<m_strlen(i_str) << " charachters \n";

	char* dup_str=strdup(i_str);
	cout<<"duplicated string is: "<<dup_str<<'\n';
	
	const char* pattern="nil Ya";
	cout<<"input str is: "<<i_str<<" and pattern is: "<<pattern
		<<" and strdup():"<< findx(i_str, pattern)<<endl;
		
	cout<<"result of strcmp is: "<<strcmp("Sunil Yadav", "Sunil Yadav")<<endl;
	
	// exercise 4. Using non terminating c string i.e. missing '\0'
	// Note due to missing string terminating character, program will continue reading next
	// memory blocks until \0 is found. To fix this redisign function with second argument 
	// which indcate size of strings
	char err_str[5]={'s','u','n','i','l'};
	char err_str2[5]={'s','u','n','i','l'};
	cout<<"err_str has 5 character and strlen op is "<<m_strlen(err_str) << " charachters \n";
	cout<<"duplicated string is: "<<strdup(err_str)<<'\n';
	
	return 0;
}



