#include <iomanip>
#include "Algorithm1.h"
#include "Algo2.h"

int main()
{
    int choice;
    cout << "Which Algorithm do you want to test? Enter the number. (1 or 2)" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        //Test 1:
        int n = 3;
        int w = 10;
        vector<int> weight = { 2, 3, 5 };
        vector<double> value = { 3.0, 4.0, 7.5 };
        cout << "Test 1: " << endl;
        cout << "=========================================" << endl;
        charmBracelet result(n, w, weight, value);
        double maxTotalCharm = result.knapSack(n, w, weight, value);
        cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << fixed << setprecision(2) << maxTotalCharm << endl;

        //Test 2:
        int n1 = 3;
        int w1 = 7;
        vector<int> weight1 = { 2, 3, 4 };
        vector<double> value1 = { 3.0, 4.0, 5.0 };
        cout << "\nTest 2: " << endl;
        cout << "=========================================" << endl;
        charmBracelet result1(n1, w1, weight1, value1);
        double maxTotalCharm1 = result1.knapSack(n1, w1, weight1, value1);
        cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << fixed << setprecision(2) << maxTotalCharm1 << endl;

        //Test 3:
        int n2 = 3;
        int w2 = 1000001;
        vector<int> weight2 = { 2, 3, 4 };
        vector<double> value2 = { 3.0, 4.0, 5.0 };
        cout << "\nTest 3: " << endl;
        cout << "=========================================" << endl;
        charmBracelet result2(n2, w2, weight2, value2);
        double maxTotalCharm2 = result2.knapSack(n2, w2, weight2, value2);
        cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << fixed << setprecision(2) << maxTotalCharm2 << endl;

        //Test 4:
        int n3 = 101;
        int w3 = 7;
        vector<int> weight3 = { 2, 3, 4 };
        vector<double> value3 = { 3.0, 4.0, 5.0 };
        cout << "\nTest 4: " << endl;
        cout << "=========================================" << endl;
        charmBracelet result3(n3, w3, weight3, value3);
        double maxTotalCharm3 = result3.knapSack(n3, w3, weight3, value3);
        cout << "Maximum Total Charm Achievable Under the Weight Constraint is: " << fixed << setprecision(2) << maxTotalCharm3 << endl;

        break;
    }

    case 2:
    {
        Wine item1;
        Wine item2;
        Wine item3;
        item1.aged({ 7, 1, 5, 3, 6, 4 });
        item2.aged({ 9, 8, 6, 3, 1 });
        item3.aged({ 34, 12, 78, 5, 0, 45, 23, 89, 7, 56 });
        item1.print();
        item2.print();
        item3.print();
        break;
    }
    }
}
