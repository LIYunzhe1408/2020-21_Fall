/***************************************
����
��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���

����
��һ���ǲ������ݵ���Ŀt��0��t��20��������ÿ�о�������������M��N���Կո�ֿ���1��M��N��10��

���
�������ÿ������ M�� N����һ�������Ӧ��K��
*********************************************/
//���룺https://blog.csdn.net/fun_always/article/details/94433863?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param 


/*����
�ݹ�
f(m,n)��ʾm��ƻ���ŵ�n�������еķ�����
��n>mʱ����Ȼ�������ǿյģ���Ϊ���Ҳ���õ�m�����ӣ����f(m,n)=f(m,m);
��n<=mʱ�������������
������Ϊ��ʱ��
f(m,n)=f(m,n-1)��Ϊ������һ��Ϊ�գ���ȥ��һ����ȫ��Ӱ�����еķ�������������������Ӳ����ƻ����
�����Ӳ��յ�ʱ��ȫ��n�����Ӷ���װƻ���������еĶ������õ�һ��ƻ����Ҳ����
f(m,n)=f(m-n,n) ��������һ���ģ�ֻ�����������Ӷ����ϵ�ʱ��ÿ������װ���������ܲ�һ��
��n<=m��ʱ������пպ�û����������ĺ�
f(n,m)=f(m,n-1)+f(m-n,n)
���ߵݹ�ʱ��n��m�����𽥼�С ������Ϊn==1||m==0��ʱ�򣬶�ֻ��һ�ַ��� */ 


#include<iostream>
using namespace std;
int count(int m,int n);

int main(){
	int k;
	cin>>k;
	while(k--){
		int m,n;
		cin>>m>>n;
		int ans ;
		ans = count(m,n);
		cout<<ans<<endl;
		ans = 0 ;//?
	}
	return 0;
} 

int count(int m,int n){
	if(m==0||n==1){
		return 1;
	}
	if(m>=n){
		return (count(m,n-1)+count(m-n,n));
	}
	if(m<n){
		return (count(m,m));
	}
	return 0 ;
}
