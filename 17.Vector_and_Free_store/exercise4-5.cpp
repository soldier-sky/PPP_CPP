/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 16 July 2021
* Description: 4. Write a function, char* strdup(const char*), that copies a C-style string into
*      memory it allocates on the free store. Do not use any standard library functions.
*      5. Write a function, char* findx(const char* s, const char* x), that finds the first
*      occurrence of the C-style string x in s
*
**************************************************************************************/
#include<iostream>
#include<string.h>

char* strdup(const char* s)
{
	char* ret_s=new char; 
	
	int i;  		// to count len of C-style string s
	for(i=0;s[i]!='\0';++i)
	{
		ret_s[i]=s[i]; 
	}
	ret_s[i+1]='\0';
	
	return ret_s;
}


// start with bool return
char* findx(const char* s, const char* x)
{
	int x_len=0, s_len=0;
	char* ret_s=new char{' '}; 
	
	for(x_len=0;x[x_len]!='\0'; ++x_len)
		;         // counting len of x
	for(s_len=0;s[s_len]!='\0'; ++s_len)
		;         // counting len of s
	
	// using sliding window approch
	for(int i=0; i < s_len-x_len; ++i)
	{
		int match=0;                 // hold no. of matching character set     
		for(int j=0; j<x_len; ++j)   //finding substring x in string s
		{
			if(s[i+j]==x[j])
				match++;
			
		}
		if(match==x_len)             // if x in s then return true
		{
		   strcpy(ret_s,x);       
		   return ret_s;
		}
	}
	
	return ret_s;
}

int main()
{
	char *s=new char[5];
	s[0]='S';
	s[1]='k';
	s[2]='Y';
	s[3]='S';
	s[4]='\0';
	
	char str[]="Hello World!";
	char pattern[]="ello";
	
	char *str2=strdup(str);
	
	std::cout<<str2<<'\n';
	
	
	std::cout<<std::boolalpha;
	std::cout<<findx(str,pattern)<<'\n';
	
	return 0;
}


