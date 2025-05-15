#include "knapSack01.h"

int main()
{
	// PART B
	vector<vector<int>> stocks_and_values = {
		{ 1,2 },
		{3, 3},
		{5, 6},
		{6, 7} };
	int budget = 10;
	
	stockPurchase temp1;
	vector<int>results = temp1.computeMaxStock(stocks_and_values, budget);
	
	int totalCost = 0;
	int totalStocks = 0;
	
	cout << "____________________________________________" << endl;
	cout << "Our budget is " << budget << ".\n";
	cout << "Let's find the total amount of stocks we can get with our budget!\n";
	cout << "Our 2D Array: [1,2], [3,3], [5,6], [6,7]." << endl << endl;

	for (int i = 0; i < results.size(); i++)
	{
		int stockIndex = results[i];
		totalCost += stocks_and_values[stockIndex][1];
		totalStocks += stocks_and_values[stockIndex][0];
	}

	cout << "RESULTS: " << endl;
	cout << "[" << totalCost << ", [";
	for (int i = 0; i < results.size(); i++)
	{
		cout << results[i];
		if (i != results.size() - 1)
		{
			cout << ",";
		}
	}
	cout << "]]" << endl;

	cout << "Where " << totalCost << " is the total cost, ";
	for (int i = 0; i < results.size(); i++)
	{
		int stockIndex = results[i];
		cout << "where " << stockIndex << " is the index of [" << stocks_and_values[stockIndex][0] << ", " << stocks_and_values[stockIndex][1] <<
			"]";
		if (i != results.size() - 1)
		{
			cout << " and ";
		}
	}
	cout << ".\nOur maximum total stocks within our budget is: " << totalStocks << endl;

	return 0;
}
