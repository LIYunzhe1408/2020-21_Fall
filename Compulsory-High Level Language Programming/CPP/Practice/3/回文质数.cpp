#include <iostream>
#include <cmath>
using namespace std;
bool is_prime(long x)
{
    int i;
    for ( i = 3 ;i <= sqrt(x); i ++)
    {
        if ( x % i == 0)
            return false;
        
    }
    return true;
}


bool is_huiwen(long x)
{
	long  a = 0,n = x;
	while ( n > a)
	{
		a = a * 10 + n % 10;
		n = n /10;
	}
	return (n == a ) || (n == a/10);
	

}



int main()
{
    long  a, b, i;
    cin >>a>>b;
   
    for ( i = a; i <= b; i ++)
    {
    	if ( i % 2 != 0)
    	{
    		if (  is_huiwen(i) &&is_prime(i)  )
            {
        	
                cout << i <<endl; 
              
		    }
		}
        
       
    }
    return 0;
    
}








