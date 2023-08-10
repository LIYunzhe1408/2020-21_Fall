#include <iostream>
#include <cstring>
using namespace std;
 
int main()
{
	string s, r;
	int length = s.length();
	
	getline(cin, s);
	for(int i = 0, t = length - 1;i < length;)
	{
		if(s[i] > 0)
		{
			r[t] = s[i];
			t--;
			i++;
		}
		else
		{
			r[t-1] = s[i];
			r[t] = s[i+1];
			t-=2;
			i+=2;
		}
	}
	strcpy(s,r);
	cout << s;
    return 0;
}
