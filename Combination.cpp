#include "Combination.h"
#include <iostream>
#include <vector>

//
//
Combination::Combination()
{
	_coins.clear();
}


//
//
Combination::~Combination()
{
	//TODO: Implement if necessary
}

std::vector<long> Combination::MinimumDenomination(int coin, int divisor)
{
    std::vector<long> table;
    int result = 1;
    int newcoin = coin;

    while (result > 0)
    {
        result = newcoin - divisor;
        table.push_back(divisor);
        newcoin--;
    }
    return table;
}

std::vector<long> Combination::OtherDenomination(int Othercoin, int Otherdivisor)
{
	std::vector<long> RecalcTable;
	std::vector<long> Othertable;
	int FromVector;
	int Otherresult = 1;
	int Othernewcoin = Othercoin;
	
	while(Otherresult > 0)
	{
		Otherresult = Othernewcoin - Otherdivisor;
		Othertable.push_back(Otherdivisor);
		Othernewcoin--;
	}
	RecalcTable = MinimumDenomination(Othernewcoin,Otherresult);
	for (auto i = 0; i < RecalcTable.size(); i++)
	{
		FromVector = RecalcTable[i];
		Othertable.push_back(FromVector);
	}
	return Othertable;
}

long Combination::getNumberOfWays(long N, std::vector<long> Coins)
{
    std::vector<long> ways(N + 1);
    ways[0] = 1;

    for (int i = 0; i < (long)Coins.size(); i++)
    { 
        for (int j = 0; j < (long)ways.size(); j++)
        {
            if (Coins[i] <= j)
            { 
                ways[j] += ways[(j - Coins[i])];
            }
        }
    }
    return ways[N];
}

void Combination::PrintTable(std::vector<std::vector<long>> NewTable)
{
    std::cout << std::endl << "The combinations are as follows : " << std::endl;
    for (auto i = 0; i < (long)NewTable.size(); i++)
    {
        for (auto j = 0; j < (long)NewTable[i].size(); j++)
        {
            std::cout << NewTable[i][j] << " ";
        }
    }
}

void Combination::Solution(int n, std::vector<long> x)
{
    std::vector<long> CalculateRow;
    std::vector<std::vector<long>> CurrencyTable;
    int ThisRow;
    long MaxWays;
    MaxWays = getNumberOfWays(n, x);
    int index = 0;

    if (index < MaxWays)
    {
        ThisRow = x[index];
        CalculateRow = MinimumDenomination(n, ThisRow);
        CurrencyTable.push_back(CalculateRow);
    }
    index++;

    /*while (index < MaxWays)
    {
        ThisRow = x[index];
        CalculateRow = OtherDenomination(n, ThisRow);
        CurrencyTable.push_back(CalculateRow);
        index++;
    }*/
    PrintTable(CurrencyTable);
}
    
    

        
