#include"../std_lib_facilities.h"

struct Date
{
	int year, month, day;
	Date()  // default date 1st Jan 2000
	{
		year=2000;
		month=1;
		day=1;
	}
	Date(int y, int m, int d):year{y}, month{m}, day{d}
	{
	}
};

// Overloading ostream to pring Date Structure
ostream& operator<<(ostream& os, const Date& d)
{
	os<<"("<<d.year<<", " <<d.month <<", " <<d.day <<")";
}



Date default_date;  // Created default date for further usage
Date today{2021,5,10}; 
class Book
{
	public:
	Book();
	Book(string title, string author, Date copy_right);
	string generate_isbn();
	void update_book_details(string title, string author, Date copy_right);
	void print_book_details(void);
	void checkout_details(Date d);

	public:
	string m_isbn;  // ISBN is 4 digit  with nnnx format where n is integer and x alphabate
	string m_title;
        string m_author;
	Date m_copyright_date;
	Date m_checkout_date;
	bool is_available;
};
