#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int i=0;
	string str1,str2;
	while(getline(cin,str1))
	{
		getline(cin,str2);
		int a,b,l1=str1.length()-1,l2=str2.length()-1;
		cout<<"Case "<<++i<<": ";
		for(a=0;a<=l2-l1;a++)
		{
			for(b=0;b<=l1;b++)
			if(str1[b]!=str2[a+b]) break;
			if(b==l1+1)
			{
				cout<<a;
				break;
			}
		}
		if(a==l2-l1+1) cout<<"-1";
		cout<<endl;
	}
	return 0;
} 

