/****************************************
* Chapter 18. Vectors and Arrays
* Author: Sunil Kumar Yadav
* Date: 3 Aug 2021
* Description: Drill section of page 482
*
* Note: Drill.14 pending
*******************************************/
#include<iostream>
#include<vector>
using namespace std;

//------------------------------------------------------------------------------------
template<typename T> 
struct S
{
private:
	T val;
public:
	S(T v):val{v}
	{}
	T& get(void);
	const T& get(void) const;
	void set(T v) {val=v;}
	void operator=(const T& v);
	
};

template<typename T> 
T& S<T>::get(void)
{ 
	return val;
}

template<typename T> 
const T& S<T>::get(void) const
{ 
	return val;
}

template<typename T> 
void S<T>::operator=(const T& v)
{ 
	val=v;
}

//------------------------------------------------------------------------------------
// overladed extraction operator 
template<typename T> 
istream& operator>>(istream& is, S<T>& v)    // incomplete
{
		T temp;
		//getline(is,temp);
		is>>temp;
		v.set(temp);
		return is;
}

//------------------------------------------------------------------------------------
// read_val template function reads value into struct S's val from cin 
template<typename T> 
void read_val(T& v)
{
	cout<<"Enter the value for "<< typeid(v).name()<<" :";
	cin>> v;		// for S<T> type overloaded >> would be called
	//getline(cin, temp)
	//v.set(temp);
}

int main()
{
	S<int> si(100);
	S<char> sc('c');
	S<double> sd(100.05);
	S<string> ss("Sunil Yadav");
	
	vector<int> vi{10,20,30};
	S<vector<int>> svi(vi);
	
	/* before making val private
	cout<<"Value inside si: "<< si.val<<endl;
	cout<<"Value inside si: "<< sc.val<<endl;
	cout<<"Value inside si: "<< sd.val<<endl;
	cout<<"Value inside si: "<< ss.val<<endl;
	cout<<"Value inside svi: "<< svi.val[1]<<endl;   //only first element of vector val
	*/
	cout<<"Value inside si: "<< si.get()<<endl;
	cout<<"Value inside sc: "<< sc.get()<<endl;
	cout<<"Value inside sd: "<< sd.get()<<endl;
	cout<<"Value inside sd: "<< ss.get()<<endl;
	cout<<"Value inside svi: "<< svi.get()[0]<<endl;   //only 0th element of vector val
	
	
	ss.set("Ayaan Yadav");
	cout<<"After set operation value inside si: "<< ss.get()<<endl;
	
	vector<int> v2{100,200,300};
	svi.set({111,112});	// either pass on v2 or implecit use vector's initializer constructor
	cout<<"After set operation value inside svi: "<< svi.get()[1]<<endl;
	
	S<double> nsd(10.45);
	
	sd=nsd;
	cout<<"Value inside sd: "<< sd.get()<<endl;
	
	const S<int> si2(555);
	cout<<"Value inside si: "<< si2.get()<<endl;	
	//si2.get()=1;	  // Error: const/read only get refernce gives const ref	
	
	cout<<"Input int: ";
	cin>>si;			// uses overloaded >> operator
	cout<<"Value inside si: "<< si.get()<<endl;
	
	read_val<S<int>>(si);
	cout<<"Value inside si: "<< si.get()<<endl;
	
	return 0;
	
}
