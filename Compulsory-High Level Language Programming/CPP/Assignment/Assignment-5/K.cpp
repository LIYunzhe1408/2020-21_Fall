#include <iostream>
#include <string.h> 
using namespace std;

int main()
{
	string s;
	int cnt = 0, mark = 0;
	
	while(getline (cin, s))	
	{
		for (int i = 0;i < s.length();i++)
		{
			if ( s[i] >= '0' && s[i] <= '9')
			{
				cnt ++;
			}
		}
		cout << cnt<<endl;
		cnt = 0;
	}
	
	return 0;
}
