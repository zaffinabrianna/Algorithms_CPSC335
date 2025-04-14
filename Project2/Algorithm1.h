// Suanna Shih
// CPSC 335
// Professor Sugandha Bhandari

#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Array{
  public:
  //2D array find O, [i][j]
  vector<vector<int>> locateSpawn(vector<vector<string>> arr)
  {
    vector<vector<int>> location;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++){
          if(arr[i][j] == "0"){
            location.push_back({i,j});
            //location[i].push_back(j);
          }
        }
    }
      return location;
  }

  //directions need for walking in spaces
  const map<string, pair<int, int>> directions = {
          {"up", {-1, 0}},
          {"down", {1, 0}},
          {"left", {0, -1}},
          {"right", {0, 1}}
    };

  //takes in original map and location of spawn points
  vector<vector<int>> stepMap(vector<vector<string>>& arr, vector<vector<int>> location)
  {
    //initialize things
      int bound_i = arr[0].size();
      int bound_j = arr.size();
      vector<vector<int>> result(bound_i, vector<int>(bound_j));  //initialize an empty final map

      // BFS
      queue<pair<int, int>> q;  //visited spaces, since we're using BFS


    //get spawn point in the queue
      for (auto& loc : location)
      { // start from spawn points
        int r = loc[0];
        int c = loc[1];
        result[r][c] = 0;
        q.push({r, c});
      }

      //BFS
      int step = 0;
      while (!q.empty()) // if there's divided point exist
      {
        pair<int, int> us = q.front();    //our current location(1st spawn point)
        //step = 1;
        int i = us.first;
        int j = us.second;
        q.pop();

        for (auto it = directions.begin(); it != directions.end(); ++it)  //look at all direction
        {
          //next spaces
          int next_i = i + it->second.first;
          int next_j = j + it->second.second;

          if(next_i >= 0 && next_i < bound_i && next_j >= 0 && next_j < bound_j && arr[next_i][next_j] != "-1") //within bounds and not a wall
          {
            // if(arr[next_i][next_j] == "INF"){
            //   arr[next_i][next_j] = step;
            //   result[next_i][next_j] = step; //copy to result
            //   ++step;
            //   q.push({next_i, next_j}); //move spaces
              if (arr[next_i][next_j] > arr[i][j])//if step count is less, overwrite
              {
                arr[next_i][next_j] = arr[i][j];
                result[next_i][next_j] = result[i][j] + 1;    //copt to result
                q.push({next_i, next_j}); // move spaces
              }
          // }
          }

        }


      }
        // so apparently above keeps rewriting -1, so I rewrite again
        for (int i = 0; i < arr[0].size(); i++)
        {
          for (int j = 0; j < arr.size(); j++)
          {
            if (arr[i][j] == "-1")
            {
              result[i][j] = -1; // Keep it as -1 instead of a step count
            }
          }
        }
        return result;
      }

      void printArray(vector<vector<int>> arr)
      {
        for (int i = 0; i < arr.size(); i++)
        {
          for (int j = 0; j < arr[i].size(); j++)
          {
            cout << arr[i][j] << " ";
          }
          cout << endl;
        }
  }



  private:
  //help
};
