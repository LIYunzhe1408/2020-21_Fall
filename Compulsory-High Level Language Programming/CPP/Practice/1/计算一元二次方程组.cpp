/**************************************
����һԪ���η��̸������� 
�汾v1.0
���� 2020/9/28 22��54 
***************************************/ 
#include <iostream>
#include <cmath>                             //����math����������֮���pow�ĵ��� 
using namespace std;
double root_1(double a, double b, double c); //��������һ�����ĺ��� 
double root_2(double a, double b, double c);
void   bigger(double *x, double *y);        //�����Ƚ�������С����С��������ĺ��� 

int main()
{    
    //����һԪ���η��̵�����ϵ�� 
	double a, b, c;
	cout << "please input coefficient a, b, c for the equation \" ax^2 + bx + c = 0 \"\n"; 
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	//����delta 
	double sq_dierta = sqrt(pow(b,2) - 4*a*c);
	//�ж�һ����ϵ���Ƿ�Ϊ�� 
	if (a != 0 )
{
	//�ж�delta�Ƿ������ 
		if (sq_dierta >= 0)
	{ 
	//��������������������������� 
		double root1, root2;
		root1 = root_1(a, b, c);
		root2 = root_2(a, b, c);
	//�ж���������ֵ�Ƿ���ͬ	
		if (root1 == root2)
		{
	//��ͬ�����������ͬ��ʵ���� 
			cout << "X1 = X2 = " << root1<<endl;
		}
		else
		{
	//��ͬ�����bigger�����Ƚ�������С����С�������� 
			bigger(&root1, &root2);//��ȡroot�ĵ�ַ 
		    cout << "X1 = "<<root1 <<" and "<< "X2 = "<< root2 << endl;	
		}
	} 
	//delta < 0,����ʵ���� 
	    else 
	    {
		cout << "��ʵ����"<<endl;
	    }
}
    //��һ����ϵ��=0����ô����һԪһ�η��̣������ڴ˼�������ⷶΧ
	else 
	{
		cout << "it's the root of equation of a degree";
	}
	return 0;
}


//�������1�����������ʽ������õ�ֵ���� 
double root_1(double a, double b, double c)
{
	double ret;
	ret = ( - b + sqrt(pow(b,2) - 4*a*c))/(2*a);
	return ret;
}
//�������1�����������ʽ������õ�ֵ���� 
double root_2(double a, double b, double c)
{
	double ret;
	ret = ( - b - sqrt(pow(b,2) - 4*a*c))/(2*a);
	return ret;
}


//�Ƚ�����С���󣩺���������ָ�� 
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











