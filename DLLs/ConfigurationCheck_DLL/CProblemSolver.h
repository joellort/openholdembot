#pragma once
//******************************************************************************
//
// This file is part of the OpenHoldem project
//    Source code:           https://github.com/OpenHoldem/openholdembot/
//    Forums:                http://www.maxinmontreal.com/forums/index.php
//    Licensed under GPL v3: http://www.gnu.org/licenses/gpl.html
//
//******************************************************************************
//
// Purpose: guiding new users getting startex
//
//******************************************************************************

#include "LibDef.h"

class CONFIGURATION_CHECK_DLL_API CProblemSolver
{
public:
	CProblemSolver();
	~CProblemSolver();
public:
	void TryToDetectBeginnersProblems();
private:
	bool NoTableMapsInScraperFolder();
	bool NotConnected();
	bool UserChairUnknown();
	bool NoOpponents();
	bool AutoPlayerDidActAtLeastOnce();
	bool NoCardsVisible();
	bool NotEnoughButtonsVisible();
};