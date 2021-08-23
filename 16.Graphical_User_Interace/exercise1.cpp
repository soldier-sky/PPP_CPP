/**********************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 2 July 2021
* Description: 1. Make a My_window that’s a bit like Simple_window except that 
*              it has two buttons, next and quit.
*
*
*
**********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"

namespace Graph_lib
{
// My_window is Simple_Window with quit and next button
struct My_window: Window
{
public:
	My_window(Point xy, int ww, int hh, const string& title);
	static void cb_next(Address, Address pw);
	static void cb_quit(Address, Address pw);
	void next(){ cout<<"Pressed next button\n";}
	void quit(){ hide();} //FLTK lib call hide() to close GUI
private:
	Button next_button;
	Button quit_button;

};

My_window::My_window(Point xy, int ww, int hh, const string& title)
	:Window{xy, ww, hh, title},
	next_button{Point{x_max()-140,0}, 70, 20,"next",cb_next},
	quit_button{Point{x_max()-70,0}, 70, 20,"quit",cb_quit}
{	
	attach(next_button);
	attach(quit_button);
}

void My_window::cb_next(Address, Address pw)
{
	reference_to<My_window>(pw).next();
}

void My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

}

int main()
{
	using namespace Graph_lib;
	try
	{
		My_window win{Point{100,100}, 600,600, "My Window"};
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

