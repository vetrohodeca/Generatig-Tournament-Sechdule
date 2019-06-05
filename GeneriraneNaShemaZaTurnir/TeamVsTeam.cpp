#include"TeamVsTeam.h"

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
	for (size_t i = 0; i < numberOfLoops; i++)
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
				this->startTime.addMinutes(interval);
				{
					cout << "Okey!";
				}
			}
		}
				if ((1 + i) * numberOfFreeCourts > numberOfFreeCourts&&i == numberOfLoops - 1)
				{
					cout << "Match " << numberOfFreeCourts * i + 1 << "-" << numberOfMatches << " start at: ";
				}
				else cout << "Match " << numberOfFreeCourts * i + 1 << "-" << (1 + i) * numberOfFreeCourts << " start at: ";
			this->startTime.printDate();
			this->startTime.addMinutes(matchDuration);
		}
	
}
void TeamVsTeam::makeScheduleFile()
{

}
TeamVsTeam::~TeamVsTeam()
{

}