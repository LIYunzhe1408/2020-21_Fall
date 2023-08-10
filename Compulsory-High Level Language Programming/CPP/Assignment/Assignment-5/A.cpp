#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, Case = 0, cnt = 0, i, k, j;
	int mark[1000];
	
	while ( cin >> n)
	{
	    string s[63356];
		i = 0, k = 0, j = 0;
		for ( int i = 0; i <= n;i++)
		{
			mark[i] = 0;
			getline(cin,s[i]);
			int l = s[i].length();
			for ( int j = 0;j < l/2;j++)
			{
				if ( (s[i])[j] != (s[i])[l-j-1])
				{
					mark[i] = 0;
					break;
				}
				else
				{
					mark[i] = 1;
				} 
			}	
		}
		for ( int k = 1;k <= n;k++)
		{
			if ( mark[k] == 0)
				cout <<"Case "<<++Case<<": " <<"No"<<endl;
			else	
				cout <<"Case "<<++Case<<": " << "Yes"<< endl;	
		}
	
//		for ( int j = 0;j < n;j++)
//		{
//			int l = s[j].length();
//			for (int k = 0;k < n;k++)
//			{
//				
//				if ( (s[j])[k] == (s[j])[l-k-1])
//				{
//					cnt++;
//				}else
//				{
//					cout <<"Case "<<++Case<<": " <<"No"<<endl;
//					break;
//				}
//			}
//			if ( cnt == l)
//			{
//				cout <<"Case "<<++Case<<": " << "Yes"<< endl;
//			}
//			cnt = 0, i = 0, k = 0, j = 0;
//		
//		}
	}
	return 0;
} 
