#include<iostream>
using namespace std;
 
int main() {
	int site[2][100];
	int num;
	while(cin >> num)
	{
	for (int i = 0; i < num; i++) {
		cin >> site[0][i] >> site[1][i];
	}
	//�ܹ���֧�����˼���ǣ�����x��y�����ֵ����������ڣ���ô���ֵ���Ǽ���
	int max[2][100] = { 0 }; // ��¼����ֵ������
 
	int count = 0;
	for (int i = 0; i < num; i++) {
		bool flag = true;
		for (int j = 0; j < num; j++) {
			if (i == j) {
				continue;//���������Ҫÿһ�ζ���ͷ����
				//һ��ʼ�������뵱Ȼ�����ˡ�ð�ݡ���˼·������˼���Ĳ��Ͻ������µĴ���
			}
			else if ((site[0][j] >= site[0][i]) && (site[1][j] >= site[1][i])) {
				//˵����ʱ��iλ�ò��Ǽ���
				flag = false;
			}
 
		}
 
		if (flag == true) {
			//��ʱ�ɼ�¼����ֵ������
			max[0][count] = site[0][i];
			max[1][count] = site[1][i];
			count++;
 
		}
	}
	//Ȼ���Ƕ�max���鰴��x��С��������
	for (int i = 0; i < count; i++) { //count�Ǵ�0��ʼ�����ģ����Ҵ����֮����ִ����һ��++
		for (int j = i + 1; j < count; j++) {//ð������
			if (max[0][j] < max[0][i]) {
				int tempx, tempy;
				tempx = max[0][i];
				tempy = max[1][i];
				max[0][i] = max[0][j];
				max[1][i] = max[1][j];
				max[0][j] = tempx;
				max[1][j] = tempy;
			}
 
		}
	}
 
	//��Ҫ���ʽ���
	for (int i = 0; i < count - 1; i++) {
		cout << '(' << max[0][i] << ',' << max[1][i] << ')' << ',';
	}
	cout << '(' << max[0][count - 1] << ',' << max[1][count - 1] << ')' << endl;
 
}
	return 0;
 
 
}
