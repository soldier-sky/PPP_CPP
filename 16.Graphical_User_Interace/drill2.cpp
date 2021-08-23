/*******************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 1 July 2021
* Description: Program to create new window allow user to
*		draw line interactivly by using additional
*		widgets.(16.7)
*********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"

namespace Graph_lib
{

struct Lines_window: Window
{
public:
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;
	Menu color_menu;
	
	static void cb_red(Address, Address);     // callback for red button
	static void cb_blue(Address, Address);    // callback for blue button
	static void cb_black(Address, Address);   // callback for black button
	
	// the actions:
	void red_pressed(){change(Color::red);}
	void blue_pressed(){change(Color::blue);}
	void black_pressed(){change(Color::black);}
	
	void change(Color c){lines.set_color(c);}
	
private:
	Button next_button;      // add (next_x, next_y) to line
	Button quit_button;
	
	In_box next_x;
	In_box next_y;
	
	Out_box xy_out;
	
	void next();
	void quit();
};

// Note: in consturctor initilizer we are using template implement our GUI windows call back part of window only
// as call back function looks like cb_function(Address, Address)
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window{xy,w,h,title},
    next_button{Point{x_max()-150,0}, 70,20, "Next Point",
         [](Address, Address pw){reference_to<Lines_window>(pw).next();}},
    quit_button{Point{x_max()-70,0}, 70,20, "Quit",
         [](Address, Address pw){reference_to<Lines_window>(pw).quit();}},
    next_x{Point{x_max()-310,0}, 50,20, "next x:"},
    next_y{Point{x_max()-210,0}, 50,20, "next y:"},
    xy_out{Point{100,0}, 100,20, "currrent (x,y):"},
    color_menu{Point{x_max()-70, 40}, 70,20, Menu::vertical, "color"}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("no Point");
	
	color_menu.attach(new Button{Point{0,0},0,0,"red",cb_red});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",cb_blue});
	color_menu.attach(new Button{Point{0,0},0,0,"black",cb_black});
	
	attach(color_menu);
	attach(lines);
}

void Lines_window::quit()
{
	hide();     // curious FLTK idiom to delete window
}


void Lines_window::next()
{
	int x=next_x.get_int();
	int y=next_y.get_int();
	
	lines.add(Point{x,y});
	
	// update current position readout:
	ostringstream ss;
	ss<<'('<<x<<','<<y<<')';
	xy_out.put(ss.str());
	
	redraw();	
}

// call back action 
void Lines_window::cb_red(Address, Address pw)
{
	reference_to<Lines_window>(pw).red_pressed();
}  

void Lines_window::cb_blue(Address, Address pw)
{
	reference_to<Lines_window>(pw).blue_pressed();
}  

void Lines_window::cb_black(Address, Address pw)
{
	reference_to<Lines_window>(pw).black_pressed();
}  

}


int main()
{
	using namespace Graph_lib;
	
	try
	{
		Lines_window win{Point{100,100}, 600,400,"lines"};
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



