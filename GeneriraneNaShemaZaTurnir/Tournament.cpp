#include"Tournament.h"
#include<cmath>
#include<iostream>
using namespace std;
void Tournament::setNumberOfTeams(int numberOfTeams)
{
	this->numberOfTeams = numberOfTeams;
}
void Tournament::setMatchDuration(int matchDuration)
{
	this->matchDuration = matchDuration;
}
void Tournament::setNumberOfFreeCourts(int numberOfFreeCourts)
{
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


Tournament* Tournament::create(type Scheme, int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	if (Scheme == type::elimination)
		return new EliminationTournament(numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	if (Scheme == type::allVsAll)
		return new TeamVsTeam(numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	return nullptr;
}


EliminationTournament::EliminationTournament()
{
	this->scheme = elimination;
}

void EliminationTournament::validation(int numberOfTeams)
{
	bool flag = 0;
	for (int i = 2; i <= 32; i *= 2)
	{
		if (numberOfTeams == i)
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		throw"Wrong number of teams";
	}
}

EliminationTournament::EliminationTournament(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime)
{
	setNumberOfTeams(numberOfTeams);
	setMatchDuration(matchDuration);
	setNumberOfFreeCourts(numberOfFreeCourts);
	setOutputType(outputType);
	setStartTime(StartTime);
	validation(numberOfTeams);
}
int EliminationTournament::calculateMatches()
{
	int result = 0;
	for (size_t i = 1; i < this->numberOfTeams; i *= 2)
	{
		result += i;
	}
	return result;
}
void EliminationTournament::makeSchedule()
{
	this->startTime.printDate();
	int numberOfMatches = calculateMatches();
	int numberOfLoops = ceil((double)numberOfMatches / (double)numberOfFreeCourts);
	for (size_t i = 0; i<numberOfLoops; i++)
	{

		if ((1 + i) * numberOfFreeCourts > numberOfFreeCourts&&i == numberOfLoops-1)
		{
			cout << "Match " << numberOfFreeCourts * i + 1 << "-" << numberOfMatches * numberOfFreeCourts << " start at: ";
		}
		else cout << "Match " << numberOfFreeCourts * i + 1 << "-" << (1 + i) * numberOfFreeCourts << " start at: ";
		this->startTime.printDate();
		this->startTime.addMinutes(matchDuration);
	}
}
EliminationTournament::~EliminationTournament()
{

}





TeamVsTeam::TeamVsTeam()
{
	this->scheme = allVsAll;
}
void TeamVsTeam::validation(int numberOfTeams)
{
	if (numberOfTeams > 32)
	{
		throw"Too much teams";
	}
}

TeamVsTeam::TeamVsTeam(int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date StartTime)
{
	setNumberOfTeams(numberOfTeams);
	setMatchDuration(matchDuration);
	setNumberOfFreeCourts(numberOfFreeCourts);
	setOutputType(outputType);
	setStartTime(StartTime);
	validation(numberOfTeams);
}
int TeamVsTeam::calculateMatches()
{
	int result = 0;
	for (size_t i = 1; i < numberOfTeams; i++)
	{
		result += i;

	}
	return result;
}
void TeamVsTeam::makeSchedule()
{
	char answer;
	int numberOfMatches = calculateMatches();
	int numberOfLoops = ceil((double)numberOfMatches / (double)numberOfFreeCourts);
	for (size_t i = 0; i <numberOfLoops; i++)
	{
		if (i != 0)
		{
			cout << "Do you want to make a litle pause between matches?  Y/N   ";
			cin >> answer;
			if (answer == 'Y' || answer == 'y')
			{
				int interval;
				cout << "Input minutes: ";
				cin >> interval;
				setMatchDuration(matchDuration + interval);
				{
					cout << "Okey!";
				}
			}
		}
		else
			
		if ((1 + i) * numberOfFreeCourts > numberOfFreeCourts&&i == numberOfLoops - 1)
		{
			cout << "Match " << numberOfFreeCourts * i + 1 << "-" << numberOfMatches * numberOfFreeCourts << " start at: ";
		}
		else cout << "Match " << numberOfFreeCourts * i + 1 << "-" << (1 + i) * numberOfFreeCourts << " start at: ";
		this->startTime.printDate();
		this->startTime.addMinutes(matchDuration);
	}

}

TeamVsTeam::~TeamVsTeam()
{

}