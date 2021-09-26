/**********************************************************************************
* Chapter Chapter 21. Algorithms and Mapsv
* Author: Sunil Kumar Yadav
* Date: 10 Sep 2021
* Description:  9. Define an Order class with (customer) name, address, data, and vector<Purchase> members. 
*  Purchase is a class with a (product) name, unit_price, and count members. Define a mechanism for reading 
*  and writing Orders to and from a file. Define a mechanism for printing Orders. Create a file of at least 
*  ten Orders, read it into a vector<Order>, sort it by name (of customer), and write it back out to a file. 
*  Create another file of at least ten Orders of which about a third are the same as in the first file, 
*  read it into a list<Order>, sort it by address (of customer), and write it back out to a file. 
*  Merge the two files into a third using std::merge().
*
*
* Note: Incomplete
***********************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

// Purchase class holds item details
class Purchase
{
private:
	string product_name;
	int unit_price;
	int count;
public:
	Purchase():
	     product_name{""}, unit_price{0}, count{0}{}
	     
	Purchase(string str, int up, int c):
	     product_name{str}, unit_price{up}, count{c}{}
	     
	void set_product_name(string s){ product_name=s;}
	void set_unit_price(int price){ unit_price=price;}
	void set_count(int c){ count=c;}
	
	string get_name(){ return product_name;}
	int get_unit_price() { return unit_price;}
	int get_count(){ return count;}
};


// Order class hols Purchase details of customer
class Order
{
private:
	string name;
	string address;
	int data;
	vector<Purchase> vp;
public:
	Order():
	    name{""}, address{""}, data{0}{ }
	
	Order(string str, string adrs, int d, vector<Purchase> v):
		name{str}, address{adrs}, data{d}, vp{v} { }
	
	void set_name(string s){ name=s;}
	void set_address(string a){ address=a;}
	void set_purchase(Purchase p){ vp.push_back(p);}
	
	string get_name(){ return name;}
	string get_address(){ return address;}
	int get_data(){ return data;}
	vector<Purchase> get_purchase_data(){ return vp;}
};


//ifstream& operator>>(ifstream& inf, Order 

int main()
{
	vector<Order> v_orders;
	
	//cout<<"Input file name containing Orders(sample input_order.txt) : ";
	string ifile="input_order.txt";
	//cin>>ifile;
	
	ifstream ifs{ifile};
	
	string temp;
	while(getline(ifs, temp))
	{
		Purchase p;
		string cust_name, cust_add, items;
		int d=0;
		cust_name=temp;
		
		getline(ifs, cust_add);
		getline(ifs, temp);
		d=stoi(temp);
		cout<<d<<endl;
		
		getline(ifs, items);
			
		
		//cout<<temp<<'\n';
		
		
		
		//v_orders.push_back();
		
		
	}
/*
Bob
Boston
0x001
{Apple 10 1 Banana 8 2 Kiwi 3 2}
*/	
	
	

	return 0;
}



