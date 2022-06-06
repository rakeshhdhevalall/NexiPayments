#include "Menu.h"
#include <vector>
#include "Entities/Denominator.h"
#include "Entities/Combination.h"
#include <fstream>

Combination NewCombination;
Denominator NewDenominator;
//
//
void Menu::configureOptions()
{
	_options.clear();
	_optionHeadings.clear();

	_options[0]        = std::bind(&Menu::quit, this);
	_options[1]		   = std::bind(&Menu::amt, this);

	_optionHeadings[0] = "Exit";
	_optionHeadings[1] = "Transact";
}


//
//
void Menu::print()
{
	system("CLS");

	std::cout << std::string(_heading.length(), '*') << std::endl;
	std::cout << _heading << std::endl;
	std::cout << std::string(_heading.length(), '*') << std::endl;

	std::cout << "Available options:" << std::endl;
	
	for (std::pair<int, std::function< void(void) > > option : _options)
	{
		std::cout << "\t" << option.first << "\t-\t" << _optionHeadings[option.first] << std::endl;	
	}

	std::cout << std::string(_heading.length(), '*') << std::endl;
	std::cout << "Please make your selection: ";
}




//
//
int Menu::getInput()
{
	int input = 0;

	std::cin >> input;

	return input;
}


//
//
void Menu::processInput(int option)
{
	int chosenOption = option;

	while (_options.find(chosenOption) == _options.end())
	{
		std::cout << "No such option available.  Please retry: ";

		chosenOption = getInput();
	}

	_options[chosenOption]();
}


//
//
void Menu::quit()
{
	_quit = 1;
}

void Menu::amt()
{
	std::vector<long> MyDenominators;
	_amt = 2;
	std::cout << "Please enter the Rand value : ";
	std::cin >> RandValue;
	MyDenominators = NewDenominator.GetDenominator();
	SaveToFile(RandValue, MyDenominators);
	NewCombination.Solution(RandValue, MyDenominators);
}


//
//
Menu::Menu()
{
	_heading = "Perago's Default Menu";
	_quit    = 0;

	configureOptions();
}


//
//
Menu::Menu(std::string heading)
{
	_heading = heading;
	_quit    = 0;

	configureOptions();
}


//
//
Menu::~Menu()
{
	// Empty for now
}


//
//
void Menu::run()
{

	do
	{
		print();
		processInput(getInput());

	} while ( _quit == 0 );
}

void Menu::SaveToFile(int Rand, std::vector<long> Denoms)
{
	std::ofstream fout;
	fout.open("Transaction.txt", std::ios::app);

	fout << std::endl << "Rand : " << Rand << std::endl << "Denominators : " << std::endl;
	for (auto i = 0; i < (long)Denoms.size(); i++)
		fout << Denoms[i] << " ";
	fout.close();
}

		

	
	


