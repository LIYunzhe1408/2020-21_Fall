#include <iostream>
using namespace std;

int main()
{
	int cnt = 0, Case = 0, t = 0;
	static int a[10];
	int s[1000];
	
	
	while ( cin >> s[cnt])
	{
		cnt ++;
		char ch = getchar();
		if ( ch != ' ')
		{
			cout << "Case "<<++Case<<": ";
			//Ã°ÅÝ·¨ÅÅÐò 
			for ( int i = 0;i < cnt;i++)
			{	
			    for ( int k = 0;k<cnt;k++)
			    {
			        if ( s[i] > s[k])
				    {
					    t = s[k];
					    s[k] = s[i];
					    s[i] = t;
				    }
				}
			}
			for ( int j = 0;j < 10;j++)
			{
				if ( j != 9)
				cout << s[j]<<", ";
				else 
				cout << s[j]<< endl;
			}
			cnt = 10;
		} 
		
	}
	
	return 0;
}
