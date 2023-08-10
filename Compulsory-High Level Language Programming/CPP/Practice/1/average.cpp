/**********************************
给定一系列数据，去掉其中一个最大值、一个最小值后求平均值。

输入

输入数据仅有一行，其中有若干（大于2）个双精度浮点型数据。

输出

输出数据项数，最小值，最大值，计算结果，换行。
***********************************/

#include <iostream>
using namespace std;

int main()
{
	float a[100];
	float max, min, sum, in;
	int cnt = 1;
	cout << "a[0] = ";
	cin >> a[0];
	min = a[0];
	sum = a[0];
	char c; 
	
	for (int i = 1;i !=0;i++)
	{
		cin >> in ;
		
		if ( in != 0)
		{
		a[i] = in;
		if (a[i] > a [i-1])
		{
			max = a[i];
		}
		if ( a[i] < a[i-1])
		{
			min = a[i];
		}
		cnt ++;
		sum = sum + a[i]; 
	    }
	}
	cout << "cnt = "<<cnt << endl;//数据项数
	cout << "max = "<<max<<" min = "<< min <<endl;
	sum = (sum - max - min )/(cnt - 2);
	cout << "average = "<< sum << endl;
	
	return 0;
}
