#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x,k=0, cnt= 0, t;
	while (cin >> x)
	{
		cnt = 0;
		for ( int i = 1;i <= x;i++)
		{
			if ( i % 5 ==0)
			{
				t = i;
				while ( i % 5 ==0)
			{
				i /= 5;
				cnt ++;
			}
			i = t;
			}
		
		}
		k ++;
		cout << "Case "<<k<<": "<<x<<", "<< cnt << endl; 
	}

	return 0;
}
