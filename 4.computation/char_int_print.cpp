//This program prints ascii equivalent of alphabets
#include"std_lib_facilities.h"

int main()
{
	char cvar='a';
	unsigned int count=26;

	for(int i=0;i<count;++i)
	{
		cout<<cvar <<"\t" <<int(cvar)<<endl;
		++cvar;
	}
	return 0;
}
