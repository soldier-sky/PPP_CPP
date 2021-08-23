/*******************************************
* Author: Sunil Kumar Yadav
* Date: 22June2021
* Note: This program draws exponential function interactively
*        e**x =1 + x + x**2/2! + x**3/3! + x**4/4! + . . .
*	exp0(x) = 0         // no terms
*	exp1(x) = 1         // one term
*	exp2(x) = 1+x       // two terms; 
*	pow(x,1)/fac(1)==x
*	exp3(x) = 1+x+pow(x,2)/fac(2)
*	exp4(x) = 1+x+pow(x,2)/fac(2)+pow(x,3)/fac(3)
*	exp5(x) = 1+x+pow(x,2)/fac(2)+pow(x,3)/fac(3)+pow(x,4)/fac(4)
**********************************************/

#include"Simple_window.h"
#include"Graph.h"


// factorial(n); n!
double fact(double n)      
{
	double r=1;
	while(n>1)
	{
		r*=n;
		--n;
	}
	
	return r;
}

double term(double x, int n)
{
	return pow(x,n)/fact(n);   // nth term of series
}

double expe(double x, int n)    // sum of n terms of x
{
	double sum=0;
	for(int i=0;i<n;i++)
		sum+=term(x,i);
		
	return sum;

}

int main()
{
	using namespace Graph_lib;
	
	constexpr int xmax = 600;    		 // window size
	constexpr int ymax = 400;
	
	constexpr int x_orig = xmax/2;  	// position of (0,0) is center of window

	constexpr int y_orig = ymax/2;
	constexpr Point orig {x_orig,y_orig};
	constexpr int r_min=-10;
	constexpr int r_max=11; 		// range [–10:11)
	constexpr int n_points=400; 	// number of points used in range
	constexpr int x_scale=30; 		// scaling factors 
	constexpr int y_scale=30;
	
	
	Simple_window win{Point{100,100}, xmax,ymax,"exp approximation"};
	cout<<"Press button 'Next' in order to draw other exp approximation";
	
	// since Function requires function with one input,
	// we are using lambda function
	for(int n=0; n<50; ++n)
	{
		ostringstream ss;
		ss<<"exp approximation; n=="<<n;
		win.set_label(ss.str());
		//get next approximation:
		Function e{[n](double x){return expe(x,n);},
			   r_min, r_max, orig, 50, x_scale, y_scale};
		
		win.attach(e);
		win.wait_for_button();
		win.detach(e);         // each time we loop e's scope end and to avoid 
		                       // win to refer out of scope variable, we are detaching
	}
		
}

