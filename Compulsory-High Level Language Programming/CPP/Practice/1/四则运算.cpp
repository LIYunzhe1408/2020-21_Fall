#include <iostream>
using namespace std;

int main()
{
	cout << "plz input a algorithm: ";
	double a, b, r;
	char s, e;
	cin >> a >> s >>  b >> e >>r ; 
	double r1;
	
	if ( s == '+')
	{
		r1 = a + b;
		if ( r1 == r)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "wrong" <<endl;
		}
	}
	
	if ( s == '-')
	{
		r1 = a - b;
		if ( r1 == r)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "wrong" <<endl;
		}
	}
	
	if ( s == '*')
	{
		r1 = a * b;
		if ( r1 == r)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "wrong" <<endl;
		}
	}
	
	if ( s == '/')
	{
		if ( b!= 0){
		r1 = a / b;
		if ( r1 == r)
		{
			cout << "yes" << endl;
		}
		else 
		{
			cout << "wrong" <<endl;
		}
	    }
	}
	
	return 0;
 } 
