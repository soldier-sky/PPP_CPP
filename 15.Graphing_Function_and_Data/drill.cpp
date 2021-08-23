/******************************************
 * Author: Sunil Kumar Yadav
 * Date: 23 June 2021
 * Problem: Drill exercice of chapter 15.Graphing Function and Data
 *
 *
 * ****************************************/

#include"Simple_window.h"
#include"Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}

int main()
{
	Point winP{100,100};
	const int xmax=600;
	const int ymax=600;
	
	const int xlength=400;
	const int ylength=400;

	const int x_orig=xmax/2;
	const int y_orig=ymax/2;

	const int xoffset=300;
	const int yoffset=300;

	const int xspace=100;
	const int yspace=100;
	const int notch_size= xlength/20;
	
	const int rmin=-10;
	const int rmax=11;
	
	const int no_points=400;
	const int x_scale=20;
	const int y_scale=20;

	Point orig{x_orig,y_orig};

	Simple_window win{winP,xmax,ymax,"Function Graph"};

	Axis x{Axis::x, Point{xspace, y_orig}, xlength, notch_size, "1==20 pixel"};
	Axis y{Axis::y, Point{x_orig,yspace+ylength}, ylength, notch_size, "1==20 pixel"};

	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);


	Function s1{one,rmin, rmax, orig, no_points,x_scale, y_scale};
	Text t1{Point{xspace,y_orig-20},"one"};
	
	win.attach(s1);
	win.attach(t1);


	Function s2{square, rmin, rmax, orig, no_points, x_scale, y_scale};
	win.attach(s2);
	
	win.wait_for_button();
	//not implementing other function as already done in simple_graph.cpp

}



