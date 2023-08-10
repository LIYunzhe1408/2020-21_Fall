/***************************************************************************************************** 
高级语言C++程序设计小组作业：魔方阵 
组号：第五小组 
教师：张博锋 
组员：杜若彬 20122954 李仁杰 20122986 郭风麟 20122997 
      李昀哲 20123101 邱逸辰 20123102
	  倪思远 20123103 丁乐俊 20123104（按学号排序） 
——————————————————————————————————————————————————— 

程序修订日志： 
奇阶魔方阵 
排序方法：Dole Rob算法：将1列于第一行正中，依次将自然数排在其前一个数的右上方（按环绕边界处理）； 
						遇到n的倍数时，将下一个自然数排在前一个数的下方。 
						 
version 1.0
编写主程序和整张魔方阵输出。 
修改于2020.11.3 19：44 

version 1.1
1.将整张图输出修改为每填入一个数字输出一张图 
2.加入Sleep函数，每张图延时输出。 
3.加入weishu函数 
修改于2020.11.7 19:48

version 1.2
1. 优化用户交互界面 
修改于2020.11.7 20:36

作者： 李昀哲 20123101 上海大学计算机工程与科学学院 
———————————————————————————————————————————————————— 
偶阶魔方阵（能被4整除） 
排序方法：1.先标记两条对角线的位置；
          2.从1到n*n的整数依次从左到右、从上到下填入魔方阵，跳过标记部分；
		  3.从1到n*n的整数依次从右向左、从下到上填入魔方阵，跳过非标记部分。
version 1.0
编写主程序和整张魔方阵输出。 
修改于2020.11.3 20:12

version 1.1
1.改为指针读取
2.加入位数函数
修改于2020.11.3 21:46 

version 1.2
1. 加入Sleep函数，每张图延时输出。
修改于2020.11.7 20:18

作者 ：倪思远 20123103 上海大学计算机工程与科学学院 
———————————————————————————————————————————————————— 
偶阶魔方阵（不能被4整除）
排序方法：1.将幻方平分为4个奇数阶小魔方阵
          2.以"左上(A)、右下(D)、右上(B)、左下(C)"的顺序依次填充4个奇数阶小魔方阵
		  3.在A象限的中间行、中间格开始，按自左向右的方向，标出(n-2)/4格。
		    A象限的其它行则标出最左边的(n-2)/4格。将这些格，和C象限相对位置上的数互换位置。
		  4.在B象限所有行的中间格，自右向左，标出(n-2)/4－1格。
		    (注：6阶幻方由于(n-2)/4－1=0，所以不用再作B、D象限的数据交换)，
		    将这些格，和D象限相对位置上的数互换位置。
version 1.0
编写主程序和整张魔方阵输出。 
修改于2020.11.7 16:37

version 1.1
1.改为指针读取
2.加入weishu函数
3.优化用户交互界面
修改于2020.11.8 15:55

作者：杜若彬  20122954 上海大学计算机工程与科学学院; 
	  郭风麟  20122997 上海大学计算机工程与科学学院 
******************************************************************************************************/ 
//头文件声明
#include <iostream>
#include <iomanip>
#include <windows.h> 
#include <cmath>
using namespace std; 


//函数声明 
int weishu(int a);//判断位数函数声明
void welcome();//交互界面函数声明  
void welcome1();
void welcome2();
void welcome3();
void thanku();


//定义全局变量 
long long n = 0;//n为每次输入的阶数
double nn; 
int Case = 0;


//子函数 
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

//交互界面函数 
void welcome()
{
	//用户交互界面 
	cout << "**********************************************************************"<<endl;
	cout << "*                                主界面                              *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                         欢迎使用魔方幻阵算法                       *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                     Welcome  to  use  Magic  Cube                  *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                     作者团队：Group 5  @ SHU.CES                   *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                           指导老师：张博锋                         *"<<endl;
	cout << "*                               输入X退出                            *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout << "请输入："; 
} 

void welcome1()
{
	//用户交互界面 
	cout << "**********************************************************************"<<endl;
	cout << "*                   欢迎使用奇阶魔方幻阵Dole Rob算法                 *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                 Welcome to use Magic Cube of Dole Rob              *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                     作者团队：Group 5  @ SHU.CES                   *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                          指导老师：张博锋                          *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout<<"请再次确认输入: ";
} 

