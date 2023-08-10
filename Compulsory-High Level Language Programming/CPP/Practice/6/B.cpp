#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double x, result;
	while (cin >> x)
	{
		if (x >= 0 && x < 5)
		{
			result = -x + 2.5;
		}else if (x >= 5 && x < 10)
		{
			result = 2- 1.5 * pow((x - 3),2);
		}else if ( x >= 10 && x < 20)
		{
			result = x / 2 - 1.5;
		}
		cout <<setprecision(3) <<std::fixed<< result <<endl;	
	}
	
	return 0;
} 
