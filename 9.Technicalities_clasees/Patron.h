// Excersize 8: Creating Patron class with user name, lib card no. and fee


class Patron
{
	private:
	string m_username;
	int m_lib_id;
	int m_lib_fee;

	public:
	Patron();
	Patron(string username, int lib_id, int lib_fee);
	int get_lib_id()
	{ 
		return m_lib_id;
	}
	void set_lib_id(int id)
	{
		m_lib_id=id;
	}
	int get_fee()
	{
		return m_lib_fee;
	}
	void set_fee(int fee)
	{
		m_lib_fee=fee;
	}
	string get_username()
	{
		return m_username;
	}
	void set_username(string name)
	{
		m_username=name;
	}
};

Patron::Patron()
   : m_username{""},
     m_lib_id{0},
     m_lib_fee{0}
{
}

Patron::Patron(string username, int lib_id, int lib_fee)
    : m_username{username},
      m_lib_id{lib_id},
      m_lib_fee{lib_fee}
{
	if(m_username =="")
		error("Invalid user name\n");
}

bool is_pending_fee(Patron& p)
{	
	bool result=false;
	if(p.get_fee() >0)
		result= true;
	return result;
}



