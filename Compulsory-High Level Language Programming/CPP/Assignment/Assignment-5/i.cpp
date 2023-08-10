#include <iostream>
using namespace std;

int main()
{
	int Case = 0;
	string s, acr;
	
	while(getline(cin, s))
	{
		int l = s.length();
		cout <<"Case "<<++Case<<": ";
		if ( s[0] != 'T' && s[1] != 'h' && s[2] != 'e')
		{
			cout << s[0];
		}
		for(int i = 0;i < l;i++)
		{
			if ( s[i]>='A'&& s[i]<='Z' && (s[i-1] == ' ' ||(s[i-1] >='a' && s[i-1]<='z')||s[i-1] == '-'))
			{
				if((s[i] != 'O' && s[i+1] != 'F')||(s[i] != 'O' && s[i+1] != 'f'))
				{
//					if ((s[i] != 'A'&&s[i+1]== ' ')||(s[i] !='A'&&s[i+1] !='n'))
//					{
//						if ((s[i] !='A'&&s[i+1] !='N'))
//						{
//							if((s[i]!='F'&&s[i+1]!='o'&&s[i+2]!='r')||(s[i]!='F'&&s[i+1]!='O'&&s[i+2]!='R'))
//							{
//								if((s[i]!='A'&&s[i+1]!='n'&&s[i+2]!='d')||(s[i]!='A'&&s[i+1]!='N'&&s[i+2]!='D'))
//								{
									if((s[i]!='T'&&s[i+1]!='h'&&s[i+2]!='e') ||(s[i]!='T'&&s[i+1]!='H'&&s[i+2]!='E'))
									{
											cout << s[i];
									}
								}
//							}
//						}
//					
//				    }
//				}
			}
		}
		cout << endl;
	}
	return 0;
}
