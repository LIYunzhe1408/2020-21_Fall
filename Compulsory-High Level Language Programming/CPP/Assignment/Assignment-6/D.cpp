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
	//能够被支配的意思就是，存在x和y≥其的值，如果不存在，那么这个值就是极大
	int max[2][100] = { 0 }; // 记录极大值的坐标
 
	int count = 0;
	for (int i = 0; i < num; i++) {
		bool flag = true;
		for (int j = 0; j < num; j++) {
			if (i == j) {
				continue;//在这里就需要每一次都从头遍历
				//一开始我在里想当然的用了“冒泡”的思路，就是思考的不严谨，导致的错误
			}
			else if ((site[0][j] >= site[0][i]) && (site[1][j] >= site[1][i])) {
				//说明此时的i位置不是极大
				flag = false;
			}
 
		}
 
		if (flag == true) {
			//此时可记录极大值的坐标
			max[0][count] = site[0][i];
			max[1][count] = site[1][i];
			count++;
 
		}
	}
	//然后是对max数组按照x从小到大排序
	for (int i = 0; i < count; i++) { //count是从0开始计数的，并且储存过之后又执行了一次++
		for (int j = i + 1; j < count; j++) {//冒泡排序
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
 
	//按要求格式输出
	for (int i = 0; i < count - 1; i++) {
		cout << '(' << max[0][i] << ',' << max[1][i] << ')' << ',';
	}
	cout << '(' << max[0][count - 1] << ',' << max[1][count - 1] << ')' << endl;
 
}
	return 0;
 
 
}
