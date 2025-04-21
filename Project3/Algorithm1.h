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

    //Function to Check if Variables are Within Valid Zone
    bool isValid(int n, int w)
    {
        //Ensure n is between 1 and 100
        if (n >= 1 && n <= 100)
        {
            //Ensure w is between 1 and 1000000
            if (w >= 1 && w <= 1000000)
            {
                return true; //If both conditions satitsfy, return true
            }
            cout << "ERROR: Weight is not in-between 1 and 1000000.\n" << endl; //If second condition doesn't satisfy, return error
            return false;
        }
        cout << "ERROR: Number of beads is not in-between 1 and 100.\n" << endl; //If first condition doesn't satisfy, return error
        return false;
    }

    //Knapsack Unbounded Algorithm
    double knapSack(int w, vector<int>& weight, vector<double>& value)
    {

        //Check if Valid
        if (isValid(n, w) == false)
        {
            return -1.0;
        }

        //1D Matrix
        vector<double> knap(w + 1, 0);

        //Building 1D Array with For Loops
        for (int i = value.size() - 1; i >= 0; i--) // Goes through array backwards till it hits i - 1 
        { // Order doesn't matter in unbounded knapsack 
            for (int j = 1; j <= w; j++) //j = current total weight
            {
                double choose = 0; // Create variable to keep track of charm value

                if (j - weight[i] >= 0) // Checks if the current bead we're at is better than the previous
                { // And does not exceed the weight limit
                    choose = value[i] + knap[j - weight[i]]; //If it doesn't exceed, add current bead value to choose + best we can get
                    // with remaining weight
                }

                double dontChoose = knap[j]; //Stores current best charm at weight j (if we skip this bead)

                knap[j] = max(choose, dontChoose); //Take max of these and thats our maximum total charm 
            }
        }
        return knap[w];
    }
};