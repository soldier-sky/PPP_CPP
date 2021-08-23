/**********************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 2 July 2021
* Description: 3. Place an Image on top of a Button; move both when the button is pushed. 
* Use this random number generator from std_lib_facilities.h to pick a new location 
* for the “image button”:
* 
* #include<random>
* inline int rand_int(int min, int max){
* static default_random_engine ran;
* return uniform_int_distribution<>{min,max}(ran);}
*
* Attempt 1: Incomplete. Not able to display image in My_window
* Attempt 2: Deriving new class to use img directly
**********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"
#include<random>

inline int rand_int(int min, int max)
{
	static default_random_engine ran;
	return uniform_int_distribution<>{min,max}(ran);
}

namespace Graph_lib
{

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------

struct Img_window:My_window
{

public:
	Img_window(Point xy, int ww, int hh, const string& path);
	static void cb_img(Address, Address pw);
	void img_action();
	void update_button_pos();
private:
	Point p;
	Button img_button;
	Image img; //{Point{100,100},"image.jpg"};   //400*212 pixel jpg
	int img_mask_w=80;
	int img_mask_h=50;
};

Img_window::Img_window(Point xy, int ww, int hh, const string& path)
       :My_window{xy, ww, hh, "image window"},
       p{xy}, 
       img_button{p, 85, 55,"image",cb_img},
       img{Point{p.x+2, p.y+2},path}
{
	attach(img_button);
	attach(img);
	img.set_mask(p, img_mask_w, img_mask_h); // offset added to visulalize button	
}

void Img_window::cb_img(Address, Address pw)
{
	reference_to<Img_window>(pw).img_action();
}

void Img_window::img_action()
{
	cout<<"Pressed img button\n";
	update_button_pos(); 
	
	
}

void Img_window::update_button_pos()
{

	int xmax=x_max()-100;
	int ymax=y_max()-100;
	// using button.loc to get point details which comes from parent class widget
	int original_x = img_button.loc.x;
	int original_y = img_button.loc.y;
	
	int new_x=rand_int(0,xmax) - original_x;
	int new_y=rand_int(20,ymax) - original_y;
	cout<<"Point :"<< new_x<< ','<< new_y<<'\n';
	
	// using widget::move which does hide() -> change position -> show()
	img_button.move(new_x,new_y);
	img.move(new_x,new_y);
	//img_button.show();
	//redraw();
}
//-----------------------------------------------------------------------------

}

int main()
{
	using namespace Graph_lib;
	try
	{
		Img_window win{Point{100,100}, 600,600, "image.jpg"};
		//Image img{Point{100,100},"image.jpg"};
		//win.attach(img);
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

