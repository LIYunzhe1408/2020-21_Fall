//����
//�����������£����й������������ʲ����Ǻܸߡ�����ݽ�ֹ2009��12��22�ո�ʡ����ļ���ȷ����������������������ڸ�ʡ�������ʡ�
//
//����
//�����һ�У���������������һ��Ϊȷ�������ڶ���Ϊ��������
//
//���
//�����һ�У����������ʣ��԰ٷ�����ʽ�������ȷ��С�����3λ


#include <iostream>
#include <iomanip> //���õ���������ݾ��ȵĺ��� 
using namespace std;

int main()
{
    long quezhen, siwang;  //������������ 
	cin >> quezhen >> siwang ;  //����������� 
	double s = (long) siwang;  //����������ת��Ϊ˫���ȵĸ��������� 
	double q = (long) quezhen;
	double rate;
	
	if ( q == 0 ){  //����if��֧���Է�֮����rate�����з�ĸq���ܳ��ֵ�Ϊ�������� 
		rate = 0;
	    cout <<fixed<<setprecision(3)<< rate << "%";  //��qΪ��ʱ��rate= 0%��������ĿҪ������Ҫ��ȷ��λ 
	   
	}else if ( q >= 0){  //����ĸq��Ϊ��ʱrate�ļ��� 
		rate = (s / q ) * 100;
	    cout <<fixed<<setprecision(3)<< rate << "%";  //������ݱ�����λС�� 
	}
	return 0 ;
 } 
