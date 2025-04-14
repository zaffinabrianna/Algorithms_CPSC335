// Brianna Zaffina
// CPSC 335
// Professor Bhandari
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class deckGroups
{
private:
    int groupSize;
    vector<int> temp;

public:
    //Default Constructor
    deckGroups() : groupSize(0), temp() {}
    //Destructor
    ~deckGroups() {}

    //Sees if the array and groupsize is valid
    bool isValid(vector<int> temp, int groupSize)
    {
        //Check to see if the size is valid first
        if (temp.empty() || temp.size() > 105)
        {
            cout << "Your array size is invalid\n";
            return false;
        }

        //Check to see if group size is valid
        if (groupSize < 1)
        {
            cout << "Your group size is not valid\n";
            return false;
        }

        //Check if the vector can even be divided into equal groups of groupSize
        if (temp.size() % groupSize != 0)
        {
            cout << "Your group is not valid, cannot be divided into even groups\n";
            return false;
        }

        return true;
    }

    //Sees if the vector "group" of cards is valid
    bool validGroup(vector<int> temp, int groupSize)
    {
        //Check if first parameters are valid
        if (!isValid(temp, groupSize))
        {
            return false;
        }

        //Sort the vector first
        sort(temp.begin(), temp.end());

        //Make a map to store the values repeated
        unordered_map<int, int> repCount;

        //If the values are repeated store them in a diff
        for (int card : temp)
        {
            repCount[card]++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            //Initalize the card with the value in the group
            int card = temp[i];

            //Check how many times the card has been in the group
            if (repCount[card] == 0)
            {
                //If the count is 0, then continue
                continue;
            }

            for (int j = 0; j < groupSize; j++)
            {
                //If the next card isn't in the group either
                if (repCount[card + j] == 0)
                {
                    cout << "Your group is invalid, it does not increase by 1 consecutively.\n";
                    return false;
                }

                repCount[card + j]--;
            }
        }
        //If the nested for-loop iteratoes fully without issues, it is valid
        //and returns true
        cout << "Your group is valid!\n";
        return true;
    }
};
