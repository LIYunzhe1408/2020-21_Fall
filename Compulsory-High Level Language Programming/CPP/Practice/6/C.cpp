#include <iostream>
#include <iomanip> 
#include <memory.h>
using namespace std;

int main()
{
	int n, reader[100], cnt[100];
	memset(cnt,0,sizeof(cnt));
	while ( cin >> n)
	{
		for ( int i = 0; i < n;i++)
		{
			cin >> reader[i];
		}
		for ( int i = 0; i < n; i++)
		{
			cnt[i]++;
			for ( int j = i - 1; j >= 0;j--)
			{
				if ( reader[j] == reader[i])
				{
					cnt[i]++;
				}
			}
		}
		
		for ( int i = 0; i < n;i++)
		{
			if ( i == n - 1)
			cout << cnt[i];
			else
			cout << cnt[i]<<' ';
		}
		cout << endl;
	}
	return 0;
}
