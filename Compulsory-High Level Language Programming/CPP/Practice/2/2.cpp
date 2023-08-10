#include <iostream> 
#include <iomanip>
using namespace std;
int main(){
	int a,b,c,x,y,z;
	cin>>x >>y >>z ;
	a = (x-y+z)/2;
	b = x - a;
	c = z - a;
	cout<<a<< " "<<b<<" " <<c;
	return 0;
	
}
