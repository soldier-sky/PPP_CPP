/***********************************
* Chapter: 15. Graphing Functions and Data
* Author: Sunil Kumar Yadav
* Date: 26 June 2021
* Problem: Design and implement a bar graph class. Its basic data is a vector<double> holding N values, 
* and each value should be represented by a “bar” that is a rectangle where the height represents 
* the value.
*
* Method1: Inheriting rectangle class to create vector of rectangle. Failed
* Method2: use directly fl_rect inside draw_lines(). Need to add Text support
*
**************************************/
#include"Simple_window.h"
#include"Graph.h"

namespace Graph_lib
{

// Bar_graph class draws vertical rectangles for given values
struct Bar_graph:Shape
{
public:
	Bar_graph(Point pp, vector<double> v);
	void set_width(int w){ width=w;}
	void draw_lines() const;
	int bar_count() const { return values.size();}
	void create_bar_points();
	
private:
	Point p;
	int width=50;
	int scale=1;
	vector<double> values;  //value drives lenght of bar

	
};

Bar_graph::Bar_graph(Point pp, vector<double> v):p{pp}
{
	values=v;
	width*=scale;
		
	create_bar_points();
	
}

// Add points to shape::points using Shape::add() call
void Bar_graph::create_bar_points()
{
 	int n_bar=bar_count();
	
	Point temp_p=p;
	for(int i=0; i<=n_bar; ++i)    // i from 1 as constructor have
	{
		temp_p.x+=width;
		add(Point{temp_p.x, temp_p.y-values[i]});  
		// offseting to draw bar down -> up direction as fltk y grows downward
		
		
	}
}
void Bar_graph::draw_lines() const
{
	
	
	
	int n=values.size();
 	for(int i=0; i<n;i++)
 	{
	    if (fill_color().visibility()) 
	    {    // fill
		fl_color(fill_color().as_int());
		fl_rectf(point(i).x,point(i).y-values[i],width,values[i]);
	    }

	    if (color().visibility()) 
	    {    // lines on top of fill
		fl_color(color().as_int());
		fl_rect(point(i).x,point(i).y,width,values[i]);
	    }
	    
    	}
}


};

int main()
{
	Point winp{100,100};
	const int xmax=600;
	const int ymax=600;
	
	Simple_window win{winp, xmax, ymax, "Bar Graph"};
	Point p{200,400};
	vector<double> values{100,200,50,300,200};
	
	Bar_graph bg{p, values};
	//bg.set_color(Color::red);
	win.attach(bg);
	
	win.wait_for_button();



}
