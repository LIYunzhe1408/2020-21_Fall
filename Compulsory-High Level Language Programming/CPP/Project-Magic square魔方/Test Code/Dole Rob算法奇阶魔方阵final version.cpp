/***************************************************************************************************** 
高级语言C++程序设计小组作业：魔方阵
组号：第五小组
教师：张博锋 
组员：杜若彬 李仁杰 李昀哲 邱逸辰 倪思远 丁乐俊（按学号排序） 
——————————————————————————————————————————————————— 

程序日志： 
奇阶魔方阵 
排序方法：Dole Rob算法：将1列于第一行正中，依次将自然数排在其前一个数的右上方（按环绕边界处理）；
						遇到n的倍数时，将下一个自然数排在前一个数的下方。 
version 1.0
编写主程序和整张魔方阵输出。 
修改于2020.11.3 19：44 

version 1.1
1.将整张图输出修改为每填入一个数字输出一张图
2.加入Sleep程序，每张图延时输出。 
3.加入weishu函数
修改于2020.11.7 19:48

version 1.2
1. 优化用户交互界面
修改于2020.11.7 20:36

作者： 李昀哲 20123101 上海大学计算机工程与科学学院 

———————————————————————————————————————————————————— 

******************************************************************************************************/ 

#include <iostream>
#include <iomanip>
#include <windows.h> 
using namespace std;

int weishu(int a);//判断位数函数声明
void welcome();//交互界面 


//定义全局变量 
//n为每次输入的阶数;row, column为行、列 
int n = 0, row = 0, column = 0;

//a为容量为51，51的数组；element为每位的元素 
int Case = 0, element = 2;


//判断位数函数 
int weishu(int a)
{
	int ret = 1;
	while(a>9)
	{
		a /= 10;
		ret ++;
 	}	
 	return ret ;
}

void welcome()
{
	//用户交互界面 
	cout << "**********************************************************************"<<endl;
	cout << "*                    欢迎使用魔方幻阵Dole Rob算法                    *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                 Welcome to use Magic Cube of Dole Rob              *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                     作者团队：Group 5  @ SHU.CES                   *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                          指导老师：张博锋                          *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout << "请输入一个52以内的奇数："; 
} 

//主函数部分 
int main()
{
	welcome();//交互 
	
	while ( cin >> n)
	{
		int a[n][n] = {0};
		int (*p)[n] = a;//定义指针数组 
		int (*q)[n] = a;
		//初始化 
		element = 1, row = 0, column = (n - 1) / 2;//初始化每次的正中间的行、列、元素 
		cout << "Case "<<++Case<<":"<<endl; 
	
	
		//遍历数组，每个数为 0 
		for( int i = 0;i < n ; i ++)
		{
			for ( int j = 0; j < n; j++)
			{
				a[i][j] = 0;
			}
		}      
		
		
		a[row][column] = 1;//初始化1号元素 
		

		

		while ( element <= n * n )//元素小于n阶方阵的总位数 
		{
			
			if ( element != 1)//1 的情况特殊考虑 
			{
				if ( (element-1) % n == 0 ) //前一个元素是 n 的倍数的情况 
				{
					p++;//迭代 " 行 " 
					(*p)[column] = element; //本元素在前一个元素下方 
					row = row + 1;//迭代 " 行 " 
					column = column;//列 不变
					element++;// 元素+1 
//					continue;//直接进入下个循环 
				}
				else if ( row - 1 < 0 || column + 1 > n-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界 
				{
					if ( row - 1 < 0)// 如果"行"会超出边界 
					{
						p = q + n - 1;
					    a[n-1][column + 1] = element;//从第一行转到最后一行，列+1 
					    row = n - 1;//迭代 " 行 " 
 						column = column + 1;//"列 "+1，满足"右移"的条件 
 						element ++;//元素+1 
					}
					else if ( column + 1 > n-1)//继续判断" 列 "是否会超出边界的情况 
					{
						p--; // 迭代" 行 " 
						(*p)[0] = element;//从末列移动至第一列，行-1
						row = row - 1;//迭代 " 行 " 
						column = 0;//迭代" 列 " 
						element++;//元素+1 
//						continue;//直接进入下个循环 
					}
				}
				else//若先前特殊情况均不满足，则正常移动。 
				{
					p--;// 迭代" 行 " 
					(*p)[column + 1] = element;//本元素赋值给先前元素"右上"位置 
					row = row - 1;//迭代 " 行 " 				
					column = column + 1;//迭代" 列 " 
					element++;//元素+1 
				}
				
			}
			
		//每填入一个元素就遍历数组，填入element,其余为 " 0 " 
		if (element == 1)
		cout << "填入元素："<< element<<endl;
		else
	    cout << "填入元素："<< element - 1<<endl;
	    
	    
	    
		for(int x=0; x < n;x++)
		{ 
  			for(int y = 0; y < n;y++)
			{
   				cout << a[x][y];//输出此元素 
   				
   				for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系 
				{
    				cout<<" ";
   				}
   				if ( y == n - 1)//当 列数 == 最大列数时，换行 
				{
					cout<<endl;
				}
  			}
 		}
			cout << endl << endl;//每输出一张图，空一行 
			Sleep (50);//输出一张图，隔50毫秒再进入下个循环 
			
			if ( element == 1)//1的情况特殊考虑 
			{
				element ++;
			}
			
		}
		

		cout << "按回车继续输入 或 输入X退出";
		getchar(); 
		if (getchar() == 'X')
		{
			cout <<endl<<endl<<endl;
			cout << "**********************************************************************"<<endl;
			cout << "*                    感谢使用魔方幻阵Dole Rob算法                    *"<<endl;
			cout << "*                                                                    *"<<endl;
			cout << "*                     您的指点是对我们最大的帮助                     *"<<endl;
			cout << "**********************************************************************"<<endl;
			return 0;	
		} 
		else
		{
			cout << "请再输入一个52以内的奇数："; 
		}
			
	}

}
