#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string a;
	while(getline(cin,a))
	{
		int n = (int)(a[0] - '\0');
		if( n % 2 != 0)
		{
			cout << "YES"<<endl;
		}else if ( n == 0)
		{
			cout << "NO"<<endl;
		}else
		{
			cout << "NO"<<endl;
		}
	}
	

	return 0;
}

