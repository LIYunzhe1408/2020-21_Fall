/******************************************************************
�߼�����c++������ƴ���ҵ����ҵ����ϵͳ
��ʦ���Ų���
���ߣ�20123101 ������ �Ϻ���ѧ������������ѧѧԺ ���ܿ�ѧ�뼼��

�����޶���־��
version 1.0
1.ȷ��������ܺ��Ӻ��� 
���ڲ�ѯ��ɾ������ӽ���Ա���������ѡ������Ϊһ�������������Ǳ�Ϊ�ֲ����������ӿɶ��ԡ� 
2.��д���Ա��/������
3.�����fwriteд��txt����̫�ã������ʱlastָ��δָ��ĩβ����
�޶���2020.11.11 1��13

version 1.1
1. ���ȫ�����Ӻ�������������д
2. ���ֺ������ע����Ϣ 
�޸���2020.11.15 7��02 
 
version 1.2
1.������Ϣ����debug 
2.����ɾ�����쵼�㼶����ǰ������ȷ��,���emp�ṹ����nameΪchar�ͣ��ں�����Ƚ�ʱ��ת��Ϊstring��
�޸���2020.11.16 11:00 

version 1.3
1.���ȫ��ע����Ϣ
2.���Ӻ�������ĸ˳��������򣬲����������ѯ���ӿɶ��ԺͲ��ұ�����
3.�հ� 
�޶���2020.11.18 16��46 
 
��������������������������������������������������������������������
question�� 
1. save�����Ƿ�ÿ�ζ��Ǵ��ļ���ͷ��ʼ���룿 
2.д����±��������ܷ��У�								A:д��ʱ�ͶԸ�ʽ���Ե��� 
3.�Ƿ���fwrite��ֻ�ܸ��ṹ���ÿ����Ա������Ϊchar���ͣ�	A:	����iostream���ļ��ɹ���
4. ���ļ������������ǿ 

******************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
using namespace std;

//����ṹ�� 
typedef struct node{												//����Ա���ڵ� 
	int num;														//Ա����� 
	char name[20];													//Ա������ 
	char sex[10];													//Ա���Ա� 
	int age;														//Ա������ 
	char department[20];											//Ա������ 
	int salary;														//Ա��н�� 
	int leader; 													//ֱϵ�쵼��� 
	struct node *next;												//ָ����ָ����һ���ڵ� 
}emp;																//emp == employee

typedef struct node1{					 							//��������ڵ� 
	int num;														//�����Ա����� 
	char duty[100];													//����ְ�� 
	struct node1 *next;												//ָ����ָ����һ���ڵ� 
}thing;							    								 

//�Ӻ������� 
int  amount(emp *head);												//����Ա���ڵ���� 												Line253				
int  amount2(thing *head);											//��������ڵ���� 												Line266 
void bound(char ch, int n); 										//�ָ��ߣ���ʾ���� 												Line279 
emp *checkfirst(char *filename1);									//����ϵͳǰ�鿴��Ա�����ļ��Ƿ�Ϊ�գ���ȷ��ϵͳ�Ƿ��һ��ʹ��  Line290 
thing *checkfirst2(char *filename1);								//����ϵͳǰ�鿴�������ļ��Ƿ�Ϊ�գ���ȷ��ϵͳ�Ƿ��һ��ʹ��  Line319 
emp *createList(int n, char *filename1);							//����Ա������ 													Line347 
emp *createListX(char *filename1);									//����Ա�����ļ��е���Ϣ����Ա������							Line383 
thing *createList2(int n, char *filename1); 						//������������ 													Line414 
thing *createListX2(char *filename1);								//���������ļ��е���Ϣ������������ 							Line448 
void display (emp *head);											//��ʾ��Ա����ȫ����Ϣ 											Line479 
void display2 (thing *head);										//��ʾ������ȫ����Ϣ 											Line492
void displayperson (emp *head, int index);							//��ʾ��Ա����������Ϣ 											Line503
void displayperson2 (thing *head, int index);						//��ʾĳ��Ա����������Ϣ 										Line541
emp *insert(emp *head, int index, char *filename1);					//���롰Ա������Ϣ 												Line562
thing *insert2(thing *head2, emp*head, int index, char *filename1); //���롰������Ϣ 												Line662
void leader(emp *head, int index); 									//�����쵼����ʾ 												Line751
void paixv(emp *head);												//���ݹ��ʴӸߵ������� 											Line801
void rank(emp *head);												//������������ʾ 												Line859
emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2);//ɾ��ĳ��Ա����ȫ����Ϣ���������� 				Line867
thing *remove2(thing *head, int index, char *filename1);			//ɾ��������Ϣ������ɾ��Ա��ʱ���ã�����Ϊ��������ʹ�ã� 		Line934 
emp *revise(emp *head, int index, char *filename1); 				//�޸�Ա����Ϣ 													Line964 
void save(char *filename1, emp *head);								//����Ա��������Ϣ�ڡ�Ա�����ļ��� 								Line1073 
void save2(char *filename1, thing *head);							//��������������Ϣ�ڡ������ļ��� 								Line1088 
void s2b(emp *head);												//small to big Ա����Ϣ����Ŵ�С�������� 						Line1101 
void s2bt(thing *head);												//small to big things ������Ϣ����Ŵ�С�������� 				Line1158 
void welcome_menu(int select);										//����ϵͳ��ӭ�˵� 												Line1188 
void LoadA(char *filename1);										//���ù��ܣ���ʱû�� 											Line1214 

//�����ļ��� 
char filename1[8] = {'e','m','p','.','t','x','t'};					//���塰Ա�����ļ��������ں����޸ġ����� 
char filename2[10] = {'t','h','i','n','g','s','.','t','x','t'};		//���塰�����ļ��������ں����޸ģ����� 


//���������� 
int main()
{
	int select = 0;						//����ѡ����������� 
	int number = 0;						//����˵�ҳ��ѡ���� 
	int num_emp = 0;					//����ѡ��Ҫ���ҡ���ӡ�ɾ����Ա�����					
	system("color F0");					//�������桢������ɫ��������ʾ 
	
	cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          ��ӭʹ����ҵ����ϵͳ                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	emp *head = checkfirst(filename1);	//���塰Ա���������ͷָ�� 
	thing *head2 = checkfirst2(filename2);//���塰����"�����ͷָ�� 
	s2b(head);							//�ԡ�Ա����������Ŵ�С�������� 
	s2bt(head2);						//�ԡ�����������Ŵ�С�������� 

	cout << "��ѡ����Ҫ�����Ķ���1.Ա�� 2.����"<<endl;
	cout << "�����룺";cin>> select; 
	cout << endl;	
	
	welcome_menu(select);				//ѡ����Ϻ�ӭ���� 

	
	while ( cin >> number)				//����˵�ѡ�� 
	{
		if ( number == 0)				//�˳�ϵͳ 
		{
			system ("cls");				//���� 
			cout << endl<<endl<<endl;
			cout << "        	************************************************************************        "<<endl;
			cout << "        	*                         ��лʹ����ҵ����ϵͳ!                        *        "<<endl;
			cout << "        	*           Thank you for using Enterprise Management System!          *        "<<endl;
			cout << "      		************************************************************************        "<<endl;
			return 0;
		}
		num_emp = 0;					//ÿ��ѭ����ֵԱ�����ѡ�� 
		if ( select == 1)				//��Ա����Ϣ���в��� 
		{
			if ( number == 1)			//��ѯ���� 
			{
				int option = 0;			//ѡ��ȫ�����Ǹ��� 
				cout << "�����ѯ 1.ȫ��Ա����Ϣ 2.Ա��������Ϣ"<<endl;
				cout << "�����룺";cin >> option ;
				if ( option == 1)
				{
					cout << "��ѯ��Ϣ���£�"<<endl; 
					display(head);		//��ʾ��Ϣ 
				}else
				{
					cout << "�����������ѯԱ����Ϣ�ı�ţ�";
					cin >> num_emp;
					displayperson(head, num_emp); 
				}	
				
			}
			else if( number == 2)		//���빦�� 
			{
				cout << "��������Ҫ�����Ա����ţ�";
				cin >> num_emp;
				insert(head, num_emp, filename1);			
			} 
			else  if ( number == 3)		//ɾ������ 
			{
				cout << "��������Ҫɾ����Ա����ţ�";
				cin >> num_emp;
				remove(head, head2, num_emp, filename1, filename2);
			}
			else if ( number == 4)		//�޸Ĺ��� 
			{
				cout <<"��������Ҫ�޸ĵ�Ա����ţ�";
				cin >> num_emp;
				cout << endl;
				revise(head, num_emp, filename1); 
			}
			else if ( number == 5)		//���������� 
			{
				cout <<"ϵͳ���ڴ������Ժ�";
				rank(head);	
				head = createListX(filename1);
			} 
			else if ( number == 6)		//����㼶���� 
			{
				cout << "������Ա����ţ�";
				cin >> num_emp;
				printf( "������ʾ���Ϊ%dԱ�����쵼��Ϣ\n" ,num_emp);
				cout << "Loading... ..."<<endl;
				bound('_',100);
				cout <<endl;
				leader(head, num_emp); 
				head = createListX(filename1);
			}
		}else if ( select == 2)			//ѡ��������Ϣ 
		{
			if ( number == 1)			//��ѯ���� 
			{
				int option = 0;
				cout << "�����ѯ 1.ȫ��������Ϣ 2.Ա��������Ϣ"<<endl;
				cout << "�����룺";cin >> option ;
				if ( option == 1)
				{
					cout << "��ѯ��Ϣ���£�"<<endl; 
					display2(head2);
				}else					//���˲�ѯ���� 
				{
					cout << "�����������ѯ������Ϣ��Ա����ţ�";
					cin >> num_emp;
					displayperson2(head2, num_emp);
				}	
			}	
			else if( number == 2)		//��ӹ��� 
			{
				cout << "��������Ҫ����������Ա����ţ�";
				cin >> num_emp;
				insert2(head2, head, num_emp, filename2);			
			} 
			else  if ( number == 3)
			{
				cout << "��������Ҫɾ���������Ա����ţ�";
				cin >> num_emp;
				remove2(head2, num_emp, filename2);
			}
		}
		cout <<endl<<endl;		
		bound('_',100);
		system("pause");
		system("cls");
		cout << "������������������˳��밴'X"<<endl; 
		//���һ�β���
		
		 
		getchar();
		char ch = getchar();
		if ( ch == 'X' || ch == 'x')
		{
			system ("cls");
			cout << endl<<endl<<endl;
			cout << "        	************************************************************************        "<<endl;
			cout << "        	*                         ��лʹ����ҵ����ϵͳ!                        *        "<<endl;
			cout << "        	*           Thank you for using Enterprise Management System!          *        "<<endl;
			cout << "      		************************************************************************        "<<endl;
			return 0;
		} 
		else
		{
			emp *head = checkfirst(filename1);
			thing *head2 = checkfirst2(filename2);
			cout << "��ѡ����Ҫ�����Ķ���1.Ա�� 2.����"<<endl;
			cout << "�����룺";cin>> select; 
			welcome_menu(select);
		}
	}
	return 0;
} 


int  amount(emp *head)								//����Ա���ڵ���� 
{
	int cnt = 0;
	emp *p = head->next;				
	while( p!=NULL)						//����Ҫ�ٶ�p���������Ե�pΪĩβ��ָ��ʱ������ 
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}


int  amount2(thing *head)							//��������ڵ���� 
{
	int cnt = 0;
	thing *p = head->next;
	while( p!=NULL)						//����Ҫ�ٶ�p���������Ե�pΪĩβ��ָ��ʱ������ 
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}


void bound(char ch, int n)							//�ָ��ߣ�������ʾ 
{
	while (n--)
	{
		putchar(ch);
	}
	cout << endl;
	return;
}  


emp *checkfirst(char *filename1)					//�״�ʹ�ã����С�Ա������Ϣ��ʼ��
{
	FILE *fp;										//�����ļ�ָ�� 
	int n;											//������Ҫ����Ա������ 
	emp *head ;										//����emp�͵�ͷָ�� 
	ifstream ifs(filename1,ios::in); 				//���ļ� 
	char ch;
	ifs>>ch;							

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())	//�ж��ļ��Ƿ�Ϊ�� 
	{
		cout <<"��ϵͳ���������Ӧ�ĳ�ʼ������!"<<endl;
		cout << "��������Ҫ¼���Ա��������";
		
		cin >> n;
		cout << endl;
		 	
		head = createList(n, filename1);			//Ϊ�ս�������n��ʾ¼��Ա������ 
		cout <<"Ա����Ϣ������ɣ�" <<endl;	
	}
	else
	{
		head = createListX(filename1);				//��Ϊ�գ����ļ����Ѵ���Ϣ���뵽������ 
		cout << "Ա����Ϣ�Ѵ���."<<endl;
	}
	return head;									//���ؽ�����������ͷָ�� 
}


thing *checkfirst2(char *filename1)					//�״�ʹ�ã����С�������Ϣ��ʼ����ע������ͬԱ���� 
{
	FILE *fp;
	int n;
	thing *head ;
	ifstream ifs(filename1,ios::in); 
	char ch;
	ifs>>ch;

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())
	{
		cout <<"��ϵͳ���������Ӧ�ĳ�ʼ������!"<<endl;
		cout << "��������Ҫ¼�������������";
		
		cin >> n;
		cout << endl; 	
		head = createList2(n, filename1);
		cout <<"������Ϣ������ɣ�" <<endl;	
	}
	else
	{
		head = createListX2(filename1);
		cout << "������Ϣ�Ѵ���."<<endl;
	}	
	return head;
}


emp *createList(int n, char *filename1)				//Ա���ļ�������ʱ 
{
	emp *head = new emp;							//ͷ�ڵ� һ�㲻�洢����
	emp *pre = head;	 							//������һ���ڵ� 
//	emp head;         								//����дhead���Ƕ�̬�ģ����Ǵ�����ջ�� 
	ofstream outfile;								//����outfile 
	outfile.open(filename1,ios::out);				//�������ʽ���ļ� 
	for ( int i = 0;i < n;i++)
	{
		emp *p = new emp;							//����һ��emp��ָ�� 
		printf("�������%d��ְԱ����Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���)\n",i+1);


		cin >>p->num>>p->name>>p->sex>>p->age>>p->department>>p->salary>>p->leader;
		cout << endl;
		outfile << p->num<<'\t'<<p->name<<'\t'		//�����Ϣ���ļ��У�ʹ�ã�outfile<< 
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


emp *createListX(char *filename1)					//Ա���ļ�����ʱ 
{
	emp *head = new emp;							//ͷ�ڵ� һ�㲻�洢����
	emp *pre = head;								//������һ���ڵ� 
//	emp head;         								//����дhead���Ƕ�̬�ģ����Ǵ�����ջ�� 
	ifstream infile;
	infile.open(filename1,ios::in);					//���뷽ʽ���ļ� 

	string line;									//����һ���ַ�����line 

	while( getline(infile,line))					//�����ڶ���ʱ����ѭ�� 
	{
		emp *p = new emp;
		stringstream ss(line);						//��line����ss���������ļ�����Ϣ���������� 
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


thing *createList2(int n, char *filename1)			//�����ļ�������ʱ ��ע����ϢͬԱ�������� 
{
	thing *head = new thing;						//ͷ�ڵ� һ�㲻�洢����
	thing *pre = head;	 							//������һ���ڵ� 
        				
	ofstream outfile;
	outfile.open(filename1,ios::out);
	for ( int i = 0;i < n;i++)
	{
	    thing *p = new thing;
		printf("������Ա����������Ϣ(Ա����� ְ��)\n",i+1);


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


thing *createListX2(char *filename1)				//�����ļ�����ʱ ��ע����ϢͬԱ��������
{
	thing *head = new thing;						//ͷ�ڵ� һ�㲻�洢����
	thing *pre = head;								//������һ���ڵ� 
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


void display (emp *head)							//չʾԱ����Ϣ 
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


void display2 (thing *head)							//չʾȫ��������Ϣ 
{
	thing *p = head->next; 							//head�ڵ�û����			
	while ( p != NULL)
	{
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->duty<<endl;
		p = p->next;
	}
}


void displayperson (emp *head, int index)			//��ʾ������Ϣ 
{
	int mark  = 0;									//�����Ƿ�  
	char name[20];
	cout <<"������������";
	cin >> name; 
	emp *p = head->next; 							//head�ڵ�û����		
	while ( p->next!=NULL)
	{
		if ( p->num == index)
		{
//			cout <<"name is = " <<name<<endl;		//���������Ƿ���� 
//			cout << "p->name is = "<<p->name<<endl;
			if ( (string)p->name != (string)name)	//�ٴ��������ּ���ȷ�� 
			{
				cout <<"��Ϣ��ƥ��";
				return ; 
			}
			else 
			{
				mark = 1;							//Ա������ʱ����Ƿ�Ϊ�� 
				break;	
			}
		} 
		p = p->next;
	}
	
	if ( mark == 0)
	{
		cout << "�����ڸ�Ա��"<<endl;
		return;	
	}	
	cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->name<<setw(4)
		 <<p->sex<<setw(6)<< p->age<<setw(25)
		 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
}


void displayperson2 (thing *head, int index)		//��ʾ������Ϣ ��ע����ϢͬԱ�������� 
{
	int mark  = 0;
	thing *p = head->next; 							//head�ڵ�û����		
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
		cout << "�����ڸ�Ա��������Ϣ"<<endl;
		return;	
	}	 	
}


emp *insert(emp *head, int index, char *filename1)	//����һ��Ա�� 
{
	cout << "���ڹ��� "<< amount(head)<<" ��Ա��"<<endl;
	printf("��Ҫ������Ϊ%d��Ա��\n",index); 

	emp *p = head;
	emp *newnode = new emp;
	while ( p != NULL)
	{
		if ( p->num == index)						//����������Ҫ��ӵ�Ա������Ѵ��ڣ�������ʾ��Ϣ 
		{
			bound('_',100);
			cout << endl;
			cout << "��Ǹ������Ѵ��ڣ�"<<endl;
			return head;
		}
		p = p->next;
	}
	p = head;
	if (index == 1)									//���ࣺ����Ϊ��λ��ĩβ���м� 
	{
		cout << "Loading ... ..."<<endl;
		bound('_',100);	
		cout << endl;
		cout << "���������Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
	
		
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
		if ( index > p->num)						//�ж�������ֵ�����һ��emp�ı�Ŵ�С��������ĩβ 
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "���������Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
			
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
		else										//��С�����м� 
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "���������Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
			
			cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
				
			p = head->next;
			emp *pre = head; 
			while(p)								//ѭ����֤��һ���ڵ�ָ��Ҫ�������һ��λ�� 
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
	cout << "������ɣ�"<<endl;	
	cout << "������Ϣ���£�"<<endl;	
	display(head);

	return head;
}


thing *insert2(thing *head2, emp *head, int index, char *filename1)				//����һ������ ��ע����ϢͬԱ�������� 
{
	int mark  = 0;
	emp *p1 = head->next; 														//head�ڵ�û����		
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
		cout << "�����ڸ�Ա��"<<endl;
		return head2;	
	}	
	
	if ( mark != 0)
	{
		printf("��Ҫ������Ϊ%d��Ա������\n",index);
		cout << "Loading ... ..."<<endl;
		bound('_',100);	
		cout << endl; 

		thing *p = head2;
		thing *newnode = new thing;
		while ( p != NULL)
		{
			if ( p->num == index)
			{
				cout << "����������������Ϣ(��� ְ��): "<<endl;
				cin >> newnode->num>>newnode->duty; 
				system("cls");
				newnode->next = p->next;
				p->next = newnode;
				save2(filename1, head2);
				cout << "������ɣ�"<<endl;	
				cout << "������Ϣ���£�"<<endl;	
				display2(head2);
				return head2;
			}
			p = p->next;
		}
		p = head2;
		if (index == 1)
		{
			
			cout << "����������������Ϣ(��� ְ��): "<<endl;
		
			cin >> newnode->num>>newnode->duty; 
		
			system("cls");
			newnode->next = head2->next;
			head2->next = newnode;
		}
		else
		{
			cout << "����������������Ϣ(��� ְ��): "<<endl;
				
			cin >> newnode->num>>newnode->duty; 
			p = head2->next;
			thing *pre = head2; 
				while(p)				//ѭ����֤��һ���ڵ�ָ��Ҫ�������һ��λ�� 
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
		cout << "������ɣ�"<<endl;	
		cout << "������Ϣ���£�"<<endl;	
		display2(head2);		
	}
	return head2;
}


void leader(emp *head, int index)       			 //ֱϵ�쵼 .debug ���飬��ָ��p,q ��ѭ���жϹؼ����ڿ�����ѭ����p��q�Ƿ���Ҫʹ�ã�Ҫp->next!=NULL,��Ҫp!=NUll 
{
	int mark  = 0, lab = 0;						 	//����������Ƿ�					 
	emp *p = head->next; 							//head�ڵ�û����		
	while ( p!=NULL)								//����Ҫ��p���к�����������˱�����p 
	{
		if ( p->num == index)						
		{
			mark = 1;								//����Ѿ���¼�� 
			lab = p->leader;						//��¼leader�ı�� 
			break;									//��¼��������ѭ�� 
		}	
		p = p->next;
	}
	
	if ( mark == 0)
	{
		cout << "�����ڸ�Ա��"<<endl;
		return;	
	}	
	p = head->next;
	emp *q = head->next;	
//	cout << " lab = "<<lab<<endl;					//������  
	while( p->num != lab )							//ѭ������Ϊ�ж�����˵�����Ƿ�Ϊ��Ҫ���쵼����ţ������ǣ�������һ�� 
	{
		p = p->next;
		if(p->next == NULL && p->num != lab)
		{
			cout << "�������쵼��Ϣ"<<endl; 
			return;
		} 
	}
	mark = p->num;
	int label = 0;
//	paixv(head);
//	cout << "mark = "<<mark<<endl;
	printf("���Ϊ%d��ֱϵ�쵼���£�\n",index);
	while (q != NULL)
	{
		if ( q->num == mark )
		{		
			cout <<"�쵼"<<": "<<setiosflags(ios::left)<<setw(10)<< q->num<<setw(8)<<q->name<<setw(4)
			 <<q->sex<<setw(6)<< q->age<<setw(15)
			 <<q->department<<setw(10)<<q->salary<<setw(2)<<q->leader<<endl; 
			 label = 1;								//�൱��������mark ����Ѿ���⵽ 
		}
	 	q = q->next;
	} 
} 


void paixv(emp *head)								//������Ա���Ĺ��ʴӸߵ������򣨲���ð�����򷨣�  
{
	emp *p = head->next->next;
	emp *pre = head->next; 
	int tmp = 0;									//�����м����		

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		
		for( p = pre->next;p != NULL;p = p->next)	
		{
			if (pre->salary < p->salary)			//�ж�н�ʴ�С 
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
				
				for( int x = 0;x < sizeof(pre->name);x++)	//���ڵ���˳�򣬶�name��char�ͣ�ֱ����string��һ������
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


void rank(emp *head)								//���ݹ������� 
{
	paixv(head);									//���������� 
	cout <<endl;
	display(head);									//��ʾ 
}


emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2)	//ɾ��Ա����Ϣ 
{
	int mark  = 0;									//�����ʶ�� 
	char name[20];
	cout <<"������������";
	cin >> name; 
	emp *p1 = head->next; 							//head�ڵ�û����		
	while ( p1!=NULL)
	{
		if ( p1->num == index)
		{
//			cout <<"name is = " <<name<<endl;
//			cout << "p->name is = "<<p1->name<<endl;
			if ( (string)p1->name != (string)name)	//char��ʱΪʲô������== ������ ��=  2020.11.16�޸���ɣ���Ϊstring�� 
			{
				cout <<"��Ϣ��ƥ��";
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
		cout << "�����ڸ�Ա��"<<endl;
		return head;	
	}	
	cout << "���ڹ��� "<< amount(head)<<" ��Ա��"<<endl;
	printf("��Ҫɾ�����Ǳ��Ϊ%d��Ա��\n",index);
	cout << "Loading ... ..."<<endl; 
	system("cls");
	emp *pre = head;
	emp *p = head->next;
	while(p != NULL)
	{
		if ( p->num == index)
		{
			if(p->next == NULL)						//pΪĩβʱ 
			{
				pre->next = NULL;	
			}
			else if(index == 1)						//pΪ��λʱ 
			{
				head = pre->next;
			}
			else									//�м���� 
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	remove2(head2, index, filename2);				//ɾ��Ա��ȫ����Ϣ������������Ϣ�������Ӻ��� 
	save(filename1, head);							//�������ļ� 
	cout << "������ɣ�"<<endl;
	cout << "������Ϣ���£�"<<endl;
	display(head);									//��ʾ������Ϣ 
	return head;
} 


thing *remove2(thing *head, int index, char *filename1)//ɾ��������Ϣ��������ĿҪ�����������Ϊ��Ϊ��һ����ʹ�ã�������Ϊ�Ӻ���ʹ�ã� 
{
	thing *p = head->next;
	thing *pre = head;
	while(p != NULL)
	{
		if ( p->num == index)
		{
			if(p->next == NULL)							//ĩβ 
			{
				pre->next = NULL;						 
			}
			else if(index == 1)							//��λ 
			{
				head = pre->next;
			}
			else										//�м���� 
			{
				pre->next = p->next;
			}
			delete p;
		}
		p = p->next;
		pre = pre->next;	
	} 
	save2(filename1, head);								//�������ļ� 
	return head;
}


emp *revise(emp *head, int index, char *filename1)	//�޸�һ��Ա����Ϣ		
{
	int mark  = 0;
	emp *p = head->next; 							//head�ڵ�û����		
	while ( p!=NULL)
	{
		if ( p->num == index)						//��⵽���ʶ��Ϊ1 
		{
			mark = 1;
			break; 
		}	
		p = p->next;
	}
	if ( mark == 0)									
	{
		cout << "�����ڸ�Ա��"<<endl;
		return head;	
	}	
	cout << "���ڹ��� "<< amount(head)<<" ��Ա��"<<endl;
	printf("��Ҫ�޸ı��Ϊ%d��Ա��ԭ��Ϣ���£�\n",index); 
	cout << "Loading ... ..."<<endl<<endl;
	bound('_',100);
	cout <<endl;


	p = head->next;									//����pͷָ�� 
	emp *pre = head;								//����һ��pǰһ���ָ�� 
	while(p != NULL)
	{
		if ( p->num == index)
		{
			printf("���Ϊ%d��Ա��ԭ��Ϣ���£�\n",index);
			cout <<setiosflags(ios::left)<<setw(10)<< p->num<<setw(8)<<p->name<<setw(4)
					 <<p->sex<<setw(6)<< p->age<<setw(15)
					 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
		
			emp *newnode = new emp;
			newnode = p; 
			cout << "\n����Ҫ�޸ĵ���  0.ȫ���޸� 1.��� 2.���� 3.�Ա� 4.���� 5.���� 6.н�� 7.ֱϵ�쵼���"<<endl;
			cout << "�����룺";
			int option[8], cnt = 0;					//����ѡ���� ����		
			do{
				cin >> option[cnt];
				if(option[cnt] == 0)
				{
					break;
				}
				cnt++;	
			}while(getchar() != '\n');              //�Է��û���������Ҫ�޸ĵ����� 
		
			if ( option[0] == 0)
			{
				cout << "�������޸�Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
				cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
			} 
			for ( int i = 0; i < cnt;i++)
			{
				if ( option[i] == 1)
				{
					cout << "�������޸ı�ţ�";
					cin >> newnode->num; 
				}
				if ( option[i] == 2)
				{
					cout << "�������޸�������";
					cin >> newnode->name; 
				}
				if ( option[i] == 3)
				{
					cout << "�������޸��Ա�";
					cin >> newnode->sex; 
				}
				if ( option[i] == 4)
				{
					cout << "�������޸����䣺";
					cin >> newnode->age; 
				}
				if ( option[i] == 5)
				{
					cout << "�������޸Ĳ��ţ�";
					cin >> newnode->department; 
				}
				if ( option[i] == 6)
				{
					cout << "�������޸�н�ʣ�";
					cin >> newnode->salary; 
				}
				if ( option[i] == 7)
				{
					cout << "�������޸�ֱϵ�쵼��ţ�";
					cin >> newnode->leader; 
				}
			}
		}
			p = p->next;
			pre = pre->next;	
	} 

	system("cls");
	save(filename1, head);
	cout << "������ɣ�"<<endl;	
	cout << "������Ϣ���£�"<<endl;	
	display(head);

	return head;
}


void save(char *filename1, emp *head)				//����Ա�� 
{
	emp *p = head->next;
	ofstream outfile1(filename1);					//���ļ� 
	while (p != NULL)								//���� 
	{
		outfile1 << p->num<<'\t'<<p->name<<'\t'		//���� 
				<<p->sex<<'\t' << p->age<<'\t'
				<<p->department<<'\t'<<p->salary<<'\t'<<p->leader<<endl;
		p = p->next;
	}
	outfile1.close();								//���ļ� 
}


void save2(char *filename1, thing *head)			//�������� 
{
	thing *p = head->next;
	ofstream outfile1(filename1);					//���ļ� 
	while (p != NULL)								//���� 
	{
		outfile1 << p->num<<'\t'<<p->duty<<endl;	//���� 
		p = p->next;
	}
	outfile1.close();								//���ļ� 
}


void s2b(emp *head)									//small to big���ݱ�Ŵ�С�������� 
{
	emp *p = head->next->next;						
	emp *pre = head->next; 
	int tmp = 0;									//������ʱ�������ڵ��� 

	for ( pre = head->next; pre != NULL ;pre = pre->next)
	{
		for( p = pre->next;p != NULL;p = p->next)
		{
			if (pre->num > p->num)					//�Ƚ���� 
			{
				tmp = pre->salary;					//��������ͬpaixv�Ӻ��� 
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


void s2bt(thing *head)								//small to big things���ݱ�Ŵ�С��������
{
	thing *p = head->next->next;
	thing *pre = head->next; 
	int tmp = 0;									//�����м���� 

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
					char a[100];					//�����м���� 
					a[x] = pre->duty[x];
					pre->duty[x] = p->duty[x];
					p->duty[x] = a[x];
				}
			}
		}
	}
}


void welcome_menu(int select)						//��ӭ�˵� 
{
    cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          ��ӭʹ����ҵ����ϵͳ                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.��ѯ��Ϣ                             *        "<<endl;
	cout << "      		*                               2.�����Ϣ                             *        "<<endl;
	if ( select != 2)
	{
	cout << "      		*                               3.ɾ����Ϣ                             *        "<<endl;
	cout << "        	*                               4.�޸���Ϣ                             *        "<<endl;
	cout << "        	*                               5.Ա������                             *        "<<endl;
	cout << "        	*                               6.����㼶                             *        "<<endl;
	}
	cout << "        	*                               0.�˳�ϵͳ                             *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    if ( select != 2)
	{
		cout << "����������Ҫ�Ĳ�����0 - 6����"; 
	}else
	{
		cout << "����������Ҫ�Ĳ�����0 - 3����"; 
	}
}


//void LoadA(char *filename1)						//���ù��� ��ʱû�� 
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
