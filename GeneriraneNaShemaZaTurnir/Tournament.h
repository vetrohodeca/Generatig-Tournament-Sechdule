#pragma once
#include<fstream>
#include"String.h"
#include"Date.h"
using namespace std;
enum type { elimination, allVsAll };
class Tournament
{
protected:
	int numberOfTeams;
	int matchDuration;
	int numberOfFreeCourts;
	type scheme;
	MyString outputType;
	Date startTime;
	// композиция- имаме шаблон, в който като член данна на клас подаваме обект от друг тип
public:
	Tournament();
	Tournament(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	Tournament(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime);
	// funkciite =0, класът е вирутален и от него не може да създаваме обекти
	void setNumberOfTeams(int numberOfTeams);
	void setMatchDuration(int matchDuration);
	void setNumberOfFreeCourts(int numberOfFreeCourts);
	void setScheme(type Scheme);
	void setOutputType(MyString outputType);
	void setStartTime(Date startTime);
	int getNumberOfCourts() const;
	MyString getOutputType() const;
	int getDurationOfMatch() const;
	Date getStartTime() const;
	void print();
	virtual void validation(int numberOfTeams) = 0;
	virtual int calculateMatches() = 0;
	virtual void makeSchedule() = 0; // виртуални функции, защото имаме малка разлка във функционалността
	virtual void makeScheduleFile() = 0;
};


