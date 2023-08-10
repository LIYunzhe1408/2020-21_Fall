#include <iostream>
using namespace std;

int main()
{
	int x, a, b, c;
	cin >> x ;
	a = x/100; //取第一位 
	x %= 100; // 划掉第一位 
	b = x/10; //取第二位 
	x %= 10; 
	c = x;
	cout << c << b <<a;
	
	return 0 ;
 } 
