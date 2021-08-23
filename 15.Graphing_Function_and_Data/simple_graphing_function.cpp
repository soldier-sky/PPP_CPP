/********************************************
* Author: Sunil Kumar Yadav
* Date: 20 June 2021
* Notes: This program is to get familiar with graphing
* functions.
*
**********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include<cmath>

double one(double d) { return 1;}

double slope(double x) { return x/2;}

double square(double x) {return x*x;}

int main()
{

	using namespace Graph_lib;
	
	constexpr int xmax=600;          //window size
	constexpr int ymax=400;
	
	constexpr int x_orig=xmax/2;    //position of (0,0) is centre of window
	constexpr int y_orig=ymax/2;
	constexpr Point orig{x_orig, y_orig};
	
	constexpr int r_min=-10;         //range [-10:11]
	constexpr int r_max=11;
	
	constexpr int n_points=400;       // no. of points used in range
	constexpr int x_scale=30;          // scaling factors
	constexpr int y_scale=30;
	
	
	
	Simple_window win{Point{100,100}, xmax,ymax,"Function Graphing"};
	
	Function s1{one, r_min, r_max, orig, n_points, x_scale, y_scale};
	Function s2{slope, r_min, r_max, orig, n_points, x_scale, y_scale};
	Function s3{square, r_min, r_max, orig, n_points, x_scale, y_scale};
	
	Text ts1{Point{100, y_orig-40}, "one"};
	Text ts2{Point{100, y_orig+y_orig/2 -20}, "x/2"};
	Text ts3{Point{x_orig -100,20}, "x*x"};
	
		
	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	
	win.attach(ts1);
	win.attach(ts2);
	win.attach(ts3);
	
	
	
	constexpr int xlength= xmax-40;       //make the axis a bit smaller than window
	constexpr int ylength= ymax-40;
	
	
	Axis x{Axis::x, Point{20,y_orig}, xlength, xlength/x_scale, "one notch ==1"};
	Axis y{Axis::y, Point{x_orig,ylength+20}, ylength, ylength/y_scale, "one notch ==1"};
	
	x.set_color(Color::red);
	y.set_color(Color::red);
	
	x.label.move(-160,0);
	x.notches.set_color(Color::dark_red);
	
	win.attach(x);
	win.attach(y);
	
	// Adding more functions
	Function s4{cos, r_min, r_max, orig, 400,30,30};  
	s4.set_color(Color::blue);
	
	Function s5{sin, r_min, r_max, orig, 400, 30,30};
	s5.set_color(Color::green);
	// similarly log, exp etc from cmath lib can be used
	s5.set_style(Line_style::dash);
	
	//lambda expression to defing function for sloping_cos: commenting since we are getting below erro 
	//error: call of overloaded ‘Function(<brace-enclosed initializer list>)’ is ambiguous
	//Function s6{[](double x){return cos(x)+slope(x);}, r_min, r_max, orig, 400,30,30};

	// Function s6 {[](double x) -> double { return cos(x)+slope(x); }, r_min,r_max,orig,400,30,30}; 
	// another way to define lambda with return type
	
	//win.attach(s6);
	win.attach(s4);
	win.attach(s5);
	
	// using below int arg lambda to avoid overload error 
	auto square_slope_cos = [](int x)
   	{
        	return cos(x)+slope(x); 
   	};
	
	Function s6{square_slope_cos, r_min, r_max, orig, 400,30,30};
	win.attach(s6);
	
	win.wait_for_button();
}
