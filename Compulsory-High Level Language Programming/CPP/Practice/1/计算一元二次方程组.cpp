/**************************************
计算一元二次方程根计算器 
版本v1.0
日期 2020/9/28 22：54 
***************************************/ 
#include <iostream>
#include <cmath>                             //声明math函数，便于之后对pow的调用 
using namespace std;
double root_1(double a, double b, double c); //声明计算一个根的函数 
double root_2(double a, double b, double c);
void   bigger(double *x, double *y);        //声明比较两根大小并从小到大排序的函数 

int main()
{    
    //输入一元二次方程的三个系数 
	double a, b, c;
	cout << "please input coefficient a, b, c for the equation \" ax^2 + bx + c = 0 \"\n"; 
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	//定义delta 
	double sq_dierta = sqrt(pow(b,2) - 4*a*c);
	//判断一次项系数是否为零 
	if (a != 0 )
{
	//判断delta是否大于零 
		if (sq_dierta >= 0)
	{ 
	//定义两个根并调用求根函数计算 
		double root1, root2;
		root1 = root_1(a, b, c);
		root2 = root_2(a, b, c);
	//判断两个根的值是否相同	
		if (root1 == root2)
		{
	//相同则输出两个相同的实数根 
			cout << "X1 = X2 = " << root1<<endl;
		}
		else
		{
	//不同则调用bigger函数比较两根大小并从小到大排序 
			bigger(&root1, &root2);//调取root的地址 
		    cout << "X1 = "<<root1 <<" and "<< "X2 = "<< root2 << endl;	
		}
	} 
	//delta < 0,就无实数根 
	    else 
	    {
		cout << "无实数根"<<endl;
	    }
}
    //若一次项系数=0，那么就是一元一次方程，不属于此计算器求解范围
	else 
	{
		cout << "it's the root of equation of a degree";
	}
	return 0;
}


//求根函数1，运用求根公式，将求得的值返回 
double root_1(double a, double b, double c)
{
	double ret;
	ret = ( - b + sqrt(pow(b,2) - 4*a*c))/(2*a);
	return ret;
}
//求根函数1，运用求根公式，将求得的值返回 
double root_2(double a, double b, double c)
{
	double ret;
	ret = ( - b - sqrt(pow(b,2) - 4*a*c))/(2*a);
	return ret;
}


//比较排序（小到大）函数，运用指针 
void bigger(double *x, double *y)
{
	if (*x > *y)
	{
		double t;
		t =  *x;
		*x = *y;
		*y = t;
	}
}











