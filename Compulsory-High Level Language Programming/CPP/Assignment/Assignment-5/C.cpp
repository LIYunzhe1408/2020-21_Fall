#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string s[32768];
	int n = 0, Case = 0;
	int l[32768];
	
	while ( cin >> n)
	{
		for ( int cnt = 0; cnt <= n;cnt++)
		{
			getline(cin, s[cnt]);
			l[cnt] = s[cnt].length();
		}
				
		for ( int j = 1; j <= n;j++)
		{
			if (l[j] % 2 == 0)
			{
				cout <<"Case "<<++Case<<": "<<'"' <<s[j];
				for (int i = 0;l[j] > 0;l[j]--)
				{
			    	cout << (s[j])[l[j]-1];
				}

				cout <<'"'<< endl;
			}
			else
			{
				cout <<"Case "<<++Case<<": "<<'"' <<s[j];
				if ( l[j] != 1)
				{
					for ( int i = 0;l[j] > 1;l[j]--)
					{
						cout << (s[j])[l[j]-2];
					}
		
				}
				cout <<'"'<< endl;
			}
		}
	}
	
	
	return 0;
}

