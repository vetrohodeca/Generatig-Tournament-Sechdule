#include<iostream>
#include"Date.h"
#include<cmath>
int daysOfMonths[12];
using namespace std;
Date::Date()
	{
		this->day = 1;
		this->month = 1;
		this->year = 2000;
		this->hour = 0;
		this->min = 0;
	}

	Date::Date(int day, int month, int year, int hour, int min)
	{
		setYear(year);
		setMonth(month);
		setDay(day);
		setHour(hour);
		setMin(min);
	}
	int Date::getMin() const
	{
		return min;
	}
	void Date::setMin(int min)
	{
		this->min = min;
		if (min < 0)
		{
			this->min = 0;
		}
	}
	int Date::getHour() const
	{
		return hour;
	}
	void Date::setHour(int hour)
	{
		this->hour = hour;
		if (hour < 0)
		{
			this->hour = 0;
		}
	}
	void Date::setDay(int day)
	{
		this->day = day;
		if (day < 0)
		{
			this->day = 1;
		}
	}
	int Date::getDay() const
	{
		return day;
	}
	int Date:: getMonth() const
	{
		return month;
	}
	void Date:: setMonth(int month)
	{
		this->month = month;
		if (month < 0)
		{
			this->month = 1;
		}
	}
	int Date::getYear() const
	{
		return year;
	}
	void Date::setYear(int year)
	{
		this->year = year;
	}

	void Date::addMinutes(int minutes)
	{
		this->min += minutes;
		int newHour = min / 60;
		min = min - newHour * 60;
		this->hour = (this->hour + newHour);

		int days = hour / 24;
		hour = hour - days * 24;
		this->day = (this->day + days);

		monthTable(daysOfMonths, *this);
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
			|| month == 10 || month == 12)
		{
			while (day > 31)
			{
				day = this->day - daysOfMonths[getMonth() - 1];
				month++;
				this->day = day;

			}
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			while (day > 30)
			{
				day = day - daysOfMonths[getMonth() - 1];
				month++;
				this->day = day;
			}
		}
		if (checkLeapYear(*this) == 1 &&month==2)
		{
			while (day > 29)
			{
				day = day - daysOfMonths[getMonth() - 1];
				month++;
				this->day = day;
			}
		}
		if (checkLeapYear(*this) == 0 && month==2)

		{
			while (day > 28)
			{
				day = day - daysOfMonths[getMonth() - 1];
				month++;
				this->day = day;
			}
		}
		if (this->month > 12)
		{
			this->month = 1;
			year++;
		}
	}

	void Date::printDate()
	{
		if (getDay() < 10)
		{
			cout << "0" << getDay();
		}
		else
		{
			cout << getDay();
		}
		cout << ".";
		if (getMonth() < 10)
		{
			cout << "0" << getMonth();
		}
		else
		{
			cout << getMonth();
		}
		cout << ".";
		cout << getYear() << "  ";
		if (getHour() < 10)
		{
			cout << "0" << getHour();
		}
		else
		{
			cout << getHour();
		}
		cout << ":";
		if (getMin() < 10)
		{
			cout << "0" << getMin();
		}
		else
		{
			cout << getMin();
		}
		cout << endl;
	}

	// 1- is for leap, 0 is not leap
	bool Date::checkLeapYear(Date d)
	{
		int  year = d.getYear();

		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
					return 1;
				else
					return 0;
			}
			else
				return 1;
		}
		else
			return 0;

	}

	void Date::monthTable(int months[12], Date d)
	{
		daysOfMonths[0] = 31;
		bool leap = d.checkLeapYear(d);
		if (leap == 1)
		{
			daysOfMonths[1] = 29;
		}
		else
		{
			daysOfMonths[1] = 28;
		}
		daysOfMonths[2] = 31;
		daysOfMonths[3] = 30;
		daysOfMonths[4] = 31;
		daysOfMonths[5] = 30;
		daysOfMonths[6] = 31;
		daysOfMonths[7] = 31;
		daysOfMonths[8] = 30;
		daysOfMonths[9] = 31;
		daysOfMonths[10] = 30;
		daysOfMonths[11] = 31;
	}

	int Date::DaysInMonth(Date d)
	{
		int days[] = { -1, 31,28,31,30,31,30,31,31,30,31,30,31 };

		if (checkLeapYear(d) == 1)
		{
			days[2] = 29;
		}

		return days[month];
	}

