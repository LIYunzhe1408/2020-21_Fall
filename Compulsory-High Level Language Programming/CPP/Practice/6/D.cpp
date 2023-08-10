#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a[100], n, cnt = 0;
	while ( cin >> n)
	{
		for ( int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		for ( int i = 0;i < n;i++)
		{
			for ( int j = i+1; j < n;j++)
			{
				if(abs(a[j] - a[i]) == 1)
				{
					cnt ++;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
