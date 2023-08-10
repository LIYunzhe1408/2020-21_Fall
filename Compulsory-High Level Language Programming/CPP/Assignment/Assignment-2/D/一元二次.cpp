#include <iostream>
#include <cmath>                             
using namespace std;

int main()
{    
	double a, b, c;
    cin >> a;
	cin >> b;
	cin >> c;
	double sq_dierta = (b*b-4*a*c); 
	double x, y;
	x =(-b+pow((b*b-4*a*c),0.5))/(2*a);
	y =(-b-pow((b*b-4*a*c),0.5))/(2*a);


       if (sq_dierta < 0 )
	{
		cout << "无实数根"<<endl;
    }
    
    
    
    
    
	if (sq_dierta >	 0)
	{ 
	if (x>= y)
	{
		cout <<y <<"， "<<x ;
	}
	else
	{
		cout <<x <<"， "<<y;
	}
	} 
	
	
    if( sq_dierta == 0)
	{
		cout <<x;
	} 
 



	return 0;
}