void welcome2()
{
	//用户交互界面 
	cout << "**********************************************************************"<<endl;
	cout << "*                  欢迎使用偶阶(仅4的倍数)魔方幻阵算法               *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                       Welcome to use Magic Cube                    *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                      作者团队：Group 5  @ SHU.CES                  *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                            指导老师：张博锋                        *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout<<"请再次确认输入: ";
} 

void welcome3()
{
	//用户交互界面 
	cout << "**********************************************************************"<<endl;
	cout << "*                  欢迎使用偶阶(非4的倍数)魔方幻阵算法               *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                       Welcome to use Magic Cube                    *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                      作者团队：Group 5  @ SHU.CES                  *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                            指导老师：张博锋                        *"<<endl;
	cout << "**********************************************************************"<<endl<<endl; 
	//用户输入 
	cout<<"请再次确认输入: ";
}
void thanku()
{	
	cout <<endl<<endl<<endl;		
	cout << "**********************************************************************"<<endl;
	cout << "*                        感谢使用魔方幻阵算法                        *"<<endl;
	cout << "*                                                                    *"<<endl;
	cout << "*                     您的指点是对我们最大的帮助                     *"<<endl;
	cout << "**********************************************************************"<<endl;
}

//奇数函数部分 
void ji()
{
	long long n1;
	double nnn;
	welcome1();//交互 
	cin >> nnn;
	n1=nnn;
	cout<<endl<<endl;
	if(n1-nnn>0&&n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，且不允许小数的出现，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(nnn-n1>0)
	{
		cout<<"我都已经猜到啦！！！重来！！(不允许小数出现)"<<endl<<endl;
		Sleep(500); 
		return;
	}
	if(n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1>709)
	{
		cout<<"电脑撑不住！！！重来！！(请输入小于710的数值，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
		if(n1!=n)
		{
			cout<<"两次输入值不符，回到主页面…………"<<endl<<endl<<endl; 
			Sleep(500);
			return;
		}
		int row, column, element;//row, column为行、列;element为每位的元素
		int a[n1][n1];
		int (*p)[n1] = a;//定义指针数组 
		int (*q)[n1] = a;
		//初始化 
		memset(a,0,sizeof(a));
		element = 1, row = 0, column = (n1 - 1) / 2;//初始化每次的正中间的行、列、元素 
		cout << "Case "<<++Case<<":"<<endl; 
	
		//数组初始化为 0 
		//memset(a,0,sizeof(a));      
		
		a[row][column] = 1;//初始化1号元素 

		while ( element <= n1 * n1 )//元素小于n阶方阵的总位数 
		{
			if ( element != 1)//1 的情况特殊考虑 
			{
				if ( (element-1) % n1 == 0 ) //前一个元素是 n 的倍数的情况 
				{
					p++;//迭代 " 行 " 
					(*p)[column] = element; //本元素在前一个元素下方 
					row = row + 1;//迭代 " 行 " 
					column = column;//列 不变
					element++;// 元素+1 
//					continue;//直接进入下个循环 
				}
				else if ( row - 1 < 0 || column + 1 > n1-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界 
				{
					if ( row - 1 < 0)// 如果"行"会超出边界 
					{
						p = q + n1 - 1;
					    a[n1-1][column + 1] = element;//从第一行转到最后一行，列+1 
					    row = n1 - 1;//迭代 " 行 " 
 						column = column + 1;//"列 "+1，满足"右移"的条件 
 						element ++;//元素+1 
					}
					else if ( column + 1 > n1-1)//继续判断" 列 "是否会超出边界的情况 
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
		
		for(int x=0; x < n1;x++)
		{ 
  			for(int y = 0; y < n1;y++)
			{
   				cout << a[x][y];								//输出此元素 
   				
   				for(int z = 0;z < 5 - weishu(a[x][y]);z++)	//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系 
				{
    				cout<<" ";
   				}
   				if ( y == n1 - 1)//当 列数 == 最大列数时，换行 
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
}

//偶数（可以被4整除）函数部分 
void ou4()
{
	double nnn;
	int i=0,j=0;
	long long n1;
	welcome2(); 
	cin>>nnn;
	n1=nnn;
	cout<<endl<<endl;
	if(n1-nnn>0&&n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，且不允许小数的出现，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}	
	if(nnn-n1>0)
	{
		cout<<"我都已经猜到啦！！！重来！！(不允许小数出现)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1>709)
	{
		cout<<"电脑撑不住！！！重来！！(请输入小于710的数值，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1!=n)
	{
		cout<<"两次输入值不符，回到主页面…………"<<endl<<endl<<endl; 
		Sleep(500);
		return;
	}
	cout << "Case "<<++Case<<":"<<endl; 
	int a[n][n];
    memset(a,0,sizeof(a)); 
	int (*p)[n]=a;
	int (*q)[n]=a;
	int (*g)[n]=a;
	    for(int hang1=0;hang1<n;hang1++){
			for(int lie1=0;lie1<n;lie1++){
				i++;
				if(hang1==lie1||hang1==n-1-lie1){
					continue;
				}
				else{
					(*p)[lie1]=i;
					g=q;
						for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<(*g)[y];
			for(int z=0;z<5-weishu((*g)[y]);z++){
				cout<<" ";
			}
		}
		cout<<endl;
		g++;
	}
					cout<<endl;	
						cout<<endl;
				}
			}
			p++;
		}
	p=q+n-1;
		for(int hang2=n-1;hang2>=0;hang2--){
			for(int lie2=n-1;lie2>=0;lie2--){
				j++;
				if(hang2==lie2||hang2==n-1-lie2){
					(*p)[lie2]=j;	
					g=q;
					for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<(*g)[y];
			for(int z=0;z<5-weishu((*g)[y]);z++){
				cout<<" ";
			}
		}
		cout<<endl;
		g++;
	}
		cout<<endl;
	    cout<<endl;
				}
				else{
					continue;
				}
			}
			p--;
		}
	p=q;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			cout<<(*p)[y];
			for(int z=0;z<5-weishu((*p)[y]);z++){
				cout<<" ";
			}
		}
		cout<<endl;
		p++;
	}
	

return;
}

//偶数（不可以被4整除）函数部分 
void ou()
{
	double nnn;
	welcome3(); 
	long long n1;
	cin >> nnn;
	n1=nnn;
	cout<<endl<<endl;
	if(n1-nnn>0&&n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，且不允许小数的出现，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}	
	if(nnn-n1>0)
	{
		cout<<"我都已经猜到啦！！！重来！！(不允许小数出现)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1>709)
	{
		cout<<"电脑撑不住！！！重来！！(请输入小于710的数值，谢谢)"<<endl<<endl;
		Sleep(500);
		return;
	}
	if(n1!=n)
	{
		cout<<"两次输入值不符，回到主页面…………"<<endl<<endl<<endl; 
		Sleep(500);
		return;
	}
	cout << "Case "<<++Case<<":"<<endl; 
	int a[n1][n1] ;
	int (*p)[n1] = a;//定义指针数组
	int (*q)[n1] = a;
	memset(a,0,sizeof(a)); 
    int element = 1, row = 0, column = (n1/2 - 1) / 2;//初始化每次的正中间的行、列、元素

    a[row][column] = 1;//初始化1号元素
    while ( element <= n1 * n1 / 4 )
    {
        if ( element != 1)//1 的情况特殊考虑
        {
            if ( (element-1) % (n1/2) == 0 ) //前一个元素是 n 的倍数的情况
            {
                p++;//迭代 " 行 "
                (*p)[column] = element; //本元素在前一个元素下方
                row = row + 1;//迭代 " 行 "
                column = column;//列 不变
                element++;// 元素+1
//					continue;//直接进入下个循环
            }
            else if ( row - 1 < 0 || column + 1 > n1/2-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界
            {
                if ( row - 1 < 0)// 如果"行"会超出边界
                {
                    p = q + n1/2 - 1;
                    a[n1/2-1][column + 1] = element;//从第一行转到最后一行，列+1
                    row = n1/2 - 1;//迭代 " 行 "
                    column = column + 1;//"列 "+1，满足"右移"的条件
                    element ++;//元素+1
                }
                else if ( column + 1 > n1/2-1)//继续判断" 列 "是否会超出边界的情况
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
        if ( element == 1)//1的情况特殊考虑
		{
			element ++;
		}
    }
    for(int x=0; x < n1;x++)
	{
		for(int y = 0; y < n1;y++)
		{
			cout << a[x][y];//输出此元素

			for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
			{
				cout<<" ";
			}
			if ( y == n1 - 1)//当 列数 == 最大列数时，换行
			{
				cout<<endl;
			}
		}
	}
	cout<<endl<<endl;
    row = n1/2, column = (n1/2 - 1) + (n1/2 + 1) / 2;//初始化每次的正中间的行、列、元素

    a[row][column] = element;//初始化1.2号元素
    q= &a[n1/2];
    while ( element <= n1 * n1/2 )
    {

        if ( element != n1*n1/4+1)//1 的情况特殊考虑
        {
            if ( (element-1) % (n1/2) == 0 ) //前一个元素是 n 的倍数的情况
            {
                p++;//迭代 " 行 "
                (*p)[column] = element; //本元素在前一个元素下方
                row = row + 1;//迭代 " 行 "
                column = column;//列 不变
                element++;// 元素+1
//					continue;//直接进入下个循环
            }
            else if ( row - 1 < n1/2 || column + 1 > n1-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界
            {
                if ( row - 1 < n1/2)// 如果"行"会超出边界
                {
                    p = q + n1/2 - 1;
                    a[n-1][column + 1] = element;//从第一行转到最后一行，列+1
                    row = n1 - 1;//迭代 " 行 "
                    column = column + 1;//"列 "+1，满足"右移"的条件
                    element ++;//元素+1
                }
                else if ( column + 1 > n1-1)//继续判断" 列 "是否会超出边界的情况
                {
                    p--; // 迭代" 行 "
                    (*p)[n1/2] = element;
                    row = row - 1;//迭代 " 行 "
                    column = n1/2;//迭代" 列 "
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
        if ( element == n1*n1/4+1)//1的情况特殊考虑
		{
			element ++;
		}
    }
    for(int x=0; x < n1;x++)
	{
		for(int y = 0; y < n1;y++)
		{
			cout << a[x][y];//输出此元素

			for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
			{
				cout<<" ";
			}
			if ( y == n1 - 1)//当 列数 == 最大列数时，换行
			{
				cout<<endl;
			}
		}
	}
	cout<<endl<<endl;
    row = 0, column = (n1/2 - 1) + (n1/2 + 1) / 2;//初始化每次的正中间的行、列、元素

    a[row][column] = n1*n1/2+1;//初始化1.2号元素
    q=a;
    while ( element <= n1 * n1*3/4 )
    {

        if ( element != n1*n1/2+1)//1 的情况特殊考虑
        {
            if ( (element-1) % (n1/2) == 0 ) //前一个元素是 n 的倍数的情况
            {
                p++;//迭代 " 行 "
                (*p)[column] = element; //本元素在前一个元素下方
                row = row + 1;//迭代 " 行 "
                column = column;//列 不变
                element++;// 元素+1
//					continue;//直接进入下个循环
            }
            else if ( row - 1 < 0 || column + 1 > n1-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界
            {
                if ( row - 1 < 0)// 如果"行"会超出边界
                {
                    p = q+n1/2-1;
                    a[n1/2-1][column + 1] = element;//从第一行转到最后一行，列+1
                    row = n1/2 - 1;//迭代 " 行 "
                    column = column + 1;//"列 "+1，满足"右移"的条件
                    element ++;//元素+1
                }
                else if ( column + 1 > n1-1)//继续判断" 列 "是否会超出边界的情况
                {
                    p--; // 迭代" 行 "
                    (*p)[n1/2] = element;//从末列移动至第一列，行-1
                    row = row - 1;//迭代 " 行 "
                    column = n1/2;//迭代" 列 "
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
        if ( element == n1*n1/2+1)//1的情况特殊考虑
		{
			element ++;
		}
    }
    for(int x=0; x < n1;x++)
	{
		for(int y = 0; y < n1;y++)
		{
			cout << a[x][y];//输出此元素

			for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
			{
				cout<<" ";
			}
			if ( y == n1 - 1)//当 列数 == 最大列数时，换行
			{
				cout<<endl;
			}
		}
	}
	cout<<endl<<endl;
    row = n1/2, column = (n1/2-1)/2;//初始化每次的正中间的行、列、元素

    a[row][column] = n1*n1/4*3+1;//初始化1.2号元素
    q=&a[n1/2];
    while ( element <= n1 * n1 )
    {

        if ( element != n1*n1*3/4+1)//1 的情况特殊考虑
        {
            if ( (element-1) % (n1/2) == 0 ) //前一个元素是 n 的倍数的情况
            {
                p++;//迭代 " 行 "
                (*p)[column] = element; //本元素在前一个元素下方
                row = row + 1;//迭代 " 行 "
                column = column;//列 不变
                element++;// 元素+1
//					continue;//直接进入下个循环
            }
            else if ( row - 1 < n1/2 || column + 1 > n1/2-1 )//若不是倍数的情况，判断向"右上"移动是否会超出边界
            {
                if ( row - 1 < n1/2)// 如果"行"会超出边界
                {
                    p = q + n1/2 - 1;
                    a[n-1][column + 1] = element;//从第一行转到最后一行，列+1
                    row = n1 - 1;//迭代 " 行 "
                    column = column + 1;//"列 "+1，满足"右移"的条件
                    element ++;//元素+1
                }
                else if ( column + 1 > n1/2-1)//继续判断" 列 "是否会超出边界的情况
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
        if ( element == n1*n1/4*3+1)//1的情况特殊考虑
		{
			element ++;
		}
    }
    for(int x=0; x < n1;x++)
	{
		for(int y = 0; y < n1;y++)
		{
			cout << a[x][y];//输出此元素

			for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
			{
				cout<<" ";
			}
			if ( y == n1 - 1)//当 列数 == 最大列数时，换行
			{
				cout<<endl;
			}
		}
	}
	cout<<endl<<endl;
	for(int dh=(n1/2-1)/2,dl=(n1/2-1)/2,delta=1;delta<=(n1-2)/4;delta++,dl++)//A区中间行调换 
	{
		swap(a[dh][dl],a[dh+n/2][dl]);
	}
	for(int dh=0,delta=1;delta<=n/2;delta++,dh++)//A区中间行调换  
	{
		for(int dl=0,delta2=1;delta2<=(n1-2)/4;delta2++,dl++)
		{
			if(dh!=(n1/2-1)/2)
			{
				swap(a[dh][dl],a[dh+n1/2][dl]);
			}
		}
	}
	if(n1==6)
	{
		for(int x=0; x < n1;x++)
		{
			for(int y = 0; y < n1;y++)
			{
				cout << a[x][y];//输出此元素
	
				for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
				{
					cout<<" ";
				}
				if ( y == n1 - 1)//当 列数 == 最大列数时，换行
				{
					cout<<endl;
				}
			}
		}
	}
	else
	{
		for(int dl=(n1/2-1)/2+n1/2,delta=1;delta<=(n1-2)/4-1;delta++,dl--)
		{
			for(int dh=0,delta2=1;delta2<=n1/2;delta2++,dh++)//A区中间行调换 
	 		{
	 			swap(a[dh][dl],a[dh+n1/2][dl]);
			}
		}
		for(int x=0; x < n1;x++)
		{
  			for(int y = 0; y < n1;y++)
			{
   				cout << a[x][y];//输出此元素

   				for(int z = 0;z < 5 - weishu(a[x][y]);z++)//输出后优化格式，以 5 个字节位置为基准判断元素位数和基准数字的关系
				{
    				cout<<" ";
   				}
   				if ( y == n1 - 1)//当 列数 == 最大列数时，换行
				{
					cout<<endl;
				}
  			}
 		}
	}
	return;
} 


//主函数 
int main()
{
	MAIN:welcome(); 
	cin>>nn;
	n=nn;
	if(getchar()=='X')
	{	
		thanku();
		return 0;//退出整个程序
	}
	if(n-nn>0&&n<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，且不允许小数的出现，谢谢)"<<endl<<endl;
		Sleep(500);
		goto MAIN;
	}
	if(nn-n>0)
	{
		cout<<"我都已经猜到啦！！！重来！！(不允许小数的出现)"<<endl<<endl;
		Sleep(500);
		goto MAIN;
	}
	if(n<=0)
	{
		cout<<"我都已经猜到啦！！！重来！！(请输入正数，谢谢)"<<endl<<endl;
		Sleep(500);
		goto MAIN;
	}
	if(n>709)
	{
		cout<<"电脑撑不住！！！重来！！(请输入小于710的数值，谢谢)"<<endl<<endl;
		Sleep(500);
		goto MAIN;
	}
	if(n == 2)
    {
        cout << "李想赣神魔？不讲武德！！重来！！（2阶幻方不存在）" << endl;
        Sleep(500);
        goto MAIN; 
    }
	if(n%2!=0)
	{
		cout<<"正在进入奇阶幻方算法…………"<<endl<<endl; 
		Sleep (500);
		ji();	
	}
	else if(n%4==0)
	{
		cout<<"正在进入偶阶(仅4的倍数)幻方算法…………"<<endl<<endl; 
		Sleep (500);	
		ou4();
	}
	else
	{
		cout<<"正在进入偶阶(非4的倍数)幻方算法…………"<<endl<<endl; 
		Sleep (500);		
		ou();
	} 
	goto MAIN;
	return 0;
}
