#include<iostream>
#include<cstring>
#include<memory>

//ʵ���ַ�������ת(����,��ĸ,����)

using namespace std;

#define MAX 1000

//�ⷨ1: ָ��
void res(char *s) //����(������)�ַ���
{
	int len = strlen(s);//�ַ�������;
	char *p = new char[len + 1];//����ѿռ����ַ���
	for (int i = 0, t = len - 1; s[i]; )
	{
		if (s[i] > 0) {//�Ǻ���һ��һ���ַ���ת;
			p[t--] = s[i++];
		}else{//�������������ַ���ת;
			p[t - 1] = s[i];
			p[t] = s[i + 1];
			t -= 2;
			i += 2;
		}
	}
	strcpy(s,p);
	delete[]p; //�ͷŶѿռ�
	
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
