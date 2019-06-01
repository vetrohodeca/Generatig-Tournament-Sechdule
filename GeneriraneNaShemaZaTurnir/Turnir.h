#pragma once
#include"String.h"
using namespace std;
class “Óurnament
{
protected:
	int numberOfTeams;
	int matchDuration;
	int numberOfFreeCourts;
	MyString outputType;
public:
	“Óurnament();
	Tournament(int numberOfTeams, bool type, int matchDuration, int numberOfFreeCourts, MyString outputType);
	
};

class eliminationTournament : public “Óurnament //if tournament is elimination, the number of teams must be power of 2
{

};
class allVsAllTournament : public “Óurnament
{

};