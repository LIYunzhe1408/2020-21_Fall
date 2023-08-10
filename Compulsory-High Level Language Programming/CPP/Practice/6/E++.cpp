
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

typedef struct boat{
		int time;
		int people;
		int nation[50];
	}boatX;
	
	
int main()
{
	int n,  nationX[1000], cnt[50];
	boatX boat[50];

	while( cin >> n)
	{
		int sum = 0, q = 0, y = 0,  s = 0, k = 0;
		int t = 0, marker = 0, xsum = 0, mark = 0;
		memset(boat,0,sizeof(boat));
		memset(cnt,0,sizeof(cnt));
		for ( int i = 0;i < n;i++)
		{
			cin >> boat[i].time>>boat[i].people;
			for (int j = 0;j < boat[i].people;j++)
			{
				cin >> boat[i].nation[j];
			}
			
			
			
			if( boat[i].time - boat[q].time < 86400)
			{
				for ( int j = 0; j < boat[i].people;j++)
				{
					nationX [k] = boat[i].nation[j];
					k++;
				}
				
//				sort(&nationX[0],&nationX[k]);
				sum =  sum + boat[i].people;
		
				for ( int j = k - 1;j > k - sum;j--)
				{
					mark = 0;
					for (int y = j - 1;y >= k - sum;y--)
					{
						if ( nationX[j] == nationX[y] && j != y)
						{
							mark = 1;
							break;
						}
					}
					if ( mark == 0 )
					{
						cnt[i]++;
					}
				}					
			}
			else if(boat[i].time - boat[q].time >= 86400)
			{
				for(int c = 0; c < n;c++)
				{
					if ( boat[i].time - boat[c].time < 86400)
					{
						marker = c - 1;
					}
				}
				for (int c = 0;c < marker;c++)
				{
					xsum += boat[c].people;
				}
			    s = k - boat[q+1].people;	
				for ( int j = 0; j < boat[i].people;j++)
				{
					nationX [k] = boat[i].nation[j];
					k++;
				}
				sum = sum + boat[i].people - xsum;
//				sort(&nationY[s],&nationY[k-1]);
				
//				int length = &nationX[k] - &nationX[s];
//				cout << "s = "<<s<<"k= "<<k<<endl;
//				cout << "length= "<< length<<endl;
//				cout << nationX[4]<<endl;
//
				for ( int j = k - 1;j >= s;j--)
				{
					mark = 0;
					for (int y = k-2;y >= s;y--)
					{
						if ( nationX[j] == nationX[y] && j != y)
						{
							mark++;
						}
					}
					if ( mark == 0)
					{
						cnt[i]++;
					}
				}
				q++;
			}
		}
		for(int i = 0;i < n;i++)
		{
			cout << cnt[i] + 1<<endl;
		}	
		
	}
	
	return 0;
}
