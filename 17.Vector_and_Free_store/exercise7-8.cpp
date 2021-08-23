/*************************************************************************************
* Chapter 17. Vector and Free Store
* Author: Sunil Kumar Yadav
* Date: 17 July 2021
* Description: 7. Write a program that reads characters from cin into an array that you allocate
*      on the free store. Read individual characters until an exclamation mark (!) is entered.
*      Do not use a std::string. Do not worry about memory exhaustion.
*      8. Repeat 7. using string
*
**************************************************************************************/
#include<iostream>
#include<string>

int main()
{
	char* str=new char[100];   // or declare: char* str=new char; 
				    //as pointer does not know end of char array
	char c;
	int idx=0;
	
	std::cout<<"Please enter charachters and terminate using !\n>>";
	while(std::cin>>c)
	{
		if(c=='!') break;
		
		str[idx]=c;
		idx++;	
	}
	std::cout<<"\nEntered charachters are: "<<str<<'\n';
	
	std::string str2;
	std::cout<<"Please enter(again) charachters and once done terminate using !\n>>";
	while(std::cin>>c && c!='!')
	{
		str2.push_back(c);
	}
	std::cout<<"\nEntered charachters are: "<<str2<<'\n';
	
	
	delete[] str;

	return 0;
}
