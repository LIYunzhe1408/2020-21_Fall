#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
 char c;
 int m1 = 0, n1 = 0;
 int m2 = 0, n2 = 0;
 int r21[100000][2], n = 0;
 
 while(cin >> c)
 {
  if ( 'E' != c)
  {
   if ('W' == c)
   {
    m1++;
    m2++;
    //cout << m1 << endl;
   }
   else
   {
    n1++;
    n2++;
    //cout << n1 << endl;
   }
   
   if ((m1 >= 11 || n1 >= 11) && abs(m1-n1) >= 2)
   {
    cout << m1 << ':' << n1 << endl;
    m1 = 0;
    n1 = 0;
   }
   if ((m2 >= 21 || n2 >= 21) && abs(m2-n2) >= 2)
   {
    r21[n][0] = m2;
    r21[n][1] = n2;
    n++;
    //cout << m2 << ':' << n2 << endl;
    m2 = 0;
    n2 = 0;
   }
  }
  else
  {
    cout << m1 << ':' << n1 << endl;
    m1 = 0;
    n1 = 0;
    
    r21[n][0] = m2;
    r21[n][1] = n2;
    n++;
    //cout << m2 << ':' << n2 << endl;
    m2 = 0;
    n2 = 0;
    break;
  }
 }
 
 cout << endl;
 for (int i = 0; i < n; i++)
 {
  cout << r21[i][0] << ':' << r21[i][1] << endl;
 }
}


