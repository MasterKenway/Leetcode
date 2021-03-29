//
// Created by Kenway on 7/28/2020.
//

#include <iostream>
#include <vector>

class App {
    int b;
    int mem;
};

class Solution {
    std::vector<App> answer(std::vector<App> apps) {
        std::vector<App> normal, import;
        for (int i = 0; i < apps.size(); ++i) {
            if (apps[i].b == 1) {
                normal.push_back(apps[i]);
            } else {
                import.push_back(apps[i]);
            }
        }

        std::vector<int, std::vector<int>> dp;
        for (int i = 0; i < normal.size(); ++i) {
            // 01 package judge
        }

        for (int i = 0; i < import.size(); ++i) {
            // 01 package judge
        }
    }
};

