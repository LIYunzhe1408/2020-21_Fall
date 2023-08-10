#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	string s;
	int cnt = 0, Case = 0;
	
	while(getline (cin, s))	
	{
		cout << "Case "<<++Case<< ": ";
		for (int i = 1;i < s.length();i++)
		{
			if ( s[i-1] != ' ' && s[i]== ' ' && i != s.length()-1)
			{
				cnt ++;
			}
		}
		if ( s[s.length()-1] != ' ')
		{
			cnt ++;
		}
		cout << cnt <<endl;
		cnt = 0;
	}
	
	return 0;
}
