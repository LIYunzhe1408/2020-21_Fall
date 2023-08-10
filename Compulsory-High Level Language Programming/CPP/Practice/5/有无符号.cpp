#include <iostream>
using namespace std;

int main()
{
	short int x = -1;
	cin >> x ;
	unsigned short int y = (short int )x; //有符号短整型to无符号短整型 
	unsigned long long int z = (short int )x;//有符号短整形to无符号长整型 
	long int j = (short int )x; //有符号短整型to有符号长整型 
	
	cout << y << ','<<' '<< x << '\n'; //输出语句+换行 
	cout << z << ','<<' '<< j << '\n';
	
	return 0;
}
