#include <iostream>
#include <memory.h>
using namespace std;

int main()
{
	int n, time, nation[56], people[86400], cnt[100], j = 0;
	memset(cnt,0,sizeof(cnt));
	int sum = 0;
	
	while ( cin >> n)
	{
		
		for(int i = 0; i < n;i++)
		{
			cnt[i] = 1;
			cin >> time;
			if ( time - 86400 > 0)
			{
				time = time - 86400;
				cin >> people[time];
				while(j < sum)
				{
					cin >> nation[j];
					j++;
				}
				peopleX[time] = people[time];
				for(int c = time;c < n;c++)
				{
					sum += peopleX[c];
				}
			}
			else
			{
				cin >>people[time];
				peopleX[i] = people[time];
				 
			}
			sum += people[time];
		
			for ( int k = 1;k < sum;k++)
			{
				if ( nation[k] != nation[k-1])
				{
					cnt[i] ++;
				}
			}
			
		}
		
		for ( int i = 0; i < n;i++)
		{
			cout << cnt[i]<<endl;
		}
			
		
	}
	return 0;
}
