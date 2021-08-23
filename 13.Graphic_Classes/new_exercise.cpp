// Exercise program to draw arc: chapter 13. Graphic Classes
// Author: Sunil Kumar Yadav
// Ex1. Define a class Arc, which draws a part of an ellipse. Hint: fl_arc().
// Ex2. Drawa box with rounded corner. Define a class Box, consisting of four lines and four arcs.

#include"Simple_window.h"
#include"Graph.h"

namespace Graph_lib{

class Arc:public Shape{

public:
	Arc(){  //default constructor
		m_p=Point{0,0};
		m_r=0;
		m_start=m_end=0;
	}  
	
	Arc(Point p, int r, double start, double end):
		m_p{p}, m_r{r}, m_start{start}, m_end{end}
	{
		add(Point{m_p.x-m_r, m_p.y-m_r});  // storing top left corner 
						   // using as refernce from Circle
	}

	void draw_lines()const {

		if(color().visibility())
			fl_arc(m_p.x,m_p.y, m_r+ m_r, m_r+m_r, m_start, m_end);
	}
	Point get_centre() const { return m_p;}
	double get_start_angle() const { return m_start;}
	double get_end_angle() const { return m_end;}
	void add_point(Point p) { m_p=p;}
	void add_radius(int r) {m_r=r;}
	void add_angles(double s, double e) { m_start=s; m_end=e;}


private:
	Point m_p;
	int m_r;             // arc radius
       			     // encosing rectangle width and height r+r
	double m_start, m_end;   // start and end angle. 0 => 3 O clock

};

// Helper function which over loads arithmatic on point
inline Point operator-(Point P, int i)
{
	return (Point{P.x-i, P.y-i});
}

inline Point operator+(Point P, int i)
{
	return (Point{P.x+i, P.y+i});
}



// Defining Box to draw rounded box consisting of 4 lines with 4 arc
// considering 4 arc as small 90 degree for four sides
class Box: public Shape{

public:
	Box(Point p, int length, int width):
		m_p{p}, m_l{length}, m_w{width}
	{	
		r=10;
		generate_lines();              //generate points of 4 lines of box and 4 arcs
	}	
	int get_length() const { return m_l;}
	int get_width() const { return m_w;}
	void draw_lines() const;
	void generate_lines(); 
private:
	Point m_p;
	int m_l, m_w;                          // length and width of box
	int r;                                 // corner arc radius. 	
	Lines lv,lh;                           // Lines holding 4 sides of box
        Point P1,P2,P3,P4;                     // Points which holds 2 verticle and 2 horizontal lines
	Arc A1, A2, A3, A4;                    // Arc for each corner
};



void Box::draw_lines() const
{

	// Using Lines::draw_line() and Arc::draw_lines() 

	lh.draw_lines();
	lv.draw_lines();
	// drawing 4 corner's arc
	A1.draw_lines();
	A2.draw_lines();
	A3.draw_lines();
	A4.draw_lines();

}


void Box::generate_lines() 
{
	    
		int x1,y1;    // holds top left corner point
		x1=m_p.x;
		y1=m_p.y;

		// Point P*1 start from top left corner then move clock wise to P2, P3, P4
		P1=Point{x1,y1};
		P2=Point{x1+m_l,y1};
		P3=Point{x1+m_l,y1+ m_w};
		P4=Point{x1,y1+m_w};

		// Creating horizontal lines with size "length - 2*r"
		lh.add(Point{P1.x+r,P1.y}, Point{P2.x-r,P2.y});
		lh.add(Point{P4.x+r,P4.y}, Point{P3.x-r,P3.y});
		
		// Creating vertical lines with size "length - 2*r"
		lv.add(Point{P1.x,P1.y+r}, Point{P4.x,P4.y-r});
		lv.add(Point{P2.x,P2.y+r}, Point{P3.x,P3.y-r});
		
		
		

		// Creating required arcs
		A1.add_point(P1);
		A1.add_radius(r);
		A1.add_angles(90,180);
		
		A2.add_point(Point{P2.x-2*r, P2.y});        // adjusting points to fit arc 
		A2.add_radius(r);
		A2.add_angles(0,90);
		A2.set_color(Color::green);
		
		A3.add_point(Point{P3.x-2*r, P3.y-2*r});    // adjusting points to fit arc 
		A3.add_radius(r);
		A3.add_angles(270,360);
		
		A4.add_point(Point{P4.x, P4.y-2*r});        // adjusting points to fit arc 
		A4.add_radius(r);
		A4.add_angles(180,270);
}

};  //end of Graph_lib namespace


int main(){

	using namespace Graph_lib;
	
	Simple_window win{Point{100,100}, 600,600, "Arc"};

	Point p{200,200};
	int r=50;  //radius
	double s_angle=0, e_angle=90; // start and end angle

	Arc a{p, r, s_angle, e_angle};
	a.set_color(Color::blue);
	win.attach(a);

	// Drawing box with corner
	Point bp{100,100};
	Box b{bp, 400,300};
	b.set_color(Color::red);
	win.attach(b);
	

	win.wait_for_button();

}




