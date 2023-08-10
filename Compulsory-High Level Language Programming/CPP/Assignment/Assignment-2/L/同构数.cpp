#include <iostream>
#include <cmath> 
using namespace std;



int Digit(int x)
{
	int ret, i;
	for ( i = 1;i <=10;i++)
	{
		x /= 10;
		if ( x == 0)
		{
			break;
		}
	}
	ret = i;
	return ret;
}

int main()
{
	int x, digit, k;
	int j, t;
	int SQ;
	for(k = 1;cin >> x;k++)
{
	t = 0;
	SQ = pow ( x, 2);
	digit = Digit(x);//¼ÆËãÎ»Êý 
	for ( j = digit;j >=0;j--)
	{
		int y = pow ( 10, j);
		SQ = SQ % y;
		if ( SQ == x)
		{
			t = 1;
			cout << "Case "<<k<<": "<<x<<", "<<"Yes"<<endl;
			break;
		}
	}
	if ( t != 1)
	{
	    cout << "Case "<<k<<": "<<x<<", "<<"No"<<endl;
	}
}
	
    return 0;	
}


