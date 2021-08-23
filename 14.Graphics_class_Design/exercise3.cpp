// Exercise 3 Chapter 14. Graphic Class Design
// Author: Sunil Kumar Yadav
// Date 12 June 2021
// Problem: Define an abstract class and try to define an object of that type. What happens?

class Abstract1
{
	public:
		Abstract1()
		{}
		virtual void foo(void)=0;   //pure virtual function
		void bar()
		{
			int c;
			c=a+b;
		}
	private:
		int a,b;

};

class Abstract2
{
public:
	void foo()
	{
		//do nothing
	}
private:
	int a, b;
	Abstract2()
	{
	}

};


int main()
{
	Abstract1 a1;
	Abstract2 a2;

	return 0;
}
