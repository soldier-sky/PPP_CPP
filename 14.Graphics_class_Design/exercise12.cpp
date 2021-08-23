/************************************************
* Exercise 12 Chapter 14.Graphics Class Design
* Author: Sunil Kumar Yadav
* Date: 18 June 2021
* Problem: Modify Binary_tree to draw its nodes using a virtual function. Then, derive a new class from Binary_tree that
* overrides that virtual function to use a different representation for a node (e.g., a triangle).,
*
************************************************/

#include"Simple_window.h"
#include"Graph.h"
#include"math.h"

namespace Graph_lib
{

// overloading addition to add two point
Point operator+(Point p1, Point p2)
{
	return Point{p1.x+p2.x, p1.y+p2.y};
}

class Binary_tree: public Shape
{
public:
	Binary_tree(Point pp, int level):p{pp}, levels{level}
	{
		
		
		r=10;    
		ndist=40; 
		ldist=30; 
		if(levels>0)
		{ 
			add(p);             // point(0) =: root node; using shape::add to create vector of point
			create_points(levels);  
		} 
	}
	
	void create_points(int level);       // hold points to draw node and child circles
	virtual void draw_lines() const;
	int no_of_nodes(int level);	      // returns no. of nodes at particular level
	int parent_node(int node_no) const;	      // returns parent node for a given node

private:
	Point p;
	int levels;        	   // no of levels in tree
	int r;            	   // radius of node circles
	int ndist;                // distance between two nodes in a level 
	int ldist;       	   //distance between two level

};

void Binary_tree::create_points(int level)                //incomplete       
{
	Point lp{0,0}, rp{0,0};        // left and right node point
	int nn=1;                      // no. nodes 
	int hd=ndist*10, vd=ldist*10;  // horizontal and vertical offset 
	int n=1;			// no. of child node counter
	int parent;//=parent_node(n);
	for(int i=1; i< levels;i++)
	{
	        
	              
	    nn=nn*2;                   // each lower level have twice node as earlier
	    
	    for(int j=0; j<nn ;++j)
	    {
	    	
	    	
	    	n=number_of_points();        // getting no. of total child so far in vector of point  
	    	parent=parent_node(n);       // finding parent node for given point

	    	// adding 2 child per parent nodes of level 
	    	if(j%2!=0)
	    	{
	    		lp=Point{point(parent).x + hd/2, point(parent).y+vd};
	    		add(lp);           	// using shape::add to create vector of point
	    	}
	    	else 
	    	{
	    		rp=Point{point(parent).x - hd/2, point(parent).y+vd};
	    		add(rp); 
	    	}
		
	    }
	    hd=hd/2;           // decreasing horizontal and vertical distance between nodes and level
	    vd=vd/2;           // for better visualization
	
	}
	
	
}


int Binary_tree::no_of_nodes(int level)
{	
	int no_node=1;
	for(int i=0;i<level;i++)
		no_node*=2;
	return no_node;
}

int Binary_tree::parent_node(int node_no) const
{
	int parent_node;
	
	if(node_no==0 )
		return 0; // no parent for root
	
	parent_node=(node_no-1)/2;
		
	return parent_node;
}

void Binary_tree:: draw_lines() const
{
	for(int i=0;i< number_of_points();i++)
	{
		if (color().visibility())
		{
        		fl_arc(point(i).x, point(i).y,r+r,r+r,0,360);      // using fl_arc directly to draw circle
        								     // instead of Circle 
        		
        	}
        	
        }
      
        // Drawing connecting lines from child to parent
        int parent;
        for(int child=number_of_points()-1; child>0; child--)
        {	
        	parent=parent_node(child);
        	fl_line(point(child).x+r ,point(child).y+r, point(parent).x+r,point(parent).y+r);  // r is offset for centre
        	#ifdef DEBUG
        		cout<<"(Child, Parent) : ("<<child <<","<<parent<<")\n";
        	#endif
        }
        
}

// Class draws binary tree
class Binary_tree_triangle: public Binary_tree
{
public:
	Binary_tree_triangle(Point pp, int level):Binary_tree(pp,level), p{pp}, levels{level}
	{
		// Binary_tree will handle creation of points etc
		t_size=10;
	}
	void draw_lines() const;
	void draw_triangle(Point P,int size) const;   // node will represented by triangle
private:
	Point p;
	int levels;
	int t_size;
	
};

void Binary_tree_triangle::draw_triangle(Point p,int s) const
{
	fl_line(p.x, p.y-s, p.x-s, p.y+s);         // left arm 
	fl_line(p.x, p.y-s, p.x+s, p.y+s);         // righ arm 
	fl_line(p.x-s, p.y+s, p.x+s, p.y+s);       // bottom arm 
}

void Binary_tree_triangle::draw_lines() const
{
	for(int i=0;i< number_of_points();i++)
	{
		if (color().visibility())
		{
         		draw_triangle(point(i), t_size);
        		
        	}
        	
        }
      
        // Drawing connecting lines from child to parent
        int parent;
        for(int child=number_of_points()-1; child>0; child--)
        {	
        	parent=parent_node(child);
        	fl_line(point(child).x ,point(child).y, point(parent).x,point(parent).y);  // r is offset for centre
        	#ifdef DEBUG
        		cout<<"(Child, Parent) : ("<<child <<","<<parent<<")\n";
        	#endif
        }
}

};

int main()
{
	using namespace Graph_lib;
	
	Simple_window win{Point{100,100}, 1000,1000, "Binary Tree"};
	
	Binary_tree_triangle bt{Point{500,100},5};
	
	#ifdef DEBUG
	for(int i=0;i<bt.number_of_points()-1;++i)
		cout<<"position of "<<i<<" i("<< bt.point(i).x <<", "<<bt.point(i).y<<")"<<endl;
	#endif
	
	win.attach(bt);
	win.wait_for_button();
	
}












