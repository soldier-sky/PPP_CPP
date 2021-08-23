// Exercise 5 Chapter 14.Graphics Class Design
// Author: Sunil Kumar Yadav
// Date: 12 March 2021
// Problem: Define a Striped_rectangle where instead of fill, the rectangle is “filled” by drawing one-pixel-wide horizontal lines
//across the inside of the rectangle (say, draw every second line like that). You may have to play with the width of lines and the line spacing to get a pattern you like.

#include"Simple_window.h"
#include"Graph.h"

namespace Graph_lib
{

// overloading addition to add two point
Point operator+(Point p1, Point p2)
{
	return Point{p1.x+p2.x, p1.y+p2.y};
}

class Striped_rectangle: public Rectangle
{

public:
	Striped_rectangle(Point pp, int ll, int ww)
			:Rectangle(pp,ll,ww), p{pp}, l{ll}, w{ww}
	{
		
		fill_lines();  // constructing lines with strip
	}

	void draw_lines() const;
	void fill_lines()
	{
		for(int i=2; i<w-1; i=i+2)
	        {
               		 hl.add(Point{p.x, p.y+i}, Point{p.x+l,p.y+i});
       		}

	}
	void set_fill_style(Line_style style)
	{
		hl.set_style(style);
	}
private:
	Point p;
	int l, w;   // lenght and width of rectangle
	Lines hl;   // lines uses to fill rect
};

void Striped_rectangle::draw_lines() const
{
	Rectangle::draw_lines();  
	// generating  horizontal stripes inside rectngle
	hl.draw_lines();
}

class Striped_circle: public Circle
{
public:
	Striped_circle(Point pp, int rr):Circle(pp,rr), p{pp}, r{rr}
	{
		
		fill_lines();
	}	
		
	void fill_lines()
	{
		
       	for (int i = -r;i < r; i += 5)                    // i:=0-r half i.e. handle only lower half of horizontal strip
       	{
			int x = sqrt(pow(r, 2) - pow(i, 2));     // equation of circle with cetre (h,k): (x-h)^2 + (y-k)^2 =r^2
								  // Since r is known, find x on circle arc (as i is used as y)
			Point pt{x, i};
			hl.add(pt + p, Point{-pt.x, pt.y} + p);    // adding line right to left
		}
       	
       	
	}
	void set_fill_style(Line_style style)
	{
		hl.set_style(style);
	}
	
	void draw_lines() const;
private:
	Point p;      // top left start point
	int r;        // radius of circle
	Lines hl;      // lines uses to fill circle

};

void Striped_circle::draw_lines() const
{
	Circle::draw_lines();
	hl.draw_lines();
}


};


int main()
{
	using namespace Graph_lib;

	Simple_window win{Point{200,200}, 500,500,"Srtriped Rectangle"};
	
	Striped_rectangle sr{Point{100,100}, 200,300};
	//sr.set_fill_style(Line_style::dash);
	
	Striped_circle sc(Point{300,300},100);
	sc.set_fill_style(Line_style::dash);
	//win.attach(sr);
	win.attach(sc);
	win.wait_for_button();


}


