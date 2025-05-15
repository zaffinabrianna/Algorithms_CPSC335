//Brianna Zaffina
//CPSC 335
//Professor Bhandari
//16 May 2025

#include <iostream>
#include <vector>
using namespace std;

class stockPurchase
{
private:
	vector<pair<int, int>> stocks_and_values; //Stocks and values in a 2D vector
	vector<vector<int>> results; 
	int budget; //Max amount of money we can use
	int knapSackRec(int budget, int capacity)
	{
		if (capacity == 0 || budget == 0)
		{
			return 0;
		}

		if (results[capacity][budget] != -1)
		{
			return results[capacity][budget];
		}

		int pick = 0;
		int value = stocks_and_values[capacity - 1].first;
		int weight = stocks_and_values[capacity - 1].second;

		if (weight <= budget)
		{
			pick = value + knapSackRec(budget - weight, capacity - 1);
		}

		int notPick = knapSackRec(budget, capacity - 1);

		return results[capacity][budget] = max(pick, notPick);
	}

	vector<int> knapSack(int budget, int capacity)
	{
		vector<int> selected;
		int remainingBudget = budget;

		for (int i = capacity; i > 0 && remainingBudget > 0; i--)
		{
			int value = stocks_and_values[i - 1].first;
			int weight = stocks_and_values[i - 1].second;

			if (weight <= remainingBudget && results[i][remainingBudget] == value + results[i - 1][remainingBudget - weight])
			{
				selected.push_back(i - 1);
			}

		}

		reverse(selected.begin(), selected.end());
		return selected;
	}

public:
	pair<int, vector<int>> computerMaxStockProb(int budget, const vector<pair<int, int>>& stocks_and_values)
	{
		this->budget = budget;
		this->stocks_and_values = stocks_and_values;
		int capacity = stocks_and_values.size();

		results.assign(capacity + 1, vector<int>(budget + 1, -1));

		int maxStockCount = knapSackRec(capacity, budget);
		vector<int> selected = knapSack(capacity, budget);

		return { maxStockCount, selected };
	}
};
