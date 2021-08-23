/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 16 July 2021
* Description: 3. Write a function, void to_lower(char* s), that replaces all uppercase characters
*	 in the C-style string s with their lowercase equivalents. For example, 
*	 Hello, World! becomes hello, world!. Do not use any standard library functions. 
*	 A C-style string is a zero-terminated array of characters, so if you find a char 
*	 with the value 0 you are at the end
*   
**************************************************************************************/
#include<iostream>

void to_lower(char* s)
{
	for(int i=0;s[i]!='\0';++i)
	{
		if(s[i]>=0x41 && s[i]<=0x5A)
			s[i]=s[i] + 0x20;
	}
	
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
	
	std::cout<<"Before: "<<s<<'\n';
	to_lower(s);
	std::cout<<"After: "<<s<<'\n';
	
	
	std::cout<<"Before: "<<str<<'\n';
	to_lower(str);
	std::cout<<"After: "<<str<<'\n';
	
	
	return 0;
}


