#include <iostream>
using namespace std;


int n,i,j,k,a[52][52], Case = 0;


int main()
{
	while ( cin >> n)
	{
		cout << "Case "<<++Case<<":"<<endl;
		for(k = 1; k <= (n+1)/2; k++)
		{
			for(i = k;i <= n+1-k; i++)
			{
				for(j = k;j <= n+1-k; j++)
				a[i][j] = k;
			}
	 	} 
	 for(i = 1;i <= n; i++)
	 {
	 	for(j = 1;j <= n;j++)
	 	{
	 		if ( j == n)
	 		{
	 			cout << a[i][j]<<endl;
			}
			else
			{
	 		    cout << a[i][j]<<' ';
			}
		}
	 }
	}
	
	return 0;
}
