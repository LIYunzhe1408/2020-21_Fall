#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string s[65536];
	int l[65536], n = 0, Case = 0;
	
	while ( cin >> n)
	{
		for (int j = 0;j <= n;j++)
		{
			getline(cin,s[j]);
			l[j] = s[j].length();
		}
		for ( int k = 1;k <= n;k++)
		{
			cout <<"Case "<<++Case<<": ";
			for (int i = l[k] - 1;i >= 0;i--)
			{
				cout << (s[k])[i];
			}
			cout << endl;
			
		}
	}
	
	
	return 0;
}
