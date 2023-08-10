#include <iostream>
#include<istream>
#include<string>
using namespace std;
int main()
{
   string a,b;
int Case=0;
	while(getline(cin,a))
    {
	int len= a.length()-1;
	int i=0;

	while(len>=0)
    {
        if(a[len]-1>=0&&a[len]-1<=126)
        {
            b[i]=a[len];
            len--;
            i++;
        }
        else
        {
           b[i]=a[len-1];
            b[i+1]=a[len];
            len=len-2;
            i=i+2;
        }

    }
	cout<<"Case "<<++Case<<": "<<'\"';
	for(int k=0;k<=i-1;k++)
    {
        cout<<b[k];
    }
	cout<<'\"'<<endl;

    }
}
