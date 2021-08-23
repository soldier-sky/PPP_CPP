//Program except 3 strings and prints the value in increasing order/sequence. 


#include"std_lib_facilities.h"

void sort_array(string v[], unsigned int size);

int main()
{
	int sz;
	string str1, str2, str3;

	sz=3;
	cout<<"Please enter "<<sz <<" string as  input: ";

	cin>>str1;
	cin>>str2;
	cin>>str3;

	string num_array[sz]={str1, str2, str3}; //Assigning value array  
	
	sort_array(num_array,sz);
	for(int k=0;k<sz;k++)
		cout<<num_array[k]<<" ,";

	return 0;
}

//Implementing bubble sort
void sort_array(string v[], unsigned int size)
{
	int i,j;
	string temp;

	for(i=0;i<size-1;++i) 
	{
		for(j=0;j< (size-1-i);++j)
		{
			if(v[j]>v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}

}
