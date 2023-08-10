/******************************************************************
高级语言c++程序设计大作业：企业管理系统
教师：张博锋
作者：20123101 李昀哲 上海大学计算机工程与科学学院 智能科学与技术

程序修订日志：
version 1.0
1.确定基础框架和子函数 
对于查询、删除、添加进行员工和事务的选择，整合为一个函数，而不是变为分步函数，增加可读性。 
2. 编写添加员工/事务函数
对如何fwrite写入txt纠结太久，最后发现时last指针未指向末尾后解决
Q:写入记事本的文字能否换行？
Q:是否用fwrite就只能给结构体的每个成员都定义为char类型？ 
修订于2020.11.11 1：13

version 1.1
1. 

 
——————————————————————————————————
version1.0
demo
修改于2020.11.8 21：02

******************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct employee//定义员工结构体
{
	char num[8];
	char name[10];
	char sex[8];
	char age[3];
	char department[10];
	char salary[6];
	char mobile[11];
	struct employee *next;
}employee;

typedef struct things//定义事务结构体
{
	char num[8];
	char duty[10];
	struct things *next;
}things;

//定义全局变量 
employee *head_emp, *last_emp;
things *head_things, *last_things;

//子函数声明 
void welcome_menu();							//需要显示 6 种功能 
int select();									//根据select选择打开文件 
void Search();
void Delete();
void Revise();
void Add(int option);
void Input(int option);									//输入初始员工信息  check
void Sort();
void Hierarchy();
void Save();
void bound(char ch, int n);									//分割线函数 

int main()
{
	head_emp = last_emp = NULL;
	int number = 0, isout = 0, option = 0;
    welcome_menu();													//需要显示 7 种功能 
    
    
    cin >> number;													//输入选择的操作选项 
    while ( isout != 1)
    {
    	if ( number == 1 || number == 2 || number == 4  )			//对于查询、删除、添加存在事务和员工的选项 
    	{
    		option = select();										//option == 1为员工， 2为事务 
		}
	
    	switch (number)												//根据输入来选择 
    	{
    		case 0: isout = 1;break; 								//退出
			 
//    		case 1:													//查询选项 
//			{										
//				Search();
//			}
//			
//    		case 2:													//删除选项 
//			{
//				Delete();	
//			}
//			
//    		case 3: Revise();										//修改选项 
    		 
//    		case 4:													//添加选项		 
//			{
//				Add();
//			}
			
//    		case 5: Sort();											//员工排序选项
//			 
//    		case 6: Hierarchy();									//管理层级选项 
			case 7: Input(option); 
		} 
		cout << "	当前员工/事务信息将会保存"<<endl; 
//		Save();

		isout = 1;													//退出程序 
	}
 
	
	return 0;
}


void welcome_menu()
{
    cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          欢迎使用企业管理系统                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.查询信息                             *        "<<endl;
	cout << "      		*                               2.删除信息                             *        "<<endl;
	cout << "      		*                               3.修改信息                             *        "<<endl;
	cout << "        	*                               4.添加信息                             *        "<<endl;
	cout << "        	*                               5.员工排序                             *        "<<endl;
	cout << "        	*                               6.管理层级                             *        "<<endl;
	cout << "        	*                               7.录入信息                             *        "<<endl;
	cout << "        	*                               0.退出系统                             *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    cout << "请输入您需要的操作（0 - 7）："; 
}

int select()
{
	int option = 1;
	cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          请选择需要操作的对象                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.员工                                 *        "<<endl;
	cout << "      		*                               2.事务                                 *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    cout << "您需要操作的对象是（1 或 2）："; 
    cin >> option ;
    return option;
}

void Input(int option)															//输入初始员工/事务信息 						
{
	FILE *fp;//用于打开文件 
	employee *head1 ;
	things *head2 ;
	int i = 0;
	if ( option == 1)
	{
		fp = fopen("employee.txt","ab");									//以追加方式打开文件 
		if ( fp == NULL)
		{
		cout << "文件打开出错"<<endl;
		getchar();
		return; 
		}
		
		
		do{
		i ++;
		head1 = (employee*)malloc(sizeof(employee));
		if ( head1 == NULL)
		{
		cout << "文件无法打开"<<endl;
		return ;
		}
		cout << "	请输入第"<<i<<"个员工的信息："<<endl;
		bound('_',40);
		cout << endl;
		
		cout << "	请输入员工编号：";
		cin >> *head1->num;
//		scanf("%s",&head1->num);
		cout << "	请输入员工姓名：";
		cin >> *head1->name;
		cout << "	请输入员工性别：";
		cin >> *head1->sex;
		cout << "	请输入员工年龄：";
		cin >> *head1->age;
		cout << "	请输入员工部门：";
		cin >> *head1->department; 
		cout << "	请输入员工月薪：";
		cin >> *head1->salary; 
		cout << "	请输入员工手机号码：";
		cin >> *head1->mobile;  
		head1->next = NULL;
		 
		if ( head_emp == NULL)
		{
			head_emp = head1;
			last_emp = head1;
		}else
		{
			last_emp->next = head1;
			last_emp = head1;
		} 
		
		fwrite(last_emp,sizeof(employee),1,fp);												
		cout << endl<<endl;
		bound('_',40);
		cout << "	是否继续输入？继续按'y'"<<endl;
		fflush(stdin);													//清空输入缓冲区，通常是为了确保不影响后面的数据读取
		char ch = getchar();
		if ( ch != toupper('y'))
		{
		fclose(fp);
		cout <<"	输入完毕，请按任意键返回!"<<endl;
		getchar();
		return;	
		} 
		system("cls");
		
		}while(1);
	}
	else
	{
		fp = fopen("things.txt","ab");									//以追加方式打开文件 
		
		if ( fp == NULL)
		{
		cout << "文件打开出错"<<endl;
		getchar();
		return; 
		}
		
		
		do{
		i ++;
		head2 = (things*)malloc(sizeof(things));
		if ( head2 == NULL)
		{
			cout << "文件无法打开"<<endl;
			return ;
		}
		
		
		cout << "	请输入第"<<i<<"项事务信息："<<endl;
		bound('_',40);
		cout << endl;
		
		cout << "	请输入事务编号：";
		scanf("%s",&head2->num);
		cout << "	请输入员工事务：";
		scanf("%s",&head2->duty);
		head2->next = NULL; 
		
		if ( head_things == NULL)
		{
			head_things = head2;
			last_things = head2;
		}else
		{
			last_things->next = head2;
			last_things = head2;
		} 
		fwrite(last_things,sizeof(things),1,fp);												
		cout << endl<<endl;
		bound('_',40);
		
		cout << "	是否继续输入？继续按'y'"<<endl;
		fflush(stdin);	
		
														//清空输入缓冲区，通常是为了确保不影响后面的数据读取
		char ch = getchar();
		if ( ch != toupper('y'))
		{
		fclose(fp);
		cout <<"	输入完毕，请按任意键返回!"<<endl;
		getchar();
		return;	
		} 
		system("cls");
		
		}while(1);
	}
	
}

void bound(char ch, int n)
{
	while (n--)
	{
		putchar(ch);
	}
	cout << endl;
	return;
}  
