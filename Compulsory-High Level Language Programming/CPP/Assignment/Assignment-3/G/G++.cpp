#include <iostream>
#include<memory.h>
using namespace std;

    int main()
    {
        int  n;
        int Case =0;
        int p,c;
        int m=0;
        int s[100];
       while(cin>>n>>p)
       {
           cout<<"Case "<<++Case<<": ";
           if (n==0)
            cout<<"0"<<endl;
           else

        {while (n!=0)
        {
            c=n%p;
            n=n/p;
            m++;s[m]=c;
        }

        for(int k=m;k>=1;k--)
        {
            if(s[k]>=10)
                cout<<(char)(s[k]+55);
            else
                cout<<s[k];
        }

        cout<<endl;}
        m=0;
        memset(s,0,sizeof(s));
       }

        return 0;
    }
