#include <iostream>
using namespace std;
int isPrime(int n); 

int main()
{
	int x, result, i = 1;
	while (cin >> x )
{
	if ( x > 0)
{
	
	result = isPrime (x);
	if (result == 1)
	{
		cout <<"Case "<<i<<": Number "<<x<<" is prime."<<endl;
	}
	else 
	{
		cout <<"Case "<<i<<": Number "<<x<<" is not prime."<<endl;
	}
	i ++;
}
}
	return 0;
}


int isPrime(int n)
{
	int ret, t = 0;
	if ( n ==2)//�ų� 2 ����� 
	{
		ret = 1;
	}
	else if ( n ==1)//�ų�1 ����� 
	{
	    ret = 0;
	}
	//�ձ���� 
	else
	{
	    for ( int i = 2;i < n; i++)
	{
		if ( n % i == 0)
		{
			t = 1;
		    ret = 0;
		    break;
		}
    }
	    if ( t != 1)
	    {
		ret = 1;
	    }
	}
	return ret;
}
