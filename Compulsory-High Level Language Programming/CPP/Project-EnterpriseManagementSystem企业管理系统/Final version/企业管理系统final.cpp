/******************************************************************
高级语言c++程序设计大作业：企业管理系统
教师：张博锋
作者：20123101 李昀哲 上海大学计算机工程与科学学院 智能科学与技术

程序修订日志：
version 1.0
1.确定基础框架和子函数 
对于查询、删除、添加进行员工和事务的选择，整合为一个函数，而不是变为分步函数，增加可读性。 
2.编写添加员工/事务函数
3.对如何fwrite写入txt纠结太久，最后发现时last指针未指向末尾后解决
修订于2020.11.11 1：13

version 1.1
1. 完成全部初子函数、主函数编写
2. 部分函数添加注释信息 
修改于2020.11.15 7：02 
 
version 1.2
1.初步信息调试debug 
2.增加删除、领导层级功能前的姓名确认,针对emp结构体中name为char型，在和输入比较时均转化为string型
修改于2020.11.16 11:00 

version 1.3
1.添加全部注释信息
2.对子函数按字母顺序进行排序，并添加行数查询增加可读性和查找便利性
3.终版 
修订于2020.11.18 16：46 
 
——————————————————————————————————
question： 
1. save函数是否每次都是从文件开头开始输入？ 
2.写入记事本的文字能否换行？								A:写入时就对格式加以调整 
3.是否用fwrite就只能给结构体的每个成员都定义为char类型？	A:	运用iostream流文件成功。
4. 对文件的运用仍需加强 

******************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
using namespace std;

//定义结构体 
typedef struct node{												//创建员工节点 
	int num;														//员工编号 
	char name[20];													//员工姓名 
	char sex[10];													//员工性别 
	int age;														//员工年龄 
	char department[20];											//员工部门 
	int salary;														//员工薪资 
	int leader; 													//直系领导编号 
	struct node *next;												//指针域：指向下一个节点 
}emp;																//emp == employee

typedef struct node1{					 							//创建事务节点 
	int num;														//事务的员工编号 
	char duty[100];													//事务职责 
	struct node1 *next;												//指针域：指向下一个节点 
}thing;							    								 

//子函数声明 
int  amount(emp *head);												//计算员工节点个数 												Line253				
int  amount2(thing *head);											//计算事务节点个数 												Line266 
void bound(char ch, int n); 										//分割线：显示美化 												Line279 
emp *checkfirst(char *filename1);									//进入系统前查看“员工”文件是否为空，即确认系统是否第一次使用  Line290 
thing *checkfirst2(char *filename1);								//进入系统前查看“事务”文件是否为空，即确认系统是否第一次使用  Line319 
emp *createList(int n, char *filename1);							//建立员工链表 													Line347 
emp *createListX(char *filename1);									//将“员工”文件中的信息导入员工链表							Line383 
thing *createList2(int n, char *filename1); 						//建立事务链表 													Line414 
thing *createListX2(char *filename1);								//将“事务”文件中的信息导入事务链表 							Line448 
void display (emp *head);											//显示“员工”全部信息 											Line479 
void display2 (thing *head);										//显示“事务”全部信息 											Line492
void displayperson (emp *head, int index);							//显示“员工”个人信息 											Line503
void displayperson2 (thing *head, int index);						//显示某个员工“事务”信息 										Line541
emp *insert(emp *head, int index, char *filename1);					//插入“员工”信息 												Line562
thing *insert2(thing *head2, emp*head, int index, char *filename1); //插入“事务”信息 												Line662
void leader(emp *head, int index); 									//查找领导并显示 												Line751
void paixv(emp *head);												//根据工资从高到低排序 											Line801
void rank(emp *head);												//按工资排序并显示 												Line859
emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2);//删除某个员工的全部信息（包括事务） 				Line867
thing *remove2(thing *head, int index, char *filename1);			//删除事务信息（仅在删除员工时调用，不作为单个功能使用） 		Line934 
emp *revise(emp *head, int index, char *filename1); 				//修改员工信息 													Line964 
void save(char *filename1, emp *head);								//保存员工链表信息于“员工”文件中 								Line1073 
void save2(char *filename1, thing *head);							//保存事务链表信息于“事务”文件中 								Line1088 
void s2b(emp *head);												//small to big 员工信息按编号从小到大排序 						Line1101 
void s2bt(thing *head);												//small to big things 事务信息按编号从小到大排序 				Line1158 
void welcome_menu(int select);										//进入系统欢迎菜单 												Line1188 
void LoadA(char *filename1);										//备用功能；暂时没用 											Line1214 

//定义文件名 
char filename1[8] = {'e','m','p','.','t','x','t'};					//定义“员工”文件名，便于后续修改、调用 
char filename2[10] = {'t','h','i','n','g','s','.','t','x','t'};		//定义“事务”文件名，便于后续修改，调用 


//主函数部分 
int main()
{
	int select = 0;						//定义选择操作对象编号 
	int number = 0;						//定义菜单页面选择编号 
	int num_emp = 0;					//定义选择要查找、添加、删除的员工编号					
	system("color F0");					//调整界面、字体颜色：美化显示 
	
	cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          欢迎使用企业管理系统                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	emp *head = checkfirst(filename1);	//定义“员工”链表的头指针 
	thing *head2 = checkfirst2(filename2);//定义“事务"链表的头指针 
	s2b(head);							//对”员工”链表按编号从小到大排序 
	s2bt(head2);						//对”事务”链表按编号从小到大排序 

	cout << "请选择需要操作的对象：1.员工 2.事务"<<endl;
	cout << "请输入：";cin>> select; 
	cout << endl;	
	
	welcome_menu(select);				//选择完毕后欢迎界面 

	
	while ( cin >> number)				//输入菜单选项 
	{
		if ( number == 0)				//退出系统 
		{
			system ("cls");				//清屏 
			cout << endl<<endl<<endl;
			cout << "        	************************************************************************        "<<endl;
			cout << "        	*                         感谢使用企业管理系统!                        *        "<<endl;
			cout << "        	*           Thank you for using Enterprise Management System!          *        "<<endl;
			cout << "      		************************************************************************        "<<endl;
			return 0;
		}
		num_emp = 0;					//每次循环充值员工编号选项 
		if ( select == 1)				//对员工信息进行操作 
		{
			if ( number == 1)			//查询功能 
			{
				int option = 0;			//选择全部还是个人 
				cout << "您想查询 1.全部员工信息 2.员工个人信息"<<endl;
				cout << "请输入：";cin >> option ;
				if ( option == 1)
				{
					cout << "查询信息如下："<<endl; 
					display(head);		//显示信息 
				}else
				{
					cout << "请输入您想查询员工信息的编号：";
					cin >> num_emp;
					displayperson(head, num_emp); 
				}	
				
			}
			else if( number == 2)		//插入功能 
			{
				cout << "请输入想要插入的员工编号：";
				cin >> num_emp;
				insert(head, num_emp, filename1);			
			} 
			else  if ( number == 3)		//删除功能 
			{
				cout << "请输入想要删除的员工编号：";
				cin >> num_emp;
				remove(head, head2, num_emp, filename1, filename2);
			}
			else if ( number == 4)		//修改功能 
			{
				cout <<"请输入想要修改的员工编号：";
				cin >> num_emp;
				cout << endl;
				revise(head, num_emp, filename1); 
			}
			else if ( number == 5)		//工资排序功能 
			{
				cout <<"系统正在处理，请稍后";
				rank(head);	
				head = createListX(filename1);
			} 
			else if ( number == 6)		//管理层级功能 
			{
				cout << "请输入员工编号：";
				cin >> num_emp;
				printf( "即将显示编号为%d员工的领导信息\n" ,num_emp);
				cout << "Loading... ..."<<endl;
				bound('_',100);
				cout <<endl;
				leader(head, num_emp); 
				head = createListX(filename1);
			}
		}else if ( select == 2)			//选择事务信息 
		{
			if ( number == 1)			//查询功能 
			{
				int option = 0;
				cout << "您想查询 1.全部事务信息 2.员工事务信息"<<endl;
				cout << "请输入：";cin >> option ;
				if ( option == 1)
				{
					cout << "查询信息如下："<<endl; 
					display2(head2);
				}else					//个人查询功能 
				{
					cout << "请输入您想查询事务信息的员工编号：";
					cin >> num_emp;
					displayperson2(head2, num_emp);
				}	
			}	
			else if( number == 2)		//添加功能 
			{
				cout << "请输入想要插入的事务的员工编号：";
				cin >> num_emp;
				insert2(head2, head, num_emp, filename2);			
			} 
			else  if ( number == 3)
			{
				cout << "请输入想要删除的事务的员工编号：";
				cin >> num_emp;
				remove2(head2, num_emp, filename2);
			}
		}
		cout <<endl<<endl;		
		bound('_',100);
		system("pause");
		system("cls");
		cout << "按任意键继续操作，退出请按'X"<<endl; 
		//完成一次操作
		
		 
		getchar();
		char ch = getchar();
		if ( ch == 'X' || ch == 'x')
		{
			system ("cls");
			cout << endl<<endl<<endl;
			cout << "        	************************************************************************        "<<endl;
			cout << "        	*                         感谢使用企业管理系统!                        *        "<<endl;
			cout << "        	*           Thank you for using Enterprise Management System!          *        "<<endl;
			cout << "      		************************************************************************        "<<endl;
			return 0;
		} 
		else
		{
			emp *head = checkfirst(filename1);
			thing *head2 = checkfirst2(filename2);
			cout << "请选择需要操作的对象：1.员工 2.事务"<<endl;
			cout << "请输入：";cin>> select; 
			welcome_menu(select);
		}
	}
	return 0;
} 


int  amount(emp *head)								//计算员工节点个数 
{
	int cnt = 0;
	emp *p = head->next;				
	while( p!=NULL)						//不需要再对p操作，所以当p为末尾空指针时即结束 
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}


int  amount2(thing *head)							//计算事务节点个数 
{
	int cnt = 0;
	thing *p = head->next;
	while( p!=NULL)						//不需要再对p操作，所以当p为末尾空指针时即结束 
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}


void bound(char ch, int n)							//分割线：美化显示 
{
	while (n--)
	{
		putchar(ch);
	}
	cout << endl;
	return;
}  


emp *checkfirst(char *filename1)					//首次使用，进行“员工”信息初始化
{
	FILE *fp;										//定义文件指针 
	int n;											//定义需要输入员工数量 
	emp *head ;										//定义emp型的头指针 
	ifstream ifs(filename1,ios::in); 				//打开文件 
	char ch;
	ifs>>ch;							

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())	//判断文件是否为空 
	{
		cout <<"新系统，请进行相应的初始化操作!"<<endl;
		cout << "请输入需要录入的员工数量：";
		
		cin >> n;
		cout << endl;
		 	
		head = createList(n, filename1);			//为空建立链表，n表示录入员工数量 
		cout <<"员工信息输入完成！" <<endl;	
	}
	else
	{
		head = createListX(filename1);				//不为空，将文件中已存信息输入到链表中 
		cout << "员工信息已存在."<<endl;
	}
	return head;									//返回建立完成链表的头指针 
}


thing *checkfirst2(char *filename1)					//首次使用，进行“事务”信息初始化（注释内容同员工） 
{
	FILE *fp;
	int n;
	thing *head ;
	ifstream ifs(filename1,ios::in); 
	char ch;
	ifs>>ch;

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())
	{
		cout <<"新系统，请进行相应的初始化操作!"<<endl;
		cout << "请输入需要录入的事务数量：";
		
		cin >> n;
		cout << endl; 	
		head = createList2(n, filename1);
		cout <<"事务信息输入完成！" <<endl;	
	}
	else
	{
		head = createListX2(filename1);
		cout << "事务信息已存在."<<endl;
	}	
	return head;
}


emp *createList(int n, char *filename1)				//员工文件不存在时 
{
	emp *head = new emp;							//头节点 一般不存储数据
	emp *pre = head;	 							//声明上一个节点 
//	emp head;         								//这样写head不是动态的，而是存在于栈上 
	ofstream outfile;								//定义outfile 
	outfile.open(filename1,ios::out);				//以输出方式打开文件 
	for ( int i = 0;i < n;i++)
	{
		emp *p = new emp;							//定义一个emp型指针 
		printf("请输入第%d个职员的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号)\n",i+1);


		cin >>p->num>>p->name>>p->sex>>p->age>>p->department>>p->salary>>p->leader;
		cout << endl;
		outfile << p->num<<'\t'<<p->name<<'\t'		//输出信息至文件中，使用：outfile<< 
				<<p->sex<<'\t' << p->age<<'\t'
				<<p->department<<'\t'<<p->salary<<'\t'<<p->leader<<endl;
		if ( head == NULL)							 
		{
			head = p;
		}
		else
		{
			pre->next = p;			
		}
		pre = p;
		p->next = NULL; 
	} 	

	outfile.close();
	system("cls");
	return head;
} 


emp *createListX(char *filename1)					//员工文件存在时 
{
	emp *head = new emp;							//头节点 一般不存储数据
	emp *pre = head;								//声明上一个节点 
//	emp head;         								//这样写head不是动态的，而是存在于栈上 
	ifstream infile;
	infile.open(filename1,ios::in);					//输入方式打开文件 

	string line;									//定义一个字符串型line 

	while( getline(infile,line))					//当还在读入时进入循环 
	{
		emp *p = new emp;
		stringstream ss(line);						//对line进行ss操作，将文件中信息存入链表中 
		ss >>p->num>>p->name>>p->sex>>p->age>>p->department>>p->salary>>p->leader;
		if ( head == NULL)							
		{
			head = p;
		}
		else
		{
			pre->next = p;			
		}
		pre = p;
		p->next = NULL; 
	} 	
	infile.close();
	return head;
} 


thing *createList2(int n, char *filename1)			//事务文件不存在时 （注释信息同员工函数） 
{
	thing *head = new thing;						//头节点 一般不存储数据
	thing *pre = head;	 							//声明上一个节点 
        				
	ofstream outfile;
	outfile.open(filename1,ios::out);
	for ( int i = 0;i < n;i++)
	{
	    thing *p = new thing;
		printf("请输入员工的事务信息(员工编号 职务)\n",i+1);


		cin >>p->num>>p->duty;
		cout << endl;
		outfile << p->num<<'\t'<<p->duty<<endl;
		if ( head == NULL)
		{
			head = p;
		}
		else
		{
			pre->next = p;			
		}
		pre = p;
		p->next = NULL; 
	} 	

	outfile.close();
	system("cls");
	return head;
} 


thing *createListX2(char *filename1)				//事务文件存在时 （注释信息同员工函数）
{
	thing *head = new thing;						//头节点 一般不存储数据
	thing *pre = head;								//声明上一个节点 
	ifstream infile;
	infile.open(filename1,ios::in);

	string line;

	while( getline(infile,line))
	{
		thing *p = new thing;
		stringstream ss(line);
		ss >>p->num>>p->duty;
		if ( head == NULL)
		{
			head = p;
		}
		else
		{
			pre->next = p;			
		}
		pre = p;
		p->next = NULL; 
	} 	

	infile.close();
	return head;
} 


void display (emp *head)							//展示员工信息 
{	
	emp *p = head->next; 							
	while ( p != NULL)
	{
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->name<<setw(4)
			 <<p->sex<<setw(6)<< p->age<<setw(25)
			 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
		p = p->next;
	}
}


void display2 (thing *head)							//展示全部事务信息 
{
	thing *p = head->next; 							//head节点没东西			
	while ( p != NULL)
	{
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->duty<<endl;
		p = p->next;
	}
}


void displayperson (emp *head, int index)			//显示个人信息 
{
	int mark  = 0;									//定义标记符  
	char name[20];
	cout <<"请输入姓名：";
	cin >> name; 
	emp *p = head->next; 							//head节点没东西		
	while ( p->next!=NULL)
	{
		if ( p->num == index)
		{
//			cout <<"name is = " <<name<<endl;		//测试姓名是否相等 
//			cout << "p->name is = "<<p->name<<endl;
			if ( (string)p->name != (string)name)	//再次输入名字加以确认 
			{
				cout <<"信息不匹配";
				return ; 
			}
			else 
			{
				mark = 1;							//员工存在时，标记符为真 
				break;	
			}
		} 
		p = p->next;
	}
	
	if ( mark == 0)
	{
		cout << "不存在该员工"<<endl;
		return;	
	}	
	cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->name<<setw(4)
		 <<p->sex<<setw(6)<< p->age<<setw(25)
		 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
}


void displayperson2 (thing *head, int index)		//显示个人信息 （注释信息同员工函数） 
{
	int mark  = 0;
	thing *p = head->next; 							//head节点没东西		
	while ( p->next!=NULL)
	{
		if ( p->num == index)
		{
			mark = 1;
			cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(10)<<p->duty<<endl;
		}	
		p = p->next;
	}
	if ( mark == 0)
	{
		cout << "不存在该员工事务信息"<<endl;
		return;	
	}	 	
}


emp *insert(emp *head, int index, char *filename1)	//插入一个员工 
{
	cout << "现在共有 "<< amount(head)<<" 个员工"<<endl;
	printf("您要插入编号为%d的员工\n",index); 

	emp *p = head;
	emp *newnode = new emp;
	while ( p != NULL)
	{
		if ( p->num == index)						//遍历，若需要添加的员工编号已存在，给出提示信息 
		{
			bound('_',100);
			cout << endl;
			cout << "抱歉！编号已存在！"<<endl;
			return head;
		}
		p = p->next;
	}
	p = head;
	if (index == 1)									//分类：插入为首位、末尾、中间 
	{
		cout << "Loading ... ..."<<endl;
		bound('_',100);	
		cout << endl;
		cout << "请输入插入员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
	
		
		cin >> newnode->num>>newnode->name>>newnode->sex
			>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
	
		system("cls");
		newnode->next = head->next;
		head->next = newnode;
	}
	else
	{
		while(p->next!=NULL)
		{
			p = p->next;
		} 
		if ( index > p->num)						//判断输入数值和最后一个emp的编号大小，若大，则末尾 
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "请输入插入员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
			
			cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
			p = head;
			while(p->next !=NULL)
			{
				p = p->next;
			} 
			p->next = newnode;
			newnode->next = NULL;
		}  
		else										//若小，则中间 
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "请输入插入员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
			
			cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
				
			p = head->next;
			emp *pre = head; 
			while(p)								//循环保证上一个节点指向要插入的上一个位置 
				{
					if(pre->num < index && index < p->num)
					{
						break;
					}
					p = p->next;
					pre = pre->next;	
				} 
				if ( p->next == NULL)
				{
					p->next = newnode;
					newnode->next = NULL;
				}else if (pre->num < index && index < p->num) 
				{
					pre->next = newnode;
					newnode->next = p;
				}
			}
		}
	
	system("cls");
	save(filename1, head);
	cout << "更新完成！"<<endl;	
	cout << "更新信息如下："<<endl;	
	display(head);

	return head;
}


thing *insert2(thing *head2, emp *head, int index, char *filename1)				//插入一个事务 （注释信息同员工函数） 
{
	int mark  = 0;
	emp *p1 = head->next; 														//head节点没东西		
	while ( p1!=NULL)
	{
		if ( p1->num == index)
		{
			mark = 1;
		}	
		p1 = p1->next;
	}
	
	if ( mark == 0)
	{
		cout << "不存在该员工"<<endl;
		return head2;	
	}	
	
	if ( mark != 0)
	{
		printf("您要插入编号为%d的员工事务\n",index);
		cout << "Loading ... ..."<<endl;
		bound('_',100);	
		cout << endl; 

		thing *p = head2;
		thing *newnode = new thing;
		while ( p != NULL)
		{
			if ( p->num == index)
			{
				cout << "请输入插入事务的信息(编号 职务): "<<endl;
				cin >> newnode->num>>newnode->duty; 
				system("cls");
				newnode->next = p->next;
				p->next = newnode;
				save2(filename1, head2);
				cout << "更新完成！"<<endl;	
				cout << "更新信息如下："<<endl;	
				display2(head2);
				return head2;
			}
			p = p->next;
		}
		p = head2;
		if (index == 1)
		{
			
			cout << "请输入插入事务的信息(编号 职务): "<<endl;
		
			cin >> newnode->num>>newnode->duty; 
		
			system("cls");
			newnode->next = head2->next;
			head2->next = newnode;
		}
		else
		{
			cout << "请输入插入事务的信息(编号 职务): "<<endl;
				
			cin >> newnode->num>>newnode->duty; 
			p = head2->next;
			thing *pre = head2; 
				while(p)				//循环保证上一个节点指向要插入的上一个位置 
				{
					if(p->next == NULL || (pre->num < index && index < p->num))
					{
						break;
					}
					p = p->next;
					pre = pre->next;	
				} 
				if ( p->next == NULL)
				{
					p->next = newnode;
					newnode->next = NULL;
				}else if (pre->num < index && index < p->num) 
				{
					pre->next = newnode;
					newnode->next = p;
				}
			}
			
		system("cls");
		save2(filename1, head2);
		cout << "更新完成！"<<endl;	
		cout << "更新信息如下："<<endl;	
		display2(head2);		
	}
	return head2;
}


void leader(emp *head, int index)       			 //直系领导 .debug 建议，对指针p,q 的循环判断关键在于看：出循环后p，q是否需要使用，要p->next!=NULL,不要p!=NUll 
{
	int mark  = 0, lab = 0;						 	//定义两个标记符					 
	emp *p = head->next; 							//head节点没东西		
	while ( p!=NULL)								//不需要对p进行后续操作，因此遍历到p 
	{
		if ( p->num == index)						
		{
			mark = 1;								//标记已经记录到 
			lab = p->leader;						//记录leader的编号 
			break;									//记录到就跳出循环 
		}	
		p = p->next;
	}
	
	if ( mark == 0)
	{
		cout << "不存在该员工"<<endl;
		return;	
	}	
	p = head->next;
	emp *q = head->next;	
//	cout << " lab = "<<lab<<endl;					//调试用  
	while( p->num != lab )							//循环条件为判断这个人的序号是否为所要求领导的序号，若不是，继续下一个 
	{
		p = p->next;
		if(p->next == NULL && p->num != lab)
		{
			cout << "不存在领导信息"<<endl; 
			return;
		} 
	}
	mark = p->num;
	int label = 0;
//	paixv(head);
//	cout << "mark = "<<mark<<endl;
	printf("编号为%d的直系领导如下：\n",index);
	while (q != NULL)
	{
		if ( q->num == mark )
		{		
			cout <<"领导"<<": "<<setiosflags(ios::left)<<setw(10)<< q->num<<setw(8)<<q->name<<setw(4)
			 <<q->sex<<setw(6)<< q->age<<setw(15)
			 <<q->department<<setw(10)<<q->salary<<setw(2)<<q->leader<<endl; 
			 label = 1;								//相当于上述的mark 标记已经检测到 
		}
	 	q = q->next;
	} 
} 


void paixv(emp *head)								//对所给员工的工资从高到低排序（采用冒泡排序法）  
{
	emp *p = head->next->next;
	emp *pre = head->next; 
	int tmp = 0;									//定义中间变量		

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		
		for( p = pre->next;p != NULL;p = p->next)	
		{
			if (pre->salary < p->salary)			//判断薪资大小 
			{
				tmp = pre->salary;					
				pre->salary = p->salary;
				p->salary = tmp;
				
				tmp = pre->num;
				pre->num= p->num;
				p->num = tmp;
				
				tmp = pre->age;
				pre->age= p->age;
				p->age = tmp;
				
				tmp = pre->leader;
				pre->leader = p->leader;
				p->leader = tmp;
				
				for( int x = 0;x < sizeof(pre->name);x++)	//由于调整顺序，而name是char型，直接用string有一定问题
				{
					char a[20];
					a[x] = pre->name[x];
					pre->name[x] = p->name[x];
					p->name[x] = a[x];
				}
				
				for( int x = 0;x < sizeof(pre->department);x++)
				{
					char a[20];
					a[x] = pre->department[x];
					pre->department[x] = p->department[x];
					p->department[x] = a[x];
				}
				
				for( int x = 0;x < sizeof(pre->sex);x++)
				{
					char a[10];
					a[x] = pre->sex[x];
					pre->sex[x] = p->sex[x];
					p->sex[x] = a[x];
				}
			}
		}
	}
}


void rank(emp *head)								//根据工资排序 
{
	paixv(head);									//调用排序函数 
	cout <<endl;
	display(head);									//显示 
}


emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2)	//删除员工信息 
{
	int mark  = 0;									//定义标识符 
	char name[20];
	cout <<"请输入姓名：";
	cin >> name; 
	emp *p1 = head->next; 							//head节点没东西		
	while ( p1!=NULL)
	{
		if ( p1->num == index)
		{
//			cout <<"name is = " <<name<<endl;
//			cout << "p->name is = "<<p1->name<<endl;
			if ( (string)p1->name != (string)name)	//char型时为什么这里是== 而不是 ！=  2020.11.16修改完成，改为string型 
			{
				cout <<"信息不匹配";
				return head; 
			}
			else
			{
				mark = 1;	
			}
		}	
		p1 = p1->next;
	}
	
	if ( mark == 0)
	{
		cout << "不存在该员工"<<endl;
		return head;	
	}	
	cout << "现在共有 "<< amount(head)<<" 个员工"<<endl;
	printf("您要删除的是编号为%d的员工\n",index);
	cout << "Loading ... ..."<<endl; 
	system("cls");
	emp *pre = head;
	emp *p = head->next;
	while(p != NULL)
	{
		if ( p->num == index)
		{
			if(p->next == NULL)						//p为末尾时 
			{
				pre->next = NULL;	
			}
			else if(index == 1)						//p为首位时 
			{
				head = pre->next;
			}
			else									//中间情况 
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	remove2(head2, index, filename2);				//删除员工全部信息，包括事务信息，调用子函数 
	save(filename1, head);							//保存至文件 
	cout << "更新完成！"<<endl;
	cout << "更新信息如下："<<endl;
	display(head);									//显示更新信息 
	return head;
} 


thing *remove2(thing *head, int index, char *filename1)//删除事务信息（由于题目要求，这个函数并为列为单一功能使用，而是作为子函数使用） 
{
	thing *p = head->next;
	thing *pre = head;
	while(p != NULL)
	{
		if ( p->num == index)
		{
			if(p->next == NULL)							//末尾 
			{
				pre->next = NULL;						 
			}
			else if(index == 1)							//首位 
			{
				head = pre->next;
			}
			else										//中间情况 
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	save2(filename1, head);								//保存至文件 
	return head;
}


emp *revise(emp *head, int index, char *filename1)	//修改一个员工信息		
{
	int mark  = 0;
	emp *p = head->next; 							//head节点没东西		
	while ( p!=NULL)
	{
		if ( p->num == index)						//检测到后标识符为1 
		{
			mark = 1;
			break; 
		}	
		p = p->next;
	}
	if ( mark == 0)									
	{
		cout << "不存在该员工"<<endl;
		return head;	
	}	
	cout << "现在共有 "<< amount(head)<<" 个员工"<<endl;
	printf("您要修改编号为%d的员工原信息如下：\n",index); 
	cout << "Loading ... ..."<<endl<<endl;
	bound('_',100);
	cout <<endl;


	p = head->next;									//重置p头指针 
	emp *pre = head;								//定义一个p前一项的指针 
	while(p != NULL)
	{
		if ( p->num == index)
		{
			printf("编号为%d的员工原信息如下：\n",index);
			cout <<setiosflags(ios::left)<<setw(10)<< p->num<<setw(8)<<p->name<<setw(4)
					 <<p->sex<<setw(6)<< p->age<<setw(15)
					 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
		
			emp *newnode = new emp;
			newnode = p; 
			cout << "\n您想要修改的是  0.全部修改 1.编号 2.姓名 3.性别 4.年龄 5.部门 6.薪资 7.直系领导编号"<<endl;
			cout << "请输入：";
			int option[8], cnt = 0;					//定义选项数 数组		
			do{
				cin >> option[cnt];
				if(option[cnt] == 0)
				{
					break;
				}
				cnt++;	
			}while(getchar() != '\n');              //以防用户输入多个需要修改的数据 
		
			if ( option[0] == 0)
			{
				cout << "请输入修改员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
				cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
			} 
			for ( int i = 0; i < cnt;i++)
			{
				if ( option[i] == 1)
				{
					cout << "请输入修改编号：";
					cin >> newnode->num; 
				}
				if ( option[i] == 2)
				{
					cout << "请输入修改姓名：";
					cin >> newnode->name; 
				}
				if ( option[i] == 3)
				{
					cout << "请输入修改性别：";
					cin >> newnode->sex; 
				}
				if ( option[i] == 4)
				{
					cout << "请输入修改年龄：";
					cin >> newnode->age; 
				}
				if ( option[i] == 5)
				{
					cout << "请输入修改部门：";
					cin >> newnode->department; 
				}
				if ( option[i] == 6)
				{
					cout << "请输入修改薪资：";
					cin >> newnode->salary; 
				}
				if ( option[i] == 7)
				{
					cout << "请输入修改直系领导编号：";
					cin >> newnode->leader; 
				}
			}
		}
			p = p->next;
			pre = pre->next;	
	} 

	system("cls");
	save(filename1, head);
	cout << "更新完成！"<<endl;	
	cout << "更新信息如下："<<endl;	
	display(head);

	return head;
}


void save(char *filename1, emp *head)				//保存员工 
{
	emp *p = head->next;
	ofstream outfile1(filename1);					//开文件 
	while (p != NULL)								//遍历 
	{
		outfile1 << p->num<<'\t'<<p->name<<'\t'		//存入 
				<<p->sex<<'\t' << p->age<<'\t'
				<<p->department<<'\t'<<p->salary<<'\t'<<p->leader<<endl;
		p = p->next;
	}
	outfile1.close();								//关文件 
}


void save2(char *filename1, thing *head)			//保存事务 
{
	thing *p = head->next;
	ofstream outfile1(filename1);					//开文件 
	while (p != NULL)								//遍历 
	{
		outfile1 << p->num<<'\t'<<p->duty<<endl;	//存入 
		p = p->next;
	}
	outfile1.close();								//关文件 
}


void s2b(emp *head)									//small to big根据编号从小到大排序 
{
	emp *p = head->next->next;						
	emp *pre = head->next; 
	int tmp = 0;									//定义临时变量用于调换 

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		for( p = pre->next;p != NULL;p = p->next)
		{
			if (pre->num > p->num)					//比较序号 
			{
				tmp = pre->salary;					//调换方法同paixv子函数 
				pre->salary = p->salary;
				p->salary = tmp;
				
				tmp = pre->num;
				pre->num= p->num;
				p->num = tmp;
				
				tmp = pre->age;
				pre->age= p->age;
				p->age = tmp;
				
				tmp = pre->leader;
				pre->leader = p->leader;
				p->leader = tmp;
				
				for ( int x = 0;x < sizeof(pre->name);x++)
				{
					char a[20];
					a[x] = pre->name[x];
					pre->name[x] = p->name[x];
					p->name[x] = a[x];
				}
				
				for( int x = 0;x < sizeof(pre->department);x++)
				{
					char a[20];
					a[x] = pre->department[x];
					pre->department[x] = p->department[x];
					p->department[x] = a[x];
				}
				
				for( int x = 0;x < sizeof(pre->sex);x++)
				{
					char a[10];
					a[x] = pre->sex[x];
					pre->sex[x] = p->sex[x];
					p->sex[x] = a[x];
				}
			}
		}
	}
}


void s2bt(thing *head)								//small to big things根据编号从小到大排序
{
	thing *p = head->next->next;
	thing *pre = head->next; 
	int tmp = 0;									//定义中间变量 

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		
		for( p = pre->next;p != NULL;p = p->next)
		{
			if (pre->num > p->num)
			{
				tmp = pre->num;
				pre->num= p->num;
				p->num = tmp;
				
				for ( int x = 0;x < sizeof(pre->duty);x++)
				{
					char a[100];					//定义中间变量 
					a[x] = pre->duty[x];
					pre->duty[x] = p->duty[x];
					p->duty[x] = a[x];
				}
			}
		}
	}
}


void welcome_menu(int select)						//欢迎菜单 
{
    cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          欢迎使用企业管理系统                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.查询信息                             *        "<<endl;
	cout << "      		*                               2.添加信息                             *        "<<endl;
	if ( select != 2)
	{
	cout << "      		*                               3.删除信息                             *        "<<endl;
	cout << "        	*                               4.修改信息                             *        "<<endl;
	cout << "        	*                               5.员工排序                             *        "<<endl;
	cout << "        	*                               6.管理层级                             *        "<<endl;
	}
	cout << "        	*                               0.退出系统                             *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    if ( select != 2)
	{
		cout << "请输入您需要的操作（0 - 6）："; 
	}else
	{
		cout << "请输入您需要的操作（0 - 3）："; 
	}
}


//void LoadA(char *filename1)						//备用功能 暂时没用 
//{
//	
//	ifstream infile;
//	infile.open(filename1,ios::in);
//	
//	string s;
//    while(getline(infile,s))
//    {
//        cout<<s<<endl;
//    }
//    infile.close(); 
//    
//}
