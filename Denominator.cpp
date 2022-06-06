#include "Denominator.h"
#include <iostream>
#include <vector>

//
//
Denominator::Denominator()
{
	_money = 0;

	_denominations.clear();

	_combinations.clear();
}

std::vector<long> Denominator::GetDenominator()
{
	int Count;
	long Amount;
	std::vector<long> Denominators;

	std::cout << "Please enter the denominators and press the Enter key after each input. Enter X to terminate" << std::endl;
	while (std::cin >> Amount)
		Denominators.push_back(Amount);
	return Denominators;
}

//
//
Denominator::~Denominator()
{
}
