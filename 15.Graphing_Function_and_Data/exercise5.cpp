/*******************************************
* Chapter: 15. Graphing Functions and Data
* Author: Sunil Kumar Yadav
* Date: 26 June 2021
* Note: This program draws “Animate” (as in §15.5) the series 1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11+ . . . .
*       It is known as Leibniz’s series and converges to pi/4
*
* Issue: Incomplete and need correction to plot correct graph
*	
**********************************************/

#include"Simple_window.h"
#include"Graph.h"

double one_div(double x){ return 1/x;}

double leibniz_series(double x)
{	
	double sum=0;
	//int j=1
	for(int i=1,j=1 ; j<=x; i++)
	{
		if(i%2!=0)
			sum+=one_div(j);
		else
			sum-=one_div(j);
		j=j+2;
	}
	return sum;
}

int main()
{
		
	constexpr int xmax = 600;    		 // window size
	constexpr int ymax = 600;
	
	constexpr int x_orig = xmax/2;  	// position of (0,0) is center of window
	constexpr int y_orig = ymax/2;
	
	constexpr int xspace=100;
	constexpr int yspace=100;
	
	constexpr int xlength=200;
	constexpr int ylength=200;
	
	constexpr int notch_size=xlength/20;
	
	constexpr Point orig {x_orig,y_orig};
	constexpr int r_min=-10;
	constexpr int r_max=11; 		// range [–10:11)
	constexpr int n_points=400; 	// number of points used in range
	constexpr int x_scale=10; 		// scaling factors 
	constexpr int y_scale=10;
	
	Simple_window win{orig, xmax,ymax, "Leibniz's series"};
	cout<<"Press button 'Next' in order to draw other exp approximation";
	
	Axis x{Axis::x, Point{xspace, y_orig}, xlength, notch_size, "1==20 pixel"};
	Axis y{Axis::y, Point{x_orig,yspace+ylength}, ylength, notch_size, "1==20 pixel"};
	
	win.attach(x);
	win.attach(y);
	
	for(int n=0; n<50; ++n)
	{
		ostringstream ss;
		ss<<"Leibniz's series approximation; n=="<<n;
		win.set_label(ss.str());
		
		cout<< leibniz_series(n)<<endl;
		//Function e{[n](double x){return leibniz_series(n);},
			  // r_min, r_max, orig, 50, x_scale, y_scale};
		Function e{leibniz_series,r_min, r_max, orig, n_points, x_scale, y_scale};
		win.attach(e);
		win.wait_for_button();
		win.detach(e);         // each time we loop e's scope end and to avoid 
		                       // win to refer out of scope variable, we are detaching
	}
	
	
	
	win.wait_for_button();
}
