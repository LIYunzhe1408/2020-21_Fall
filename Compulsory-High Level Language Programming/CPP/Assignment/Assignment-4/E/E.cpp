#include <iostream>
using namespace std;

int main()
{
	int n, Case = 0, a[21][21];
	a[0][0] = 1;
	a[0][1] = 0;

	for ( int i = 1;i < 21 ;i ++)
		{
			for ( int j = 0;j <= i + 1;j++)
			{
				if ( j == 0)
				{
					a[i][j] = 1;
				}
				else if (j == i + 1)
				{
					a[i][j] = 0;
				}
				else
				{
				    a[i][j] = a[i-1][j-1] + a[i-1][j];	
				}		
			}
		}
		
		
		
		
	while (cin >> n )
	{
		cout << "Case "<<++Case<<":"<<endl; 
		for ( int i = 0;i <= n ;i ++)
		{
			for ( int j = 0;j <= i;j++)
			{
				if ( a[i][j] != 0)
				{
					if ( j == i)
					{
						cout << a[i][j];
					}
					else
					{
						cout << a[i][j]<<' ';
					}
				}
				
			}
			cout << endl;
		}
	}
	return 0;
}
