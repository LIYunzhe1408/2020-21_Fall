/************************************ 
奇阶魔方阵 
排序方法：Dole Rob算法：将1列于第一行正中，依次将自然数排在其前一个数的右上方（按环绕边界处理）；
						遇到n的倍数时，将下一个自然数排在前一个数的下方。 
version 1.0
修改于2020.11.3 19：44 
作者： 李昀哲 
*************************************/ 

#include <iostream>
#include <iomanip>
#include <windows.h> 
using namespace std;


//定义全局变量 
//n为每次输入的阶数;row, column为行、列 
int n = 0, row = 0, column = 0 ;

//a为容量为51，51的数组；element为每位的元素 
int Case = 0, a[51][51], element = 2;




int main()
{
	cout << "**********************************************************************"<<endl;
	cout << "*                    欢迎使用魔方幻阵Dole Rob算法                    *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout << "请输入一个数字:"; 
	while ( cin >> n)
	{
		//初始化 
		element = 2, row = 0, column = (n - 1) / 2;//初始化每次的正中间的行、列、元素 
		cout << "Case "<<++Case<<":"<<endl;      
		a[row][column] = 1;//初始化1号元素 
		

		while ( element <= n * n )//元素小于n阶方阵的总位数 
		{

			if ( (element-1) % n == 0)//前一个元素是 n 的倍数的情况 
			{
				a[row+1][column] = element; //本元素在前一个元素下方 
				row = row + 1;//迭代 " 行 " 
				column = column;//列 不变 
				element++;// 元素+1 
//				continue;//直接进入下个循环 
			}
			else if ( row-1 < 0 || column+1 > n-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界 
			{
				if ( row-1 < 0)// 如果"行"会超出边界 
				{
					a[n-1][ column+1] = element;//从第一行转到最后一行，列+1 
					row = n - 1;//迭代" 行 " 
 					column = column + 1;//"列 "+1，满足"右移"的条件 
 					element ++;//元素+1 
				}
				if ( column+1 > n-1)//继续判断" 列 "是否会超出边界的情况 
				{
					a[row-1][0] = element;//从末列移动至第一列，行-1 
					row = row - 1;// 迭代" 行 " 
					column = 0;//迭代" 列 " 
					element++;//元素+1 
//					continue;//直接进入下个循环 
				}
			}
			else//若先前特殊情况均不满足，则正常移动。 
			{
				a[row-1][ column+1] = element;//本元素赋值给先前元素"右上"位置 
				row = row - 1;// 迭代" 行 " 				
				column = column + 1;//迭代" 列 " 
				element++;//元素+1 
			}
			
			
			for ( int x = 0; x < n; x++ )
			{
				for ( int y = 0; y < n; y ++)
				{
					if ( y == n - 1)
					{
						cout<< a[x][y]<<endl;
					}
					else
						cout << a[x][y]<<"  ";
				}
			}
			cout << endl << endl;
			Sleep (300);
		}
	}
		
		
//		for ( int x = 0; x < n; x++ )
//		{
//			for ( int y = 0; y < n; y ++)
//			{
//				if ( y == n - 1)
//				{
//					cout<< a[x][y]<<endl;
//				}else
//				cout << a[x][y]<<"  ";
//				Sleep(1000);//每个输出延时1000毫秒，即1秒 
//			}
//		}

	
	return 0;
}
