#include "TournamentFactory.h"

Tournament * TournamentFactory::create(type schema, int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime)
{
	if (schema == type::elimination)
		return new EliminationTournament(numberOfTeams, matchDuration, numberOfFreeCourts, outputType, startTime);
	if (schema == type::allVsAll)
		return new TeamVsTeam(numberOfTeams, schema, matchDuration, numberOfFreeCourts, outputType, startTime);
	return nullptr;
}
