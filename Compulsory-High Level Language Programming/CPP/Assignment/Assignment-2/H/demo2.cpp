#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int  a1, n1, amount = 0;
	int a[10], n[31];
	char ch ;
	//定义所有输入的a, n数组 
	int i;
	for (  i = 0;cin >> a1 >> n1;i++ )
{
	a[i] = a1;
	n[i] = n1;
	if( ch = getchar() =='\n')
	{
		break;
	}
}
    //判断a的值 
	
	for ( int j = 0; j <= n[j];j++){
	if (a[j] > 0 && a[j] < 10)
{	
	int sum = 0;
	int t = 0;
	cout << "Case "<< j + 1 <<": ";
	for ( int k = 0;k <= n[k];k++)
{
	int x = a[k] * pow(10.0, k);
	t += x;
	sum += t;
	if (k == 0)
	{
		cout << t ;
	}
	else if (k == n[k]-1)
	{
		cout << " + "<< t << " = "<<sum <<endl;
	}else{
		cout << " + "<< t;
	}
}	
}
}

	return 0;
}


