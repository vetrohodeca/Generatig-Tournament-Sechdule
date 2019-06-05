#include"Date.cpp"
#include"Tournament.h"
#include"String.h"
#include "TournamentFactory.h"
int main()
{
	int day, month, year, hour, min;
	cout << "Input day: ";
	cin >> day;
	cout << "Input month: ";
	cin >> month;
	cout << "Input year: ";
	cin >> year;
	cout << "Input hour: ";
	cin >> hour;
	cout << "Input minutes: ";
	cin >> min;
	int numberOfTeams;
	cout << "Number of teams: ";
	cin >> numberOfTeams;
	int matchDuration;
	cout << "Input match duration: ";
	cin >> matchDuration;
	int numberOfFreeCourts;
	cout << "Number of free courts: ";
	cin >> numberOfFreeCourts;
	Date startTime(day, month,year, hour, min);
	MyString outputType;
	cout << "Input output type (""console"" is the only one available for now): ";
		cin>> outputType;
	cin >> outputType;
	type scheme;
	bool schemeB;
	cout << "Input 0 for elimination and 1 for AllVsAll! ";
	cin >> schemeB;
	if (schemeB == 0)
	{
		scheme = elimination;
	}
	else  scheme= allVsAll;
	Tournament * pTournament = TournamentFactory::create(scheme, numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	if (pTournament->getOutputType()=="console")
	{
		cout << pTournament->calculateMatches() << " Matches   " << pTournament->getNumberOfCourts() << " Courts   "
			<< pTournament->getDurationOfMatch() << "min is one match" << endl;
		pTournament->makeSchedule();
	}
	

	system("pause");
	return 0;
}