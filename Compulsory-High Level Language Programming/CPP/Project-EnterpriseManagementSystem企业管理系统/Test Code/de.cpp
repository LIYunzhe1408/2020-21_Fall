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
问题解决 运用iostream流文件成功。
 
修订于2020.11.11 1：13

version 1.1
1. 完成全部修改 修改部分见注释信息
修改于2020.11.15 7：02 
 
version 1.2
初步信息调试debug 
 
——————————————————————————————————
version1.0
demo

version 1.1
完成全部子函数，进行debug

version 1.2
初步debug完成

 
修改于2020.11.8 21：02

******************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
using namespace std;

typedef struct node{					//创建节点 
	int num;
	char name[20];
	char sex[10];
	int age;
	char department[20];
	int salary;
	int leader; 
	char variable[20];
	struct node *next;
}emp;	

typedef struct node1{					 //创建节点 
	int num;
	char duty[100];
	struct node1 *next;
}thing;							    	//emp == employee 

int  amount(emp *head);					//子函数声明 
void LoadA(char *filename1);						
void welcome_menu(int select);
void display (emp *head);
void display2 (thing *head);
void displayperson (emp *head, int index);
void displayperson2 (thing *head, int index);
emp *insert(emp *head, int index, char *filename1); 
void save(char *filename1, emp *head);
emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2);	
emp *createList(int n, char *filename1);
emp *createListX(char *filename1);
emp *checkfirst(char *filename1);
emp *revise(emp *head, int index, char *filename1); 
thing *checkfirst2(char *filename1);
thing *createListX2(char *filename1);
thing *createList2(int n, char *filename1);
thing *insert2(thing *head2, emp*head, int index, char *filename1);
thing *remove2(thing *head, int index, char *filename1);
int  amount2(thing *head);
void save2(char *filename1, thing *head);
void rank(emp *head);
void leader(emp *head, int index); 
void paixv(emp *head);
void bound(char ch, int n); 
void s2b(emp *head);
void s2bt(thing *head);



