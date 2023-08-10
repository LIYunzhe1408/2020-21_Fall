#include <iostream>
using namespace std;


void print (List*pList);
void add( List *pList, int number);


typedef struct _node{
	int value;
	struct _node *next;
}Node;

employee * head

int main(int argc, char const *argv[])
{
	List list; 
	int number;
	list.head = NULL;
	do{
		cin >> number;
		if ( number != -1)
		{
			add(&list, number);
		}
	}while (number != -1);
	print (&list);
	
	//找
	cin >> number;
	Node *p;
	int isFound = 0;
	for (p = list.head;p;p = p->next)
	{
		if ( p->value == number)
		{
			cout << "找到了"<<endl;
			isFound = 1;
			break;
		}
	}
	if ( !isFound)
	{
		cout << "没找到"<<endl; 
	}
	
	//delete
	cin >> number;
	Node *p;
	int isFound = 0;
	Node *q = NULL;
	for (q = NULL, p = list.head;p;p = p->next)
	{
		if ( p->value == number)
		{
			if ( q )									//看指针作为->左值时NULL的情况是否加入足够的判断条件 
			{
				q->next = p->next;
			}
			else
			{
				list.head = p->next;
			}
			free(p);    
			break;
		}
	}
	if ( !isFound)
	{
		cout << "没找到"<<endl; 
	}
	
	
	
	return 0;
}

void add( List *pList, int number)
{
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	Node *last = pList->head;
	if ( last)
	{
		while ( last->next)
		{
			last = last->next;
		}
		last->next = p;
	}
	else
	{
		pList->head = p;
	}
}

void print (List*pList)
{
	Node*p;
	for (p = pList->head;p;p = p->next)
	{
		cout << p->value<<endl;
	}
}
