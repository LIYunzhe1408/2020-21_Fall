#include <iostream>
#include <iomanip>
using namespace std;

double  fac( double  x)
{
	double  ret;
	if ( x == 1 || x == 0)
	{
		ret = 1;
	}
	else 
	{
		ret = x * fac(x-1);
	}
	return ret;
}

int main()
{
    double Case = 0, m, n;
	while ( cin >> m >> n)
	{
		cout << "Case "<<++Case<<":"<<endl;
		if ( m < n)
		{
			cout << '0'<<endl;
		}else
		{
			double  result = 0;
			result = fac(m) / (fac(m-n)*fac(n));
			cout <<fixed<<setprecision(0)<< result<<endl;	
		}
	}
	return 0;
} 
