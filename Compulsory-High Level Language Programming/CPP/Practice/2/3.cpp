#include <iostream> 
#include <iomanip>
using namespace std;
int main(){
	long a,b,c,x,y,z;
	cin>>x>>y>>z;
	c = (x-z)/2;
	a = (c+z+y)/2;
	b = x-a-c;
	cout<<a<<" "<<b<<" "<<c;
	return 0 ;
	
}
