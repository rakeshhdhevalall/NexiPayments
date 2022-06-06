#pragma once

#include <vector>

#include "Combination.h"

class Denominator
{
private:
	unsigned long            _money;
	std::vector<int>         _denominations;
	std::vector<Combination> _combinations;

public:
	//
	// Default constructor
	Denominator();
	std::vector<long> Denominator::GetDenominator();

	//
	// Destructor
	~Denominator();
};

