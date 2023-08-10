#include <iostream>
using namespace std;

int main()
{
	int Case = 0, mark = 0, cnt = 0;
	string s1, s2;
	while ( getline(cin, s1))
	{
		getline(cin, s2);
		int l1 = s1.length(), l2 = s2.length();
		cout << "Case "<<++Case<<": ";
		
		for ( int i = 0;i < l2;i++)
		{
			if (s2[i] == s1[0])
			{
				cnt = i;
				for (int k = i, j = 0; j < l1;k++, j++)
				{
					if (s2[k] != s1[j])
					{
						mark = 0;
						break;
					}
					else
					{
						mark = 1;
					}
				}break; 
			}	
		} 
		
		if ( mark == 0)
		{
			cout <<"-1"<<endl;
		}
		else
		{
			cout << cnt<<endl;
		}
		cnt = 0, mark = 0;
			
		
	} 
	return 0;
}
