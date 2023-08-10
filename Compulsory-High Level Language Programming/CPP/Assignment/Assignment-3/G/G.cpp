#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m, n, i = 0,j = 1, r = 0, cnt = 1;
	char a[36],c[40] = {"0123456789ABCDEFGFIJKLMNOPQRSTUVWXYZ"};

	while ( cin >> n >> m )
	{
	
//¶Ì³ý·¨ 

		if ( n == 0 || m == 0)
		{
			cout << "Case "<< ++i << ": "<<'0'<<endl;
		}
		else
		{
			int t = n % m;
			for (  j = 0; n != 0;j ++)
		{
			t = n % m;
			a[j] = c[t]; 
			n = n / m;
			

		}

		cout << "Case "<< ++i << ": ";
		for ( int k = j - 1;  k >=0;k--)
		{
			cout << a[k];
		}
		cout<<endl;
		}
		
		

		
		

	}
	return 0;
} 
