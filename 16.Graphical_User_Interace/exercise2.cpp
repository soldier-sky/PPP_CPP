/**************************************************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 2 July 2021
* Description: 2. Make a window (based on My_window) with a 4-by-4 checkerboard of square
* buttons. When pressed, a button performs a simple action, such as printing 
* its coordinates in an output box, or turns a slightly different color 
* (until another button is pressed).
*
***************************************************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"

namespace Graph_lib
{

struct My_window: Window
{
public:
	My_window(Point xy, int ww, int hh, const string& title);
	static void cb_next(Address, Address pw);
	static void cb_quit(Address, Address pw);
	void next(){ cout<<"Pressed next button\n";}
	void quit(){ hide();} //FLTK lib call hide() to close GUI
	
	static void cb_button_1(Address, Address pw);
	static void cb_button_2(Address, Address pw);
	static void cb_button_3(Address, Address pw);
	static void cb_button_4(Address, Address pw);
	
	void action_1(){ op_box.put("Button 1"); }
	void action_2(){ op_box.put("Button 2");}
	void action_3(){ op_box.put("Button 3");}
	void action_4(){ op_box.put("Button 4");}
	
private:
	Button next_button;
	Button quit_button;
	
	Button button_1;
	Button button_2;
	Button button_3;
	Button button_4;
	
	Out_box op_box;   // to display position 
};

My_window::My_window(Point xy, int ww, int hh, const string& title)
	:Window{xy, ww, hh, title},
	next_button{Point{x_max()-140,0}, 70, 20,"next",cb_next},
	quit_button{Point{x_max()-70,0}, 70, 20,"quit",cb_quit},
	button_1{Point{x_max()/2-70, y_max()/2-70}, 70, 20,"action 1",cb_button_1},
	button_2{Point{x_max()/2+70, y_max()/2-70}, 70, 20,"action 2",cb_button_2},
	button_3{Point{x_max()/2-70, y_max()/2+70}, 70, 20,"action 3",cb_button_3},
	button_4{Point{x_max()/2+70, y_max()/2+70}, 70, 20,"action 4",cb_button_4},
	op_box{Point{150,0}, 100,20, "Button pressed"}
{	
	attach(next_button);
	attach(quit_button);
	
	attach(button_1);
	attach(button_2);
	attach(button_3);
	attach(button_4);
	
	attach(op_box);
}

void My_window::cb_next(Address, Address pw)
{
	reference_to<My_window>(pw).next();
}

void My_window::cb_quit(Address, Address pw)
{
	reference_to<My_window>(pw).quit();
}

void My_window::cb_button_1(Address, Address pw)
{
	reference_to<My_window>(pw).action_1();
}

void My_window::cb_button_2(Address, Address pw)
{
	reference_to<My_window>(pw).action_2();
}

void My_window::cb_button_3(Address, Address pw)
{
	reference_to<My_window>(pw).action_3();
}

void My_window::cb_button_4(Address, Address pw)
{
	reference_to<My_window>(pw).action_4();
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

