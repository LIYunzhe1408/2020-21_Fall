#include <iostream>
using namespace std;
int cnt (int m, int n);


int main()
{
	int t;
	cin >> t;
	
	while ( t --){
		int M, N ;
		cin >> M >> N ;
		int k ;
		k = cnt ( M, N);
		cout << k << endl ;
		
	}
	return 0;
 } 
 
 int cnt (int m, int n )
 {
 	if ( m == 0 || n == 1){
 		return 1 ;
	 }
	 if ( m >= n){
	 	return (cnt( m , n - 1) + cnt ( m - n, n));
	 }
	 if ( m < n){
	 	return cnt ( m , m);
	 }
	 return 0 ;
 }
