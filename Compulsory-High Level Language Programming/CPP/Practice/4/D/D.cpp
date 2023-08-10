#include <iostream>
using namespace std;

int main()
{
	int n, m, cnt = 0;
	char a[100][100];
	cin >> n >>m;


	for( int i = 0;i < n;i++)
	{
		for ( int j = 0;j < m;j++)
		{
			cin >> a[i][j];
			
			if ( a[i][j] =='?')
			{
				for ( int k = i-1; k <= i+1; k++)
				{
					for (int l = j-1; l <= j+1;j++)
					{
						if (a[k][l] == '*')
						{
							cnt ++; 
						}
						a[i][j] = cnt;
					}
				}
			}
			
			
			
		}
	}
	
	
	
	
	
	
	
	for( int i = 0;i < n;i++)
	{
		int t = 0;
		for ( int j = 0;j < m;j++)
		{
			if ( j == m-1)
			{
				cout << a[i][j];
				cout <<'\n';
				t = 1;
			}
			if ( t == 0) 	
			cout << a[i][j];
		}
	}
	
	
    return 0;
} 
