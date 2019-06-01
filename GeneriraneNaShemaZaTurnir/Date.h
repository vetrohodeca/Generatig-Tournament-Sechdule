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
	bool checkLeapYear(Date d);
	void addMinutes(int minutes);
	void printDate();
	void monthTable(int months[12], Date d);
	int DaysInMonth(Date d);
};