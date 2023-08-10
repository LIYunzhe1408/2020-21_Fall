#include<iostream>
using namespace std;
int main(){
	char a[102][102];
	int b[102][102];
	int m, n,i,j,p,q,x,y,e,f;
	cin>>m>>n;
    for(e=0;e<=m+1;e++){
    	a[e][0]='?';
    	a[e][n+1]='?';
	}
	for(f=0;f<=n+1;f++){
    	a[0][f]='?';
    	a[m+1][f]='?';
	}
    for (int p=1; p<=m; p++)

	{

		for (int q=1; q<=n; q++)

		{

			cin >> a[p][q];

		}

	}
	   for (int i = 1;i<=m;i++){
		for (int j = 1;j<=n;j++){
			b[i][j]=0;
			if(a[i-1][j-1]=='*'){
				b[i][j]++;
			}
			if(a[i][j-1]=='*'){
				b[i][j]++;
			}
			if(a[i+1][j-1]=='*'){
				b[i][j]++;
			}
			if(a[i-1][j]=='*'){
				b[i][j]++;
			}
			if(a[i+1][j]=='*'){
				b[i][j]++;
			}
			if(a[i-1][j+1]=='*'){
				b[i][j]++;
			}
			if(a[i][j+1]=='*'){
				b[i][j]++;
			}
			if(a[i+1][j+1]=='*'){
			    b[i][j]++;
		    }
        }
    } 
    for(x=1;x<=m;x++){
    	for(y=1;y<=n;y++){
    		if(a[x][y]=='*'){
    			cout<<"*";
			}
			else{
				cout<<b[x][y];
			}
		}
		cout<<endl;
	}
	return 0;
}

