
#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    char str[40][40] = {"¡õ¡õ¡õ¡õ", "¡õ¡õ¡õ¡ö", "¡õ¡õ¡ö¡õ", "¡õ¡õ¡ö¡ö",

                        "¡õ¡ö¡õ¡õ","¡õ¡ö¡õ¡ö", "¡õ¡ö¡ö¡õ", "¡õ¡ö¡ö¡ö",

                        "¡ö¡õ¡õ¡õ","¡ö¡õ¡õ¡ö", "¡ö¡õ¡ö¡õ", "¡ö¡õ¡ö¡ö",

                        "¡ö¡ö¡õ¡õ","¡ö¡ö¡õ¡ö", "¡ö¡ö¡ö¡õ", "¡ö¡ö¡ö¡ö"};

    int k[88];
    int cas=0;
    while(cin>>hex>>k[0])
    {
 
        int temp;
        for(int x=1;x<=31;x++) cin>>hex>>k[x];
        if(getchar()=='\n')
        {
            cas++;
            cout<<"Case "<<cas<<":"<<endl;
            for(int t=0;t<=31;t++){
                int s,g;
                s=(int)k[t]/16;
                g=(int)k[t]-s*16;
                cout<<str[s]<<str[g];
                if(t%2==1)cout<<endl;
            }
        }
    }

    return 0;
}
