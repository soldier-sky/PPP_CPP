/*******************************************
* Chapter 16. Graphical User Interface
* Author: Sunil Kumar Yadav
* Date: 8 July 2021
* Description: 16.6. Make an “analog clock,” that is, a clock with hands that move. You get the time of day from the 
*     operating system through a library call. A major part of this exercise is to find the functions that give you the 
*     time of day and a way of waiting for a short period of time (e.g., a second for a clock tick) and to learn to
*     use them based on the documentation you found. Hint: clock(), sleep().
*
* Note:  Rotation by θ radian counterclockwise, around the origin:Formula x=ucosθ+vsinθ and y=−usinθ+vcosθ
* Issue: Contains BUG. Does not work as intended. Use of Vector_ref makes memory inflated for every time we draw.
*        Need to comeup with better approch. Refer draw_clock() method for more infomation
*********************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"GUI.h"
#include<cmath>        // for math function and M_PI
#include<ctime>        // to get system date and time
#ifdef _WIN32		// To include sleep()
#include <Windows.h>
#else
#include <unistd.h>  
#endif

namespace Graph_lib
{
//-----------------------------------------------------------------------------------
struct Analog_clock: Window
{

public:
	Analog_clock(Point xy, int ww, int hh, const string& title);
		
	static void cb_exit(Address, Address pw);
	void quit(){ hide();} //FLTK lib call hide() to close GUI
	void draw_clock();
	
protected:
	Point cp;  // centre point
	int r=100;
	Button button_exit;
	Line* hand;
	Vector_ref<Shape> s;    // hold clock dial and other item
	Vector_ref<Line> ln;    // holds hr, min, sec hands. Could have use single ref
};

Analog_clock::Analog_clock(Point xy, int ww, int hh, const string& title)
          :Window(xy,ww,hh,title),
          button_exit{Point{x_max()-70,5},70,20,"exit", cb_exit}
{

	cp= Point{x_max()/2, y_max()/2}; 
	attach(button_exit);
	
	s.push_back(new Circle{cp,r+5});    // clock's outer dial
	attach(s[s.size()-1]);

	while(1)
	{
		Fl::wait();
		sleep(1);
		draw_clock();
		Fl::redraw();
	}
}

void Analog_clock::cb_exit(Address, Address pw)
{
	reference_to<Analog_clock>(pw).quit();
}

void Analog_clock::draw_clock()
{
	int line_objects=ln.size();
	// detaching(not deleting) earlier clock's hand objects
	if(line_objects!=0)
	{
		for(int i=0; i<ln.size();++i)
			detach(ln[i]);
	
	}

	time_t now = time(0);
	tm *ltm = localtime(&now);

	int hand_offset=r/2 +5;
	
	
		
	// Rotation of shape
	// counter clockwise x1=xcosθ+ysinθ and y1=−xsinθ+ycosθ
        // clockwise x1=xcosθ-ysinθ and y1=xsinθ+ycosθ
      
        // Hour hand
        Point original_pt1{0,-80}; //hour hand
	Point rotated_pt1;
	float hr_radian=(2*M_PI/12)*ltm->tm_hour; 
      	     	
	rotated_pt1.x=original_pt1.x*cos(hr_radian) - original_pt1.y*sin(hr_radian);
	rotated_pt1.y=original_pt1.x*sin(hr_radian)+ original_pt1.y*cos(hr_radian);
	
	ln.push_back(new Line{cp, Point{cp.x+rotated_pt1.x, cp.y+rotated_pt1.y}});
	attach(ln[ln.size()-1]);

	// Minute hand
	Point original_pt2{0,-90}; //hour hand
	Point rotated_pt2;
	float min_radian=(2*M_PI/60)*ltm->tm_min; 
      	     	
	rotated_pt2.x=original_pt2.x*cos(min_radian) - original_pt2.y*sin(min_radian);
	rotated_pt2.y=original_pt2.x*sin(min_radian)+ original_pt2.y*cos(min_radian);
	
	ln.push_back(new Line{cp, Point{cp.x+rotated_pt2.x, cp.y+rotated_pt2.y}});
	ln[ln.size()-1].set_color(Color::blue);
	attach(ln[ln.size()-1]);
	
	
		
	// Second hand
	Point original_pt3{0,-95}; //hour hand
	Point rotated_pt3;
	float sec_radian=(2*M_PI/60)*ltm->tm_sec; 
      	     	
	rotated_pt3.x=original_pt3.x*cos(sec_radian) - original_pt3.y*sin(sec_radian);
	rotated_pt3.y=original_pt3.x*sin(sec_radian)+ original_pt3.y*cos(sec_radian);
	
	ln.push_back(new Line{cp, Point{cp.x+rotated_pt3.x, cp.y+rotated_pt3.y}});
	ln[ln.size()-1].set_color(Color::red);
	attach(ln[ln.size()-1]);
	
	//cout<<"ln size: "<<ln.size()<<endl;  // each call add 3 lines into ln
}
//-----------------------------------------------------------------------------------

}

int main()
{
	try
	{
		Analog_clock win{Point{100,100}, 600,600,"Shape Window"};
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
