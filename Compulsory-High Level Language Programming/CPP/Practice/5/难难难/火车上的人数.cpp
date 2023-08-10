/***********************************************
描述
火车从始发站（称为第1站）开出，在始发站上车的人数为a，然后到 达第2站，
在第2站有人上、下车，但上、下车的人数相同，
因此在第2站开出时（即在到达第3站之前）车上的人数保持为a人。
从第3站起（包括第3站）上、下车的人数有一定规律：
上车的人数都是上两站上车人数之和，而下车人数等于上一站上车人数，
一直到终点站的前一站（第n-1站），都满足此规律。现给出的条件是：共有n个车站，始发站上车的人数为a，最后一站下车的人数是m（全部下车）。试问x站开出时车上的人数是多少？

输入
一行，包含四个整数a，n，m和x，相邻两个整数之间用单个空格隔开。0≤a≤10, 3≤x<n≤15, 0≤m≤10000。 题目保证数据有唯一解。允许有人在同一站上下车。

输出
一个整数，为从x站开出时车上的人数。

样例输入1
5 7 32 4
样例输出1
13
************************************************/




#include <iostream>
using namespace std;
int in[15], sheng[15];

int main(){
	int a, n, m, x;
	cin >> a >> n >> m >> x ;
	
	if ( x <= 2){
	cout << a  ;
	} else{
		
	in[1]=a;
	sheng[1]=sheng[2]=a ;
	
	for (int people = 0 ; people <= 10 ; people ++){
		 in[2] = people ;
		 
		 for ( int stationx = 3; stationx < n; stationx++){
				in[stationx] = in[stationx-1] + in[stationx-2];
				sheng[stationx] = sheng[stationx-1] + in[stationx] - in[stationx-1];	
			}
			
		 if (sheng[n-1] == m){
				cout << sheng[x] <<endl ;
				return 0 ;
			}
		}
	}
	return 0 ;

}
