#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int i=0; 
    string p;
	while(getline(cin,p))
	{
	    cout<<"Case "<<++i<<": ";
	    int ans=0,l=p.length()-1;
	    
	    if(p[l]!=' ') ans++;
	    for(int a=1;a<=l;a++)
		if(p[a]==' ' && p[a-1]!=' ') ans++;
		cout<<ans<<endl; 
	}
	return 0;
}
