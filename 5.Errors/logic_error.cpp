// This program take calculate min, max and avg temperate for given inputs

#include "std_lib_facilities.h"

int main()
{
	vector<double> temps;
	double sum_temp=0, min_temp=0, max_temp=0;

	cout<<"Please enter list of temperateures: ";
	
	for(double temp=0; cin>>temp;)
		temps.push_back(temp);    // Appending temperature in temps vector

	// Accessing temps elements to find min and max temp
	
	if(temps.size()==0)
	{
		cout<<"Ooops! temperature list is empty\n";
		return -1;
	}
	else    // setting min and max with temps[0] for next step calcuation
	{
		min_temp=temps[0];
		max_temp=temps[0];
	}

	for(double x:temps)
	{	
		if(x>max_temp) max_temp=x;
		if(x<min_temp) min_temp=x;

		sum_temp+=x;   //calculating sum
	}
	// To find min and max we can sort the list:
	//  easier option but time complexity would be higher
	
	cout<<"Min temp: "<<min_temp<<endl
	     <<"Max temp: "<<max_temp<<endl
	     <<"Avg temp: "<<sum_temp/temps.size()<<endl;
	cout<<'\n';
	return 0;
}
