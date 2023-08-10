#include <iostream>
using namespace std;

int main()
{
	int a, b, cnt,  k = 0;
	while (cin >> a >>b )
{ 	
	int suma = 0, sumb = 0;   
	for (int i = 1;i < a; i++)
	{
		if ( a % i == 0)
		{
			suma += i;
		}
	}

	for (int j = 1;j < b; j++)
	{
		if ( b % j == 0)
		{
			sumb += j;
		}
	}
	
	
	if (suma == b && sumb ==a)
	{
		cout << "Case "<< ++k <<": "<<a<<", "<<b<<", " <<"Yes"<<endl;     
	}else {
		cout << "Case "<< ++k <<": "<<a<<", "<<b<<", " <<"No"<<endl;
	}
}


	return 0;
}
