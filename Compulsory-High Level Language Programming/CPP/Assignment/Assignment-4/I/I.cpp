#include <iostream>
using namespace std;

int main()
{
	int n, m, Case = 0;
	
	while ( cin >> n >> m)
	{
	    cout << "Case "<<++Case<<": "<< n << ", "<< m<<", ";	
		if ( n > m)
		{
			cout << m + 1<<endl;
		}
		else
		{
			cout << m % n + 1<<endl;
		}
	}

	return 0;
}
