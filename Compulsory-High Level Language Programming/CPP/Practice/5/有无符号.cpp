#include <iostream>
using namespace std;

int main()
{
	short int x = -1;
	cin >> x ;
	unsigned short int y = (short int )x; //�з��Ŷ�����to�޷��Ŷ����� 
	unsigned long long int z = (short int )x;//�з��Ŷ�����to�޷��ų����� 
	long int j = (short int )x; //�з��Ŷ�����to�з��ų����� 
	
	cout << y << ','<<' '<< x << '\n'; //������+���� 
	cout << z << ','<<' '<< j << '\n';
	
	return 0;
}
