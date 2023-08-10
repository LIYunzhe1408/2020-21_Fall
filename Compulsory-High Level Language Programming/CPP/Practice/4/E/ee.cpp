#include <iostream>
using namespace std;
 
 
int fun(int n){
    if(n==0)
       return 0;
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else if(n>2)
        return fun(n-1)+fun(n-2);
}
 
 
int main(){
   int n;
   cin>>n;
   int m=fun(n);
   cout<<m<<endl;
    return 0;
}

