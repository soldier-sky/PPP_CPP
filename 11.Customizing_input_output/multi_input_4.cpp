// This program read input integers in and automatically convert input integers base to decimal
/* In order to not assume base of integer we will use cin.unsetf() \
 *
 * cin.unsetf(ios::dec); // don’t assume decimal (so that 0x can mean hex)
 * cin.unsetf(ios::oct); // don’t assume octal (so that 12 can mean twelve)
 * cin.unsetf(ios::hex); // don’t assume hexadecimal (so that 12 can mean twelve
*
*  Note: Above option does not work. Hence using strtol funtion to handle this issue
*/

#include"../std_lib_facilities.h"


// Helper function to identify base system of input integer
void number_sys(string num, string& sys)
{
	if(num[0] == '0' && (num[1]=='x' || num[1]=='x') )	
	{
		sys="hexadecimal";
	}
	else if(num[0] == '0' && !(num[1]=='x' || num[1]=='x') )	
	{
		sys="octel";
	}
	else
		sys="decimal";
}

int main()
{
	vector<string> num_str;
	string temp, num_sys;
	int val;
	
	cout<<"Please enter valid integer value(s): ";

	
	while(cin>>temp)   // Reading integer into string
	{
		num_str.push_back(temp);   
	}

	for(int i=0; i< num_str.size();++i)
	{
		val=strtol(num_str[i].c_str(),NULL,0);    // converting string int to long int
							  // note strtol is c function. Hence str.c_str():
		number_sys(num_str[i],num_sys);   //getting num base system

		cout<<num_str[i]<<" " <<setw(20-num_sys.length()) <<num_sys 
		    <<" coverts to " <<dec <<val <<" decimal\n";
	}

	return 0;
}
