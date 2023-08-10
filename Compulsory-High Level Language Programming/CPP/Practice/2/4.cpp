#include <iostream> 
#include <iomanip>
using namespace std;
int main(){
	long x, y, z, a ,b , c;
	cin>>x>>y>>z;
	c = (z + x/3 +(y+x/3)/3)/3;
	a = x/3 +(y+x/3)/3+c;
	b = (y+x/3)/3+c;
	
	cout<<a<<", "<<b<<", "<<c;
	return 0;
	
}
