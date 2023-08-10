#include <iostream>
using namespace std;

int main()
{
	int Case = 0;
	int year, month, day;
	
	
	while ( cin >> year >>month>>day)
	{
		//输出日期 
		cout << "Case "<<++Case<<": ";
		if ( month < 10)
		{
			cout << '0'<<month<<'/';
		}
		else
		{
			cout << month<<'/';
		}
		if ( day < 10)
		{
			cout << '0'<<day<<'/';
		}
		else
		{
			cout << day<<'/';
		}
		cout << year << ", ";
		
		
		
		//计算天数
		int sum = day;
		int day_mon2 = 0;
		if ( year % 400 == 0 || year%4==0 && year %100!=0)
		{
		    day_mon2 = 29;	
		} else
		{
			day_mon2 = 28;
		}
			
		switch(month)
		{
			case 1:
				sum =  day;
				break;
			case 2:
				sum += 31;
				break;
			case 3:
			    sum += day_mon2 + 31;
			    break;
			case 4:
				sum += day_mon2 + 31*2;  
				break;
			case 5:
				sum += day_mon2 + 31*2 + 30;
				break;
			case 6:
				sum += day_mon2 + 31*3 + 30;
				break;
			case 7:
				sum += day_mon2 + 31*3 + 30*2;
				break;
			case 8:
				sum += day_mon2 + 31*4 + 30*2;
				break;
			case 9:
				sum += day_mon2 + 31*5 + 30*2;
				break;
			case 10:
				sum += day_mon2 + 31*5 + 30*3;
				break;
			case 11:
				sum += day_mon2 + 31*6 + 30*3;
				break;
			case 12:
				sum += day_mon2 + 31*6 + 30*4;
				break;
		}
		cout << sum <<endl;
		
	}
	return 0;
}
