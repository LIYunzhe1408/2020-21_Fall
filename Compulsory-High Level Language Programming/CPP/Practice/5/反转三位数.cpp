#include <iostream>
using namespace std;

int main()
{
	int x, a, b, c;
	cin >> x ;
	a = x/100; //ȡ��һλ 
	x %= 100; // ������һλ 
	b = x/10; //ȡ�ڶ�λ 
	x %= 10; 
	c = x;
	cout << c << b <<a;
	
	return 0 ;
 } 
