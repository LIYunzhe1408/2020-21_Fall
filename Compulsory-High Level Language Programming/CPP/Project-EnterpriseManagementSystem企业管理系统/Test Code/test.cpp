#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
void bound(char ch,int n);

int main()
{
	FILE *fp;
	if  ((fp = fopen("C:\Users\Jonas Li\Desktop\employee.txt","r")) == NULL)
	{
		printf("")
	}
	return 0;
}

void bound(char ch,int n)
{
    while(n--)
		putchar(ch);
//	printf("\n");
	return;
}
