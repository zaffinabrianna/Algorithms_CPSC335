// Suanna Shih
// CPSC 335
// Professor Sugandha Bhandari

#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Wine{
  public:
    void aged(const std::vector<int>& values){
      for (int i = 0; i < values.size() - 1; ++i){
        for (int j = 1; j < values.size(); ++j){
          if(values[i] < values[bottle]){    //find min
            bottle = i ; //day index
          }
          if(values[j] > values[sell] && j != 0){  //find max
            sell = j;
          }
        }
      }
      total_value = values[sell] - values[bottle];
      if (sell < bottle || bottle == values.size() || sell == 0 || total_value < 0)
      {
        total_value = 0;  //fail
      }
    }

    void print(){
      cout << "Bottle day: Day " << bottle + 1 << endl;
      cout << "Sold day: Day " << sell + 1<< endl;
      cout << "Total value: " << total_value << endl
           << endl;
    }

    private:
      int bottle = 0;
      int sell = 1;
      int total_value = 0;
};
