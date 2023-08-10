/************
给定一系列整数，计算其总和。 

输入

输入数据有2行，第一行有一个正整数n；第二行有n个整数。

输出

输出n，及计算结果，换行。
****************************/

#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int r;
	for ( int i = 0; i<n; i++){
		int a;
		cin >> a;
		r += a;
	}
	cout << n << ", "<< r<< endl;
	return 0 ;
}
