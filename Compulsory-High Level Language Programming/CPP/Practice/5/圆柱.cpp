#include <iostream>
#include <cmath> //调用pow函数，以完成二次方 
#include <iomanip> // 调用精确位数函数 
using namespace std;
//π 取3.1415926 

int main()
{
	double r, h, s, v;
	cin >> h >> r ;
	s = 2 * 3.1415926 * pow ( r, 2) //圆柱上下两个圆的面积 
	    + 2 * 3.1415926 * r * h; //圆柱侧面的面积= 周长* 高 
	v = 3.1415926 * pow (r, 2)*h; //体积为底面积*高 
	
	cout <<fixed<<setprecision(4)<< s <<", "<<fixed<<setprecision(5)<< v;//输出保留4、5位的表面积和体积 
	
	
	return 0 ;
}
