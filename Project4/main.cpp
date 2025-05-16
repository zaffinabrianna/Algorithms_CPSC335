// CPSC 335
// Professor Bhandari
// 16 May 2025

#pragma once
#include "AlgoA.h"
#include "knapSack01.h"

using namespace std;
int main() {
	//Choose Algorithm
	char choice;
	cout << "Which part do you want to test? Enter the letter (char). (A or B)" << endl;
	cin >> choice;
	choice = toupper(choice);

	switch (choice) {
	case 'A': {
		std::vector<std::pair<int, int>> stocks_and_values = { {1,2}, {3,3}, {5,6}, {6,7} };
		int amount = 10;
		//{10, {1,3}}
		//1 is {3,3} and 3 is {6,7}  
		cout << "Using exhaustive search: " << endl;
		algoA temp;
		std::map<int, std::pair<int, int>> result = temp.stock_maximization(amount, stocks_and_values);
		for (auto& m : result) {
			cout << "{" << m.first << ", {" << m.second.first << ", " << m.second.second << "}}";
		}
		break;
	}
	case 'B': {
		cout << "Using dynamic programing: " << endl;
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

		// ALL OUTPUT STUFF:
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


		break;
	}
	}

	return 0;
}
