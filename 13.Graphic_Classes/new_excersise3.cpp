// This program is to create Arrow class which draws graphic shape of arrow
// as part of chapter 13.3 execerise: Define a class Arrow, which draws a line with an arrowhead.
// Author: Sunil Kumar Yadav

#include"Simple_window.h"
#include"Graph.h"
//#include"../std_lib_facilities.h"

namespace Graph_lib{

enum class dir{
	N=1,
	E,
	W,
	S,
	NE,
	NW,
	SE,
	SW
};

// Class Arrow to draws arrow
class Arrow: public Shape{
public:
	Arrow()
	{
		m_p=Point{0,0};
		m_len=0;
		m_size=0;
		m_dir=dir::E;
	}
	Arrow(Point p, int len, int size, dir d);       // point p with lenght len with size 
							  // as size of arrow head
	int get_length() const { return m_len; }
	void draw_lines() const;
	void make_arrow(dir d);
private:
	Point m_p;		   // origin point of arrow
	int m_len;		   // length of arrow body
	int  m_size;		   // size of arrow head
	Lines m_l;		   // Line ie. body of arrow
	dir m_dir;                // direction of arrow 

};

Arrow::Arrow(Point p, int len, int size, dir d):
	m_p{p}, m_len{len}, m_size{size}, m_dir{d}
{

	make_arrow(m_dir);    // calling make_arrow
	// perform other checks if required
}

void Arrow::make_arrow(dir d)
{
	Point p2;        // second point of line
            
        Point phu;       // arrow head point up
        Point phl;       // arrow heaad lower
 	
	switch(d)        //constructor should check if lenth is correct or not
	{
		case dir::S :
			p2=Point{m_p.x, m_p.y+m_len};
			phu=Point{p2.x-m_size, p2.y-m_size};       
        		phl=Point{p2.x+m_size, p2.y-m_size};
			break;
			
		case dir::E :
			p2=Point{m_p.x+m_len, m_p.y};
			phu=Point{p2.x-m_size, p2.y-m_size};       
        		phl=Point{p2.x-m_size, p2.y+m_size}; 
			break;
			
		case dir::N :
			p2=Point{m_p.x, m_p.y-m_len};
			phu=Point{p2.x-m_size, p2.y+m_size};       
        		phl=Point{p2.x+m_size, p2.y+m_size};
			break;
			
		case dir::W :
			p2=Point{m_p.x-m_len, m_p.y};
			phu=Point{p2.x+m_size, p2.y-m_size};       
        		phl=Point{p2.x+m_size, p2.y+m_size}; 
			break;


	}


        m_l.add(m_p, p2);                          // main axis of arrow
        m_l.add(p2, phu);			     // adding upper part of arrow head 
        m_l.add(p2, phl);			     // adding lower part of arrow head 

}

void Arrow::draw_lines()const{
	if (color().visibility())
	{
		m_l.draw_lines();
	}
}

};

int main()
{
	using namespace Graph_lib;
	
	Point wp=Point{100,100};
	int wl=600,ww=400;
	Simple_window win{wp,wl,ww,"Arrow"};

	Point ap=Point{200,200};
	int len=100,size=5;
	Arrow N(ap,len,size, dir::N);
	Arrow E(ap,len,size, dir::E);
	Arrow W(ap,len,size, dir::W);
	Arrow S(ap,len,size, dir::S);	
	
	S.set_color(Color::red);

	win.attach(N);
	win.attach(E);
	win.attach(W);
	win.attach(S);
	
	win.wait_for_button();
}






