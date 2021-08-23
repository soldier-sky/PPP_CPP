#include"Graph.h"
#include"Simple_window.h"

int main()
{
	using namespace Graph_lib;

	Point lt{100,100};

	Simple_window win{lt,600,600,"12.Exercise" };

	Polygon rect;  // rectangle as polygon
	rect.add(Point{200,200});
	rect.add(Point{400,200});
	rect.add(Point{400,300});
	rect.add(Point{200,300});
	
	rect.set_color(Color::red);

	win.attach(rect);

	Rectangle r{Point{350, 410}, 100,60}; // Rectangle with lenght, width
	r.set_color(Color::blue);

	win.attach(r);

	// excersise 2
	Text t1{Point{380,430},"Howdy!!"};
	win.attach(t1);


	// excersise 3
	Text t2{Point{200,300},"Sunil"};
	t2.set_font_size(150);
	win.attach(t2);

	win.wait_for_button();

}



