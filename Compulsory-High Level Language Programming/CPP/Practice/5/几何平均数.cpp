#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main()
{
	double a, b, c, d, e;
	cin >> a >> b >> c >> d >> e ;
	
	double x, y;
	double A = a + b + c + d + e;
	double B = a * b * c * d * e;
	
	x = A /5;
	y = pow( B , 1.0/5);
	cout <<setiosflags(ios::fixed)<<setprecision(1)<< x << ',' <<' '<<setiosflags(ios::fixed)<<setprecision(1)<<y << endl;	
	return 0;
 } 
