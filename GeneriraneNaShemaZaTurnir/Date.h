#pragma once
class Date {
private:
	int day;
	int month;
	int year;
	int hour;
	int min;
public:
	Date();
	Date(int day, int month, int year, int hour, int min);
	int getMin() const;
	void setMin(int min);
	int getHour() const;
	void setHour(int hour);
	void setDay(int day);
	int getDay() const;
	int getMonth() const;
	void setMonth(int month);
	int getYear() const;
	void setYear(int year);
	bool checkLeapYear(const Date d);
	void addMinutes(int minutes);
	void printDate() const;
	void monthTable(int months[12], Date d)const;
	int DaysInMonth(const Date d) ;
};