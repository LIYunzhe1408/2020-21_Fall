#include <iostream>
using namespace std;
int fact(int n);


int main()
{
	int x, result,cnt= 0;
	cin >> x;
	result = fact(x);
	cout << result;
	
//	while ( cin >> x)
//{
//	result = fact(x);
//	while (result % 5 ==0 && result % 2 ==0 )
//	{
//		result /= 10;
//	    cnt ++;	
//	}
//    	cout <<cnt;
//}

 	
} 


int fact(int n)
{
	int ret,f;
	if (n == 0 || n == 1){
	f =1; 
    }else{
    	if ( n % 5 == 0)
    	{
    		ret ++;
		}
    f = fact(n-1)*n; 
	}
	return ret;
}
