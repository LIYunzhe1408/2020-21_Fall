#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long x ;
	cin >> x ;
	cout << oct << x << "(Oct)"<< ','<<' ' 
	     << dec << x <<"(Dec)"<<','<< ' '
		 << setiosflags(ios::uppercase)<< hex<<x <<"(Hex)"<< '\n'; 
	return 0;
}
