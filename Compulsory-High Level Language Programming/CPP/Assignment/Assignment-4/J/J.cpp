#include <iostream>
using namespace std;

int main()
{
	int cnt1 = 0, cnt2 = 0, Case = 0, sum;
	double a[100][100];
	
	
	while (cin >> a[cnt1][cnt2])
	{
		cnt1 ++;
		cnt2 ++;
		sum = 0;
		char ch = getchar();
		if ( ch != ' ')
		{
	    	cout << "Case "<<++Case<<": "<<cnt1<< ", "<< cnt2<<", ";
			for ( int i = 0; i < cnt1; i++)
			{
				for (int j = 0;j < cnt2;j++)
				{
					sum += a[i][j];
				}
			}		
			cout << sum << endl;	
		}
	}
	return 0;
}