int main()
{
	int number = 0, num_emp;
	char filename1[11] = {'t','e','s','t','e','m','p','.','t','x','t'};
	char filename2[10] = {'t','h','i','n','g','s','.','t','x','t'};
	system("color F0");
	int select = 0;
	cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          欢迎使用企业管理系统                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	emp *head = checkfirst(filename1);
	thing *head2 = checkfirst2(filename2);
	s2b(head);
	s2bt(head2);	

	cout << "请选择需要操作的对象：1.员工 2.事务"<<endl;
	cout << "请输入：";cin>> select; 
	cout << endl;	
	
	welcome_menu(select);

	
	while ( cin >> number)
	{
		
		if ( number == 0)
		{
			return 0;
		}
		num_emp = 0;
		if ( select == 1)
		{
			if ( number == 1)
			{
				int option = 0;
				cout << "您想查询 1.全部员工信息 2.员工个人信息"<<endl;
				cout << "请输入：";cin >> option ;
				if ( option == 1)
				{
					cout << "查询信息如下："<<endl; 
					display(head);
				}else
				{
					cout << "请输入您想查询员工信息的编号：";
					cin >> num_emp;
					displayperson(head, num_emp);
				}	
				
			}
			else if( number == 2)
			{
				cout << "请输入想要插入的员工编号：";
				cin >> num_emp;
				insert(head, num_emp, filename1);			
			} 
			else  if ( number == 3)
			{
				cout << "请输入想要删除的员工编号：";
				cin >> num_emp;
				remove(head, head2, num_emp, filename1, filename2);
			}
			else if ( number == 4)
			{
				cout <<"请输入想要修改的员工编号：";
				cin >> num_emp;
				cout << endl;
				revise(head, num_emp, filename1); 
			}
			else if ( number == 5)
			{
				cout <<"系统正在处理，请稍后";
				rank(head);	
				head = createListX(filename1);
			} 
			else if ( number == 6)
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
		}else if ( select == 2)
		{
			if ( number == 1)
			{
				int option = 0;
				cout << "您想查询 1.全部事务信息 2.员工事务信息"<<endl;
				cout << "请输入：";cin >> option ;
				if ( option == 1)
				{
					cout << "查询信息如下："<<endl; 
					display2(head2);
				}else
				{
					cout << "请输入您想查询事务信息的员工编号：";
					cin >> num_emp;
					displayperson2(head2, num_emp);
				}	
				
			}
			else if( number == 2)
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
		getchar();
		char ch = getchar();
		if ( ch == 'X' || ch == 'x')
		{
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




int  amount(emp *head)					//计算员工节点个数 
{
	int cnt = 0;
	emp *p = head->next;
	while( p!=NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

int  amount2(thing *head)				//计算事务节点个数 
{
	int cnt = 0;
	thing *p = head->next;
	while( p!=NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}

emp *createList(int n, char *filename1)	//员工文件不存在时 
{
	emp *head = new emp;				//头节点 一般不存储数据
	emp *pre = head;	 				//声明上一个节点 
//	emp head;         					//这样写head不是动态的，而是存在于栈上 
	ofstream outfile;
	outfile.open(filename1,ios::out);
	for ( int i = 0;i < n;i++)
	{
		emp *p = new emp;
		printf("请输入第%d个职员的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号)\n",i+1);


		cin >>p->num>>p->name>>p->sex>>p->age>>p->department>>p->salary>>p->leader;
		cout << endl;
		outfile << p->num<<'\t'<<p->name<<'\t'
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

thing *createList2(int n, char *filename1)	//事务文件不存在时 
{
	thing *head = new thing;				//头节点 一般不存储数据
	thing *pre = head;	 					//声明上一个节点 
        				
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


emp *createListX(char *filename1)		//员工文件存在时 
{
	emp *head = new emp;				//头节点 一般不存储数据
	emp *pre = head;					//声明上一个节点 
//	emp head;         					//这样写head不是动态的，而是存在于栈上 
	ifstream infile;
	infile.open(filename1,ios::in);

	string line;

	while( getline(infile,line))
	{
		emp *p = new emp;
		stringstream ss(line);
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

thing *createListX2(char *filename1)	//事务文件存在时 
{
	thing *head = new thing;			//头节点 一般不存储数据
	thing *pre = head;					//声明上一个节点 
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

void display (emp *head)				//展示员工信息 
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

void display2 (thing *head)				//展示全部事务信息 
{
	thing *p = head->next; 				//head节点没东西			
	while ( p != NULL)
	{
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->duty<<endl;
		p = p->next;
	}
}

//void LoadA(char *filename1)				//暂时没用 
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

emp *checkfirst(char *filename1)		//首次使用，进行用户信息初始化
{
	FILE *fp;
	int n;
	emp *head ;
	ifstream ifs(filename1,ios::in); 
	char ch;
	ifs>>ch;

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())
	{
		cout <<"新系统，请进行相应的初始化操作!"<<endl;
		cout << "请输入需要录入的员工数量：";
		
		cin >> n;
		cout << endl; 	
		head = createList(n, filename1);
		cout <<"员工信息输入完成！" <<endl;	
	}
	else
	{
		head = createListX(filename1);
		cout << "员工信息已存在."<<endl;
	}

	return head;
}


thing *checkfirst2(char *filename1)		//首次使用，进行事务用户信息初始化
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

void welcome_menu(int select)			//欢迎菜单 
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


emp *insert(emp *head, int index, char *filename1)				//插入一个员工 
{
	cout << "现在共有 "<< amount(head)<<" 个员工"<<endl;
	printf("您要插入编号为%d的员工\n",index); 

	emp *p = head;
	emp *newnode = new emp;
	while ( p != NULL)
	{
		if ( p->num == index)
		{
			bound('_',100);
			cout << endl;
			cout << "抱歉！编号已存在！"<<endl;
			return head;
		}
		p = p->next;
	}
	p = head;
	if (index == 1)
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
		if ( index > p->num)
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
		else
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "请输入插入员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
			
			cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
				
			p = head->next;
			emp *pre = head; 
			while(p)				//循环保证上一个节点指向要插入的上一个位置 
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
			
//			p = head->next;
//			for (int i = 0; i < index - 1;i++)			//循环保证上一个节点指向要插入的上一个位置 
//			{
//				p = p->next;	
//			} 
////	
//			cout << "Loading ... ..."<<endl;
//			bound('_',100);
//			cout << endl;
//			cout << "请输入插入员工的信息(编号 姓名 性别 年龄 部门 薪资 直系领导编号): "<<endl;
//			
//			cin >> newnode->num>>newnode->name>>newnode->sex
//				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
//			
//				newnode->next = p->next;
//				p->next = newnode;
		}
	
	system("cls");
	save(filename1, head);
	cout << "更新完成！"<<endl;	
	cout << "更新信息如下："<<endl;	
	display(head);


	return head;
}


thing *insert2(thing *head2, emp *head, int index, char *filename1)				//插入一个员工 
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

void save(char *filename1, emp *head)	//保存员工 
{
	emp *p = head->next;
	ofstream outfile1(filename1);
	while (p != NULL)
	{
		outfile1 << p->num<<'\t'<<p->name<<'\t'
				<<p->sex<<'\t' << p->age<<'\t'
				<<p->department<<'\t'<<p->salary<<'\t'<<p->leader<<endl;
		p = p->next;
	}
	outfile1.close();	
}

void save2(char *filename1, thing *head)//保存事务 
{
	thing *p = head->next;
	ofstream outfile1(filename1);
	while (p != NULL)
	{
		outfile1 << p->num<<'\t'<<p->duty<<endl;
		p = p->next;
	}
	outfile1.close();	
}

thing *remove2(thing *head, int index, char *filename1)
{
	thing *p = head->next;
	thing *pre = head;
	while(p != NULL)
	{
		if ( p->num == index)
		{
			if(p->next == NULL)
			{
				pre->next = NULL;
			}
			else if(index == 1)
			{
				head = pre->next;
				
			}
			else
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	save2(filename1, head);
	return head;
}

emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2)				//删除员工员工信息 
{
	int mark  = 0;
	char name[20];
	cout <<"请输入姓名：";
	cin >> name; 
	emp *p1 = head->next; 				//head节点没东西		
	while ( p1!=NULL)
	{
		if ( p1->num == index)
		{
			if ( p1->name == name)
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
			if(p->next == NULL)
			{
				pre->next = NULL;
			}
			else if(index == 1)
			{
				head = pre->next;
				
			}
			else
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	remove2(head2, index, filename2);
	save(filename1, head);
	cout << "更新完成！"<<endl;
	cout << "更新信息如下："<<endl;
	display(head); 
	return head;
} 

emp *revise(emp *head, int index, char *filename1)				//修改一个员工信息		
{
	int mark  = 0;
	emp *p = head->next; 				//head节点没东西		
	while ( p!=NULL)
	{
		if ( p->num == index)
		{
			mark = 1;
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


	p = head->next;
	emp *pre = head;
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
		int option[8], cnt = 0;
		do{
			cin >> option[cnt];
			if(option[cnt] == 0)
			{
				break;
			}
			cnt++;	
		}while(getchar() != '\n');
	
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

void rank(emp *head)											//根据工资排序 
{
	paixv(head);
	cout <<endl;
	display(head);
}

void paixv(emp *head)
{
	emp *p = head->next->next;
	emp *pre = head->next; 
	int tmp = 0;

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		
		for( p = pre->next;p != NULL;p = p->next)
		{
			if (pre->salary < p->salary)
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


void leader(emp *head, int index)        //直系领导 .debug 建议，对指针p,q 的循环判断关键在于看：出循环后p，q是否需要使用，要p->next!=NULL,不要p!=NUll 
{
	int mark  = 0, lab = 0;
	emp *p = head->next; 				//head节点没东西		
	while ( p!=NULL)
	{
		if ( p->num == index)
		{
			mark = 1;
			lab = p->leader;
			break;
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
//	cout << " lab = "<<lab<<endl;
	while( p->num != lab )
	{
		p = p->next;
	}
	mark = p->num;
	int label = 0;
//	paixv(head);
//	cout << "mark = "<<mark<<endl;
	printf("编号为%d的直系领导如下：\n",index);
	int cnt = 0;
	while (q != NULL)
	{
		if ( q->num == mark )
		{
			cnt ++;			
			cout <<"领导"<<cnt<<": "<<setiosflags(ios::left)<<setw(10)<< q->num<<setw(8)<<q->name<<setw(4)
			 <<q->sex<<setw(6)<< q->age<<setw(15)
			 <<q->department<<setw(10)<<q->salary<<setw(2)<<q->leader<<endl; 
			 label = 1;

		}
	 	q = q->next;

	} 
	if ( label == 0)
	{
		cout << "不存在领导信息"<<endl; 
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

void displayperson (emp *head, int index)	//显示个人信息 
{
	int mark  = 0;
	char name[20];
	cout <<"请输入姓名：";
	cin >> name; 
	emp *p = head->next; 					//head节点没东西		
	while ( p->next!=NULL)
	{
		if ( p->num == index)
		{
			if ( p->name != name)
			{
				cout <<"信息不匹配";
				return ; 
			}
			else
			{
				mark = 1;
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

void displayperson2 (thing *head, int index)//显示个人信息 
{
	int mark  = 0;
	thing *p = head->next; 					//head节点没东西		
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

void s2b(emp *head)
{
	emp *p = head->next->next;
	emp *pre = head->next; 
	int tmp = 0;

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		
		for( p = pre->next;p != NULL;p = p->next)
		{
			if (pre->num > p->num)
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

void s2bt(thing *head)
{
	thing *p = head->next->next;
	thing *pre = head->next; 
	int tmp = 0;

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
					char a[100];
					a[x] = pre->duty[x];
					pre->duty[x] = p->duty[x];
					p->duty[x] = a[x];
				}
			}
		}

	}
}
