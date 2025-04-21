//Brianna Zaffina
//CPSC 335
//Professor Bhandari
//23 April 2025

#include <iostream>
#include <vector>
using namespace std;

//Using Unbounded Knapsack
class charmBracelet
{
private:
    vector<int> weight; // Mass of each bead
    vector<double> value; // Charm value of each bead
    int n; // Number of bead types
    int w; // Maximum allowed total mass of the bracelet

public:
    //Default Constructor
    charmBracelet() : n(0), w(0), weight(0), value(0) {}

    //Overloaded Constructor
    charmBracelet(int n, int w, vector<int> weight, vector<double> value)
    {
        this->n = n;
        this->w = w;
        this->weight = weight;
        this->value = value;
    }

    bool isValid(int n, int w)
    {
        if (n >= 1 && n <= 100)
        {
            if (w >= 1 && w <= 1000000)
            {

                return true;
            }
            cout << "\nWeight is not in-between 1 and 1000000." << endl;
            return false;
        }
        cout << "\nNumber of beads is not in-between 1 and 100." << endl;
        return false;
    }

    double knapSack(int w, vector<int>& weight, vector<double>& value)
    {
        //Check if Valid
        if (isValid(n, w) == false)
        {
            cout << "Following Error Has Occured: " << endl;
            return -1.0;
        }

        //1D Matrix
        vector<double> knap(w + 1, 0);

        //Building 1D Array with For Loops
        for (int i = value.size() - 1; i >= 0; i--)
        {
            for (int j = 1; j <= w; j++)
            {
                double choose = 0;

                if (j - weight[i] >= 0)
                {
                    choose = value[i] + knap[j - weight[i]];
                }

                double dontChoose = knap[j];

                knap[j] = max(choose, dontChoose);
            }
        }
        return knap[w];
    }
};