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
�޶���2020.11.11 1��13

version 1.1
1. 

 
��������������������������������������������������������������������
version1.0
demo
�޸���2020.11.8 21��02

******************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct employee//����Ա���ṹ��
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

typedef struct things//��������ṹ��
{
	char num[8];
	char duty[10];
	struct things *next;
}things;

//����ȫ�ֱ��� 
employee *head_emp, *last_emp;
things *head_things, *last_things;

//�Ӻ������� 
void welcome_menu();							//��Ҫ��ʾ 6 �ֹ��� 
int select();									//����selectѡ����ļ� 
void Search();
void Delete();
void Revise();
void Add(int option);
void Input(int option);									//�����ʼԱ����Ϣ  check
void Sort();
void Hierarchy();
void Save();
void bound(char ch, int n);									//�ָ��ߺ��� 

int main()
{
	head_emp = last_emp = NULL;
	int number = 0, isout = 0, option = 0;
    welcome_menu();													//��Ҫ��ʾ 7 �ֹ��� 
    
    
    cin >> number;													//����ѡ��Ĳ���ѡ�� 
    while ( isout != 1)
    {
    	if ( number == 1 || number == 2 || number == 4  )			//���ڲ�ѯ��ɾ������Ӵ��������Ա����ѡ�� 
    	{
    		option = select();										//option == 1ΪԱ���� 2Ϊ���� 
		}
	
    	switch (number)												//����������ѡ�� 
    	{
    		case 0: isout = 1;break; 								//�˳�
			 
//    		case 1:													//��ѯѡ�� 
//			{										
//				Search();
//			}
//			
//    		case 2:													//ɾ��ѡ�� 
//			{
//				Delete();	
//			}
//			
//    		case 3: Revise();										//�޸�ѡ�� 
    		 
//    		case 4:													//���ѡ��		 
//			{
//				Add();
//			}
			
//    		case 5: Sort();											//Ա������ѡ��
//			 
//    		case 6: Hierarchy();									//����㼶ѡ�� 
			case 7: Input(option); 
		} 
		cout << "	��ǰԱ��/������Ϣ���ᱣ��"<<endl; 
//		Save();

		isout = 1;													//�˳����� 
	}
 
	
	return 0;
}


void welcome_menu()
{
    cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          ��ӭʹ����ҵ����ϵͳ                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.��ѯ��Ϣ                             *        "<<endl;
	cout << "      		*                               2.ɾ����Ϣ                             *        "<<endl;
	cout << "      		*                               3.�޸���Ϣ                             *        "<<endl;
	cout << "        	*                               4.�����Ϣ                             *        "<<endl;
	cout << "        	*                               5.Ա������                             *        "<<endl;
	cout << "        	*                               6.����㼶                             *        "<<endl;
	cout << "        	*                               7.¼����Ϣ                             *        "<<endl;
	cout << "        	*                               0.�˳�ϵͳ                             *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    cout << "����������Ҫ�Ĳ�����0 - 7����"; 
}

int select()
{
	int option = 1;
	cout << "        	************************************************************************        "<<endl;
	cout << "        	*                          ��ѡ����Ҫ�����Ķ���                        *        "<<endl;
	cout << "      		************************************************************************        "<<endl;
	cout << "      		*                               1.Ա��                                 *        "<<endl;
	cout << "      		*                               2.����                                 *        "<<endl;
    cout << "        	************************************************************************        "<<endl<<endl;
    cout << "����Ҫ�����Ķ����ǣ�1 �� 2����"; 
    cin >> option ;
    return option;
}

void Input(int option)															//�����ʼԱ��/������Ϣ 						
{
	FILE *fp;//���ڴ��ļ� 
	employee *head1 ;
	things *head2 ;
	int i = 0;
	if ( option == 1)
	{
		fp = fopen("employee.txt","ab");									//��׷�ӷ�ʽ���ļ� 
		if ( fp == NULL)
		{
		cout << "�ļ��򿪳���"<<endl;
		getchar();
		return; 
		}
		
		
		do{
		i ++;
		head1 = (employee*)malloc(sizeof(employee));
		if ( head1 == NULL)
		{
		cout << "�ļ��޷���"<<endl;
		return ;
		}
		cout << "	�������"<<i<<"��Ա������Ϣ��"<<endl;
		bound('_',40);
		cout << endl;
		
		cout << "	������Ա����ţ�";
		cin >> *head1->num;
//		scanf("%s",&head1->num);
		cout << "	������Ա��������";
		cin >> *head1->name;
		cout << "	������Ա���Ա�";
		cin >> *head1->sex;
		cout << "	������Ա�����䣺";
		cin >> *head1->age;
		cout << "	������Ա�����ţ�";
		cin >> *head1->department; 
		cout << "	������Ա����н��";
		cin >> *head1->salary; 
		cout << "	������Ա���ֻ����룺";
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
		cout << "	�Ƿ�������룿������'y'"<<endl;
		fflush(stdin);													//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ
		char ch = getchar();
		if ( ch != toupper('y'))
		{
		fclose(fp);
		cout <<"	������ϣ��밴���������!"<<endl;
		getchar();
		return;	
		} 
		system("cls");
		
		}while(1);
	}
	else
	{
		fp = fopen("things.txt","ab");									//��׷�ӷ�ʽ���ļ� 
		
		if ( fp == NULL)
		{
		cout << "�ļ��򿪳���"<<endl;
		getchar();
		return; 
		}
		
		
		do{
		i ++;
		head2 = (things*)malloc(sizeof(things));
		if ( head2 == NULL)
		{
			cout << "�ļ��޷���"<<endl;
			return ;
		}
		
		
		cout << "	�������"<<i<<"��������Ϣ��"<<endl;
		bound('_',40);
		cout << endl;
		
		cout << "	�����������ţ�";
		scanf("%s",&head2->num);
		cout << "	������Ա������";
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
		
		cout << "	�Ƿ�������룿������'y'"<<endl;
		fflush(stdin);	
		
														//������뻺������ͨ����Ϊ��ȷ����Ӱ���������ݶ�ȡ
		char ch = getchar();
		if ( ch != toupper('y'))
		{
		fclose(fp);
		cout <<"	������ϣ��밴���������!"<<endl;
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
