#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <exception>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;
int count[26] = { 0 };
struct project   //����һ���ṹ�������ţ������Լ�������������
{
	char bian;
	string name;
	int number;
	project* next;
};
project* CreateList(); //��������
	/*cout << "�����ʼ�ִ���Ʒ����: ";
	int n; cin >> n;
	string line;
	cout << "�����ʼ�ִ�: " << endl;
	for (int i = 0; i < n; i++)//while (line != "")
	{
		p = new project;
		//q = new project;
		/*getline(cin, line);
		stringstream ss(line);
		//ss.str(line);
		ss >> p->bian >> p->name >> p->number;
		cout << "������Ʒ���: ";cin >> p->bian;
		cout << endl << "������Ʒ��: "; cin >> p->name;
		cout << endl << "������Ʒ����: "; cin >> p->number;
		if (head == NULL)
			head = p;
		else
		{
			q->next = p;
		}
		q = p;
	}*/
void add(project* head);//��������Ʒ
void out(project* head);//����ϵͳ
void manage(project* head);//�ֿ��̵�ϵͳ
void kill(project*& head);//ɾ����յĻ���(ֻ��ɾ��һ��)
void save(project* head);//�����ļ�
void in(project* head);//���ϵͳ
void list(project*& head);//����ϵͳ
int main()
{
	project* head;
	head = CreateList();
	printf("��ӭ������������ϵͳ\n");
	printf("��ѡ����Ҫ���еĲ���\n1.��Ʒ���\n2.��Ʒ����\n3.�ֿ��̵�\n4.�����Ʒ\n5.ȫ�����\n");
	save(head);
	int a;
	while (cin >> a)
	{
		if (a == 1)
			in(head);
		else if (a == 2)
		{
			out(head);
			kill(head);
			save(head);
		}
		else if (a == 3)
			manage(head);
		else if (a == 4)
			add(head);
		else if (a == 5)
		{
			cout << "���������Ա����: ";
			string str;
			cin >> str;
			if (str == "1145141919810")
			{
				head = NULL;
				save(head);
				cout << "��ɾ��" << endl;
			}
			else
				cout << "�������" << endl;
		}
		//save(head);
		else
		{
			printf("�����������������\n");
			//continue;
		}
		//save(kill(head));
		list(head);
		printf("\n\n\n��ѡ����Ҫ���еĲ���\n1.��Ʒ���\n2.��Ʒ����\n3.�ֿ��̵�\n4.�����Ʒ\n5.ȫ�����\n");
	}
	return 0;
}
project* CreateList()  //��������
{
	project* head = NULL, * p = NULL, * q = NULL;
	
	char filename[6] = { 'x' , '.' , 't' , 'x' , 't' , '\0' };
	fstream fin;
	fin.open(filename);//���ļ�
	string line;
	if (fin.is_open()) cout << "*�ɹ�����*" << endl;
	else
	{
		cout << "����ʧ��" << endl;
		return NULL;
	}
	while (getline(fin, line))
	{
		if (line == "")
			break;
		p = new project;//�����ڴ�ռ��p
		stringstream ss(line);
		ss >> p->bian >> p->name >> p->number;
		if (p->bian >= 65 && p->bian <= 90)
		{
			p->bian += 32;
		}
		if (head == NULL)
			head = p;
		else
		{
			//q = head;
			q->next = p;
		}
		q = p;//qָ��ǰ���һ���ڵ�
	}
	if (head != NULL)
		q->next = NULL;
	fin.clear();//���fin
	fin.close();//�ر��ļ�
	return head;//����ͷָ��
}
void add(project* head)//��������Ʒ
{
	int flag = 0;
	project* p = NULL, * q = NULL;
	p = head;
	char ch;
	cout << "��������Ʒ���: "; 
	cin >> ch;
	if (ch >= 65 && ch <= 90)
	{
		ch += 32;
	}
	while (p != NULL)
	{
		if (p->bian == ch)
		{
			cout << "�ñ���Ѵ�����Ʒ\n��Ҫ�鿴������Ʒ����������1\n����������������2\n�ص�������������3\n";
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 1)
	{
		int n;
		cin >> n;
		if (n == 1)
			manage(head);
		else if (n == 2)
			add(head);
		else if (n == 3)
			return;
	}
	if (flag == 0)
	{
		q = new project;
		//cout << "������Ʒ���: "; cin >> q->bian;
		q->bian = ch;
		cout << "������Ʒ��: "; cin >> q->name;
		cout << "������Ʒ����: "; cin >> q->number;
		//q->next = NULL;
		while (q->number <= 0)
		{
			cout << "��������ȷ����Ʒ����";
			cin >> q->number;
		}
		if (head == NULL)
			head = q;
		else
		{
			p = head;
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = q;
			q->next = NULL;
			cout << "���ɹ�"<<endl;
		}
		save(head);
	}
}
void in(project* head)//���ϵͳ
{
	char ch;
	int flag = 0;
	project* p = NULL;
	p = head;
	cout << "������Ʒ���: "; cin >> ch;
	if (ch >= 65 && ch <= 90)
	{
		ch += 32;
	}
	while (p != NULL)
	{
		if (p->bian == ch)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		cout << "����Ʒ������\n��Ҫ�鿴������Ʒ����������1\n����������������2\n�ص�������������3\n";
		int n;
		cin >> n;
		if (n == 1)
			manage(head);
		else if (n == 2)
			add(head);
		else if (n == 3)
			return;
	}
	else if (flag == 1)
	{
		int n;
		cout << "���������Ʒ�������: ";
		cin >> n; 
		while (n <= 0)
		{
			cout << "��������ȷ����Ʒ����";
			cin >> n;
		}
		p->number += n;
		save(head);
		cout << "��Ʒ�����";
	}
}
void out(project* head)//����ϵͳ
{
	char ch;
	int flag = 0;
	project* p = NULL;
	project* q = NULL;
	p = head;
	cout << "������Ʒ���: "; cin >> ch;
	if (ch >= 65 && ch <= 90)
	{
		ch += 32;
	}
	while (p != NULL)
	{
		q = p;
		if (p->bian == ch)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		cout << "����Ʒ������\n��Ҫ�鿴������Ʒ����������1\n����������������2\n�ص�������������3\n";
		int n;
		cin >> n;
		if (n == 1)
			manage(head);
		else if (n == 2)
			add(head);
		else if (n == 3)
			return;
	}
	else if (flag == 1)
	{
		int n;
		cout << "���������Ʒ��������: ";
		cin >> n;
		if (n>p->number)
			cout << "�ѳ�������Ʒ�������\n��Ҫ����������������������1\n�鿴�������������2\n�ص�������������3\n" ;
		while (n > p->number)
		{
			int a;
			cin >> a;
			if (a == 1)
			{
				cout << "���������Ʒ��������: ";
				cin >> n;
			}
			else if (a == 2)
			{
				cout << p->bian << " " << p->name << " " << p->number << endl << endl << endl;
				cout << "��Ҫ����������������������1\n�鿴�������������2\n�ص�������������3\n" << endl;
			}
			else if (a == 3)
				return;
		}
		p->number -= n;
		//if (p->number == 0)
			//kill(head);
		cout << "��Ʒ�ѳ���";
	}
}
void manage(project* head)//�ֿ��̵�ϵͳ
{
	project* p = NULL;
	p = head;
	if (head == NULL)
		cout << "����Ʒ" << endl;
	while (p != NULL)
	{
		cout << p->bian << " " << p->name << " " << p->number << endl;
		p = p->next;
	}
}
void kill(project*& head)//ɾ����յĻ���(ֻ��ɾ��һ��)
{
	project* p = NULL, * q = NULL;
	p = head;
	if (head->number == 0)
	{
		if (head->next != NULL)
		{   
			head = head->next;
			//cout << head->number << endl;
			delete p;
			
		}
		else
		{
			delete head;
			head = NULL;
			cout << "����Ʒ" << endl;
			//return;
		}
		//return head;
	}
	else
	{
		while (p->next != NULL)
		{
			q = p->next;
			if (q->number == 0)
			{
				p->next = q->next;
				delete q;
			}
			else
				p = q;

		}
	}
	//save(head);
}
void save(project* head)//�����ļ�
{
	kill(head);
	list(head);
	project* p = NULL, * q = NULL;
	char filename[6] = { 'x','.','t','x','t','\0' };
	ofstream fout;
	fout.open(filename, ios::trunc);
	p = head;
	while (p != NULL)
	{
		fout << p->bian << " " << p->name << " " << p->number << endl;
		p = p->next;
	}
	fout.clear();
	fout.close();
}
void list(project*& head)
{
	if (head == NULL)
		return;
	project* p = NULL, * q = NULL, * rua = NULL;
	p = head;
	int flag = 1;
	while (flag == 1)
	{
		flag = 0;
		while (p!=NULL)
		{
			q = p -> next;
			if (q == NULL)
				break;
			if (p->bian > q->bian)
			{
				if (p == head)
				{
					q->next = p;
					head = q;
					p->next =p->next->next;
				}
				else
				{
					rua -> next = q;
					p -> next = q -> next;
					q -> next = p;
				}
				flag = 1;
			}
			rua = p;
			p = p->next;
		}
	}
}
