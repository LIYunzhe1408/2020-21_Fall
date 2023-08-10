#include <iostream>
using namespace std;

int main()
{
	int m, n;
	cout << "please input two numbers:\n";
	cin >> m >> n;
	
	if (m > n)
	{
	
	int r = m % n;
	int q = m / n;
	if (r == 0)
	{
	cout << m << " = " << q <<" * "<< n << endl; 
    }
	else
	{
    cout << m << " = " << q <<" * "<< n <<" + " << r << endl; 
	}
	
	}
	return 0;
 } 


