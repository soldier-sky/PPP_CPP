#include"std_lib_facilities.h"

int main()
{

	cout<<"This program reads two inputs in continous manner"<<endl;
	cout<<"In order to exit the read loop enter ctrl+D  as input\n";

	int val1,val2,smallest=0;
        vector<int> v;	
	int condition = 1; 
	while(condition )
	{

		cout<<"\nPlease enter two integer"<<endl;
		cin>>val1>>val2;
		if(val1<= val2){
			cout<<"Entered values are "<<val1 <<" and " <<val2 << "\n";
		}else{
			cout<<"Entered values are "<<val2 <<" and " <<val1 << "\n";
		}

		//adding all values into vector v
		v.push_back(val1);
		v.push_back(val2);	

		//smallest= (val1<val2)?val1:val2;
		cout<<"\nWant to exit from loop? Enter conditiona 0: ";
		cin>>condition;
		if(condition == 0)
			break;
		else
		{
			sort(v);  //sort v from smallest to largest
			cout<<"\n smallest value so far"<<v[0];
		}
	}

	return 0;
}
