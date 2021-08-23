// Program to create window of size 600*400

#include"Graph.h"
#include"Simple_window.h"

int main()
{

	using namespace Graph_lib;

	Point tl{100,100};

	Simple_window win{tl,600,400,"My simple window"};

	//----
	Axis xa{Axis::x, Point{20,300}, 280,10, "x axis"}; // make an axis
	// an Axis is a kind of Shape 
	// Axis::x means horizontal starting at (20,300) and 280 pixel long 
	// 10 notches and lable x axis
	
	win.attach(xa); //attache to the window win
	win.set_label("Canvas #2");  // relable window


	//----
	Axis ya{Axis::y, Point{20,300}, 280, 10, "Y axis"};
	ya.set_color(Color::cyan);
	ya.label.set_color(Color::dark_red);


	win.attach(ya);
	win.set_label("Canvas #3");
	
	
	Function sine{sin,0,100,Point{20,150},1000,50,50};
	// plot sin() in range [0:100) with (0,0) at (20,150)
	// using 1000 points; scale x value*50, scale y value*50
	
	win.attach(sine);
	win.set_label("Canvas #4");

	//-----
	sine.set_color(Color::blue);

	Polygon poly; 
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");

	//----
	Rectangle r{Point{200,200},100,50};    // top left corner, width, height
	win.attach(r);
	win.set_label("Canvas #6");

	//-----
	r.set_fill_color(Color::yellow);   // fill color inside rectangle
	poly.set_style(Line_style(Line_style::dash,4));
	win.set_label("Canvas #7");


	//----
	Text t{Point{150,150},"Hello, graphical world!"};
	win.attach(t);

	//---
	//t.set_font(Font::times_bold);
	t.set_font_size(20);

	//----------
	Image ii{Point{100,50}, "image.jpg"};   //400*212 pixel jpg
	win.attach(ii);



	win.wait_for_button();
}
