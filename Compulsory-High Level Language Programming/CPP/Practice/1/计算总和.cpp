/************
����һϵ���������������ܺ͡� 

����

����������2�У���һ����һ��������n���ڶ�����n��������

���

���n���������������С�
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
