#pragma once

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>

//
// Represents the menu, along with input
class Menu
{
private:
	std::string                              _heading;
	std::map< int, std::function< void() > > _options;
	std::map< int, std::string >             _optionHeadings;
	int                                      _quit;
	int                                      _amt;
	long                                     RandValue;

	void configureOptions();
	void print();
	int  getInput();
	void processInput(int option);
	void quit();
	void amt();
	void SaveToFile(int Rand, std::vector<long> Denoms);

public:
	//
	// Default constructor
	Menu();

	//
	// Constructor taking menu heading as parameter
	Menu(std::string heading);

	//
	// Destructor
	~Menu();

	//
	//
	void run();
};


