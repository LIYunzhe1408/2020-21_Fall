#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  char a;
  while ( getchar())
  {
  	a=getchar();
    if(a%2==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  
  return 0;
}
