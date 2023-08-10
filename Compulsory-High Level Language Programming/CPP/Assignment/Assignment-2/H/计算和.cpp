#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, a, sum = 0;
	while (cin >> a >> n)
	{
		for (double i = 0;i < n;i++)
	{
		int x = a * pow(10, i);
		int t;
		t += x;
		sum += t;
	}
	cout << sum << endl;
	}
	
//	for (double i = 0;i < n;i++)
//	{
//		int x = a * pow(10, i);
//		int t;
//		t += x;
//		sum += t;
//	}
//	cout << sum << endl;
	return 0;
 } 
