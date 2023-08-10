#include <iostream>
using namespace std;

int main ()
{
	int amount, one, two, five, cnt = 0,k = 0;
	while (cin >> amount)
	{
		cnt = 0;

		for ( two = 0; two <= amount ;two ++)
		{
			for ( five = 0; five <= amount ;five ++)
			{
				if ( amount >= one + two * 2 + five * 5 )
				{
					cnt ++;
				}
			}
	    }
	k++;
	cout << "Case "<<k <<": "<<amount << ", "<<cnt <<endl;
    }

	
	return 0;
}
