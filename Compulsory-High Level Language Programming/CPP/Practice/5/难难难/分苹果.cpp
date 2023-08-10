/***************************************
描述
把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

输入
第一行是测试数据的数目t（0≤t≤20）。以下每行均包含二个整数M和N，以空格分开。1≤M，N≤10。

输出
对输入的每组数据 M和 N，用一行输出相应的K。
*********************************************/
//代码：https://blog.csdn.net/fun_always/article/details/94433863?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param 


/*分析
递归
f(m,n)表示m个苹果放到n个盘子中的方法数
当n>m时，必然有盘子是空的，因为最多也就用到m个盘子，因此f(m,n)=f(m,m);
当n<=m时，有两种情况：
有盘子为空时：
f(m,n)=f(m,n-1)因为至少有一个为空，那去掉一个完全不影响已有的方法数（反正这个空盘子不会放苹果）
当盘子不空的时候，全部n个盘子都有装苹果，那所有的都可以拿掉一个苹果，也就是
f(m,n)=f(m-n,n) 方法数是一样的，只不过所有盘子都用上的时候每个盘子装的数量可能不一样
而n<=m的时候就是有空和没空两种情况的和
f(n,m)=f(m,n-1)+f(m-n,n)
两者递归时，n和m都会逐渐减小 ，出口为n==1||m==0的时候，都只有一种方法 */ 


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
