#include <iostream>
#include <cmath> //����pow����������ɶ��η� 
#include <iomanip> // ���þ�ȷλ������ 
using namespace std;
//�� ȡ3.1415926 

int main()
{
	double r, h, s, v;
	cin >> h >> r ;
	s = 2 * 3.1415926 * pow ( r, 2) //Բ����������Բ����� 
	    + 2 * 3.1415926 * r * h; //Բ����������= �ܳ�* �� 
	v = 3.1415926 * pow (r, 2)*h; //���Ϊ�����*�� 
	
	cout <<fixed<<setprecision(4)<< s <<", "<<fixed<<setprecision(5)<< v;//�������4��5λ�ı��������� 
	
	
	return 0 ;
}
