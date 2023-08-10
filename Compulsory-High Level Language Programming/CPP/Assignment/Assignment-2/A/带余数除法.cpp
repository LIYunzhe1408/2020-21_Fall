#include <iostream>
using namespace std;

int main()
{
	long m, n;
	cin >> m >> n;
	long a = m / n;
	long b = m % n;
	
	if (b == 0)
	{
		cout << m <<" = "<< a << '*' << n << endl;
	}
	else 
	{
		cout << m <<" = "<< a << '*' << n << " + "<<b<<endl;
	}
	return 0;
 } 
