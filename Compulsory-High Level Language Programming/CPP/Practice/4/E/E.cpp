#include <iostream>
using namespace std;
int main()
{
	int x, cnt = 0, j, i;
	
	while (cin >> x)
	{
	    for ( int i = 0; i <= x; i++)
	    {
	    
	    	for (int j = 0; j <= x; j++)
	    	{

	    		if ( i + j * 2 == x || i * 2 + j == x )
	    		{
	    			cnt ++;
				}
			}
		}
		     cout << cnt <<endl;
	}
	
	    	

	
	return 0;
}
