// This source file is for working with drill of chapter 12.

#include"Simple_window.h"
#include"Graph.h"

int main()
{

	using namespace Graph_lib;

	//Drill 1: create simple window of 800*1000
	Simple_window win{Point{100,100},800,1000, "Drill Window"};
	
	// Drill 2: print 8*8 grid 
	int x_size=win.x_max();          // or directly add 800 as per exercise
	int y_size=win.y_max() - 200;   // as we are drawing 800*800 grid
	
	int x_space=100;
	int y_space=100;
	Lines grid;
       //Lines y_grid;  // no need to have two lines for x and y grid

	for(int x=x_space; x<x_size; x+=x_space)
		grid.add(Point{x,0}, Point{x,y_size});

	for(int y=y_space; y<y_size; y+=y_space)
		grid.add(Point{0,y}, Point{x_size,y});
	
	win.attach(grid);
	// Drill 3: Make 8 squares on the diagnoal from top left with red color
	
	/*  Somehow ending up with compielr error if we use this approch
       	vector<Rectangle> rv;                    // vector to strore square(8)
	int cs=100;                             // size of square side
	for(int r=0; r<8; r++)
	{
		Rectangle temp{Point{r*cs,r*cs},100,100};	  // Creating rectangle of 100*100
		rv.push_back(temp);
	}
	for(int i=0;i<rv.size();++i)
		win.attach(rv[i]);
	*/
       // independent rectangles
       Rectangle r1{Point{0,0},100,100};
       Rectangle r2{Point{100,100},100,100};
       Rectangle r3{Point{200,200},100,100};
       Rectangle r4{Point{300,300},100,100};
       Rectangle r5{Point{400,400},100,100};
       Rectangle r6{Point{500,500},100,100};
       Rectangle r7{Point{600,600},100,100};

       r1.set_color(Color::red);
       r2.set_color(Color::green);
       r3.set_fill_color(Color::yellow);
       r4.set_color(Color::blue);
       r5.set_color(Color::red);
       r6.set_color(Color::red);
       r7.set_color(Color::red);

      
       win.attach(r1);       
       win.attach(r2);       
       win.attach(r3);       
       win.attach(r4);       
       win.attach(r5);       
       win.attach(r6);       
       win.attach(r7);       

	Image im{Point{0,0},"/home/sky/working_dir/CPPCON/excercise/12.A_Display_model/image.jpg"};       
	im.set_mask(Point{000,000},400,400);    //masking out image
	win.attach(im);
       win.wait_for_button();
}
