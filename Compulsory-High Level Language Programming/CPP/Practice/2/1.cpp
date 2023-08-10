#include <iostream> 
#include <iomanip>
using namespace std;
int main(){
	double s, v1, v2,v3,d,t;
	cin>>s >>v1 >>v2 >>v3 ;
	t = s/(v1+v2);
	d = v3*t;	
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<d;
	return 0 ;
}
