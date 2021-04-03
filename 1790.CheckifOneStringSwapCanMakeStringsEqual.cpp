//
// Created by Kenway on 3/30/2021.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int length = s1.length(), counter = 0;
        vector<int> array;
        for (int i = 0; i < length; ++i) {
            if (s1[i] != s2[i]) {
                counter++;
                array.push_back(i);
            }
        }
        if (counter == 0) return true;
        if (counter == 2 && s1[array[0]] == s2[array[1]] && s1[array[1]] == s2[array[0]]) {
            return true;
        }
        return false;
    }
};