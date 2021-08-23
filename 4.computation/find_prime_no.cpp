// This program finds prime no. from 2- 100;
// Note: Prime no. are greater than 1 which are only divisible by itself.
// For example 2, 5, 7,11, 23 etc

#include"std_lib_facilities.h"

bool isPrimeNo(int num);
int main()
{
	cout<<"This program prints prime no. from 1 to 100"<<endl;
	
	vector<int> primes;
	int num;
	bool isPrime;

	for(int i=2;i<100;++i)
	{	
		num=i;
		for(int j=2; j<num;++j)
		{
			if(num%j==0) //finding if any no. from n to n-1 division is 0
			{
				isPrime=false;
				break;
			}
				
			isPrime=true;
		}
		if(isPrime==true)
			primes.push_back(num);
	}

	//print primes
	for(int x:primes)
		cout<<x<<"\n";

	//verify isPrimeNo() function
	cout<<"17 a prime no? "<<isPrimeNo(18);
	
	return 0;
}

bool isPrimeNo(int num)
{
	if(num<=1)  //Primes are positive greater than 1 
		return false;

	for(int i=2; i<num;++i)
	{
		if(num%i==0)
			return false;

		return true;
	}

}
