#include <iostream>
using namespace std;

int main()
{
	double a[100];
	int i = 0, cnt;
	char ch ;
	double max, min, sum;
	
//    for ( i = 0;ch = getchar() != '\n' ; i++)
//    {
//    	cin  >> a[i];
//    	cout << a[i] << endl;
//	}


	while (cin >> a[i])
	{
		sum += a[i];
		if (ch = getchar() =='\n')
		{
			break;
		}
		i++;
	}
	max = a[0], min = a[1];
	for ( int j = 0; j <= i; j++)
	{
		if (a[j] > max)
		{
			max = a[j];
		}
		if ( a[j] < min)
		{
			min = a[j];
		}
	}
	cnt = i + 1;//ÏîÊý 
	sum = (sum - max - min ) / (cnt - 2);

	cout << cnt <<", "<<min<<", "<< max <<", "<<sum <<endl;
	return  0;
}
