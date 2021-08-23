// Exercise 2: Creating class with name and age with input and output operation
// to get values and print them. Sort operation to sort the values.

#include "../std_lib_facilities.h"

class Name_pairs
{
	public:
	vector<double> age;
	vector<string> name;


	public:
	Name_pairs();
	Name_pairs(string n, double a);
	void sort(void);
	void read_names();
	void read_ages();
	void print();

};

//overload << to print Name_pair
ostream& operator<<(ostream& os, const Name_pairs& obj);		

Name_pairs::Name_pairs():age{},name{}
{
}

Name_pairs::Name_pairs(string n, double a)
{
	name.push_back(n);
	age.push_back(a);
}

void Name_pairs::print()
{
	
	if(age.size() != name.size() )
		error("length of age and size vector are not same");

	for(int i=0; i<name.size(); ++i)
	{
		cout<<'('<<name[i] <<", " <<age[i] <<")"<<"\n";
	}
}


void Name_pairs::read_names()
{
	string temp;
	cout<<"Please enter the names seperated by white space(use q to exit)\n";
	while(cin>>temp)  //use ctr + d to abort read
	{
		if(temp=="q")
			return;
		name.push_back(temp);
	}

}

void Name_pairs::read_ages()
{
	double temp;
	int diff=0;
	diff=name.size() - age.size();  // diff holds difference in size of two vector
	
	cout<<"Please enter "<< diff <<" ages\n";
	for(int i=0; i<diff;++i)
	{
		cin>> temp;
		age.push_back(temp);
	}
}


// Sort uses name vector to sort the values in name and age vector
// Note: We should use better sort algo
void Name_pairs::sort()
{
	double age_temp;
	string name_temp;

	if(name.size() != age.size())
		error("Size of age and name vectors are not same");

	for(int i=0;i<name.size(); ++i)
	{
		for(int j=i;j<name.size()-i-1;++j)
		{
			if(name[j] > name[j+1])
			{
				name_temp=name[j+1];
				name[j+1]=name[j];
				name[j]=name_temp;

				age_temp=age[j+1];
				age[j+1]=age[j];
				age[j]=age_temp;
			}
		}
	}
}

// overloading << for printing
ostream& operator<<(ostream& os, const Name_pairs& obj)
{
	
	for(int i=0;i<obj.name.size();++i)
	{
		os<<"("<<obj.name[i]<<", " << obj.age[i]<<")" <<"\n";
	}
	
}

// overloading == operator to compare two Name_pairs 
bool operator==(const Name_pairs& p1, const Name_pairs& p2)
{
	return (p1.name == p2.name) && (p1.age == p2.age);
}	

int main()
{
	Name_pairs np("sunil",29);
	np.print();
	np.read_names();
	np.read_ages();

	cout<<"using overload << operator to print Name_pairs\n";
	cout<<np;
	cout<<"Printing complete lis\n";
	np.print();
	
	cout<<"Calling print after sort function to sort names alphabetically\n";
	np.sort();
	np.print();

	Name_pairs p1("Ayaan",0.6);
	Name_pairs p2("Ayaan", 0.6);

	if(p1==p2)
		cout<<" p1 and p2 are equal";
	else
		cout<<"P1 and P2 are not equal";
	return 0;
}
