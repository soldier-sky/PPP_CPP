//Program except 3 integers and prints the value in increasing order/sequence. 
//Input  1 5 6 => output 1,5,6
//Input 4 5 4 => output 4,4,5

#include"std_lib_facilities.h"

void sort_array(int v[], unsigned int size);

int main()
{
	int n1,n2, n3,sz;
	sz=3;
	cout<<"Please enter "<<sz <<" three  input: ";

	cin>>n1;
	cin>>n2;
	cin>>n3;
	int num_array[sz]={n1, n2, n3}; //Assigning value array  
	
	sort_array(num_array,sz);
	for(int k=0;k<sz;k++)
		cout<<num_array[k]<<" ,";

	return 0;
}

//Implementing bubble sort
void sort_array(int v[], unsigned int size)
{
	int temp,i,j;

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
