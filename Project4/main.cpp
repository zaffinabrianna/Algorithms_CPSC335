#include "knapSack01.cpp"

int main()
{
	stockPurchase temp1;
	vector<pair<int, int>> stocks_and_values = {
		{ 1,2 },
		{3, 3},
		{5, 6},
		{6, 7} };
	int budget = 10;
	int capacity = stocks_and_values.size();
	
	pair<int, vector<int>> result = temp1.computerMaxStockProb(budget, stocks_and_values);
	
	cout << "[" << result.first << ", [";
	for (size_t i = 0; i < result.second.size(); ++i)
	{
		cout << result.second[i];
		if (i != result.second.size() - 1)
		{
			cout << ", ";
		}
		cout << "]]" << endl;
	}

	return 0;
}
