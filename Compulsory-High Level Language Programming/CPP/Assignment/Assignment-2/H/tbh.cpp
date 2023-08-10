#include<iostream>
#include<math.h>

using namespace std;
int main()
{
long long Case,a,n,b;
long long c;
Case=0;

while(cin>>a>>n)
{
    c=a;
    b=a;
     cout<<"Case "<<++Case<<": "<<a;
     for (int i=1;i<=n-1;i++)
     {
         b=(b+a*pow(10,i));
         c=c+b;
         cout<<" + "<<b;	
     }
     cout<<" = "<<c<<endl;
}
return 0;
}
