// DATE.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CDate
{
	int Year, Month, Day;
public:
	int years[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	CDate()
	{
		Year = 0;
		Month = 0;
		Day = 0;
	}
	void setvalue(int y, int m, int d)
	{
		Year = y;
		Month = m;
		Day = d;
        if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
            years[1] = 29;
		if (Day > years[Month - 1])
		{
			Day = Day - years[Month-1];
			Month++;
		}
		if (Month > 12)
		{
			Year++;
			Month = Month % 12;
		}
	}
	void display();
	CDate operator +(CDate & obj);
};
void CDate::display()
{
	cout << Year << "  year " << Month << "   month " << Day << "   Day"<<endl;
}
CDate CDate::operator+(CDate & obj)
{
	CDate temp;
	temp.setvalue(Year + obj.Year, Month + obj.Month, Day + obj.Day);
	return temp;
}
int main()
{
	CDate a, b, c;
	a.setvalue(2008, 2, 29);
	b.setvalue(0, 10,2);
	c = a + b;
	c.display();
    return 0;
}

