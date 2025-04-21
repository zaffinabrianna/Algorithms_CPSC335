//Brianna Zaffina
//CPSC 335
//Professor Bhandari
//23 April 2025

#include <iostream>
#include <vector>
using namespace std; 

class charmBracelet
{
private:
    vector<int> weight; // Mass of each bead
    vector<int> value; // Charm value of each bead
    int n; // Number of bead types
    int w; // Maximum allowed total mass of the bracelet
public:
    bool isValid(int n, int w)
    {
        if(n > 1 && n <= 100)
        {
            if (w > 1 && w <= 1000000)
            {
                cout << "\nWeight is not in-between 1 and 1000000." << endl;
                return true;
            }

            cout << "\nNumber of beads is not in-between 1 and 100." << endl;
        }
    }

    double knapSack(int w, vector<int> &weight, vector<int> &value)
    {
        //Make n the amount of bead types
        int n = weight.size();
        
        //Check if Valid
        if (isValid(n, w) == false)
        {
            cout << "Following Error Has Occured: " << endl;
            return;
        }
         
        //2D Array
        vector<vector<int>> knap(n + 1, vector<int>(w + 1));

        //Building 2D Array with For Loops
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= w; j++)
            {
                if (i == 0 || j == 0)
                {
                    knap[i][j] = 0;
                }
                else
                {
                    int choose = 0;

                    if(weight[i - 1] <= j)
                    {
                        choose = value[i - 1] + knap[i - 1][j - weight[i - 1]];
                        
                        int dontChoose = knap[i - 1][j];
                        knap[i][j] = max(choose, dontChoose);
                    }
                }
            }
        }
        return knap[n][w];
    }
};