/******************************************************************
�߼�����c++������ƴ���ҵ����ҵ����ϵͳ
��ʦ���Ų���
���ߣ�20123101 ������ �Ϻ���ѧ������������ѧѧԺ ���ܿ�ѧ�뼼��

�����޶���־��
version 1.0
1.ȷ��������ܺ��Ӻ��� 
���ڲ�ѯ��ɾ������ӽ���Ա���������ѡ������Ϊһ�������������Ǳ�Ϊ�ֲ����������ӿɶ��ԡ� 
2. ��д���Ա��/������
�����fwriteд��txt����̫�ã������ʱlastָ��δָ��ĩβ����
Q:д����±��������ܷ��У�
Q:�Ƿ���fwrite��ֻ�ܸ��ṹ���ÿ����Ա������Ϊchar���ͣ�
������ ����iostream���ļ��ɹ���
 
�޶���2020.11.11 1��13

version 1.1
1. ���ȫ���޸� �޸Ĳ��ּ�ע����Ϣ
�޸���2020.11.15 7��02 
 
version 1.2
������Ϣ����debug 
 
��������������������������������������������������������������������
version1.0
demo

version 1.1
���ȫ���Ӻ���������debug

version 1.2
����debug���

 
�޸���2020.11.8 21��02

******************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <iomanip>
using namespace std;

typedef struct node{					//�����ڵ� 
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

typedef struct node1{					 //�����ڵ� 
	int num;
	char duty[100];
	struct node1 *next;
}thing;							    	//emp == employee 

int  amount(emp *head);					//�Ӻ������� 
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
	cout << "        	*                          ��ӭʹ����ҵ����ϵͳ                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	emp *head = checkfirst(filename1);
	thing *head2 = checkfirst2(filename2);
	s2b(head);
	s2bt(head2);	

	cout << "��ѡ����Ҫ�����Ķ���1.Ա�� 2.����"<<endl;
	cout << "�����룺";cin>> select; 
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
				cout << "�����ѯ 1.ȫ��Ա����Ϣ 2.Ա��������Ϣ"<<endl;
				cout << "�����룺";cin >> option ;
				if ( option == 1)
				{
					cout << "��ѯ��Ϣ���£�"<<endl; 
					display(head);
				}else
				{
					cout << "�����������ѯԱ����Ϣ�ı�ţ�";
					cin >> num_emp;
					displayperson(head, num_emp);
				}	
				
			}
			else if( number == 2)
			{
				cout << "��������Ҫ�����Ա����ţ�";
				cin >> num_emp;
				insert(head, num_emp, filename1);			
			} 
			else  if ( number == 3)
			{
				cout << "��������Ҫɾ����Ա����ţ�";
				cin >> num_emp;
				remove(head, head2, num_emp, filename1, filename2);
			}
			else if ( number == 4)
			{
				cout <<"��������Ҫ�޸ĵ�Ա����ţ�";
				cin >> num_emp;
				cout << endl;
				revise(head, num_emp, filename1); 
			}
			else if ( number == 5)
			{
				cout <<"ϵͳ���ڴ������Ժ�";
				rank(head);	
				head = createListX(filename1);
			} 
			else if ( number == 6)
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
		}else if ( select == 2)
		{
			if ( number == 1)
			{
				int option = 0;
				cout << "�����ѯ 1.ȫ��������Ϣ 2.Ա��������Ϣ"<<endl;
				cout << "�����룺";cin >> option ;
				if ( option == 1)
				{
					cout << "��ѯ��Ϣ���£�"<<endl; 
					display2(head2);
				}else
				{
					cout << "�����������ѯ������Ϣ��Ա����ţ�";
					cin >> num_emp;
					displayperson2(head2, num_emp);
				}	
				
			}
			else if( number == 2)
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
			cout << "��ѡ����Ҫ�����Ķ���1.Ա�� 2.����"<<endl;
			cout << "�����룺";cin>> select; 
			welcome_menu(select);
		}
		
	}
	return 0;
} 




int  amount(emp *head)					//����Ա���ڵ���� 
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

int  amount2(thing *head)				//��������ڵ���� 
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

emp *createList(int n, char *filename1)	//Ա���ļ�������ʱ 
{
	emp *head = new emp;				//ͷ�ڵ� һ�㲻�洢����
	emp *pre = head;	 				//������һ���ڵ� 
//	emp head;         					//����дhead���Ƕ�̬�ģ����Ǵ�����ջ�� 
	ofstream outfile;
	outfile.open(filename1,ios::out);
	for ( int i = 0;i < n;i++)
	{
		emp *p = new emp;
		printf("�������%d��ְԱ����Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���)\n",i+1);


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

thing *createList2(int n, char *filename1)	//�����ļ�������ʱ 
{
	thing *head = new thing;				//ͷ�ڵ� һ�㲻�洢����
	thing *pre = head;	 					//������һ���ڵ� 
        				
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


emp *createListX(char *filename1)		//Ա���ļ�����ʱ 
{
	emp *head = new emp;				//ͷ�ڵ� һ�㲻�洢����
	emp *pre = head;					//������һ���ڵ� 
//	emp head;         					//����дhead���Ƕ�̬�ģ����Ǵ�����ջ�� 
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

thing *createListX2(char *filename1)	//�����ļ�����ʱ 
{
	thing *head = new thing;			//ͷ�ڵ� һ�㲻�洢����
	thing *pre = head;					//������һ���ڵ� 
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

void display (emp *head)				//չʾԱ����Ϣ 
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

void display2 (thing *head)				//չʾȫ��������Ϣ 
{
	thing *p = head->next; 				//head�ڵ�û����			
	while ( p != NULL)
	{
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->duty<<endl;
		p = p->next;
	}
}

//void LoadA(char *filename1)				//��ʱû�� 
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

emp *checkfirst(char *filename1)		//�״�ʹ�ã������û���Ϣ��ʼ��
{
	FILE *fp;
	int n;
	emp *head ;
	ifstream ifs(filename1,ios::in); 
	char ch;
	ifs>>ch;

	if((fp=fopen(filename1,"r"))==NULL||ifs.eof())
	{
		cout <<"��ϵͳ���������Ӧ�ĳ�ʼ������!"<<endl;
		cout << "��������Ҫ¼���Ա��������";
		
		cin >> n;
		cout << endl; 	
		head = createList(n, filename1);
		cout <<"Ա����Ϣ������ɣ�" <<endl;	
	}
	else
	{
		head = createListX(filename1);
		cout << "Ա����Ϣ�Ѵ���."<<endl;
	}

	return head;
}


thing *checkfirst2(char *filename1)		//�״�ʹ�ã����������û���Ϣ��ʼ��
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

void welcome_menu(int select)			//��ӭ�˵� 
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


emp *insert(emp *head, int index, char *filename1)				//����һ��Ա�� 
{
	cout << "���ڹ��� "<< amount(head)<<" ��Ա��"<<endl;
	printf("��Ҫ������Ϊ%d��Ա��\n",index); 

	emp *p = head;
	emp *newnode = new emp;
	while ( p != NULL)
	{
		if ( p->num == index)
		{
			bound('_',100);
			cout << endl;
			cout << "��Ǹ������Ѵ��ڣ�"<<endl;
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
		if ( index > p->num)
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
		else
		{
			cout << "Loading ... ..."<<endl;
			bound('_',100);
			cout << endl;
			cout << "���������Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
			
			cin >> newnode->num>>newnode->name>>newnode->sex
				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
				
			p = head->next;
			emp *pre = head; 
			while(p)				//ѭ����֤��һ���ڵ�ָ��Ҫ�������һ��λ�� 
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
//			for (int i = 0; i < index - 1;i++)			//ѭ����֤��һ���ڵ�ָ��Ҫ�������һ��λ�� 
//			{
//				p = p->next;	
//			} 
////	
//			cout << "Loading ... ..."<<endl;
//			bound('_',100);
//			cout << endl;
//			cout << "���������Ա������Ϣ(��� ���� �Ա� ���� ���� н�� ֱϵ�쵼���): "<<endl;
//			
//			cin >> newnode->num>>newnode->name>>newnode->sex
//				>>newnode->age>>newnode->department>>newnode->salary>>newnode->leader; 
//			
//				newnode->next = p->next;
//				p->next = newnode;
		}
	
	system("cls");
	save(filename1, head);
	cout << "������ɣ�"<<endl;	
	cout << "������Ϣ���£�"<<endl;	
	display(head);


	return head;
}


thing *insert2(thing *head2, emp *head, int index, char *filename1)				//����һ��Ա�� 
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

void save(char *filename1, emp *head)	//����Ա�� 
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

void save2(char *filename1, thing *head)//�������� 
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

emp *remove(emp *head, thing *head2, int index, char *filename1,char *filename2)				//ɾ��Ա��Ա����Ϣ 
{
	int mark  = 0;
	char name[20];
	cout <<"������������";
	cin >> name; 
	emp *p1 = head->next; 				//head�ڵ�û����		
	while ( p1!=NULL)
	{
		if ( p1->num == index)
		{
			if ( p1->name == name)
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
	cout << "������ɣ�"<<endl;
	cout << "������Ϣ���£�"<<endl;
	display(head); 
	return head;
} 

emp *revise(emp *head, int index, char *filename1)				//�޸�һ��Ա����Ϣ		
{
	int mark  = 0;
	emp *p = head->next; 				//head�ڵ�û����		
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
		cout << "�����ڸ�Ա��"<<endl;
		return head;	
	}	
	cout << "���ڹ��� "<< amount(head)<<" ��Ա��"<<endl;
	printf("��Ҫ�޸ı��Ϊ%d��Ա��ԭ��Ϣ���£�\n",index); 
	cout << "Loading ... ..."<<endl<<endl;
	bound('_',100);
	cout <<endl;


	p = head->next;
	emp *pre = head;
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

void rank(emp *head)											//���ݹ������� 
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


void leader(emp *head, int index)        //ֱϵ�쵼 .debug ���飬��ָ��p,q ��ѭ���жϹؼ����ڿ�����ѭ����p��q�Ƿ���Ҫʹ�ã�Ҫp->next!=NULL,��Ҫp!=NUll 
{
	int mark  = 0, lab = 0;
	emp *p = head->next; 				//head�ڵ�û����		
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
		cout << "�����ڸ�Ա��"<<endl;
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
	printf("���Ϊ%d��ֱϵ�쵼���£�\n",index);
	int cnt = 0;
	while (q != NULL)
	{
		if ( q->num == mark )
		{
			cnt ++;			
			cout <<"�쵼"<<cnt<<": "<<setiosflags(ios::left)<<setw(10)<< q->num<<setw(8)<<q->name<<setw(4)
			 <<q->sex<<setw(6)<< q->age<<setw(15)
			 <<q->department<<setw(10)<<q->salary<<setw(2)<<q->leader<<endl; 
			 label = 1;

		}
	 	q = q->next;

	} 
	if ( label == 0)
	{
		cout << "�������쵼��Ϣ"<<endl; 
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

void displayperson (emp *head, int index)	//��ʾ������Ϣ 
{
	int mark  = 0;
	char name[20];
	cout <<"������������";
	cin >> name; 
	emp *p = head->next; 					//head�ڵ�û����		
	while ( p->next!=NULL)
	{
		if ( p->num == index)
		{
			if ( p->name != name)
			{
				cout <<"��Ϣ��ƥ��";
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
		cout << "�����ڸ�Ա��"<<endl;
		return;	
	}	
		cout <<setiosflags(ios::left)<<setw(8)<< p->num<<setw(8)<<p->name<<setw(4)
			 <<p->sex<<setw(6)<< p->age<<setw(25)
			 <<p->department<<setw(10)<<p->salary<<setw(2)<<p->leader<<endl;
}

void displayperson2 (thing *head, int index)//��ʾ������Ϣ 
{
	int mark  = 0;
	thing *p = head->next; 					//head�ڵ�û����		
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
