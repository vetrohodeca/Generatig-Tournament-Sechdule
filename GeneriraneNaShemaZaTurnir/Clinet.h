#pragma once
#include"Turnir.h"
class Client { 
private:
	int numberOfTeams;
	int matchDuration;
	int numberOfFreeCourts;
	type scheme;
	MyString outputType;
	Date startTime;
	Tournament *pTournament;
public: 
	void setTournament(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime);
	Client();
	Client(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime);
	~Client();
Tournament* getTournament();
}; 
