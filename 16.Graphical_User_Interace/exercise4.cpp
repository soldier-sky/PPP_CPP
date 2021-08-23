/*******************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 3 July 2021
* Description: 16.4. Make a menu with items that make a circle, a square, an equilateral
*              triangle, and a hexagon, respectively. Make an input box (or two) for giving a
*              coordinate pair, and place the shape made by pressing a menu item at tha coordinate.
* Note: 
*********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"

namespace Graph_lib
{

//-----------------------------------------------------------------------------------
struct Triangle:Closed_polyline
{
public:
	Triangle(Point pp, int rr);
private:
	Point p;
	int r;

};

Triangle::Triangle(Point pp, int rr)
	:Closed_polyline(), p{pp}, r{rr}
{
	int x_offset=r/2;
	int y_offset=r;
	
	Closed_polyline::add(p);
	Closed_polyline::add(Point{p.x-x_offset,p.y+y_offset});
	Closed_polyline::add(Point{p.x+x_offset,p.y+y_offset});
}

//-----------------------------------------------------------------------------------
struct Shape_window: Window
{

public:
	Shape_window(Point xy, int ww, int hh, const string& title);
		
	static void cb_circle(Address, Address pw);
	static void cb_square(Address, Address pw);
	static void cb_triangle(Address, Address pw);
	enum shape_type{circle, square, triangle};
	
	void draw_shape(shape_type s);
	
protected:
	Point p;
	int r=0;
	Button button_circle;
	Button button_square;
	Button button_triangle;
	
	In_box x_box;
	In_box y_box;
	In_box size_box;
	
	Out_box out_shape_box;
	
	Vector_ref<Shape> sv;     // refernce of vector
	
};

Shape_window::Shape_window(Point xy, int ww, int hh, const string& title)
          :Window(xy,ww,hh,title),
          p{xy}, 
          button_circle{Point{x_max()-70,5},70,20,"Circle", cb_circle},
          button_square{Point{x_max()-70,25},70,20,"Square", cb_square},
          button_triangle{Point{x_max()-70,45},70,20,"Triangle", cb_triangle},
          x_box{Point{50,5},70, 20, "x pos:"},
          y_box{Point{50,25},70, 20, "y pos:"},
          size_box{Point{50,45},70, 20, "size:"},
          out_shape_box{Point{200,25},100, 20, "shape"}
{
	attach(button_circle);
	attach(button_square);
	attach(button_triangle);
	attach(x_box);
	attach(y_box);
	attach(size_box);
	attach(out_shape_box);
	
	
}


void Shape_window::cb_circle(Address, Address pw)
{
	reference_to<Shape_window>(pw).draw_shape(circle);
}

void Shape_window::cb_square(Address, Address pw)
{
	reference_to<Shape_window>(pw).draw_shape(square);
}

void Shape_window::cb_triangle(Address, Address pw)
{
	reference_to<Shape_window>(pw).draw_shape(triangle);
}


// using draw_shape() since getting size and co-ordinates become simpler
void Shape_window::draw_shape(shape_type s)
{
	Point p;
	p.x=x_box.get_int();
	p.y=y_box.get_int();
	r=size_box.get_int();
	
	ostringstream ss;
	string str;
	
	if(p.x==-999999 || p.y==-999999 || r==-999999)
	{
		cout<<"Please enter valid values"; 
		out_shape_box.put("Invalid Value");
	}
	else
	{
		switch(s)
		{
			case circle: sv.push_back(new Circle{p,r/2}); str="circle"; break;
			case square: sv.push_back(new Rectangle{p,r,r}); str="square"; break;
			case triangle: sv.push_back(new Triangle{p,r}); str="triangle";break;
		}
		ss<<"Shape type "+ str;
		out_shape_box.put(ss.str());
		
		attach(sv[sv.size()-1]);    // draw recent added shape
		redraw();
	}
	
}

}

int main()
{
	try
	{
		Shape_window win{Point{100,100}, 600,600,"Shape Window"};
		//Triangle t{Point{100,100}, 40};
		//win.attach(t);
		return gui_main();
	}
	catch(exception& e)
	{
		cerr<<"exception: "<<e.what() <<'\n';
		return 1;
	}
	catch(...)
	{
		cerr<<"Some exception\n";
		return 2;
	}
}
