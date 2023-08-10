#include<iostream>
#include<cmath>
using namespace std;
int weishu(int a){
 int w=1,c;
 c=a;
 while(a>9){
  a=a/10;
  w++;
 }
 a=c;
 return w;
}
int main(){
 int n,i=0,j=0;
 cin>>n;
 int a[n][n];
 int (*p)[n]=a;
 int (*q)[n]=a;
     for(int hang1=0;hang1<n;hang1++){
   for(int lie1=0;lie1<n;lie1++){
    i++;
    if(hang1==lie1||hang1==n-1-lie1){
     continue;
    }
    else{
     (*p)[lie1]=i;
    }
   }
   p++;
  }
 p=q+n-1;
  for(int hang2=n-1;hang2>=0;hang2--){
   for(int lie2=n-1;lie2>=0;lie2--){
    j++;
    if(hang2==lie2||hang2==n-1-lie2){
     (*p)[lie2]=j;
    }
    else{
     continue;
    }
   }
   p--;
  }
 p=q;
 for(int x=0;x<n;x++){
  for(int y=0;y<n;y++){
   cout<<(*p)[y];
   for(int z=0;z<5-weishu((*p)[y]);z++){
    cout<<" ";
   }
  }
  cout<<endl;
  p++;
 }
 

return 0;
}
