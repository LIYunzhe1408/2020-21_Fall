#include <iostream>
using namespace std;

int main()
{
	int x;
	int i  = 0, cnt = 0, j = 1;
	while ( cin >> x)
{
	long t = x;
	if ( x <= 0)
	{
		cout <<"Case "<< j << ": "<<x <<", -1"<<endl;  
	}
	else
	{ 
	for ( i = 0; x != 1; i++)
	{
		if ( x % 2 == 0)
		{
		    x /= 2;
		}else
		{
	    	x = x * 3 + 1;
		}
		cnt = i + 1;
	}
	cout <<"Case "<< j << ": "<< t <<", "<< cnt <<endl;
    }
	j++;
}
	return 0;
} 
