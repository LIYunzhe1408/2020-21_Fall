//#include <iostream>
//#include <cmath>
//using namespace std;
//long long ans;
//int k,n,a[20];
//
//bool is_prime(int x)
//{
//    int i;
//    if (x == 1) return false;
//    if (x == 2) return true;
//    for ( i = 3 ;i <= sqrt(x); i ++)
//    {
//        if ( x % i == 0)
//            return false;
//        
//    }
//    return true;
//}
//
//void dfs(int x,int sum,int ss) {//x用来统计选了几个数（x<=k),sum用来加所选的数，ss用来防止重复的升序值
// if (x == k) {//加了满四个数，判断
//  if (is_prime(sum)) 
//   ans++;//是素数加一
//  return;
// }
// for (int i = ss; i < n; i++) {
//  dfs(x + 1, sum + a[i], i + 1);
// }//个数加一，加上和，升序的初始值加一
//  return ;//加满了就返回
//}
//
//int main()
//{
//	int n, k, i;
//	int a[20];
//	cin >> n >> k;
//	for ( i = 0; i < n - 1; i ++)
//	{
//		cin >> a[i];
//	}
//	dfs(0, 0, 0);
//	cout << ans;
//	
//	
//	
//	return 0;
//}

#include <iostream>
#include <cmath>
#define maxn 25
using namespace std;
int a[maxn];
int n, k;
long long ans;//统计是素数的总数
bool isprime(int z) {//判断素数
 if (z == 1) return false;
 if (z == 2 || z == 3) return true;
 if (z % 6 != 1 && z % 6 != 5) return false;
 int s = sqrt(z);
 for (int i = 5; i <= s; i += 6) {
  if (z % i == 0 || z% ( i + 2 ) == 0)
   return false;
 }
 return true;
}
void dfs(int x,int sum,int ss) {//x用来统计选了几个数（x<=k),sum用来加所选的数，ss用来防止重复的升序值
 if (x == k) {//加了满k个数，判断
  if (isprime(sum)) 
   ans++;//是素数加一
  return;
 }
 for (int i = ss; i < n; i++) {
  dfs(x + 1, sum + a[i], i + 1);
 }//个 数 加 一，加上和，升序的初始值加一
  return ;//加 满了就返回
}
int main()
{
 cin >> n >> k;
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 dfs(0, 0, 0);
 cout << ans;//输出个数
 return 0;
}
