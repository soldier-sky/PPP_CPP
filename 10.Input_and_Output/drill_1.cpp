#include"../std_lib_facilities.h"


struct point
{
	int x,y;
};

istream& operator>>(istream& is, point& p)
// reading point via terminal
// format: (5,5)
{
	char ch1, ch2, ch3;
	int x,y;

	is>>ch1;
	if(!is || ch1!='(')
		error("Format not as expected");
	is>>x >>ch2 >>y >>ch3;
	
	p.x=x;
	p.y=y;
	return is;

}

ofstream& operator<<(ofstream& ofs,const point& p)
{
	ofs<< "(" <<p.x <<"," << p.y <<")\n";
	return ofs;
}

int main()
{	
	string ofile,ifile;

	cout<<"Example to read points via terminam. e.g. (5,4)";

	//istream is{};
        //if(!is)
	//	error("can't open input stream ");

	vector<point> original_points;
	for(int i=0; i<7;++i)
	{
		cout<<"Please input point";
		point temp{0,0};     // initialize new point each time
		cin>>temp;
		original_points.push_back(temp);
	}
	// printing data to ouptut console
	for(auto point:original_points)
	{
		cout<<"collected input ("<<point.x <<","  <<point.y <<")\n";
	}
	cout<<"Input out file name: ";
	cin>> ofile;

	
	ofstream ofs{ofile};
	if(!ofs)
		error("Could not open file",ofile);

	// redirecting output to file
	for(auto point:original_points)
		ofs<<point;


	return 0;
}




