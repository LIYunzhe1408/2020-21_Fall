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
		}
	}
	
	for( int i = 0;i < n;i++)
	{
		for ( int j = 0;j < m;j++)
		{
			cnt = 0;
		    if ( a[i][j] == '*')
		    {
		    	cout << '*';
			}
			else
			{
				
			for ( int k = i-1; k <= i+1; k++)
				{
					for (int l = j-1; l <= j+1;l++)
					{
						if (a[k][l] == '*')
						{
							cnt ++; 
						}

					}
				}
			cout << cnt;
			}
			if ( j == m-1 )
			cout <<'\n';
			
		}	
	}
	
	
	
	
	
	
	

	
    return 0;
}


