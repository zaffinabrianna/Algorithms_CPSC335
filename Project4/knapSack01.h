//Brianna Zaffina
//CPSC 335
//Professor Bhandari
//16 May 2025

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stockPurchase
{
private:
	vector<pair<int, int>> stocks_and_values; //Stocks and values in a 2D vector
	vector<vector<int>> resultOfPicked; //Stores whether an index was picked or not
	vector<vector<int>> memoization; //Stores memoization table
	int budget; //Max amount of money we can use

	//Knapsack recursion to perform top-down DP w/ memoizaiton (O(n * W) time and space)
	int knapSackRec(vector<vector<int>> stocks_and_values, int index, int remainingBudget)
	{
		// Check if our index goes out of the bounds of our inital vector and if we have a budget
		if (index >= stocks_and_values.size() || remainingBudget == 0)
		{
			return 0;
		}

		//-1 Indicates whether or not the table has been filled out yet, if it has return it
		if (memoization[index][remainingBudget] != -1)
		{
			return memoization[index][remainingBudget];
		}

		//The max num. of stocks you can get if you skip current index
		int dontPick = knapSackRec(stocks_and_values, index + 1, remainingBudget);

		//Used for the max num. of stocks you can curretnly get 
		int pick = 0;
		//If our current stock index cost is less than or equal to the remaining budget we have
		if (stocks_and_values[index][1] <= remainingBudget)
		{
			//Recurisvely check the next values and decrease the budget
			pick = 1 + knapSackRec(stocks_and_values, index + 1, remainingBudget - stocks_and_values[index][1]);
		}

		//If the item currently picked is greater than the next item in our index
		if (pick > dontPick)
		{
			//Pick the current state
			resultOfPicked[index][remainingBudget] = 1;
			//Store the best result thus far
			memoization[index][remainingBudget] = pick;
		}
		else //If dontPick was better
		{
			//Dont pick the current stock
			resultOfPicked[index][remainingBudget] = 0;
			//Store the best result (which is the value after our current value)
			memoization[index][remainingBudget] = dontPick; 
		}

		//Return the memoization table that stores our max stock count thus far from index with the remainingBudget we have left
		return memoization[index][remainingBudget];
	}

public:
	//Default Constructor
	stockPurchase() : stocks_and_values(0), budget(0) {}
	
	//Overloaded Constructor
	stockPurchase(vector<pair<int, int>> stocks_and_values, int budget)
	{
		this->stocks_and_values = stocks_and_values;
		this->budget = budget;
	}

	//Perform knapsack
	vector<int> computeMaxStock(vector<vector<int>>& stocks_and_values, int budget)
	{
		//Set capacity to the vector size
		int capacity = stocks_and_values.size();
		//Create 2D Vector for memoization table to catch subproblems
		memoization.assign(capacity + 1, vector<int>(budget + 1, -1));
		//Store the result of whether we picked the current or not (0-1 knapsack ITS THE NAME!!!!!)
		resultOfPicked.assign(capacity + 1, vector<int>(budget + 1, 0));

		//Perform the recursion 
		knapSackRec(stocks_and_values, 0, budget);

		vector<int> selected;
		int i = 0;
		int weight = budget;

		// While loop to store the solutions
		while (i < capacity && weight >= 0)
		{
			//Checks if its picked or not picked at the state
			if (resultOfPicked[i][weight])
			{
				//If it is push_back that current stock's index
				selected.push_back(i);
				//Reduce the total weight by the weight of that stock's weight (or cost in this case), and continue to decrease the remaining budget
				weight -= stocks_and_values[i][1];
			}

			i++;
		}

		return selected; //Return the selected indexes
	}
};
