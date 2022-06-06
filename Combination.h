#pragma once
#include <vector>

//
// Simply stores a list of numbers to represent
// a combination of coins
class Combination
{
private:
	std::vector<int> _coins;

public:
	//
	// Default constructor
	Combination();

	//
	// Destructor
	~Combination();

	std::vector<long> Combination::MinimumDenomination(int coin, int divisor);
	std::vector<long> Combination::OtherDenomination(int Othercoin, int Otherdivisor);
	long Combination::getNumberOfWays(long N, std::vector<long> Coins);
	void Combination::PrintTable(std::vector<std::vector<long>> NewTable);
	void Combination::Solution(int n, std::vector<long> x);
};

