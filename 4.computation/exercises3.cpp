// Program to take input in double as distance between multiple cities and calculate
// avgerage distance, total distance and minimum distance of cities

#include"std_lib_facilities.h"

int main()
{
	vector<double> distances;
	double sum=0;

	cout<<"Enter distance between different cities: ";
	cout<<"Note: To stop entering distance use Ctrl + D"<<endl;
	
	for(double dist; cin>>dist ;)
		distances.push_back(dist);

	//calculate sum of all distance
	for(double d:distances)
		sum+=d;
	cout<<"Sum of all distance is: "<< sum <<endl;

	// sort distance 
	sort(distances);
	cout<<"Smallest distance between two city is: "<<distances[0] << endl;

	return 0;
}
