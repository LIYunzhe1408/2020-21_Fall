#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n, Case = 0, a[52][52], i = 2;
	int j = 0, k = 0;
	while ( cin>>n)
	{
		i = 2, j = 0 , k = 0;
		cout << "Case "<<++Case<<":"<<endl;
		a[0][(n-1)/2] = 1;
		k = (n-1)/2;
		
		
		while ( i <= n * n )
		{
			if ( i == 2)	
			{
				j = 0;
				k = (n-1)/2;
			}
			if ( (i-1) % n == 0)
			{
				a[j+1][k] = i;
				j = j + 1;
				k = k;
				i++;
				continue;
			}
			
			if ( j-1 < 0)
			{
				a[n-1][k+1] = i;
				j = n - 1;
 				k = k + 1;
 				i ++;
 				continue;
			}
			else if(  k+1 > n-1)
			{
				a[j-1][0] = i;
				j = j - 1;
				k = 0;
				i++;
				continue;
			}
			else
			{
				a[j-1][k+1] = i;
				j = j - 1;				
				k = k + 1;
				i++;
			}
	
			
		}
		
		for ( int x = 0; x < n; x++ )
		{
			for ( int y = 0; y < n; y ++)
			{
				if ( y == n - 1)
				{
					cout<< a[x][y]<<endl;
				}else
				cout << a[x][y]<<"   ";
			}
		}
	}
	
	return 0;
}
