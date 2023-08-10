#include <iostream>
using namespace std;

int main()
{
	int n, a[1000], Case = 0, cnt = 0, mark = 0;
	while ( cin >> n)
	{
		while ( cin>> a[cnt])
		{
			cnt ++;
		    char ch = getchar();
		    if ( ch != ' ')
		    {
		     	cout << "Case "<<++Case<< ": "<<n<<", ";
		    	for ( int i = 0; i < cnt;i++)
	    		{
	    			if ( a[i] == n)
					{
						cout <<i<<endl;
						mark = 1;
					}
				}
				if ( mark != 1)
				{
					cout << "-1"<<endl;
				}
					cnt = 0;
					break;	
				}
				
		}
	
		
	}
	return 0;
}
