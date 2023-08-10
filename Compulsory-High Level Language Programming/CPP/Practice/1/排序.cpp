#include <iostream>
#include <algorithm> 
using namespace std;

int main()
{
	int s[3] ;
	cin >> s[0]>>s[1]>>s[2];
	sort(s,s+3);
	for (int i = 0; i <=2; i++)
	{
		cout << s[i]<<" ";
	}
	cout << '\n';
	return 0;
}
