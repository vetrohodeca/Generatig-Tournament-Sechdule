#pragma once
#include "Turnir.h"
class TournamentFactory {
public:
	static Tournament* create(type Scheme, int numberOfTeams, int matchDuration, int numberOfFreeCourts, const MyString outputType, Date startTime);
};