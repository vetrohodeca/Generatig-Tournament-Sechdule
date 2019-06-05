#pragma once
#include<iostream>
using namespace std;
#include"Tournament.h"
class TeamVsTeam : public   Tournament
{
public:
	TeamVsTeam();
	TeamVsTeam(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	virtual void validation(int numberOfTeams);
	virtual int calculateMatches();
	virtual void makeSchedule();
	virtual void makeScheduleFile();
	virtual ~TeamVsTeam();
};
