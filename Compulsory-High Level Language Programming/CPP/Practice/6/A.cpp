#include <iostream>
using namespace std;

int main()
{
	int fengliu, gaokao, xueke, pingshi;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> gaokao>>xueke>>pingshi;
		fengliu = gaokao * 0.45 + xueke * 0.45 + pingshi * 0.1; 
		cout << fengliu<<endl;
	}
	
	return 0;
}
