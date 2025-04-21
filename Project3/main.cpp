#pragma once
#include "Algorithm1.h"

int main()
{
    //Test 1:
    cout << "Test 1: " << endl;
    cout << "=========================================" << endl;
    int n = 3;
    int w = 10;
    vector<int> weight = { 2, 3, 5 };
    vector<double> value = { 3.0, 4.0, 7.5 };

    charmBracelet result(n, w, weight, value);
    double maxTotalCharm = result.knapSack(w, weight, value);
    cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << maxTotalCharm << endl;

    //Test 2:
    int n1 = 3;
    int w1 = 7;
    vector<int> weight1 = { 2, 3, 4 };
    vector<double> value1 = { 3.0, 4.0, 5.0 };
    cout << "\nTest 2: " << endl;
    cout << "=========================================" << endl;
    charmBracelet result1(n1, w1, weight1, value1);
    double maxTotalCharm1 = result.knapSack(w1, weight1, value1);
    cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << maxTotalCharm1 << endl;
    return 0;
}