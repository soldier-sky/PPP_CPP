// This program is part of exercise in chapter 13 of Programming: Principles and Practice using C++
// Date: 6-June-2021
// Author: Sunil Kumar Yadav
// Problem: Define functions n(), s(), e(), w(), center(), ne(), se(), sw(), and nw(). 
//          Each takes a Rectangle argument and returns a Point. These functions define “connection points” on and 
//          in the rectangle. For example, nw(r) is the northwest (top left) corner of a Rectangle called r.


#include"Simple_window.h"
#include"Graph.h"

namespace Graph_lib{

// Helper function centre return centre of rectangle
Point centre(const Rectangle& r)
{
	int rh=0,rl=0;
	Point p, cp;       // point p to hold rectengle point and cp holds centre point
	
	rh=r.height();	
	rl=r.width();
	p=r.point(0);    // shape.point is return 1st point left corner
	
	// Calculating centre point using top left point and l & w of rectangle
	cp.x=p.x+(rl/2);
	cp.y=p.y+(rh/2);
	return cp;
	
}

// Helper function ne() returns north east point of rectangle
Point ne(const Rectangle& r)
{

	int rh=0,rl=0;
	Point p;       
	
	rh=r.height();	   
	rl=r.width();     
	p=r.point(0);    // shape.point is return 1st point left corner
	
	return p;
	
}

// similarly define other helper function
/*
Point e(Rectangle r);
Point w(Rectangle r);
Point s(Rectangle r);
Point ne(Rectangle r);
Point se(Rectangle r);
Point nw(Rectangle r);
Point sw(Rectangle r);
*/

};

int main()
{
	using namespace Graph_lib;
	
	Point wp{100,100};
	Simple_window win{wp, 800,800, "Window"};
	
	Point rp{100,100};   // rectangle point
	Rectangle r{rp, 200,100};


	win.attach(r);
	
	Point cp{0,0}, nep{0,0};            // centre and ne point initalized to default
	cp=centre(r); 
	nep=ne(r);                
	cout<<"Centre point is: ("<<cp.x<< ", "<<cp.y<<")\n";
	cout<<"NE point is: ("<<nep.x<< " "<<nep.y<<")\n";

	win.wait_for_button();
}













