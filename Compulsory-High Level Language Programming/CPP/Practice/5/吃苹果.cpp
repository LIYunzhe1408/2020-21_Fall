#include <iostream>
using namespace std;

int main()
{
	int x, y, n, a, b;
	cin >> n >> x >> y ;
	b = y % x ;
	if ( y <= n * x){
	
		if (b == 0){//d等于运算是==而不是=！！！！ 
		a = (n - y / x) ;
	    cout << a ; 
		}else {
		a = (n - y / x) -1 ;
		cout << a ;
	
        }
	}
	return 0;
}
