#pragma once
#include"Tournament.h"
#include<iostream>
using namespace std;
class EliminationTournament : public Tournament
{
public:
	EliminationTournament();
	EliminationTournament(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime);
	virtual void validation(int numberOfTeams);
	virtual int calculateMatches();
	virtual void makeSchedule();
	virtual void makeScheduleFile();
	virtual ~EliminationTournament();// в случая нямаме нужда от деструтори на поризводните класове, но съм ги написал, при добавяне на нови член данни да са готови
};
