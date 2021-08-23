// Program to draw arc using shape lib and fl_arc() function call
// Not working. Refer new_exercise.cpp
#include"Simple_window.h"
#include"Graph.h"
namespace Graph_lib
{
class Arc: public Shape  
{
	public:
	Arc(Point c, double r, double start, double end ):
		centre{c}, radius{r}, a_start{start}, a_end{end}
	{	
		if(a_start <0 || a_end >360)
			error("invalid angles");
		fl_arc(centre.x, centre.y, radius, a_start,a_end);  // draws arc
	}

	void draw_arc(void)
	{	
		if (color().visibility())
		      fl_arc(centre.x, centre.y, radius, a_start,a_end);  // draws arc
	}
	
	double get_radius(void) { return radius;}
	
	Point get_centre(void)  { return centre;}
	private:
		double  a_start, a_end;  //angle start from 3 O clock anti clock wise
		Point centre;
		double radius;
};

};

int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{100,100}, 600,600, "Excersise chapter 13"};
	
	Arc a{Point{200,200},50, 0,180};
	//a.draw_arc();
	win.attach(a);

	win.wait_for_button();

}
