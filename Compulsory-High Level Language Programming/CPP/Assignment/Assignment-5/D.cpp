#include <iostream>
#include <cstring>
using namespace std;
void ni_zhuan(string &s, int l)
{
	int length = l;
	for( int i = 0; i < length/2; i+=2)
	{
		int x = s[i];
		s[i] = s[length - 2];
		s[length - 2] = x;
		
		x = s[i+1];
		s[i+1] = s[length-1];
		s[length-1] = x;
	}
}

int main()
{
	string s;
	int l, n = 0, Case = 0, j;
	

	    while(getline(cin,s))
	    {
	    	l = s.length();
			cout <<"Case "<<++Case<<": ";
			ni_zhuan(s, l);
			cout << s<<endl;
		}

	return 0;
}
