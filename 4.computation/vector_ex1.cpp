#include"std_lib_facilities.h"

int main()
{
	vector<double> temps; // temperature 
	cout<< "Please enter list of temperature: ";
	for(double temp;cin>>temp;)    //read temperature from user
		temps.push_back(temp);

	//calculating sum and average of temps
	double sum=0;
	for(double x:temps)
		sum+=x;

	cout<<"\nSum of all temperature is: "<<sum;
	cout<<"\nTotal no. input from user is:" <<temps.size();
	cout<<"\nAverage of temperature is: "<<(sum/temps.size())<<endl;

	//compute median temperature
	sort(temps);
	cout<<"Median temperature:"<<temps[temps.size()/2]<<endl;

	return 0;
}


