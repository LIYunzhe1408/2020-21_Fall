#include<iostream>
#include<iomanip>
using namespace std;
//1900年1月1号是星期一
 
int nyear(int year)//判断是平年，还是润年
{
	if(year%400==0||(year%4==0&&year%100!=0))
	   return 366;
   else
	   return 365;
}
 
int nmonth(int m,int y)  //根据年份和月份，判断是那一个月的天数
{
   if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
	   return 31;
   else if(nyear(y)==366&&m==2)
	   return 29;
   else if(nyear(y)==365&&m==2)
	   return 28;
   else
	   return 30;
}
 
int getDays(int year, int month)
{
   int i;
   int sum=0;
   if(year>0)
      for(i=1;i<year;i++)
    	  sum+=nyear(i);
   if(month>1)
      for(i=1;i<month;i++)
    	  sum+=nmonth(i,year);
 
   return sum;     //返回总共多少天；
}
 
int main()
{
   int i,j,year,month,day,sum,daycount,cases=1;
 
   while(cin>>year>>month)
   {
      sum=getDays(year,month);
      day=(sum+1)%7;  //这里算出来这个月的一号前面需要几个空格；等于0的话，前面就不需要空格
      daycount=nmonth(month,year);//算出这个月的天数
      cout<<"Case "<<cases++<<": "<<year<<"年"<<month<<"月"<<endl;
      cout<<"Sun Mon Tue Wed Thu Fri Sat"<<endl;
      for(i=0;i<day%7;i++)
         cout<<"    ";
      for(i=1,j=day+1;i<=daycount;i++,j++)
      {
        if( i <=9)
        cout<<"  "<<i<<" ";
        else
        cout <<" "<< i <<" ";
         if(j%7==0) cout<<endl;
      }
      cout<<endl;
   }
 
   return 0;
}
