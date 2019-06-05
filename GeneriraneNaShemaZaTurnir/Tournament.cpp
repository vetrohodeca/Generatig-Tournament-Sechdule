#include"Tournament.h"
#include"EliminationTournament.h"
#include"TeamVsTeam.h"
#include<cmath>
#include<iostream>
using namespace std;
void Tournament::setNumberOfTeams(int numberOfTeams)
{
	if (numberOfTeams < 2)
	{
		this->numberOfTeams = 2;
	}
	this->numberOfTeams = numberOfTeams;
}
void Tournament::setMatchDuration(int matchDuration)
{
	if (matchDuration < 1)
	{
		this->matchDuration = 1;
	}
	this->matchDuration = matchDuration;
}
void Tournament::setNumberOfFreeCourts(int numberOfFreeCourts)
{
	if (numberOfFreeCourts < 1)
	{
		this->numberOfFreeCourts = 1;
	}
	this->numberOfFreeCourts = numberOfFreeCourts;
}
void Tournament::setScheme(type scheme)
{
	this->scheme = scheme;
}
void Tournament::setOutputType(MyString outputType)
{
	this->outputType = outputType;
}
void Tournament::setStartTime(Date StartTime)
{
	this->startTime = StartTime;
}
MyString Tournament::getOutputType() const
{
	return this->outputType;
}
int Tournament::getNumberOfCourts() const
{
	return this->numberOfFreeCourts;
}
int Tournament::getDurationOfMatch() const
{
	return this->matchDuration;
}
Date Tournament::getStartTime() const
{
	return this->startTime;
}
Tournament::Tournament()
{
	numberOfTeams = 2;
	matchDuration = 60;
	numberOfFreeCourts = 1;
	scheme = elimination;
	outputType = "Console";
	startTime = Date(1, 6, 2018, 12, 00);
}
Tournament::Tournament(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	setNumberOfTeams(numberOfTeams);
	setMatchDuration(matchDuration);
	setNumberOfFreeCourts(numberOfFreeCourts);
	setScheme(elimination);
	setOutputType(outputType);
	setStartTime(startTime);
}
Tournament::Tournament(int numberOfTeame, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	setNumberOfTeams(numberOfTeams);
	setMatchDuration(matchDuration);
	setNumberOfFreeCourts(numberOfFreeCourts);
	setScheme(elimination);
	setOutputType(outputType);
	setStartTime(startTime);
}
void Tournament::print()
{
	cout << "Number of teams: ";
	cout << this->numberOfTeams << endl;
	cout << "Match duration: ";
	cout << this->matchDuration << endl;
	cout << "Number of free courts: ";
	cout << this->numberOfFreeCourts << endl;
	cout << "Scheme: ";
	if (this->scheme == 0)
		cout << "Elimination ";
	cout << endl;
	if (this->scheme == 1)
		cout << "All vs all " << endl;
	cout << "Output type: ";
	this->outputType.print();
	cout << "Starting Date: ";
	this->startTime.printDate();
}



