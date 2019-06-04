#include "TournamentFactory.h"

Tournament * TournamentFactory::create(type scheme, int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	if (scheme == type::elimination)
		return new EliminationTournament(numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	if (scheme == type::allVsAll)
		return new TeamVsTeam(numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	return nullptr;
}
