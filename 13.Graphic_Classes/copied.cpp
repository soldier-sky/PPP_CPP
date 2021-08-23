// Osman Zakir
// 5 / 8 / 2017
// Bjarne Stroustrup: Programming: Principles and Practice Using C++ 2nd Edition
// Chapter 13 Exercise 1
// Exercise Specifications:
/**
 * Define a class Arc , which draws a part of an ellipse. Hint: fl_arc().
 */

//#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

namespace Graph_lib
{
	class Arc : public Shape
	{
	public:
		Arc(double r, Graph_lib::Point p, double start_deg, double end_deg)
			: m_r{ r }, m_p{ p }, m_start_deg{ start_deg }, m_end_deg{ end_deg }
		{
			add(Graph_lib::Point{ int(m_p.x - m_r), int(m_p.y - m_r) });
		}
		void draw_lines() const;
		double get_radius() const { return m_r; }
		Graph_lib::Point get_point() const { return m_p; }
		double set_start_deg(double theta) { m_start_deg = theta; }
		double set_end_deg(double theta) { m_end_deg = theta; }
	private:
		double m_r;
		Graph_lib::Point m_p;
		double m_start_deg;
		double m_end_deg;
	};
}

int main()
{
	using namespace Graph_lib;

	constexpr int win_x = 100, win_y = 100;
	constexpr int win_width = 600, win_height = 400;
	Simple_window win{ Point{win_x, win_y}, win_width, win_height, "Arc" };

	const double radius1 = 4.0;

	const int arc1_x = 200, arc1_y = 200;
	const double start_theta = 0, end_theta = 180;

	Graph_lib::Arc arc1{ radius1, Point{arc1_x, arc1_y}, start_theta, end_theta };
	win.attach(arc1);

	win.wait_for_button();
}

void Arc::draw_lines() const
{
	using namespace Graph_lib;
	if (color().visibility())
	{
		fl_arc(point(0).x, point(0).y, int(m_r + m_r), int(m_r + m_r), m_start_deg, m_end_deg);
	}
}
