#pragma once
#include "Tournament.h"
#include"EliminationTournament.h"
#include"TeamVsTeam.h"
class TournamentFactory {
public:
	static Tournament* create(type Scheme, int numberOfTeams, int matchDuration, int numberOfFreeCourts,
		const MyString outputType, Date startTime);
};