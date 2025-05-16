// Suanna Shih
// CPSC 335
// Professor Bhandari
// 16 May 2025

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

class algoA {
public:
    std::map<int, std::pair<int, int>> stock_maximization(int M, std::vector<std::pair<int, int>> vec) { //{{1,2}, {3,3}, {5,6}, {6,7}};
        std::map<int, std::pair<int, int>> result;    //{10, {1,3}}
        int total_value;
        int current_max;
        total_value = vec[0].second + vec[findMax(vec)].second; //default max
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].second + vec[findMax(vec)].second <= M &&
                vec[i].second + vec[findMax(vec)].second > total_value) {
                result.insert({ M, {i, findMax(vec)} });
            }
        }
        return result;
    }

    //return index of max
    int findMax(std::vector<std::pair<int, int>> vec) {
        if (vec.empty()) return -1;  //catch
        int current_index = 0;
        int max_index = 0;
        for (const auto& m : vec) {
            if (m.second > vec[max_index].second) {
                max_index = current_index;  //replace w currently highest
            }
            ++current_index;
        }
        return max_index;
    }
};
