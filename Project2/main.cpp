// Brianna Zaffina & Suanna Shih
// CPSC 335
// Professor Bhandari
#include <iostream>
#include <vector>
#include "Algorithm1.h"
#include "vibeCheck.h"
using namespace std;
int main(){
  int choice;
  cout << "Which Algorithm do you want to test? Enter the number. (1 or 2)" << endl;
  cin >> choice;
  
  switch(choice)
  {
    case 1:{
      cout << "Algorithm 1 Test: "  << endl;
      std::vector<vector<string>> walls = {{"INF", "-1", "0", "INF"},
                                           {"INF", "INF", "INF", "-1"},
                                           {"INF", "-1", "INF", "-1"},
                                           {"0", "-1", "INF", "INF"}};
      std::vector<vector<string>> walls2 = {{"0", "INF", "INF"},
                                            {"INF", "-1", "INF"},
                                            {"INF", "INF", "0"}};
      cout << "Test 1: " << endl;
      Array temp;
      vector<vector<int>> spawn_point = temp.locateSpawn(walls);
      vector<vector<int>> result = temp.stepMap(walls, spawn_point);
      temp.printArray(result);
      cout << endl;

      cout << "Test 2:" << endl;
      Array temp2;
      vector<vector<int>> spawn_point2 = temp2.locateSpawn(walls2);
      vector<vector<int>> result2 = temp2.stepMap(walls2, spawn_point2);
      temp.printArray(result2);
      break;
    }

    case 2:{
      deckGroups temp;
      cout << "Algorithm 2 Test: " << endl;
      // First Test (should be valid)
      vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
      int groupSize = 3;
      cout << "First Test [1, 2, 3, 6, 2, 3, 4, 7, 8]:\n";
      temp.validGroup(hand, groupSize);

      // Second Test (should be invalid)
      cout << "\n";
      vector<int> hand1 = {1, 2, 3, 3, 4, 5, 6, 7};
      int groupSize1 = 4;
      cout << "Second Test [1, 2, 3, 3, 4, 5, 6, 7]:\n";
      temp.validGroup(hand1, groupSize1);

      // Third Test (should be invalid)
      cout << "\n";
      vector<int> hand2 = {1, 2, 3, 3, 4, 5, 6, 7};
      int groupSize2 = 5;
      cout << "Third Test (Group Size 5) [1, 2, 3, 3, 4, 5, 6, 7]:\n";
      temp.validGroup(hand2, groupSize2);

      // Fourth Test (should be valid)
      cout << "\n";
      vector<int> hand3 = {1, 3, 6, 2, 4, 2, 3, 8, 7};
      int groupSize3 = 3;
      cout << "Fourth Test [1, 3, 6, 2, 4, 2, 3, 8, 7]:\n";
      temp.validGroup(hand3, groupSize3);

      return 0;
      break;
    }
  }
}
