// Excerside 1 for chapter 14. Graphics Class Design
// Author: Sunil Kumar Yadav
// Date: 11 June 2021
// Define two classes Smiley and Frowny, which are both derived from class Circle and have two eyes and a mouth.
// Next, derive classes from Smiley and Frowny which add an appropriate hat to each.

#include"Simple_window.h"
#include"Graph.h"

namespace Graph_lib
{

// Simly class will draw circle and within circle it will have eyes and mouth
class Smiley: public Circle
{
public:
	Smiley(Point pp, int rr):Circle(pp,rr)
	{
		m_p=pp;
		m_r=rr;
		
		m_eye_size= m_r/8;
		m_mouth_size= m_r/4;
	}
	void draw_lines()const;
	Point get_leye_position() const;     // adding const as these functions will be called from              
	Point get_reye_position() const;     // draw_lines() which is const. Also we are not not using
	Point get_mouth_position() const;    // input argument and simply retrunrning new point. 
						// Still better abstraction is needed
private:
	Point m_p;
	int m_r;                                      // radius for face outline circle
	int m_eye_size;				// radius of eye circle
	int m_mouth_size;				// radius of mouth circle
	

};


void Smiley::draw_lines() const
{
	Circle contour{m_p,m_r};   // outline of face
	contour.draw_lines();     
	
	Point leye=get_leye_position();
	Point reye=get_reye_position();
	Point mp=get_mouth_position();
	
	Circle lec{leye,m_eye_size};
	Circle rec{reye,m_eye_size};
	Circle mc{mp, m_mouth_size};
	lec.draw_lines();
	rec.draw_lines();
	mc.draw_lines();
	
	
}

Point Smiley::get_leye_position() const
{
	Point lp{m_p.x-4*m_eye_size, m_p.y-m_eye_size};
	return lp;
}

Point Smiley::get_reye_position() const
{
	Point rp{m_p.x+4*m_eye_size, m_p.y-m_eye_size};
	return rp;
}

Point Smiley::get_mouth_position() const
{
	Point mp{m_p.x, m_p.y+2*m_mouth_size};
	return mp;
}


};


int main()
{
	using namespace Graph_lib;
	Simple_window win{Point{100,100},600,600,"Exercise 1"};
	
	Smiley s{Point{300,300},50};
	win.attach(s);
	
	/*Exercise 2*/ 
	// Smiley s2=s;         // copying not supported as shape::shape(const shape&)=delete;
	
	win.wait_for_button();
}

