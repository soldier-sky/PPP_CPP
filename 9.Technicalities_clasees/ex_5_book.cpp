// This example contain Book class with details assosiated with book and related operation

#include"Book.h"
#include "Patron.h"

Book::Book()
{
	m_isbn = "000X";
	m_title="";
	m_author="";
	m_copyright_date=default_date;
	m_checkout_date= Date{2000,1,1};
	is_available=false;
}

Book::Book(string title, string author, Date copy_right)
	:m_title{title},
	 m_author{author},
	 m_copyright_date{copy_right}
{
	m_isbn="001a";
	m_checkout_date=default_date;
	is_available=true;
}


string Book::generate_isbn()
{
	return "";
}

void Book:: update_book_details(string title, string author, Date copy_right)
{
}

void Book::print_book_details(void)
{
	cout<<"Book details are: \n";
	cout<<"Title: "<<m_title
	    <<"\nAuthor: "<<m_author
	    <<"\nCopyright date: "<<m_copyright_date
	    <<"\nCheckout details: "<<m_checkout_date <<"\n";
}

void Book::checkout_details(Date d)
{
	m_checkout_date=d;
	is_available=false;
}

int main()
{
	Book b1;
	b1.print_book_details();

	Book b2{"12 Rules of Life","Jordan B Peterson",Date{1,1,2019}};
	b2.checkout_details(Date{12,5,2021});
	b2.print_book_details();
	//cout<<b2.m_checkout_date;
	
	Book b3{"Ultimate Goal", "Vikram Sood", Date{2021,1,1}};

	if(b3.is_available)
		cout<<"Book is available";
	else
		cout<<"Book is not available";




	cout<<"\n------------------------------\n";

	Patron p1("Sunil Yadav", 1234,10) ;
	cout<<"Lib Id of patron "<<p1.get_username()<<"is "<<p1.get_lib_id()<<"\n";

	cout<<is_pending_fee(p1);
	return 0;
}
