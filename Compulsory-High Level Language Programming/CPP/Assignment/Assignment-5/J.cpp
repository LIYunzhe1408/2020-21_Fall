#include <iostream>
#include <string.h> 
using namespace std;

int main()
{
	string s, r;
	int  Case = 0;
	
	while(getline (cin, s))	
	{
		int k = 0, cnt = 0;
		int l = s.length();
		
		for (int i = 1;i < l;i++)
		{
			if(s[i-1] >= '0' && s[i-1] <= '9')
			{
				r[k] = s[i - 1];
				k++;
				if (s[i]<'0' || s[i]>'9' )
				{
					r[k] = ' ';
					k++;
					cnt ++;
				}
			}
		}
		if ( s[l-1] >= '0' && s[l-1] <= '9')
		{
			r[k] = s[l-1];
		}
		

		if ( cnt != 0)
		{
			cnt ++;
			cout << "Case "<<++Case<< ": "<<"("<<cnt<<") ";
			for ( int x = 0;x < k+1; x++)
			{
				cout << r[x];
			}
			cout << endl;
		}
		else if( k == 0)
		{
			cout << "Case "<<++Case<< ": "<<"("<<"0"<< ")"<<endl;
		}
	
	}
	
	return 0;
}
