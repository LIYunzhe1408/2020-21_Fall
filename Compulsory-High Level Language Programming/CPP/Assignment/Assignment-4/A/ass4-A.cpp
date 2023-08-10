#include <iostream>
#include <memory.h>
using namespace std;

int main(){
	double a[1000];
	int Case = 0, rank = 1, cnt = 0;

	
	while ( cin >> a[cnt])
	{
		cnt ++;
		char ch = getchar();
		if ( ch != ' ')
		{
			
		    cout << "Case "<<++Case<< ":"<<endl;
		    for ( int i = 0;i < cnt;i++)
		    {
			    rank = 1;
			    for ( int j = 0;j < cnt;j++)
			    {
				    if (a[i] < a[j])
				    {
					    rank ++;
				    }
		        }
		        if (i == cnt - 1)
		        {
		            cout << rank ;
				}
				else
		            cout << rank << ", ";
		    }

		    cout << endl;
		    cnt = 0;
		}
		
	}

		
		
	
	
	return 0;
}
