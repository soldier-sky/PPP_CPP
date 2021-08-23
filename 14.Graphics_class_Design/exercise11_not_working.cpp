// Exercise 11 Chapter 14.Graphics Class Design
// Author: Sunil Kumar Yadav
// Date: 15 June 2021
// Problem: Define a Binary_tree class derived from Shape. Give the number of levels as a parameter (levels==0 means no
// nodes, levels==1 means one node, levels==2 means one top node with two sub-nodes, levels==3 means one top node
// with two sub-nodes each with two sub-nodes, etc.). Let a node be represented by a small circle. Connect the nodes by
// lines (as is conventional). P.S. In computer science, trees grow downward from a top node (amusingly, but logically,
// often called the root).


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
	void draw_lines() const;
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
	Point lp{0,0}, rp{0,0};       // left and right node point
	int nn=1;                     // no. nodes 
	int hd=ndist, vd=ldist;       // horizontal and vertical offset 
	int n=0;
	for(int i=1; i< levels;i++)
	{
	        
	    vd=vd+i*ldist;             // Increading vertical distance between nodes of level
	    nn=nn*2;                   // each level have twice node as earlier
	    
	    for(int j=0; j<=nn ;++j)
	    {
	    	
	    	int parent=parent_node(i-1);
	   	//hd+=ndist;
	   	//hd=hd+i*ndist;
	   	//hd=hd+ndist*j;
	    	// adding 2 child per parent nodes of level 
	    	if(j%2!=0)
	    	{
	    		lp=Point{point(parent).x + hd, point(parent).y+vd};
	    		add(lp);           				  // using shape::add to create vector of point
	    	}
	    	else 
	    	{
	    		//hd=hd+i*ndist;
	    		rp=Point{point(parent).x - level*hd, point(parent).y+vd};
	    		add(rp); 
	    	}
	
	    }
	    
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
        		fl_arc(point(i).x, point(i).y,r+r,r+r,0,360);      // using fl_arc to draw circle
        		
        	}
        	
        }
      
        // Drawing connecting lines from child to parent
        int parent;
        for(int child=number_of_points()-1; child>0; child--)
        {	
        	parent=parent_node(child);
        	fl_line(point(child).x+r ,point(child).y+r, point(parent).x+r,point(parent).y+r);  // r is offset for centre
        	cout<<"(Child, Parent) : ("<<child <<","<<parent<<")\n";
        }
        
}

};

int main()
{
	using namespace Graph_lib;
	
	Simple_window win{Point{100,100}, 1000,1000, "Binary Tree"};
	
	Binary_tree bt{Point{500,100},3};
	
	for(int i=0;i<bt.number_of_points()-1;++i)
		cout<<"position of "<<i<<" i("<< bt.point(i).x <<", "<<bt.point(i).y<<")"<<endl;
	
	win.attach(bt);
	win.wait_for_button();
	
}












