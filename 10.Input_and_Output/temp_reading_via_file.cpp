// This example program will use ifstream to read hour temp from file and
// write formated hour temp  data into another file
//

#include "../std_lib_facilities.h"

struct Reading          // a temperature reading
{
	int hour;       // hour after midnight [0:12]
	double temperature;  // in Fahrenheit
};



int main()
{
	cout<< "Please enter input file name: ";
	string iname;
	cin>> iname;

	ifstream ist{iname};    //ist reads from the file named iname
	if (!ist) error("Can't open input file ", iname);

	string oname;
	cout<<"Please enter name of output file: ";
	cin>>oname;
	ofstream ost{oname};    //ost writes to a file named oname
	if(!ost) error("Can't open output file ", oname);

	vector<Reading> temps;     // strore the readings here

	int hour;
	double temperature;
	while(ist>>hour>>temperature)
	{
		if(hour< 0|| 23<hour) error("Hour out of range");
		temps.push_back(Reading{hour,temperature});
	}
		
	for(int i=0;i<temps.size();++i)
		ost<<'('<<temps[i].hour<<','
			<<temps[i].temperature<<")\n";

	return 0;

}







