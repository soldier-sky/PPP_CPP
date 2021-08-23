/***********************************
* Chapter: 15. Graphing Functions and Data
* Author: Sunil Kumar Yadav
* Date: 23 June 2021
* Problem: Define a class Fct that is just like Function except that it stores 
*          its constructor arguments. Provide Fct with “reset” operations, 
*          so that you can use it repeatedly for different ranges, different functions, etc
*
* Attempt 1: Failed. I tried using existing Function inside new class ending up with issue passing Function& and
*	     eventual core dump error.
* Attempt 2: Simply create new struct Function like done inside Graph.h by inheriting Shape
*************************************/

#include"Simple_window.h"
#include"Graph.h"
#include<cmath>     

double square(double x) { return x*x; }
double one(double x) { return 1;}
double sine(double x) { return sin(x);}
double slope(double x) { return x/2;}
double slope_sine(double x) { return sin(x)+(x/2);}

//typedef std::function<double (double)> Fct;
typedef double Fctn(double);    // using Fctn as Fct already in use

//----------------------------------------------------------------------------------------------------------------
namespace Graph_lib
{

struct myFunction:Shape
{
public:
	myFunction(Fctn* f,double rrmin, double rrmax, Point rorig, int rcount, double rxscale, double ryscale);
	~myFunction(){}
	void draw_function();     // draws the function as per specs             
	void set_function(Fctn* f){ fp=f;}
	void set_min(double min){ rmin=min;}
	void set_max(double max){ rmax=max;}
	void set_xscale(double scale){ xscale=scale;}
	void set_yscale(double scale){ yscale=scale;}
	void set_orig(Point p){orig=p;}
	void reset(Fctn* f,double rrmin, double rrmax, Point rorig, 
	            int rcount, double rxscale, double ryscale);      // method to reset function to reuse further
	
private:
	Fctn* fp;
	double rmin;
	double rmax;
	Point orig;
	int count;
	double xscale;
	double yscale;
	 
};




myFunction::myFunction(Fctn* f,double rrmin, double rrmax, Point rorig, int rcount, double rxscale, double ryscale):
fp{f}, rmin{rrmin}, rmax{rrmax}, orig{rorig}, count{rcount}, xscale{rxscale}, yscale{ryscale}
{
	draw_function();
}

void myFunction:: draw_function()
// implementation via Function::Function fromm graph.cpp
{

    if (rmax-rmin<=0) error("bad graphing range");
    if (count <=0) error("non-positive graphing count");
    double dist = (rmax-rmin)/count;
    double r = rmin;
    for (int i = 0; i<count; ++i) 
    {
    	//double j=fp(r);
        add(Point{orig.x+int(r*xscale),orig.y-int(fp(r)*yscale)});
        r += dist;
    
    }
}
void myFunction::reset(Fctn* f,double rrmin, double rrmax, Point rorig, int rcount, double rxscale, double ryscale)
// incomplete as last point from earlier function draw() remains in point vector
// need to devise method to delete points while re drawing. 
{

	set_function(f);
	set_min(rrmin);
	set_max(rrmax);
	set_xscale(rxscale);
	set_yscale(ryscale);
	set_orig(rorig);
	
	// Drawing again
	draw_function();
}
//----------------------------------------------------------------------------------------------------------------

};


int main()
{
	using namespace Graph_lib;
	
	Simple_window win{Point{100,100}, 600,600, "Function graph"};
	
	const int rmin=-10;
	const int rmax=11;
	const int count=400;
	const int xscale=25;
	const int yscale=25;
	const Point orig{300,300};
	
	myFunction f{square,rmin, rmax, orig, count, xscale, yscale};
	//Fctn f{square, rmin, rmax, orig, count, xscale, yscale};
	//f.reset_function(one);
	
	win.attach(f);
	win.detach(f);  
	f.set_function(sine);
	f.reset(sine,rmin, rmax, orig, count, xscale, yscale);
	win.attach(f);
	
	win.wait_for_button();
	
	
	
	
}
