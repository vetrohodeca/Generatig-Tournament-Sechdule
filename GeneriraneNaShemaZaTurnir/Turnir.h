#pragma once
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
public:
	Tournament();
	Tournament(int numberOfTeams , int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	Tournament(int numberOfTeams, type Scheme ,int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime);
	// funkciite =0
	void setNumberOfTeams(int numberOfTeams);
	void setMatchDuration(int matchDuration);
	void setNumberOfFreeCourts(int numberOfFreeCourts);
	void setScheme(type Scheme);
	void setOutputType(MyString outputType);
	void setStartTime(Date startTime);
	int getNumberOfCourts() const;
	int getDurationOfMatch() const;
	Date getStartTime() const;
	void print();
	virtual void validation();
	virtual int calculateMatches();
	virtual void makeSchedule();
	static Tournament* Create(type Scheme, Tournament T);// create object of new class with same member data
	void output();
};

class EliminationTournament : public Tournament
{
public:
	EliminationTournament();
	EliminationTournament(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	virtual void validation(int numberOfTeams);
	virtual int calculateMatches();
	virtual void makeSchedule();
	virtual ~EliminationTournament();
};

class TeamVsTeam : public Tournament
{
public:
	TeamVsTeam();
	TeamVsTeam(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	virtual void validation(int numberOfTeams);
	virtual int calculateMatches(); 
	virtual void makeSchedule();
	virtual ~TeamVsTeam();
};
