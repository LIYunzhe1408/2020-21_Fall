#include<iostream>
#include<cstring>
#include<memory>

//实现字符串的逆转(汉字,字母,数字)

using namespace std;

#define MAX 1000

//解法1: 指针
void res(char *s) //逆序(带中文)字符串
{
	int len = strlen(s);//字符串长度;
	char *p = new char[len + 1];//申请堆空间存放字符串
	for (int i = 0, t = len - 1; s[i]; )
	{
		if (s[i] > 0) {//非汉字一个一个字符逆转;
			p[t--] = s[i++];
		}else{//汉字两个两个字符逆转;
			p[t - 1] = s[i];
			p[t] = s[i + 1];
			t -= 2;
			i += 2;
		}
	}
	strcpy(s,p);
	delete[]p; //释放堆空间
	
}
int main()
{
	char a[65536];
	int Case = 0;
	while(	cin >> a)
	{
		res(a);
     	cout <<"Case "<<++Case<<": "<<'"' << a<<'"' << endl;	
	}

	return 0;
} 
