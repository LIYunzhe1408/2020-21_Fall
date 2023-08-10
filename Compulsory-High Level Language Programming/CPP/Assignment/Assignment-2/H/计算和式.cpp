#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{   
	int a, n;//定义a, n 
	for ( int i = 1;cin >> a >> n ;i++ )//输入若干组数据 
{
		
	int sum = a, t = a;
	
	cout << "Case "<< i <<": "<<a;
	//计算和 
	for (int j = 1;j < n;j++)
{
	int x = a * pow(10.0, j);
	t += x;//22 222 2222
	sum += t;//22+222+2222
	cout << " + "<<t;
}
    cout << " = "<< sum << endl;	
}		

	return 0;
}




