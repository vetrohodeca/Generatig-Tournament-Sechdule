#include"Clinet.h"
Client::Client()
{

	numberOfTeams = 2;
	matchDuration = 60;
	numberOfFreeCourts = 1;
	scheme = elimination;
	outputType = "Console";
	startTime = Date(1, 6, 2018, 12, 00);
	pTournament = Tournament::create(scheme, numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
}
Client::Client(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	this->numberOfTeams = numberOfTeams;
	this->matchDuration = matchDuration;
	this->numberOfFreeCourts = numberOfFreeCourts;
	this->outputType = outputType;
	this->startTime = startTime;
	this->scheme = scheme;
	pTournament = Tournament::create(scheme, numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
}
Client::~Client()
{
	if (pTournament)
	{
		delete[] pTournament;
		pTournament = NULL;
	}
}
void Client::setTournament(int numberOfTeams, type Scheme, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	pTournament->setMatchDuration(matchDuration);
	pTournament->setNumberOfTeams(numberOfTeams);
	pTournament->setNumberOfFreeCourts(numberOfFreeCourts);
	pTournament->setOutputType(outputType);
	pTournament->setStartTime(startTime);
	pTournament->setOutputType(outputType);
}
Tournament* Client::getTournament()
{
	return pTournament;
}