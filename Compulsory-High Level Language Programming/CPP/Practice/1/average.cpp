/**********************************
����һϵ�����ݣ�ȥ������һ�����ֵ��һ����Сֵ����ƽ��ֵ��

����

�������ݽ���һ�У����������ɣ�����2����˫���ȸ��������ݡ�

���

���������������Сֵ�����ֵ�������������С�
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
	cout << "cnt = "<<cnt << endl;//��������
	cout << "max = "<<max<<" min = "<< min <<endl;
	sum = (sum - max - min )/(cnt - 2);
	cout << "average = "<< sum << endl;
	
	return 0;
}
