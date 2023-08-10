//描述
//甲流并不可怕，在中国，它的死亡率并不是很高。请根据截止2009年12月22日各省报告的甲流确诊数和死亡数，计算甲流在各省的死亡率。
//
//输入
//输入仅一行，有两个整数，第一个为确诊数，第二个为死亡数。
//
//输出
//输出仅一行，甲流死亡率，以百分数形式输出，精确到小数点后3位


#include <iostream>
#include <iomanip> //调用调整输出数据精度的函数 
using namespace std;

int main()
{
    long quezhen, siwang;  //定义两个整数 
	cin >> quezhen >> siwang ;  //输出两个整数 
	double s = (long) siwang;  //将整型数据转换为双精度的浮点型数据 
	double q = (long) quezhen;
	double rate;
	
	if ( q == 0 ){  //采用if分支：以防之后在rate计算中分母q可能出现的为零的情况。 
		rate = 0;
	    cout <<fixed<<setprecision(3)<< rate << "%";  //当q为零时，rate= 0%，按照题目要求仍需要精确三位 
	   
	}else if ( q >= 0){  //当分母q不为零时rate的计算 
		rate = (s / q ) * 100;
	    cout <<fixed<<setprecision(3)<< rate << "%";  //输出数据保留三位小数 
	}
	return 0 ;
 } 
