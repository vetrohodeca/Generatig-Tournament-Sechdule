#include"EliminationTournament.h"

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
	for (size_t i = 0; i < numberOfLoops; i++)
	{

		if ((1 + i) * numberOfFreeCourts > numberOfFreeCourts&&i == numberOfLoops - 1)
		{
			cout << "Match " << numberOfFreeCourts * i + 1 << "-" << numberOfMatches  << " start at: ";
		}
		else cout << "Match " << numberOfFreeCourts * i + 1 << "-" << (1 + i) * numberOfFreeCourts << " start at: ";
		this->startTime.printDate();
		this->startTime.addMinutes(matchDuration);
	}
}
void EliminationTournament::makeScheduleFile()
{
}
EliminationTournament::~EliminationTournament()
{

}