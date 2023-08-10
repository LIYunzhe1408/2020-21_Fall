#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main(){


    char ch[6];


    cin >> ch;
    sort(ch,ch+strlen(ch));//从小到大排列 
    do{
    cout << ch << endl;
    }while(next_permutation(ch,ch+strlen(ch)));//全排列  https://blog.csdn.net/sgsyacm/article/details/80139089


    return 0;
}




