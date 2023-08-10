#include <iostream>
#include <cstring>
using namespace std;

void reve(char *s)
{
	char r[1000];
	int length = strlen(s);
	for(int i = 0, t = length - 1;i < length;)
	{
		if(s[i] > 0)//不是汉字的时候 
		{
			r[t] = s[i];
			t--;
			i++;
		}
		else
		{
			r[t-1] = s[i];
			r[t] = s[i+1];
			t-=2;
			i+=2;
		}
	}
	strcpy(s,r);
}
 
int main()
{
	char s[1000];
	int Case = 0;
	
	while (gets(s))
	{
		cout <<"Case "<<++Case<<": \"";
		reve(s);
		cout << s<<"\""<<endl;
	}
	
    return 0;
}
