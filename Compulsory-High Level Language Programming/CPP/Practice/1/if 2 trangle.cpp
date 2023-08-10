#include <iostream>
using namespace std;
int trangle(double a, double b, double c);

int main()
{
	double x, y, z;
	cin >> x >> y >> z;
	int r = trangle (x, y, z);
	if (r)
	{
		cout << "YES"<<endl;
	}
	else
	{
		cout << "NO"<< endl;
	 } 
	 return 0;	
}


int trangle (double a, double b, double c)
{
	int ret;
	if (a + b > c && a + c > b && b + c > a)
	{
		ret = 1;
	}
	else 
	{
		ret = 0;
	}
	return ret;
 } 


