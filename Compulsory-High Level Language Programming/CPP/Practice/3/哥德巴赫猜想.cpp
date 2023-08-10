#include <iostream>
using namespace std;
int is_prime( int n);

int main()
{
    int n, i ,j ,k, t = 1;
    cin >> n;

        
		
		for ( i = 2 ;i < n;i ++)
        {
        	if (is_prime(i) == 1 )
        	{
			for ( j = i;j < n - i	;j ++)
            {
            	if (is_prime(j) == 1 && is_prime(n-i-j) == 1)
            		
                    {
                        cout <<i<<" "<<j<<" "<< n - i -j<< endl;  
						 t = 0;
						break; 
                  
                    }
            }
            
            }
            if (t == 0){
            	break;
			}

            
        }          	
    return 0;
}






int is_prime( int n)
{
    int ret = 0, x = 1;
    if ( n == 1)
    {
        ret = 0;
    }
    if ( n == 2)
    {
        ret = 1;
    }
    for ( int i = 2; i < n;i ++)
    {
        if ( n % i == 0)
        {
            ret = 0;
            x = 0;
            break;
        }
        if ( x != 0)
        {
            ret = 1;
        }
        
    }
    return ret;
}
