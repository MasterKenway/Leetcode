//
// Created by Kenway on 2/10/2021.
//
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        int i = 0, j = 0, size1 = s1.size(), size2 = s2.size();
        std::unordered_map<char, int> map;
        while (i < size1) {
            map[s1[i]]++;
            map[s2[j]]--;
            i++;
            j++;
        }

        i = 0;
        while (j < size2) {
            while (j < size2 && (j - i) < size1) map[s2[j++]]--;
            auto k = map.begin();
            for (; k != map.end(); ++k) {
                if (k->second != 0) break;
            }
            if (k == map.end()) return true;
            map[s2[i++]]++;
        }

        return false;
    }
};
