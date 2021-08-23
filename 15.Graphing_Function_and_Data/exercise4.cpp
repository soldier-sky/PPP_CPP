/***********************************
* Chapter: 15. Graphing Functions and Data
* Author: Sunil Kumar Yadav
* Date: 23 June 2021
* Problem: Graph a sine (sin()), a cosine (cos()), the sum of those (sin(x)+cos(x)), and the sum of the squares of those
*	   (sin(x)*sin(x)+cos(x)*cos(x)) on a single graph. Do provide axes and labels.
*
*
*************************************/
#include"Simple_window.h"
#include"Graph.h"
#include<cmath>

double sine(double x){return sin(x);}
double cosine(double x){return cos(x);}
double cosine_sine(double x) {return sin(x)+cos(x);}

int main()
{
	Point wp{100,100};
	
	const int xmax=600, ymax=600;
	const int xspace=100, yspace=100;
	const int x_orig=xmax/2, y_orig=ymax/2;
	const int xlength=400, ylength=400;
	const int notch_size=xlength/20;
	
	Point orig{x_orig,y_orig};      // centre as point for axis
	
	
	Simple_window win{wp,xmax,ymax,"Exercise 4"};
	
	Axis x{Axis::x, Point{xspace, y_orig}, xlength, notch_size, "1==20 pixel"};
	Axis y{Axis::y, Point{x_orig,yspace+ylength}, ylength, notch_size, "1==20 pixel"};
	
	Text label_x{Point{xspace-50, y_orig}, "x-axis"};
	Text label_y{Point{x_orig, yspace+ylength+20}, "y-axis"};
	
	win.attach(x);
	win.attach(y);
	
	win.attach(label_x);
	win.attach(label_y);
		
	const int rmin=-10, rmax=11;
	const int count=400;
	const int xscale=20, yscale=25;
	
	Function f1{sine,rmin, rmax, orig, count, xscale, yscale};
	Function f2{cosine,rmin, rmax, orig, count, xscale, yscale};
	Function f3{cosine_sine,rmin, rmax, orig, count, xscale, yscale};
	
	f1.set_color(Color::red);
	f2.set_color(Color::blue);
	
	
	win.attach(f1);
	win.attach(f2);
	win.attach(f3);
	
	win.wait_for_button();
}


