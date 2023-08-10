#include <iostream>
using namespace std;

int main()
{
	long a1, a2, d, n ;
	cin >> a1 >> a2 >> n; 
	d = a2 - a1;
	if (-100 <= a1 && a2 <= 100 && 0 < n <= 1000){
		n = a1 + ( n - 1) * d;
		cout << n;
	}
	return 0;
 } 
