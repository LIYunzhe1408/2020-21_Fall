#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c, i = 0;
	double sq_dierta = (b*b-4*a*c); 
	double x, y;
	while ( cin >> a >> b >> c)
	{
		double sq_dierta = (b*b-4*a*c); 
			x =(-b+pow((b*b-4*a*c),0.5))/(2*a);
	y =(-b-pow((b*b-4*a*c),0.5))/(2*a);


       if (sq_dierta < 0 )
	{
		cout <<"Case "<<++i <<": "<< "无实数根"<<endl;
    }
    
    
    
    
    
	if (sq_dierta >	 0)
	{ 
	if (x>= y)
	{
		cout <<"Case "<<++i <<": "<< y <<", "<<x <<endl;
	}
	else
	{
		cout <<"Case "<<++i <<": "<<x <<", "<<y <<endl;
	}
	} 
	
	
    if( sq_dierta == 0)
	{
		cout <<"Case "<<++i <<": "<<x<<endl;
	} 
 
	}
	return 0;
}
